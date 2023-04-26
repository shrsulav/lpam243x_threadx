/*
 * Copyright (c) 2001,2002 Florian Schulze.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the authors nor the names of the contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * test.c - This file is part of lwIP test
 *
 */

/* C runtime includes */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include <kernel/dpl/TaskP.h>
#include <kernel/dpl/SystemP.h>

#include <drivers/udma/udma_priv.h>
#include <drivers/udma.h>

#include <enet.h>
#include <networking/enet/core/include/per/cpsw.h>
#include <networking/enet/utils/include/enet_appmemutils_cfg.h>
#include <networking/enet/utils/include/enet_apputils.h>
#include <networking/enet/utils/include/enet_appmemutils.h>
#include <networking/enet/utils/include/enet_appboardutils.h>
#include <networking/enet/utils/include/enet_appsoc.h>
#include <networking/enet/utils/include/enet_apprm.h>

#if (ENET_ENABLE_PER_ICSSG == 1)
#include <networking/enet/core/include/per/icssg.h>
#endif

/*
 * Using CPSW defined macros for this specific file
 */
#undef htons
#undef ntohs
#undef htonl
#undef ntohl

#include <networking/enet/core/lwipif/inc/lwip2lwipif.h>
#include <networking/enet/core/lwipif/inc/lwipif2enet_AppIf.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define ENETLWIP_PACKET_POLL_PERIOD_US                                  (1000U)


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                            Function Declaration                            */
/* ========================================================================== */

/* Temporary hack to hard code Tx and Rx DMA channel index until the lwipcb is migrated to syscfg generated code */
#define LWIP_ENET_TX_DMA_CH_IDX (0U)
#define LWIP_ENET_RX_DMA_CH_IDX (0U)




void LwipifEnetAppCb_getHandle(LwipifEnetAppIf_GetHandleInArgs *inArgs,
                               LwipifEnetAppIf_GetHandleOutArgs *outArgs)
{
    EnetPer_AttachCoreOutArgs attachInfo;
    uint32_t coreId          = EnetSoc_getCoreId();
    Enet_Type enetType;
    uint32_t instId;
    Enet_MacPort macPortList[ENET_MAC_PORT_NUM];
    uint8_t numMacPorts = 0;
    bool useRingMon = false;
    EnetApp_HandleInfo handleInfo;
    EnetApp_GetTxDmaHandleOutArgs  txChInfo; 
    EnetApp_GetRxDmaHandleOutArgs  rxChInfo;
    EnetApp_GetDmaHandleInArgs     txInArgs;
    EnetApp_GetDmaHandleInArgs     rxInArgs;


    EnetApp_getEnetInstInfo(&enetType,
                            &instId);

    EnetApp_getEnetInstMacInfo(enetType, instId,
                             macPortList, &numMacPorts);

    EnetApp_acquireHandleInfo(enetType, instId, &handleInfo);
    EnetApp_coreAttach(enetType,instId, coreId, &attachInfo);

    /* Open TX channel */
    txInArgs.cbArg     = inArgs->txCfg.cbArg;
    txInArgs.notifyCb  = inArgs->txCfg.notifyCb;

    EnetApp_getTxDmaHandle(LWIP_ENET_TX_DMA_CH_IDX,
                          &txInArgs,
                          &txChInfo);

    outArgs->txInfo.txChNum  = txChInfo.txChNum;
    outArgs->txInfo.hTxChannel = txChInfo.hTxCh;
    EnetAppUtils_assert(inArgs->txCfg.numPackets <= txChInfo.maxNumTxPkts);

    /* Open RX Flow */
    rxInArgs.notifyCb  = inArgs->rxCfg.notifyCb;
    rxInArgs.cbArg     = inArgs->rxCfg.cbArg;

    EnetApp_getRxDmaHandle(LWIP_ENET_RX_DMA_CH_IDX,
                          &rxInArgs,
                          &rxChInfo);
    EnetAppUtils_assert(inArgs->rxCfg.numPackets <= rxChInfo.maxNumRxPkts);
    outArgs->rxInfo.rxFlowStartIdx = rxChInfo.rxFlowStartIdx;
    outArgs->rxInfo.rxFlowIdx = rxChInfo.rxFlowIdx;
    outArgs->rxInfo.hRxFlow  = rxChInfo.hRxCh;
    EnetAppUtils_assert(rxChInfo.macAddressValid == true);
    EnetUtils_copyMacAddr(outArgs->rxInfo.macAddr, rxChInfo.macAddr);

    outArgs->coreId        = coreId;
    outArgs->coreKey       = attachInfo.coreKey;
    outArgs->hEnet         = handleInfo.hEnet;
    outArgs->hostPortRxMtu = attachInfo.rxMtu;
    ENET_UTILS_ARRAY_COPY(outArgs->txMtu, attachInfo.txMtu);
    outArgs->print           = &EnetAppUtils_print;
    outArgs->isPortLinkedFxn = &EnetApp_isPortLinked;
	outArgs->timerPeriodUs   = ENETLWIP_PACKET_POLL_PERIOD_US;
    outArgs->hUdmaDrv      = handleInfo.hUdmaDrv;
    outArgs->rxInfo.disableEvent = !useRingMon;

    outArgs->txInfo.txPortNum = ENET_MAC_PORT_INV;
    /* Use optimized processing where TX packets are relinquished in next TX submit call */
    outArgs->txInfo.disableEvent = true;

    EnetAppUtils_print("Host MAC address: ");
    EnetAppUtils_printMacAddr(&outArgs->rxInfo.macAddr[0U]);

#if (ENET_ENABLE_PER_ICSSG == 1)
    /* Add port MAC entry in case of ICSSG dual MAC */
    if (ENET_ICSSG_DUALMAC == enetType)
    {
        int32_t status;
        Enet_IoctlPrms prms;
        IcssgMacPort_SetMacAddressInArgs inArgs;

        memset(&inArgs, 0, sizeof(inArgs));
        memcpy(&inArgs.macAddr[0U], &outArgs->rxInfo.macAddr[0U], sizeof(inArgs.macAddr));
        inArgs.macPort = macPortList[0U];

        ENET_IOCTL_SET_IN_ARGS(&prms, &inArgs);
        ENET_IOCTL(handleInfo.hEnet, coreId, ICSSG_MACPORT_IOCTL_SET_MACADDR, &prms, status);
        if (status != ENET_SOK)
        {
            EnetAppUtils_print("EnetAppUtils_addHostPortEntry() failed ICSSG_MACPORT_IOCTL_ADD_INTERFACE_MACADDR: %d\r\n",
                               status);
        }
        EnetAppUtils_assert(status == ENET_SOK);
    }
#endif
}

