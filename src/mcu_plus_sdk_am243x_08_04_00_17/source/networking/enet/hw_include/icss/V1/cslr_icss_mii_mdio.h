/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
 *
*/
#ifndef CSLR_ICSSMIIMDIO_H
#define CSLR_ICSSMIIMDIO_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <drivers/hw_include/cslr.h>
#include <drivers/hw_include/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 VER;
    volatile Uint32 CONTROL;
    volatile Uint32 ALIVE;
    volatile Uint32 LINK;
    volatile Uint32 LINKINTRAW;
    volatile Uint32 LINKINTMASKED;
    volatile Uint8  RSVD0[8];
    volatile Uint32 USERINTRAW;
    volatile Uint32 USERINTMASKED;
    volatile Uint32 USERINTMASKSET;
    volatile Uint32 USERINTMASKCLR;
    volatile Uint8  RSVD1[80];
    volatile Uint32 USERACCESS0;
    volatile Uint32 USERPHYSEL0;
    volatile Uint32 USERACCESS1;
    volatile Uint32 USERPHYSEL1;
    volatile Uint8  RSVD2[420];
} CSL_IcssMiiMdioRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* MODULE VERSION REGISTER */
#define CSL_ICSSMIIMDIO_VER                                     (0x0U)

/* MODULE CONTROL REGISTER */
#define CSL_ICSSMIIMDIO_CONTROL                                 (0x4U)

/* PHY ACKNOWLEDGE STATUS REGISTER */
#define CSL_ICSSMIIMDIO_ALIVE                                   (0x8U)

/* PHY LINK STATUS REGISTER */
#define CSL_ICSSMIIMDIO_LINK                                    (0xCU)

/* LINK STATUS CHANGE INTERRUPT REGISTER (RAW VALUE) */
#define CSL_ICSSMIIMDIO_LINKINTRAW                              (0x10U)

/* LINK STATUS CHANGE INTERRUPT REGISTER (MASKED VALUE) */
#define CSL_ICSSMIIMDIO_LINKINTMASKED                           (0x14U)

/* USER COMMAND COMPLETE INTERRUPT REGISTER (RAW VALUE) */
#define CSL_ICSSMIIMDIO_USERINTRAW                              (0x20U)

/* USER COMMAND COMPLETE INTERRUPT REGISTER (MASKED VALUE) */
#define CSL_ICSSMIIMDIO_USERINTMASKED                           (0x24U)

/* USER INTERRUPT MASK SET REGISTER */
#define CSL_ICSSMIIMDIO_USERINTMASKSET                          (0x28U)

/* USER INTERRUPT MASK CLEAR REGISTER */
#define CSL_ICSSMIIMDIO_USERINTMASKCLR                          (0x2CU)

/* USER ACCESS REGISTER0 */
#define CSL_ICSSMIIMDIO_USERACCESS0                             (0x80U)

/* USER PHY SELECT REGISTER0 */
#define CSL_ICSSMIIMDIO_USERPHYSEL0                             (0x84U)

/* USER ACCESS REGISTER1 */
#define CSL_ICSSMIIMDIO_USERACCESS1                             (0x88U)

/* USER PHY SELECT REGISTER1 */
#define CSL_ICSSMIIMDIO_USERPHYSEL1                             (0x8CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* VER */

#define CSL_ICSSMIIMDIO_VER_REVMIN_MASK                         (0x000000FFU)
#define CSL_ICSSMIIMDIO_VER_REVMIN_SHIFT                        (0U)
#define CSL_ICSSMIIMDIO_VER_REVMIN_RESETVAL                     (0x00000005U)
#define CSL_ICSSMIIMDIO_VER_REVMIN_MAX                          (0x000000ffU)

#define CSL_ICSSMIIMDIO_VER_REVMAJ_MASK                         (0x0000FF00U)
#define CSL_ICSSMIIMDIO_VER_REVMAJ_SHIFT                        (8U)
#define CSL_ICSSMIIMDIO_VER_REVMAJ_RESETVAL                     (0x00000001U)
#define CSL_ICSSMIIMDIO_VER_REVMAJ_MAX                          (0x000000ffU)

#define CSL_ICSSMIIMDIO_VER_MODID_MASK                          (0xFFFF0000U)
#define CSL_ICSSMIIMDIO_VER_MODID_SHIFT                         (16U)
#define CSL_ICSSMIIMDIO_VER_MODID_RESETVAL                      (0x00000007U)
#define CSL_ICSSMIIMDIO_VER_MODID_MAX                           (0x0000ffffU)

