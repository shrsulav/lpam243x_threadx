/*
 *  Copyright (C) 2022 Texas Instruments Incorporated
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

/**
 *  \file   dthe_aes.c
 *
 *  \brief  This file contains the implementation of Dthe aes driver
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <string.h>
#include <security/crypto/dthe/dthe_aes.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

static void DTHE_AESSetDMAContextStatus(CSL_AesRegs *ptrAesRegs, uint8_t dmaStatus);
static void DTHE_AESSetDMAOutputRequestStatus(CSL_AesRegs *ptrAesRegs, uint8_t dmaStatus);
static void DTHE_AESSetDMAInputRequestStatus(CSL_AesRegs *ptrAesRegs, uint8_t dmaStatus);
static void DTHE_AESSetKeySize(CSL_AesRegs *ptrAesRegs, uint8_t size);
static void DTHE_AESSet256BitKey1(CSL_AesRegs *ptrAesRegs, const uint32_t* ptrKey);
static void DTHE_AESDSetIV(CSL_AesRegs *ptrAesRegs, const uint32_t* ptrIV);
static void DTHE_AESPollInputReady(CSL_AesRegs *ptrAesRegs);
static void DTHE_AESWriteDataBlock(CSL_AesRegs *ptrAesRegs, const uint32_t* ptrData);
static void DTHE_AESPollOutputReady(CSL_AesRegs *ptrAesRegs);
static void DTHE_AESReadDataBlock(CSL_AesRegs *ptrAesRegs, uint32_t* ptrData);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t DTHE_AESOpen(DTHE_Handle handle)
{
    uint32_t        status  = SystemP_FAILURE;
    DTHE_Config     *config = NULL;
    DTHE_Attrs      *attrs  = NULL;
    CSL_AesRegs     *ptrAesRegs;

    if(NULL != handle)
    {
        status  = SystemP_SUCCESS;
    }

    if(status  == SystemP_SUCCESS)
    {
        config          = (DTHE_Config *) handle;
        attrs           = config->attrs;
        ptrAesRegs      = (CSL_AesRegs *)attrs->aesBaseAddr;

        /* Enable the secure request access */
        status = DTHE_enableSecureRequest(handle);
    }

    if(status  == SystemP_SUCCESS)
    {
        /* Reset the AES and ensure it is out of reset */
        CSL_REG32_FINS(&ptrAesRegs->SYSCONFIG, AES_S_SYSCONFIG_SOFTRESET, 1U);
        while (CSL_REG32_FEXT(&ptrAesRegs->SYSSTS, AES_S_SYSSTS_RESETDONE) == 0U)
        {
        }

        /* Disable the DMA for the AES */
        DTHE_AESSetDMAContextStatus(ptrAesRegs, 0);
        DTHE_AESSetDMAOutputRequestStatus(ptrAesRegs, 0);
        DTHE_AESSetDMAInputRequestStatus(ptrAesRegs, 0);
    }

    return (status);
}