void LwipifEnetAppCb_releaseHandle(LwipifEnetAppIf_ReleaseHandleInfo *releaseInfo)
{
    EnetDma_PktQ fqPktInfoQ;
    EnetDma_PktQ cqPktInfoQ;
    Enet_Type enetType;
    uint32_t instId;

    EnetApp_getEnetInstInfo(&enetType,
                            &instId);

    /* Close TX channel */
    {
        EnetQueue_initQ(&fqPktInfoQ);
        EnetQueue_initQ(&cqPktInfoQ);
        EnetApp_closeTxDma(LWIP_ENET_TX_DMA_CH_IDX,
                           releaseInfo->hEnet, 
                           releaseInfo->coreKey,
                           releaseInfo->coreId,
                           &fqPktInfoQ,
                           &cqPktInfoQ);
        releaseInfo->txFreePktCb(releaseInfo->txFreePktCbArg, &fqPktInfoQ, &cqPktInfoQ);
    }

    {
        /* Close RX Flow */
        EnetQueue_initQ(&fqPktInfoQ);
        EnetQueue_initQ(&cqPktInfoQ);

        EnetApp_closeRxDma(LWIP_ENET_RX_DMA_CH_IDX,
                        releaseInfo->hEnet, 
                        releaseInfo->coreKey,
                        releaseInfo->coreId,
                        &fqPktInfoQ,
                        &cqPktInfoQ);

        releaseInfo->rxFreePktCb(releaseInfo->rxFreePktCbArg, &fqPktInfoQ, &cqPktInfoQ);
    }

    EnetApp_coreDetach(enetType, instId, releaseInfo->coreId, releaseInfo->coreKey);
    EnetApp_releaseHandleInfo(enetType, instId);
}