#define CSL_ICSSMIIMDIO_VER_RESETVAL                            (0x00070105U)

/* CONTROL */

#define CSL_ICSSMIIMDIO_CONTROL_CLKDIV_MASK                     (0x0000FFFFU)
#define CSL_ICSSMIIMDIO_CONTROL_CLKDIV_SHIFT                    (0U)
#define CSL_ICSSMIIMDIO_CONTROL_CLKDIV_RESETVAL                 (0x000000ffU)
#define CSL_ICSSMIIMDIO_CONTROL_CLKDIV_MAX                      (0x0000ffffU)

#define CSL_ICSSMIIMDIO_CONTROL_INT_TEST_ENABLE_MASK            (0x00020000U)
#define CSL_ICSSMIIMDIO_CONTROL_INT_TEST_ENABLE_SHIFT           (17U)
#define CSL_ICSSMIIMDIO_CONTROL_INT_TEST_ENABLE_RESETVAL        (0x00000000U)
#define CSL_ICSSMIIMDIO_CONTROL_INT_TEST_ENABLE_MAX             (0x00000001U)

#define CSL_ICSSMIIMDIO_CONTROL_FAULT_DETECT_ENABLE_MASK        (0x00040000U)
#define CSL_ICSSMIIMDIO_CONTROL_FAULT_DETECT_ENABLE_SHIFT       (18U)
#define CSL_ICSSMIIMDIO_CONTROL_FAULT_DETECT_ENABLE_RESETVAL    (0x00000000U)
#define CSL_ICSSMIIMDIO_CONTROL_FAULT_DETECT_ENABLE_MAX         (0x00000001U)

#define CSL_ICSSMIIMDIO_CONTROL_FAULT_MASK                      (0x00080000U)
#define CSL_ICSSMIIMDIO_CONTROL_FAULT_SHIFT                     (19U)
#define CSL_ICSSMIIMDIO_CONTROL_FAULT_RESETVAL                  (0x00000000U)
#define CSL_ICSSMIIMDIO_CONTROL_FAULT_MAX                       (0x00000001U)

#define CSL_ICSSMIIMDIO_CONTROL_PREAMBLE_MASK                   (0x00100000U)
#define CSL_ICSSMIIMDIO_CONTROL_PREAMBLE_SHIFT                  (20U)
#define CSL_ICSSMIIMDIO_CONTROL_PREAMBLE_RESETVAL               (0x00000000U)
#define CSL_ICSSMIIMDIO_CONTROL_PREAMBLE_MAX                    (0x00000001U)

#define CSL_ICSSMIIMDIO_CONTROL_HIGHEST_USER_CHANNEL_MASK       (0x1F000000U)
#define CSL_ICSSMIIMDIO_CONTROL_HIGHEST_USER_CHANNEL_SHIFT      (24U)
#define CSL_ICSSMIIMDIO_CONTROL_HIGHEST_USER_CHANNEL_RESETVAL   (0x00000001U)
#define CSL_ICSSMIIMDIO_CONTROL_HIGHEST_USER_CHANNEL_MAX        (0x0000001fU)

#define CSL_ICSSMIIMDIO_CONTROL_ENABLE_MASK                     (0x40000000U)
#define CSL_ICSSMIIMDIO_CONTROL_ENABLE_SHIFT                    (30U)
#define CSL_ICSSMIIMDIO_CONTROL_ENABLE_RESETVAL                 (0x00000000U)
#define CSL_ICSSMIIMDIO_CONTROL_ENABLE_MAX                      (0x00000001U)

#define CSL_ICSSMIIMDIO_CONTROL_IDLE_MASK                       (0x80000000U)
#define CSL_ICSSMIIMDIO_CONTROL_IDLE_SHIFT                      (31U)
#define CSL_ICSSMIIMDIO_CONTROL_IDLE_RESETVAL                   (0x00000001U)
#define CSL_ICSSMIIMDIO_CONTROL_IDLE_MAX                        (0x00000001U)

#define CSL_ICSSMIIMDIO_CONTROL_RESETVAL                        (0x810000ffU)

/* ALIVE */

#define CSL_ICSSMIIMDIO_ALIVE_ALIVE_MASK                        (0xFFFFFFFFU)
#define CSL_ICSSMIIMDIO_ALIVE_ALIVE_SHIFT                       (0U)
#define CSL_ICSSMIIMDIO_ALIVE_ALIVE_RESETVAL                    (0x00000000U)
#define CSL_ICSSMIIMDIO_ALIVE_ALIVE_MAX                         (0xffffffffU)