int32_t DTHE_AESExecute(DTHE_Handle handle, const DTHE_AESParams* ptrParams)
{
    uint32_t        status  = SystemP_FAILURE;
    DTHE_Config     *config = NULL;
    DTHE_Attrs      *attrs  = NULL;
    CSL_AesRegs     *ptrAesRegs;
    uint32_t*       ptrWordInputBuffer;
    uint32_t*       ptrWordOutputBuffer;
    uint8_t*        ptrByteInputBuffer;
    uint32_t        dataLenWords;
    uint32_t        numBlocks;
    uint32_t        numPartialWords;
    uint32_t        partialBlock[4];
    uint32_t        index;
    uint32_t        numBytes = 0U;

    if (NULL != handle)
    {
        status  = SystemP_SUCCESS;
    }
    if (status  == SystemP_SUCCESS)
    {
        config          = (DTHE_Config *) handle;
        attrs           = config->attrs;
        ptrAesRegs      = (CSL_AesRegs *)attrs->aesBaseAddr;

        /* AES-CBC Mode is the only supported operational mode: */
        if(ptrParams->algoType == DTHE_AES_ECB_MODE)
        {
            CSL_REG32_FINS(&ptrAesRegs->CTRL, AES_S_CTRL_MODE,CSL_AES_S_CTRL_MODE_ECB);
        }
        else
        {
            CSL_REG32_FINS(&ptrAesRegs->CTRL, AES_S_CTRL_MODE,CSL_AES_S_CTRL_MODE_CBC);
        }

         /* Key Size setting */
        DTHE_AESSetKeySize(ptrAesRegs, ptrParams->keyLen);

        /* Sanity Check: For Decryption data length always needs to be aligned */
        if (ptrParams->opType == DTHE_AES_DECRYPT)
        {
            if ((ptrParams->dataLenBytes % 4U) != 0U)
            {
                status = SystemP_FAILURE;
            }
        }

        /* Sanity Check: Key Validation */
        if (status == SystemP_SUCCESS)
        {
            /* KEK Mode or Normal Key Mode: */
            if (ptrParams->useKEKMode == TRUE)
            {
                /* KEK Mode: Operational Mode should only be ENCRYPTION */
                if (ptrParams->opType == DTHE_AES_DECRYPT)
                {
                    status = SystemP_FAILURE;
                }
            }
            else
            {
                /* Normal Mode: Key should always be specified */
                if (ptrParams->ptrKey == NULL)
                {
                    status = SystemP_FAILURE;
                }
            }
        }

        /* Sanity Check: We always need the IV to be specified */
        if (status == SystemP_SUCCESS)
        {
            if(ptrParams->algoType == DTHE_AES_CBC_MODE)
            {
                if (ptrParams->ptrIV == NULL)
                {
                    status = SystemP_FAILURE;
                }
            }
        }

        /* Execute the AES Driver: */
        if (status == SystemP_SUCCESS)
        {
            /* Select the key input: */
            if (ptrParams->useKEKMode == TRUE)
            {
                /* KEK Mode: Enable Direct Bus */
                CSL_REG32_FINS(&ptrAesRegs->SYSCONFIG,AES_S_SYSCONFIG_DIRECTBUSEN,1U);

                /* KEK Mode: This is always set to be Encryption */
                CSL_REG32_FINS(&ptrAesRegs->CTRL,AES_S_CTRL_DIRECTION,1U);
            }

            else
            {
                /* Normal Key Mode: */
                CSL_REG32_FINS(&ptrAesRegs->SYSCONFIG,AES_S_SYSCONFIG_DIRECTBUSEN,0U);

                /* Operation Mode: Encryption/Decryption */
                if (ptrParams->opType == DTHE_AES_ENCRYPT)
                {
                    /* Encryption: */
                    CSL_REG32_FINS(&ptrAesRegs->CTRL, AES_S_CTRL_DIRECTION, 1U);
                }
                else
                {
                    /* Decryption: */
                    CSL_REG32_FINS(&ptrAesRegs->CTRL, AES_S_CTRL_DIRECTION, 0U);
                }

                /* Configure the key which is to be used: */
                DTHE_AESSet256BitKey1 (ptrAesRegs, ptrParams->ptrKey);
            }

            /* Configure the Initialization Vector: */
            if (ptrParams->algoType == DTHE_AES_CBC_MODE)
            {
                DTHE_AESDSetIV (ptrAesRegs, ptrParams->ptrIV);
            }

            /* Setup the data length: */
            CSL_REG32_FINS(&ptrAesRegs->C_LENGTH_0, AES_S_C_LENGTH_0_LENGTH, ptrParams->dataLenBytes);

            /* Setup the input & output: */
            if (ptrParams->opType == DTHE_AES_ENCRYPT)
            {
                /* Encryption: Plain Text is the Input & Encrypted Data is the Output */
                ptrWordInputBuffer  = &ptrParams->ptrPlainTextData[0];
                ptrWordOutputBuffer = &ptrParams->ptrEncryptedData[0];
                ptrByteInputBuffer  = (uint8_t*)&ptrParams->ptrPlainTextData[0];
            }
            else
            {
                /* Decryption: Encrypted Data is the Input & Plain Text is the Output */
                ptrWordInputBuffer  = &ptrParams->ptrEncryptedData[0];
                ptrWordOutputBuffer = &ptrParams->ptrPlainTextData[0];
                ptrByteInputBuffer  = (uint8_t*)&ptrParams->ptrEncryptedData[0];
            }

            /* Determine the data length in words: */
            dataLenWords = ptrParams->dataLenBytes / 4U;

            /* Compute the number of full blocks which can be written: Each block is 4words long*/
            numBlocks = (dataLenWords / 4U);

            /* Compute the number of partial words which need to be handled seperately */
            numPartialWords = dataLenWords % 4U;

            /* Cycle through and write all the full blocks: */
            for (index = 0U; index < numBlocks; index++)
            {
                /* Wait for the AES IP to be ready to receive the data: */
                DTHE_AESPollInputReady(ptrAesRegs);

                /* Write the data: */
                DTHE_AESWriteDataBlock(ptrAesRegs, &ptrWordInputBuffer[index << 2U]);

                /* Wait for the AES IP to be ready with the output data */
                DTHE_AESPollOutputReady(ptrAesRegs);

                /* Read the decrypted data into the decrypted block: */
                DTHE_AESReadDataBlock(ptrAesRegs, &ptrWordOutputBuffer[index << 2U]);

                /* Compute the number of bytes which have been processed: */
                numBytes = numBytes + (4U * sizeof(uint32_t));
            }

            /* Process any left over data: */
            if (numPartialWords != 0U)
            {
                /* Initialize the partial block: */
                (void)memset ((void *)&partialBlock, 0, sizeof(partialBlock));

                /* Copy the data into the partial block: */
                (void)memcpy ((void *)&partialBlock,
                        (void *)&ptrWordInputBuffer[index << 2U],
                        (numPartialWords * sizeof(uint32_t)));

                /* Wait for the AES IP to be ready to receive the data: */
                DTHE_AESPollInputReady(ptrAesRegs);

                /* Write the data: */
                DTHE_AESWriteDataBlock(ptrAesRegs, &ptrWordInputBuffer[index << 2U]);

                /* Wait for the AES IP to be ready with the output data */
                DTHE_AESPollOutputReady(ptrAesRegs);

                /* Read the decrypted data into the decrypted block: */
                DTHE_AESReadDataBlock(ptrAesRegs, &ptrWordOutputBuffer[index << 2U]);

                /* Compute the number of bytes which have been processed: */
                numBytes = numBytes + (numPartialWords * sizeof(uint32_t));
            }

            /* Do we have any additional bytes which need to be accounted for? */
            if (numBytes != ptrParams->dataLenBytes)
            {
                /* Initialize the partial block: */
                (void)memset ((void *)&partialBlock, 0, sizeof(partialBlock));

                /* Copy the data into the partial block: */
                (void)memcpy ((void *)&partialBlock,
                        (void *)&ptrByteInputBuffer[numBytes],
                        (ptrParams->dataLenBytes - numBytes));

                /* Wait for the AES IP to be ready to receive the data: */
                DTHE_AESPollInputReady(ptrAesRegs);

                /* Write the data: */
                DTHE_AESWriteDataBlock(ptrAesRegs, &ptrWordInputBuffer[index << 2U]);

                /* Wait for the AES IP to be ready with the output data */
                DTHE_AESPollOutputReady(ptrAesRegs);

                /* Read the decrypted data into the decrypted block: */
                DTHE_AESReadDataBlock(ptrAesRegs, &ptrWordOutputBuffer[index << 2U]);
            }
        }
    }
    return (status);
}

