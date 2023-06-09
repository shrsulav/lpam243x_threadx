/*
 *  Copyright (c) Texas Instruments Incorporated 2020
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * \file  enet_udma_types.h
 *
 * \brief This file contains the base DMA definitions.
 */

/*!
 * \addtogroup ENET_DMA_API
 * @{
 */

#ifndef ENET_UDMA_TYPES_H_
#define ENET_UDMA_TYPES_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* Forward declarations */
struct EnetUdma_DrvObj_s;
struct EnetUdma_RxFlowObj_s;
struct EnetUdma_RxFlowObj_s;
struct EnetUdma_TxChObj_s;
struct EnetUdma_PktInfo_s;

/*!
 *  \name Enet DMA driver opaque handles
 *
 *  Opaque handle typedefs for Enet DMA driver objects.
 *  @{
 */

/*!
 * \brief Opaque handle for Enet UDMA driver object.
 *
 * Opaque structure to hold software state for the Enet UDMA module.
 */
typedef struct EnetUdma_DrvObj_s *EnetDma_Handle;

/*!
 * \brief Opaque handle that holds software state for Enet RX DMA flow.
 *
 * Note - Even though the typedef is EnetDma_RxChHandle, it is actually flow handle.
 *        CPSW and ICSSG has single RX channel with multiple flows with apps using
 *        flow to get data from host port.
 */
typedef struct EnetUdma_RxFlowObj_s *EnetDma_RxChHandle;

/*!
 * \brief Opaque handle that holds software state for Enet TX DMA channel.
 */
typedef struct EnetUdma_TxChObj_s *EnetDma_TxChHandle;

/*!
 * \brief Opaque handle that represents a DMA packet.
 */
typedef struct EnetUdma_PktInfo_s EnetDma_Pkt;

/*! @} */

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                        Deprecated Function Declarations                    */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                       Static Function Definitions                          */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif

#endif /* ENET_UDMA_TYPES_H_ */

/*! @} */