#define CSL_ICSSMIIMDIO_ALIVE_RESETVAL                          (0x00000000U)

/* LINK */

#define CSL_ICSSMIIMDIO_LINK_LINK_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSMIIMDIO_LINK_LINK_SHIFT                         (0U)
#define CSL_ICSSMIIMDIO_LINK_LINK_RESETVAL                      (0x00000000U)
#define CSL_ICSSMIIMDIO_LINK_LINK_MAX                           (0xffffffffU)

#define CSL_ICSSMIIMDIO_LINK_RESETVAL                           (0x00000000U)

/* LINKINTRAW */

#define CSL_ICSSMIIMDIO_LINKINTRAW_LINKINTRAW_MASK              (0x00000003U)
#define CSL_ICSSMIIMDIO_LINKINTRAW_LINKINTRAW_SHIFT             (0U)
#define CSL_ICSSMIIMDIO_LINKINTRAW_LINKINTRAW_RESETVAL          (0x00000000U)
#define CSL_ICSSMIIMDIO_LINKINTRAW_LINKINTRAW_MAX               (0x00000003U)

#define CSL_ICSSMIIMDIO_LINKINTRAW_RESETVAL                     (0x00000000U)

/* LINKINTMASKED */

#define CSL_ICSSMIIMDIO_LINKINTMASKED_LINKINTMASKED_MASK        (0x00000003U)
#define CSL_ICSSMIIMDIO_LINKINTMASKED_LINKINTMASKED_SHIFT       (0U)
#define CSL_ICSSMIIMDIO_LINKINTMASKED_LINKINTMASKED_RESETVAL    (0x00000000U)
#define CSL_ICSSMIIMDIO_LINKINTMASKED_LINKINTMASKED_MAX         (0x00000003U)

#define CSL_ICSSMIIMDIO_LINKINTMASKED_RESETVAL                  (0x00000000U)

/* USERINTRAW */

#define CSL_ICSSMIIMDIO_USERINTRAW_USERINTRAW_MASK              (0x00000003U)
#define CSL_ICSSMIIMDIO_USERINTRAW_USERINTRAW_SHIFT             (0U)
#define CSL_ICSSMIIMDIO_USERINTRAW_USERINTRAW_RESETVAL          (0x00000000U)
#define CSL_ICSSMIIMDIO_USERINTRAW_USERINTRAW_MAX               (0x00000003U)

#define CSL_ICSSMIIMDIO_USERINTRAW_RESETVAL                     (0x00000000U)

/* USERINTMASKED */

#define CSL_ICSSMIIMDIO_USERINTMASKED_USERINTMASKED_MASK        (0x00000003U)
#define CSL_ICSSMIIMDIO_USERINTMASKED_USERINTMASKED_SHIFT       (0U)
#define CSL_ICSSMIIMDIO_USERINTMASKED_USERINTMASKED_RESETVAL    (0x00000000U)
#define CSL_ICSSMIIMDIO_USERINTMASKED_USERINTMASKED_MAX         (0x00000003U)

#define CSL_ICSSMIIMDIO_USERINTMASKED_RESETVAL                  (0x00000000U)

/* USERINTMASKSET */

#define CSL_ICSSMIIMDIO_USERINTMASKSET_USERINTMASKEDSET_MASK    (0x00000003U)
#define CSL_ICSSMIIMDIO_USERINTMASKSET_USERINTMASKEDSET_SHIFT   (0U)
#define CSL_ICSSMIIMDIO_USERINTMASKSET_USERINTMASKEDSET_RESETVAL  (0x00000000U)
#define CSL_ICSSMIIMDIO_USERINTMASKSET_USERINTMASKEDSET_MAX     (0x00000003U)

#define CSL_ICSSMIIMDIO_USERINTMASKSET_RESETVAL                 (0x00000000U)

/* USERINTMASKCLR */

#define CSL_ICSSMIIMDIO_USERINTMASKCLR_USERINTMASKEDCLR_MASK    (0x00000003U)
#define CSL_ICSSMIIMDIO_USERINTMASKCLR_USERINTMASKEDCLR_SHIFT   (0U)
#define CSL_ICSSMIIMDIO_USERINTMASKCLR_USERINTMASKEDCLR_RESETVAL  (0x00000000U)
#define CSL_ICSSMIIMDIO_USERINTMASKCLR_USERINTMASKEDCLR_MAX     (0x00000003U)

#define CSL_ICSSMIIMDIO_USERINTMASKCLR_RESETVAL                 (0x00000000U)