int32_t DTHE_AESClose(DTHE_Handle handle)
{
    uint32_t        status  = SystemP_FAILURE;
    DTHE_Config     *config = NULL;
    DTHE_Attrs      *attrs  = NULL;
    CSL_AesRegs     *ptrAesRegs;

    if(NULL != handle)
    {
        status  = SystemP_SUCCESS;
    }
    if(status  == SystemP_SUCCESS)
    {
        config          = (DTHE_Config *) handle;
        attrs           = config->attrs;
        ptrAesRegs      = (CSL_AesRegs *)attrs->aesBaseAddr;

        status = DTHE_disableSecureRequest(handle);
        if(status  == SystemP_SUCCESS)
        {
            /* Reset the AES IP Block */
            CSL_REG32_FINS(&ptrAesRegs->SYSCONFIG, AES_S_SYSCONFIG_SOFTRESET, 1U);
            while (CSL_REG32_FEXT(&ptrAesRegs->SYSSTS, AES_S_SYSSTS_RESETDONE) == 0U)
            {
            }
        }
    }
    return (status);
}

/* ========================================================================== */
/*                 Internal Function Definations                              */
/* ========================================================================== */
/**
 * \brief                   The function is used to set the DMA context (input and output) status of the AES module.
 *
 * \param   ptrAesRegs      Pointer to the EIP38T AES Registers
 *
 * \param   dmaStatus       Flag which is used to enable(1)/disable(0) the DMA status.
 *
 * \return                  None
 */
