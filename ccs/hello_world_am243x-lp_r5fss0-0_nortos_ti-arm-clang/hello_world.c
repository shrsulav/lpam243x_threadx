/*
 *  Copyright (C) 2018-2021 Texas Instruments Incorporated
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


#include <stdio.h>
#include <kernel/dpl/DebugP.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"

#include "tx_api.h"
#include "tx_port.h"

TX_BYTE_POOL byte_pool_0;
TX_SEMAPHORE semaphore_0, semaphore_1;
TX_THREAD my_thread, my_thread_2;

void hello_world_main(void *args)
{
    /* Open drivers to open the UART driver for console */
    Drivers_open();
    Board_driversOpen();

    DebugP_log("Initializing ThreadX Kernel!\r\n");

    tx_kernel_enter();

    DebugP_log("Exited ThreadX Kernel!\r\n");

    Board_driversClose();
    Drivers_close();
}

void my_thread_entry(ULONG thread_input)
{
    UINT status;
    UINT thread_counter = 0;
    /* Enter into a forever loop. */
    while(1)
    {
        /* Get the semaphore with suspension. */
        status = tx_semaphore_get(&semaphore_0, TX_WAIT_FOREVER);

        /* Check status. */
        if (status != TX_SUCCESS) break;

        /* Increment thread counter. */
        thread_counter++;

        DebugP_log("\r\nThread 1 Count: %d", thread_counter);

        /* Release the semaphore. */
        status = tx_semaphore_put(&semaphore_1);

        /* Check status. */
        if (status != TX_SUCCESS) break;
    }
}

void my_thread_entry_2(ULONG thread_input)
{
    UINT status;
    UINT thread_counter = 0;
    /* Enter into a forever loop. */
    while(1)
    {
        /* Get the semaphore with suspension. */
        status = tx_semaphore_get(&semaphore_1, TX_WAIT_FOREVER);

        /* Check status. */
        if (status != TX_SUCCESS) break;

        /* Increment thread counter. */
        thread_counter++;

        DebugP_log("\r\nThread 2 Count: %d", thread_counter);

        /* Release the semaphore. */
        status = tx_semaphore_put(&semaphore_0);

        /* Check status. */
        if (status != TX_SUCCESS) break;
    }
}

void tx_application_define(void *first_unused_memory)
{
    CHAR *pointer;

    /* Create a byte memory pool from which to allocate the thread stacks. */
    tx_byte_pool_create(&byte_pool_0, "byte pool 0", first_unused_memory, 8192);

    /* Allocate the stack for thread 0. */
    tx_byte_allocate(&byte_pool_0, &pointer, 1024, TX_NO_WAIT);

    /* Create my_thread! */
    tx_thread_create(&my_thread, "My Thread",
                     my_thread_entry, 0x1234, pointer, 1024,
                     3, 3, TX_NO_TIME_SLICE, TX_AUTO_START);

    /* Allocate the stack for thread 1. */
    tx_byte_allocate(&byte_pool_0, &pointer, 1024, TX_NO_WAIT);

    /* Create my_thread! */
    tx_thread_create(&my_thread_2, "My Thread 2",
                     my_thread_entry_2, 0x1234, pointer, 1024,
                     3, 3, TX_NO_TIME_SLICE, TX_AUTO_START);

    /* Create the semaphore. */
    tx_semaphore_create(&semaphore_0, "semaphore 0", 1);

    /* Create the semaphore. */
    tx_semaphore_create(&semaphore_1, "semaphore 1", 0);

}