/* USERACCESS0 */

#define CSL_ICSSMIIMDIO_USERACCESS0_DATA_MASK                   (0x0000FFFFU)
#define CSL_ICSSMIIMDIO_USERACCESS0_DATA_SHIFT                  (0U)
#define CSL_ICSSMIIMDIO_USERACCESS0_DATA_RESETVAL               (0x00000000U)
#define CSL_ICSSMIIMDIO_USERACCESS0_DATA_MAX                    (0x0000ffffU)

#define CSL_ICSSMIIMDIO_USERACCESS0_PHYADR_MASK                 (0x001F0000U)
#define CSL_ICSSMIIMDIO_USERACCESS0_PHYADR_SHIFT                (16U)
#define CSL_ICSSMIIMDIO_USERACCESS0_PHYADR_RESETVAL             (0x00000000U)
#define CSL_ICSSMIIMDIO_USERACCESS0_PHYADR_MAX                  (0x0000001fU)

#define CSL_ICSSMIIMDIO_USERACCESS0_REGADR_MASK                 (0x03E00000U)
#define CSL_ICSSMIIMDIO_USERACCESS0_REGADR_SHIFT                (21U)
#define CSL_ICSSMIIMDIO_USERACCESS0_REGADR_RESETVAL             (0x00000000U)
#define CSL_ICSSMIIMDIO_USERACCESS0_REGADR_MAX                  (0x0000001fU)

#define CSL_ICSSMIIMDIO_USERACCESS0_ACK_MASK                    (0x20000000U)
#define CSL_ICSSMIIMDIO_USERACCESS0_ACK_SHIFT                   (29U)
#define CSL_ICSSMIIMDIO_USERACCESS0_ACK_RESETVAL                (0x00000000U)
#define CSL_ICSSMIIMDIO_USERACCESS0_ACK_MAX                     (0x00000001U)

#define CSL_ICSSMIIMDIO_USERACCESS0_WRITE_MASK                  (0x40000000U)
#define CSL_ICSSMIIMDIO_USERACCESS0_WRITE_SHIFT                 (30U)
#define CSL_ICSSMIIMDIO_USERACCESS0_WRITE_RESETVAL              (0x00000000U)
#define CSL_ICSSMIIMDIO_USERACCESS0_WRITE_MAX                   (0x00000001U)

#define CSL_ICSSMIIMDIO_USERACCESS0_GO_MASK                     (0x80000000U)
#define CSL_ICSSMIIMDIO_USERACCESS0_GO_SHIFT                    (31U)
#define CSL_ICSSMIIMDIO_USERACCESS0_GO_RESETVAL                 (0x00000000U)
#define CSL_ICSSMIIMDIO_USERACCESS0_GO_MAX                      (0x00000001U)

#define CSL_ICSSMIIMDIO_USERACCESS0_RESETVAL                    (0x00000000U)

/* USERPHYSEL0 */

#define CSL_ICSSMIIMDIO_USERPHYSEL0_PHYADR_MON_MASK             (0x0000001FU)
#define CSL_ICSSMIIMDIO_USERPHYSEL0_PHYADR_MON_SHIFT            (0U)
#define CSL_ICSSMIIMDIO_USERPHYSEL0_PHYADR_MON_RESETVAL         (0x00000000U)
#define CSL_ICSSMIIMDIO_USERPHYSEL0_PHYADR_MON_MAX              (0x0000001fU)

#define CSL_ICSSMIIMDIO_USERPHYSEL0_LINKINT_ENABLE_MASK         (0x00000040U)
#define CSL_ICSSMIIMDIO_USERPHYSEL0_LINKINT_ENABLE_SHIFT        (6U)
#define CSL_ICSSMIIMDIO_USERPHYSEL0_LINKINT_ENABLE_RESETVAL     (0x00000000U)
#define CSL_ICSSMIIMDIO_USERPHYSEL0_LINKINT_ENABLE_MAX          (0x00000001U)

#define CSL_ICSSMIIMDIO_USERPHYSEL0_LINKSEL_MASK                (0x00000080U)
#define CSL_ICSSMIIMDIO_USERPHYSEL0_LINKSEL_SHIFT               (7U)
#define CSL_ICSSMIIMDIO_USERPHYSEL0_LINKSEL_RESETVAL            (0x00000000U)
#define CSL_ICSSMIIMDIO_USERPHYSEL0_LINKSEL_MAX                 (0x00000001U)

#define CSL_ICSSMIIMDIO_USERPHYSEL0_RESETVAL                    (0x00000000U)