static void DTHE_AESSetDMAContextStatus(CSL_AesRegs *ptrAesRegs, uint8_t dmaStatus)
{
    if (dmaStatus == 1U)
    {
        CSL_REG32_FINS(&ptrAesRegs->SYSCONFIG, AES_S_SYSCONFIG_DMA_REQ_CONTEXT_OUT_EN, 1U);
        CSL_REG32_FINS(&ptrAesRegs->SYSCONFIG, AES_S_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN, 1U);
    }
    else
    {
        CSL_REG32_FINS(&ptrAesRegs->SYSCONFIG, AES_S_SYSCONFIG_DMA_REQ_CONTEXT_OUT_EN, 0U);
        CSL_REG32_FINS(&ptrAesRegs->SYSCONFIG, AES_S_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN, 0U);
    }

    return;
}

/**
 * \brief                   The function is used to set the DMA Output request status
 *
 * \param   ptrAesRegs      Pointer to the EIP38T AES Registers
 *
 * \param   dmaStatus       Flag which is used to enable(1)/disable(0) the DMA status.
 *
 * \return                  None
 */
static void DTHE_AESSetDMAOutputRequestStatus(CSL_AesRegs *ptrAesRegs, uint8_t dmaStatus)
{
    if (dmaStatus == 1U)
    {
        CSL_REG32_FINS(&ptrAesRegs->SYSCONFIG,AES_S_SYSCONFIG_DMA_REQ_DATA_OUT_EN, 1U);
    }
    else
    {
        CSL_REG32_FINS(&ptrAesRegs->SYSCONFIG,AES_S_SYSCONFIG_DMA_REQ_DATA_OUT_EN, 0U);
    }

    return;
}

/**
 * \brief                   The function is used to set the DMA Input request status
 *
 * \param   ptrAesRegs      Pointer to the EIP38T AES Registers
 *
 * \param   dmaStatus       Flag which is used to enable(1)/disable(0) the DMA status.
 *
 * \return                  None
 */
static void DTHE_AESSetDMAInputRequestStatus(CSL_AesRegs *ptrAesRegs, uint8_t dmaStatus)
{
    if (dmaStatus == 1U)
    {
        CSL_REG32_FINS(&ptrAesRegs->SYSCONFIG,AES_S_SYSCONFIG_DMA_REQ_DATA_IN_EN, 1U);
    }
    else
    {
        CSL_REG32_FINS(&ptrAesRegs->SYSCONFIG,AES_S_SYSCONFIG_DMA_REQ_DATA_IN_EN, 0U);
    }

    return;
}

/**
 * \brief                   The function is used to set the key size
 *
 * \param   ptrAesRegs      Pointer to the EIP38T AES Registers
 *
 * \param   size            Size of the key to be configured.
 *
 * \return                  None
 */
static void DTHE_AESSetKeySize(CSL_AesRegs *ptrAesRegs, uint8_t size)
{
    uint8_t keySize;

    if (size == CSL_AES_S_CTRL_KEY_SIZE_KEY128)
    {
        keySize = 1U;
    }
    else if (size == CSL_AES_S_CTRL_KEY_SIZE_KEY192)
    {
        keySize = 2U;
    }
    else
    {
        keySize = 3U;
    }
    CSL_REG32_FINS(&ptrAesRegs->CTRL,AES_S_CTRL_KEY_SIZE, keySize);

    return;
}

/**
 * \brief                   The function is used to configure the key in the AES module This will only configure the 256bit keys.
 *
 * \param   ptrAesRegs      Pointer to the EIP38T AES Registers
 *
 * \param   ptrKey          Pointer to the 256bit key to be used.
 *
 * \return                  None
 */
static void DTHE_AESSet256BitKey1(CSL_AesRegs *ptrAesRegs, const uint32_t* ptrKey)
{
    ptrAesRegs->KEY1_0 = ptrKey[0U];
    ptrAesRegs->KEY1_1 = ptrKey[1U];
    ptrAesRegs->KEY1_2 = ptrKey[2U];
    ptrAesRegs->KEY1_3 = ptrKey[3U];
    ptrAesRegs->KEY1_4 = ptrKey[4U];
    ptrAesRegs->KEY1_5 = ptrKey[5U];
    ptrAesRegs->KEY1_6 = ptrKey[6U];
    ptrAesRegs->KEY1_7 = ptrKey[7U];

    return;
}

/**
 * \brief                   The function is used to set the Initialization Vector (IV) in the AES module.
 *
 * \param   ptrAesRegs      Pointer to the EIP38T AES Registers.
 *
 * \param   ptrIV           Pointer to the IV data to be used.
 *
 * \return                  None
 */
static void DTHE_AESDSetIV(CSL_AesRegs *ptrAesRegs, const uint32_t* ptrIV)
{
    ptrAesRegs->IV_IN_0 = ptrIV[0U];
    ptrAesRegs->IV_IN_1 = ptrIV[1U];
    ptrAesRegs->IV_IN_2 = ptrIV[2U];
    ptrAesRegs->IV_IN_3 = ptrIV[3U];

    return;
}

/**
 * \brief                   The function is used to poll until the AES IP block is ready to receive data.
 *
 * \param   ptrAesRegs      Pointer to the EIP38T AES Registers
 *
 * \return                  None
 */
static void DTHE_AESPollInputReady(CSL_AesRegs *ptrAesRegs)
{
    uint8_t     done = 0U;

    /* Loop around till the condition is met: */
    while (done == 0U)
    {
        done = CSL_REG32_FEXT(&ptrAesRegs->CTRL, AES_S_CTRL_INPUT_READY);
    }
    return;
}

/**
 * \brief                   The function is used to write the data and pass this to the AES engine.
 *
 * \param   ptrAesRegs      Pointer to the EIP38T AES Registers.
 *
 * \param   ptrData         Pointer to the data to be written.
 *
 * \return                  None
 */
static void DTHE_AESWriteDataBlock(CSL_AesRegs *ptrAesRegs, const uint32_t* ptrData)
{
    ptrAesRegs->DATA_IN_3 = ptrData[0U];
    ptrAesRegs->DATA_IN_2 = ptrData[1U];
    ptrAesRegs->DATA_IN_1 = ptrData[2U];
    ptrAesRegs->DATA_IN_0 = ptrData[3U];

    return;
}

/**
 * \brief                   The function is used to poll until the AES IP block has available data which can be read out.
 *
 * \param   ptrAesRegs      Pointer to the EIP38T AES Registers
 *
 * \return                  None
 */
static void DTHE_AESPollOutputReady(CSL_AesRegs *ptrAesRegs)
{
    uint8_t     done = 0U;

    /* Loop around till the condition is met: */
    while (done == 0U)
    {
        done = CSL_REG32_FEXT(&ptrAesRegs->CTRL, AES_S_CTRL_OUTPUT_READY);
    }
    return;
}

/**
 * \brief                   The function is used to read the data from the AES engine
 *
 * \param   ptrAesRegs      Pointer to the EIP38T AES Registers
 *
 * \param   ptrData         Pointer to the data buffer populated by the API
 *
 * \return                  None
 */
static void DTHE_AESReadDataBlock(CSL_AesRegs *ptrAesRegs, uint32_t* ptrData)
{
    ptrData[0] = ptrAesRegs->DATA_IN_3;
    ptrData[1] = ptrAesRegs->DATA_IN_2;
    ptrData[2] = ptrAesRegs->DATA_IN_1;
    ptrData[3] = ptrAesRegs->DATA_IN_0;

    return;
}