/* USERACCESS1 */

#define CSL_ICSSMIIMDIO_USERACCESS1_DATA_MASK                   (0x0000FFFFU)
#define CSL_ICSSMIIMDIO_USERACCESS1_DATA_SHIFT                  (0U)
#define CSL_ICSSMIIMDIO_USERACCESS1_DATA_RESETVAL               (0x00000000U)
#define CSL_ICSSMIIMDIO_USERACCESS1_DATA_MAX                    (0x0000ffffU)

#define CSL_ICSSMIIMDIO_USERACCESS1_PHYADR_MASK                 (0x001F0000U)
#define CSL_ICSSMIIMDIO_USERACCESS1_PHYADR_SHIFT                (16U)
#define CSL_ICSSMIIMDIO_USERACCESS1_PHYADR_RESETVAL             (0x00000000U)
#define CSL_ICSSMIIMDIO_USERACCESS1_PHYADR_MAX                  (0x0000001fU)

#define CSL_ICSSMIIMDIO_USERACCESS1_REGADR_MASK                 (0x03E00000U)
#define CSL_ICSSMIIMDIO_USERACCESS1_REGADR_SHIFT                (21U)
#define CSL_ICSSMIIMDIO_USERACCESS1_REGADR_RESETVAL             (0x00000000U)
#define CSL_ICSSMIIMDIO_USERACCESS1_REGADR_MAX                  (0x0000001fU)

#define CSL_ICSSMIIMDIO_USERACCESS1_ACK_MASK                    (0x20000000U)
#define CSL_ICSSMIIMDIO_USERACCESS1_ACK_SHIFT                   (29U)
#define CSL_ICSSMIIMDIO_USERACCESS1_ACK_RESETVAL                (0x00000000U)
#define CSL_ICSSMIIMDIO_USERACCESS1_ACK_MAX                     (0x00000001U)

#define CSL_ICSSMIIMDIO_USERACCESS1_WRITE_MASK                  (0x40000000U)
#define CSL_ICSSMIIMDIO_USERACCESS1_WRITE_SHIFT                 (30U)
#define CSL_ICSSMIIMDIO_USERACCESS1_WRITE_RESETVAL              (0x00000000U)
#define CSL_ICSSMIIMDIO_USERACCESS1_WRITE_MAX                   (0x00000001U)

#define CSL_ICSSMIIMDIO_USERACCESS1_GO_MASK                     (0x80000000U)
#define CSL_ICSSMIIMDIO_USERACCESS1_GO_SHIFT                    (31U)
#define CSL_ICSSMIIMDIO_USERACCESS1_GO_RESETVAL                 (0x00000000U)
#define CSL_ICSSMIIMDIO_USERACCESS1_GO_MAX                      (0x00000001U)

#define CSL_ICSSMIIMDIO_USERACCESS1_RESETVAL                    (0x00000000U)

/* USERPHYSEL1 */

#define CSL_ICSSMIIMDIO_USERPHYSEL1_PHYADR_MON_MASK             (0x0000001FU)
#define CSL_ICSSMIIMDIO_USERPHYSEL1_PHYADR_MON_SHIFT            (0U)
#define CSL_ICSSMIIMDIO_USERPHYSEL1_PHYADR_MON_RESETVAL         (0x00000000U)
#define CSL_ICSSMIIMDIO_USERPHYSEL1_PHYADR_MON_MAX              (0x0000001fU)

#define CSL_ICSSMIIMDIO_USERPHYSEL1_LINKINT_ENABLE_MASK         (0x00000040U)
#define CSL_ICSSMIIMDIO_USERPHYSEL1_LINKINT_ENABLE_SHIFT        (6U)
#define CSL_ICSSMIIMDIO_USERPHYSEL1_LINKINT_ENABLE_RESETVAL     (0x00000000U)
#define CSL_ICSSMIIMDIO_USERPHYSEL1_LINKINT_ENABLE_MAX          (0x00000001U)

#define CSL_ICSSMIIMDIO_USERPHYSEL1_LINKSEL_MASK                (0x00000080U)
#define CSL_ICSSMIIMDIO_USERPHYSEL1_LINKSEL_SHIFT               (7U)
#define CSL_ICSSMIIMDIO_USERPHYSEL1_LINKSEL_RESETVAL            (0x00000000U)
#define CSL_ICSSMIIMDIO_USERPHYSEL1_LINKSEL_MAX                 (0x00000001U)

#define CSL_ICSSMIIMDIO_USERPHYSEL1_RESETVAL                    (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
