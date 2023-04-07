/*
 *  Copyright (C) 2021 Texas Instruments Incorporated.
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

  /**
 *
 *  \file   cslr_epwm.h
 *
 *  \brief  register-level header file for EPWM module
 *
 */  
   
#ifndef CSLR_EPWM_H_
#define CSLR_EPWM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
                                                                                                                                                                                                                              
/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define CSL_EPWM_TBCTL                                            (0x0U)
#define CSL_EPWM_TBSTS                                            (0x2U)
#define CSL_EPWM_RESERVED_1								          (0x4U)
#define CSL_EPWM_TBPHS                                            (0x6U)
#define CSL_EPWM_TBCTR                                            (0x8U)
#define CSL_EPWM_TBPRD                                            (0xaU)
#define CSL_EPWM_RESERVED_2    							          (0xcU)
#define CSL_EPWM_CMPCTL                                           (0xeU)
#define CSL_EPWM_RESERVED_3    							          (0x10U)
#define CSL_EPWM_CMPA                                             (0x12U)
#define CSL_EPWM_CMPB                                             (0x14U)
#define CSL_EPWM_AQCTLA                                           (0x16U)
#define CSL_EPWM_AQCTLB                                           (0x18U)
#define CSL_EPWM_AQSFRC                                           (0x1aU)
#define CSL_EPWM_AQCSFRC                                          (0x1cU)
#define CSL_EPWM_DBCTL                                            (0x1eU)
#define CSL_EPWM_DBRED                                            (0x20U)
#define CSL_EPWM_DBFED                                            (0x22U)
#define CSL_EPWM_TZSEL                                            (0x24U)
#define CSL_EPWM_TZDCSEL								          (0x26U)
#define CSL_EPWM_TZCTL                                            (0x28U)
#define CSL_EPWM_TZEINT                                           (0x2aU)
#define CSL_EPWM_TZFLG                                            (0x2cU)
#define CSL_EPWM_TZCLR                                            (0x2eU)
#define CSL_EPWM_TZFRC                                            (0x30U)
#define CSL_EPWM_ETSEL                                            (0x32U)
#define CSL_EPWM_ETPS                                             (0x34U)
#define CSL_EPWM_ETFLG                                            (0x36U)
#define CSL_EPWM_ETCLR                                            (0x38U)
#define CSL_EPWM_ETFRC                                            (0x3aU)
#define CSL_EPWM_PCCTL                                            (0x3cU)
#define CSL_EPWM_RESERVED_4                                   	  (0x3EU)
#define CSL_EPWM_RESERVED_5 [16U]                          		  (0x40U)
#define CSL_EPWM_DCTRIPSEL									      (0x60U)
#define CSL_EPWM_DCACTL				    				   		  (0x62U)
#define CSL_EPWM_DCBCTL									    	  (0x64U)
#define CSL_EPWM_DCFCTL									    	  (0x66U)
#define CSL_EPWM_DCCAPCTL										  (0x68U)
#define CSL_EPWM_DCFOFFSET										  (0x6AU)
#define CSL_EPWM_DCFOFFSETCNT									  (0x6CU)
#define CSL_EPWM_DCFWINDOW										  (0x6EU)
#define CSL_EPWM_DCFWINDOWCNT									  (0x70U)
#define CSL_EPWM_DCCAP								        	  (0x72U)


                 
                      
/****************************************************************************************************                                                                                                    
* Field Definition Macros
****************************************************************************************************/

#define CSL_EPWM_AQCTLA_ZRO_SHIFT                                                       (0U)
#define CSL_EPWM_AQCTLA_ZRO_MASK                                                        (0x00000003U)
#define CSL_EPWM_AQCTLA_ZRO_CLEAR                                                       (1U)
#define CSL_EPWM_AQCTLA_ZRO_SET                                                         (2U)
#define CSL_EPWM_AQCTLA_ZRO_DISABLED                                                    (0U)
#define CSL_EPWM_AQCTLA_ZRO_TOGGLE                                                      (3U)

#define CSL_EPWM_AQCTLA_PRD_SHIFT                                                       (2U)
#define CSL_EPWM_AQCTLA_PRD_MASK                                                        (0x0000000cU)
#define CSL_EPWM_AQCTLA_PRD_CLEAR                                                       (1U)
#define CSL_EPWM_AQCTLA_PRD_SET                                                         (2U)
#define CSL_EPWM_AQCTLA_PRD_DISABLED                                                    (0U)
#define CSL_EPWM_AQCTLA_PRD_TOGGLE                                                      (3U)

#define CSL_EPWM_AQCTLA_CAU_SHIFT                                                       (4U)
#define CSL_EPWM_AQCTLA_CAU_MASK                                                        (0x00000030U)
#define CSL_EPWM_AQCTLA_CAU_DISABLED                                                    (0U)
#define CSL_EPWM_AQCTLA_CAU_CLEAR                                                       (1U)
#define CSL_EPWM_AQCTLA_CAU_SET                                                         (2U)
#define CSL_EPWM_AQCTLA_CAU_TOGGLE                                                      (3U)

#define CSL_EPWM_AQCTLA_CAD_SHIFT                                                       (6U)
#define CSL_EPWM_AQCTLA_CAD_MASK                                                        (0x000000c0U)
#define CSL_EPWM_AQCTLA_CAD_CLEAR                                                       (1U)
#define CSL_EPWM_AQCTLA_CAD_SET                                                         (2U)
#define CSL_EPWM_AQCTLA_CAD_DISABLED                                                    (0U)
#define CSL_EPWM_AQCTLA_CAD_TOGGLE                                                      (3U)

#define CSL_EPWM_AQCTLA_CBU_SHIFT                                                       (8U)
#define CSL_EPWM_AQCTLA_CBU_MASK                                                        (0x00000300U)
#define CSL_EPWM_AQCTLA_CBU_DISABLED                                                    (0U)
#define CSL_EPWM_AQCTLA_CBU_CLEAR                                                       (1U)
#define CSL_EPWM_AQCTLA_CBU_SET                                                         (2U)
#define CSL_EPWM_AQCTLA_CBU_TOGGLE                                                      (3U)

#define CSL_EPWM_AQCTLA_CBD_SHIFT                                                      (10U)
#define CSL_EPWM_AQCTLA_CBD_MASK                                                       (0x00000c00U)
#define CSL_EPWM_AQCTLA_CBD_CLEAR                                                      (1U)
#define CSL_EPWM_AQCTLA_CBD_SET                                                        (2U)
#define CSL_EPWM_AQCTLA_CBD_DISABLED                                                   (0U)
#define CSL_EPWM_AQCTLA_CBD_TOGGLE                                                     (3U)
																					   
#define CSL_EPWM_CMPCTL_LOADAMODE_SHIFT                                                (0U)
#define CSL_EPWM_CMPCTL_LOADAMODE_MASK												   (0x00000003U)
#define CSL_EPWM_CMPCTL_LOADAMODE_CTR_PRD                                              (1U)
#define CSL_EPWM_CMPCTL_LOADAMODE_CTR_0_OR_PRD                                         (2U)
#define CSL_EPWM_CMPCTL_LOADAMODE_CTR_0                                                (0U)
#define CSL_EPWM_CMPCTL_LOADAMODE_FREEZE                                               (3U)
																					
#define CSL_EPWM_CMPCTL_LOADBMODE_SHIFT                                               (2U)
#define CSL_EPWM_CMPCTL_LOADBMODE_MASK                                                (0x0000000cU)
#define CSL_EPWM_CMPCTL_LOADBMODE_CTR_PRD                                             (1U)
#define CSL_EPWM_CMPCTL_LOADBMODE_CTR_0_OR_PRD                                        (2U)
#define CSL_EPWM_CMPCTL_LOADBMODE_CTR_0                                               (0U)
#define CSL_EPWM_CMPCTL_LOADBMODE_FREEZE                                              (3U)
																					
#define CSL_EPWM_CMPCTL_SHDWAMODE_SHIFT                                               (4U)
#define CSL_EPWM_CMPCTL_SHDWAMODE_MASK                                                (0x00000010U)
#define CSL_EPWM_CMPCTL_SHDWAMODE_SHADOW                                              (0U)                                                                                                                                                                  
#define CSL_EPWM_CMPCTL_SHDWAMODE_IMMEDIATE                                           (1U)
																					
#define CSL_EPWM_CMPCTL_SHDWBMODE_SHIFT                                               (6U)
#define CSL_EPWM_CMPCTL_SHDWBMODE_MASK                                                (0x00000040U)
#define CSL_EPWM_CMPCTL_SHDWBMODE_SHADOW                                              (0U)
#define CSL_EPWM_CMPCTL_SHDWBMODE_IMMEDIATE                                           (1U)
																					
#define CSL_EPWM_CMPCTL_SHDWAFULL_SHIFT                                               (8U)
#define CSL_EPWM_CMPCTL_SHDWAFULL_MASK                                                (0x00000100U)
#define CSL_EPWM_CMPCTL_SHDWAFULL_FIFO_FULL                                           (1U)                                                                                                                                                                            
#define CSL_EPWM_CMPCTL_SHDWAFULL_FIFO_NOT_FULL                                       (0U)
																					
#define CSL_EPWM_CMPCTL_SHDWBFULL_SHIFT                                               (9U)
#define CSL_EPWM_CMPCTL_SHDWBFULL_MASK                                                (0x00000200U)
#define CSL_EPWM_CMPCTL_SHDWBFULL_FIFO_NOT_FULL                                       (0U)                                                                                                                                                                          
#define CSL_EPWM_CMPCTL_SHDWBFULL_FIFO_FULL                                           (1U)
                                                                                                                                                                    
#define CSL_EPWM_DBFED_DEL_SHIFT                                                      (0U)                                                                                                                                                                    
#define CSL_EPWM_DBFED_DEL_MASK                                                       (0x000003ffU)
																					
#define CSL_EPWM_PCCTL_CHPEN_SHIFT                                                    (0U)
#define CSL_EPWM_PCCTL_CHPEN_MASK                                                     (0x00000001U)
#define CSL_EPWM_PCCTL_CHPEN_DISABLE                                                  (0U)
#define CSL_EPWM_PCCTL_CHPEN_ENABLE                                                   (1U)
																					
#define CSL_EPWM_PCCTL_OSHTWTH_SHIFT                                                  (1U)
#define CSL_EPWM_PCCTL_OSHTWTH_MASK                                                   (0x0000001eU)
#define CSL_EPWM_PCCTL_OSHTWTH_2_X_SYSCLOCKOUT_BY_8_WIDE                              (1U)
#define CSL_EPWM_PCCTL_OSHTWTH_16_X_SYSCLOCKOUT_BY_8_WIDE                             (15U)
#define CSL_EPWM_PCCTL_OSHTWTH_1_X_SYSCLOCKOUT_BY_8_WIDE                              (0U)
#define CSL_EPWM_PCCTL_OSHTWTH_4_X_SYSCLOCKOUT_BY_8_WIDE                              (3U)
#define CSL_EPWM_PCCTL_OSHTWTH_3_X_SYSCLOCKOUT_BY_8_WIDE                              (2U)
																					
#define CSL_EPWM_PCCTL_CHPFREQ_SHIFT                                                  (5U)
                                                                                                                                                                           
#define CSL_EPWM_PCCTL_CHPFREQ_MASK                                                   (0x000000e0U)
#define CSL_EPWM_PCCTL_CHPFREQ_DIV_6                                                  (5U)                                                                                                                                                                   
#define CSL_EPWM_PCCTL_CHPFREQ_DIV_3                                                  (2U)
#define CSL_EPWM_PCCTL_CHPFREQ_DIV_2                                                  (1U)
#define CSL_EPWM_PCCTL_CHPFREQ_DIV_8                                                  (7U)
#define CSL_EPWM_PCCTL_CHPFREQ_DIV_4                                                  (3U)
#define CSL_EPWM_PCCTL_CHPFREQ_DIV_1                                                  (0U)
#define CSL_EPWM_PCCTL_CHPFREQ_DIV_7                                                  (6U)
#define CSL_EPWM_PCCTL_CHPFREQ_DIV_5                                                  (4U)
																					
#define CSL_EPWM_PCCTL_CHPDUTY_SHIFT                                                 (8U)
#define CSL_EPWM_PCCTL_CHPDUTY_MASK                                                  (0x00000700U)
#define CSL_EPWM_PCCTL_CHPDUTY_DUTY_87_5                                             (6U)                                                                                                                                                                           
#define CSL_EPWM_PCCTL_CHPDUTY_EN_0X7                                                (7U)
#define CSL_EPWM_PCCTL_CHPDUTY_DUTY_25                                               (1U)
#define CSL_EPWM_PCCTL_CHPDUTY_DUTY_75                                               (5U)
#define CSL_EPWM_PCCTL_CHPDUTY_DUTY_62_5                                             (4U)
#define CSL_EPWM_PCCTL_CHPDUTY_DUTY_50                                               (3U)
#define CSL_EPWM_PCCTL_CHPDUTY_DUTY_37_5                                             (2U)
#define CSL_EPWM_PCCTL_CHPDUTY_DUTY_12_5                                             (0U)
                                                                                                                                                                     
																					
#define CSL_EPWM_DBRED_DEL_SHIFT                                                     (0U)
#define CSL_EPWM_DBRED_DEL_MASK                                                      (0x000003ffU)
																					
#define CSL_EPWM_TBCTR_SHIFT                                                         (0U)
                                                                                                                                                                   
#define CSL_EPWM_TBCTR_MASK                                                          (0x0000ffffU)
																					
#define CSL_EPWM_ETSEL_INTSEL_SHIFT                                                  (0U)
#define CSL_EPWM_ETSEL_INTSEL_MASK                                                   (0x00000007U)
#define CSL_EPWM_ETSEL_INTSEL_CTR_CMPB_INCR                                          (6U)
#define CSL_EPWM_ETSEL_INTSEL_CTR_CMPA_DECR                                          (5U)
#define CSL_EPWM_ETSEL_INTSEL_CTR_0                                                  (1U)
#define CSL_EPWM_ETSEL_INTSEL_CTR_PERIOD                                             (2U)
#define CSL_EPWM_ETSEL_INTSEL_CTR_CMPA_INCR                                          (4U)
#define CSL_EPWM_ETSEL_INTSEL_CTR_CMPB_DECR                                          (7U)
																					
#define CSL_EPWM_ETSEL_INTEN_SHIFT                                                   (3U)
#define CSL_EPWM_ETSEL_INTEN_MASK                                                    (0x00000008U)
#define CSL_EPWM_ETSEL_INTEN_DISABLE                                                 (0U)
#define CSL_EPWM_ETSEL_INTEN_ENABLE                                                  (1U)
																					
#define CSL_EPWM_TZEINT_CBC_SHIFT                                                    (1U)
#define CSL_EPWM_TZEINT_CBC_MASK                                                     (0x00000002U)
#define CSL_EPWM_TZEINT_CBC_DISABLE                                                   (0U)
#define CSL_EPWM_TZEINT_CBC_ENABLE                                                    (1U)
																					
#define CSL_EPWM_TZEINT_OST_SHIFT                                                    (2U)
#define CSL_EPWM_TZEINT_OST_MASK                                                     (0x00000004U)
#define CSL_EPWM_TZEINT_OST_DISABLE                                                   (0U)
#define CSL_EPWM_TZEINT_OST_ENABLE                                                    (1U)
																					
#define CSL_EPWM_AQSFRC_ACTSFA_SHIFT                                                 (0U)
#define CSL_EPWM_AQSFRC_ACTSFA_MASK                                                  (0x00000003U)
#define CSL_EPWM_AQSFRC_ACTSFA_SET                                                   (2U)
#define CSL_EPWM_AQSFRC_ACTSFA_CLEAR                                                 (1U)
#define CSL_EPWM_AQSFRC_ACTSFA_DISABLED                                              (0U)
#define CSL_EPWM_AQSFRC_ACTSFA_TOGGLE                                                (3U)
																					
#define CSL_EPWM_AQSFRC_OTSFA_SHIFT                                                  (2U)
#define CSL_EPWM_AQSFRC_OTSFA_MASK                                                   (0x00000004U)
#define CSL_EPWM_AQSFRC_OTSFA_NO_EFFECT                                              (0U)
#define CSL_EPWM_AQSFRC_OTSFA_SW_EVENT                                               (1U)
																					
#define CSL_EPWM_AQSFRC_ACTSFB_SHIFT                                                 (3U)
#define CSL_EPWM_AQSFRC_ACTSFB_MASK                                                  (0x00000018U)
#define CSL_EPWM_AQSFRC_ACTSFB_DISABLED                                              (0U)
#define CSL_EPWM_AQSFRC_ACTSFB_SET                                                   (2U)
#define CSL_EPWM_AQSFRC_ACTSFB_CLEAR                                                 (1U)
#define CSL_EPWM_AQSFRC_ACTSFB_TOGGLE                                                (3U)
																					
#define CSL_EPWM_AQSFRC_OTSFB_SHIFT                                                  (5U)
#define CSL_EPWM_AQSFRC_OTSFB_MASK                                                   (0x00000020U)
#define CSL_EPWM_AQSFRC_OTSFB_NO_EFFECT                                               (0U)
#define CSL_EPWM_AQSFRC_OTSFB_SW_EVENT                                                (1U)
																					
#define CSL_EPWM_AQSFRC_RLDCSF_SHIFT                                                 (6U)
#define CSL_EPWM_AQSFRC_RLDCSF_MASK                                                  (0x000000c0U)
#define CSL_EPWM_AQSFRC_RLDCSF_CTR_0_OR_PERIOD                                       (2U)
#define CSL_EPWM_AQSFRC_RLDCSF_CTR_0                                                 (0U)
#define CSL_EPWM_AQSFRC_RLDCSF_CTR_PERIOD                                            (1U)
#define CSL_EPWM_AQSFRC_RLDCSF_IMMEDIATE                                             (3U)
																					
#define CSL_EPWM_ETPS_INTPRD_SHIFT                                                   (0U)
#define CSL_EPWM_ETPS_INTPRD_MASK                                                    (0x00000003U)
#define CSL_EPWM_ETPS_INTPRD_DISABLE                                                 (0U)
#define CSL_EPWM_ETPS_INTPRD_GEN_THIRD_EVT                                           (3U)
#define CSL_EPWM_ETPS_INTPRD_GEN_SECOND_EVT                                          (2U)
#define CSL_EPWM_ETPS_INTPRD_GEN_FIRST_EVT                                           (1U)
																					
#define CSL_EPWM_ETPS_INTCNT_SHIFT                                                   (2U)
#define CSL_EPWM_ETPS_INTCNT_MASK                                                    (0x0000000cU)
#define CSL_EPWM_ETPS_INTCNT_EVT_3                                                   (3U)
#define CSL_EPWM_ETPS_INTCNT_NO_EVT                                                  (0U)
#define CSL_EPWM_ETPS_INTCNT_EVT_1                                                   (1U)
#define CSL_EPWM_ETPS_INTCNT_EVT_2                                                   (2U)
																					
#define CSL_EPWM_CMPA_SHIFT                                                          (0U)
                                                                                                                                                                    
#define CSL_EPWM_CMPA_MASK                                                           (0x0000ffffU)
																					
#define CSL_EPWM_ETCLR_INT_SHIFT                                                     (0U)
#define CSL_EPWM_ETCLR_INT_MASK                                                      (0x00000001U)
#define CSL_EPWM_ETCLR_INT_NO_EFFECT                                                  (0U)
                                                                                                                                                                    
#define CSL_EPWM_ETCLR_INT_CLEAR                                                      (1U)
																					
#define CSL_EPWM_AQCSFRC_CSFA_SHIFT                                                  (0U)
#define CSL_EPWM_AQCSFRC_CSFA_MASK                                                   (0x00000003U)
#define CSL_EPWM_AQCSFRC_CSFA_HIGH_OUTPUT                                            (2U)
#define CSL_EPWM_AQCSFRC_CSFA_DISABLED                                               (0U)
#define CSL_EPWM_AQCSFRC_CSFA_LOW_OUTPUT                                             (1U)
#define CSL_EPWM_AQCSFRC_CSFA_NO_EFFECT                                              (3U)
																					
#define CSL_EPWM_AQCSFRC_CSFB_SHIFT                                                  (2U)
#define CSL_EPWM_AQCSFRC_CSFB_MASK                                                   (0x0000000cU)
#define CSL_EPWM_AQCSFRC_CSFB_LOW_OUTPUT                                             (1U)
#define CSL_EPWM_AQCSFRC_CSFB_DISABLED                                               (0U)
#define CSL_EPWM_AQCSFRC_CSFB_NO_EFFECT                                              (3U)
#define CSL_EPWM_AQCSFRC_CSFB_HIGH_OUTPUT                                            (2U)
																					
#define CSL_EPWM_AQCTLB_ZRO_SHIFT                                                    (0U)
#define CSL_EPWM_AQCTLB_ZRO_MASK                                                     (0x00000003U)
#define CSL_EPWM_AQCTLB_ZRO_CLEAR                                                    (1U)
#define CSL_EPWM_AQCTLB_ZRO_DISABLED                                                 (0U)
#define CSL_EPWM_AQCTLB_ZRO_TOGGLE                                                   (3U)
#define CSL_EPWM_AQCTLB_ZRO_SET                                                      (2U)
																					
#define CSL_EPWM_AQCTLB_PRD_SHIFT                                                    (2U)
#define CSL_EPWM_AQCTLB_PRD_MASK                                                     (0x0000000cU)
#define CSL_EPWM_AQCTLB_PRD_CLEAR                                                    (1U)
#define CSL_EPWM_AQCTLB_PRD_DISABLED                                                 (0U)
#define CSL_EPWM_AQCTLB_PRD_TOGGLE                                                   (3U)
#define CSL_EPWM_AQCTLB_PRD_SET                                                      (2U)
																					
#define CSL_EPWM_AQCTLB_CAU_SHIFT                                                    (4U)
#define CSL_EPWM_AQCTLB_CAU_MASK                                                     (0x00000030U)
#define CSL_EPWM_AQCTLB_CAU_CLEAR                                                    (1U)
#define CSL_EPWM_AQCTLB_CAU_DISABLED                                                 (0U)
#define CSL_EPWM_AQCTLB_CAU_TOGGLE                                                   (3U)
#define CSL_EPWM_AQCTLB_CAU_SET                                                      (2U)
																					
#define CSL_EPWM_AQCTLB_CAD_SHIFT                                                    (6U)
#define CSL_EPWM_AQCTLB_CAD_MASK                                                     (0x000000c0U)
#define CSL_EPWM_AQCTLB_CAD_CLEAR                                                    (1U)
#define CSL_EPWM_AQCTLB_CAD_DISABLED                                                 (0U)
#define CSL_EPWM_AQCTLB_CAD_TOGGLE                                                   (3U)
#define CSL_EPWM_AQCTLB_CAD_SET                                                      (2U)
																					
#define CSL_EPWM_AQCTLB_CBU_SHIFT                                                    (8U)
#define CSL_EPWM_AQCTLB_CBU_MASK                                                     (0x00000300U)
#define CSL_EPWM_AQCTLB_CBU_TOGGLE                                                   (3U)
#define CSL_EPWM_AQCTLB_CBU_CLEAR                                                    (1U)
#define CSL_EPWM_AQCTLB_CBU_DISABLED                                                 (0U)
#define CSL_EPWM_AQCTLB_CBU_SET                                                      (2U)
																					
#define CSL_EPWM_AQCTLB_CBD_SHIFT                                                    (10U)
#define CSL_EPWM_AQCTLB_CBD_MASK                                                     (0x00000c00U)
#define CSL_EPWM_AQCTLB_CBD_CLEAR                                                    (1U)
#define CSL_EPWM_AQCTLB_CBD_DISABLED                                                 (0U)
#define CSL_EPWM_AQCTLB_CBD_TOGGLE                                                   (3U)
#define CSL_EPWM_AQCTLB_CBD_SET                                                      (2U)
																					
#define CSL_EPWM_TBCTL_CTRMODE_SHIFT                                                 (0U)
#define CSL_EPWM_TBCTL_CTRMODE_MASK                                                  (0x00000003U)
#define CSL_EPWM_TBCTL_CTRMODE_STOP_FREEZE                                           (3U)
#define CSL_EPWM_TBCTL_CTRMODE_DOWN_COUNT                                            (1U)
#define CSL_EPWM_TBCTL_CTRMODE_UP_COUNT                                              (0U)
#define CSL_EPWM_TBCTL_CTRMODE_UP_DOWN_COUNT                                         (2U)
																					
#define CSL_EPWM_TBCTL_PHSEN_SHIFT                                                   (2U)
#define CSL_EPWM_TBCTL_PHSEN_MASK                                                    (0x00000004U)
#define CSL_EPWM_TBCTL_PHSEN_DO_NOT_LOAD                                             (0U)
#define CSL_EPWM_TBCTL_PHSEN_LOAD                                                    (1U)
																					
#define CSL_EPWM_TBCTL_PRDLD_SHIFT                                                   (3U)
#define CSL_EPWM_TBCTL_PRDLD_MASK                                                    (0x00000008U)
#define CSL_EPWM_TBCTL_PRDLD_LOAD_IMMEDIATELY                                         (1U)
#define CSL_EPWM_TBCTL_PRDLD_LOAD_FROM_SHADOW                                         (0U)
																					
#define CSL_EPWM_TBCTL_SYNCOSEL_SHIFT                                                (4U)
#define CSL_EPWM_TBCTL_SYNCOSEL_MASK                                                 (0x00000030U)
#define CSL_EPWM_TBCTL_SYNCOSEL_CTR_0                                                (1U)
#define CSL_EPWM_TBCTL_SYNCOSEL_CTR_CPMB                                             (2U)
#define CSL_EPWM_TBCTL_SYNCOSEL_EPWMXSYNC                                            (0U)
#define CSL_EPWM_TBCTL_SYNCOSEL_DISABLE_EPWMXSYNCO                                   (3U)
																					
#define CSL_EPWM_TBCTL_SWFSYNC_SHIFT                                                 (6U)
#define CSL_EPWM_TBCTL_SWFSYNC_MASK                                                  (0x00000040U)
#define CSL_EPWM_TBCTL_SWFSYNC_FORCE_SYNC                                            (1U)
#define CSL_EPWM_TBCTL_SWFSYNC_NO_EFFECT                                             (0U)
																					
#define CSL_EPWM_TBCTL_HSPCLKDIV_SHIFT                                               (7U)
#define CSL_EPWM_TBCTL_HSPCLKDIV_MASK                                                (0x00000380U)
#define CSL_EPWM_TBCTL_HSPCLKDIV_DIV_8                                               (4U)
#define CSL_EPWM_TBCTL_HSPCLKDIV_DIV_10                                              (5U)
#define CSL_EPWM_TBCTL_HSPCLKDIV_DIV_2                                               (1U)
#define CSL_EPWM_TBCTL_HSPCLKDIV_DIV_1                                               (0U)
#define CSL_EPWM_TBCTL_HSPCLKDIV_DIV_4                                               (2U)
#define CSL_EPWM_TBCTL_HSPCLKDIV_DIV_6                                               (3U)
#define CSL_EPWM_TBCTL_HSPCLKDIV_DIV_12                                              (6U)
#define CSL_EPWM_TBCTL_HSPCLKDIV_DIV_14                                              (7U)
																					
#define CSL_EPWM_TBCTL_CLKDIV_SHIFT                                                  (10U)
#define CSL_EPWM_TBCTL_CLKDIV_MASK                                                   (0x00001c00U)
#define CSL_EPWM_TBCTL_CLKDIV_DIV_2                                                  (1U)
#define CSL_EPWM_TBCTL_CLKDIV_DIV_8                                                  (3U)
#define CSL_EPWM_TBCTL_CLKDIV_DIV_32                                                 (5U)
#define CSL_EPWM_TBCTL_CLKDIV_DIV_64                                                 (6U)
#define CSL_EPWM_TBCTL_CLKDIV_DIV_16                                                 (4U)
#define CSL_EPWM_TBCTL_CLKDIV_DIV_4                                                  (2U)
#define CSL_EPWM_TBCTL_CLKDIV_DIV_1                                                  (0U)
#define CSL_EPWM_TBCTL_CLKDIV_DIV_128                                                (7U)
																					
#define CSL_EPWM_TBCTL_PHSDIR_SHIFT                                                  (13U)                                                                                                                                                                         
#define CSL_EPWM_TBCTL_PHSDIR_MASK                                                   (0x00002000U)
#define CSL_EPWM_TBCTL_PHSDIR_COUNT_DOWN                                              (0U)                                                                                                                                                                   
#define CSL_EPWM_TBCTL_PHSDIR_COUNT_UP                                                (1U)
																					
#define CSL_EPWM_TBCTL_FREE_SOFT_SHIFT                                               (14U)
#define CSL_EPWM_TBCTL_FREE_SOFT_MASK                                                (0x0000c000U)
#define CSL_EPWM_TBCTL_FREE_SOFT_RUN3                                                (3U)
#define CSL_EPWM_TBCTL_FREE_SOFT_STOP_AFTER_NEXT_CTR                                 (0U)                                                                                                                                                                     
#define CSL_EPWM_TBCTL_FREE_SOFT_RUN2                                                (2U)
#define CSL_EPWM_TBCTL_FREE_SOFT_STOP_AFTER_CYCLE                                    (1U)
																					
#define CSL_EPWM_TZFRC_CBC_SHIFT                                                     (1U)
#define CSL_EPWM_TZFRC_CBC_MASK                                                      (0x00000002U)
#define CSL_EPWM_TZFRC_CBC_FORCE_TRIP                                                 (1U)                                                                                                                                                                      
#define CSL_EPWM_TZFRC_CBC_IGNORE                                                     (0U)
																					
#define CSL_EPWM_TZFRC_OST_SHIFT                                                     (2U)
#define CSL_EPWM_TZFRC_OST_MASK                                                      (0x00000004U)                                                                                                                                                                       
#define CSL_EPWM_TZFRC_OST_FORCE_TRIP                                                 (1U)                                                                                                                                                                   
#define CSL_EPWM_TZFRC_OST_IGNORE                                                     (0U)
																					
#define CSL_EPWM_TZCTL_TZA_SHIFT                                                     (0U)
#define CSL_EPWM_TZCTL_TZA_MASK                                                      (0x00000003U)
#define CSL_EPWM_TZCTL_TZA_LOW_STATE                                                 (2U)
#define CSL_EPWM_TZCTL_TZA_HIGH_IMPEDANCE                                            (0U)
#define CSL_EPWM_TZCTL_TZA_HIGH_STATE                                                (1U)
#define CSL_EPWM_TZCTL_TZA_DO_NOTHING                                                (3U)
																					
#define CSL_EPWM_TZCTL_TZB_SHIFT                                                     (2U)
#define CSL_EPWM_TZCTL_TZB_MASK                                                      (0x0000000cU)
#define CSL_EPWM_TZCTL_TZB_LOW_STATE                                                 (2U)
#define CSL_EPWM_TZCTL_TZB_DO_NOTHING                                                (3U)
#define CSL_EPWM_TZCTL_TZB_HIGH_IMPEDANCE                                             (0U)
#define CSL_EPWM_TZCTL_TZB_HIGH_STATE                                                 (1U)
																					
#define CSL_EPWM_TBSTS_CTRDIR_SHIFT                                                  (0U)
#define CSL_EPWM_TBSTS_CTRDIR_MASK                                                   (0x00000001U)
#define CSL_EPWM_TBSTS_CTRDIR_COUNTING_DOWN                                          (0U)
#define CSL_EPWM_TBSTS_CTRDIR_COUNTING_UP                                            (1U)
																					
#define CSL_EPWM_TBSTS_SYNCI_SHIFT                                                   (1U)
#define CSL_EPWM_TBSTS_SYNCI_MASK                                                    (0x00000002U)
#define CSL_EPWM_TBSTS_SYNCI_EXTERNAL_SYNC                                           (1U)
#define CSL_EPWM_TBSTS_SYNCI_NO_EFFECT                                               (0U)
																					
#define CSL_EPWM_TBSTS_CTRMAX_SHIFT                                                  (2U)
#define CSL_EPWM_TBSTS_CTRMAX_MASK                                                   (0x00000004U)
#define CSL_EPWM_TBSTS_CTRMAX_MAX_VALUE_REACHED                                      (1U)
#define CSL_EPWM_TBSTS_CTRMAX_MAX_VALUE_NOT_REACHED                                  (0U)
																					
#define CSL_EPWM_ETFRC_INT_SHIFT                                                     (0U)
#define CSL_EPWM_ETFRC_INT_MASK                                                      (0x00000001U)
#define CSL_EPWM_ETFRC_INT_IGNORED                                                    (0U)
#define CSL_EPWM_ETFRC_INT_GENERATE_INTR                                              (1U)
																					
#define CSL_EPWM_TBPHS_SHIFT                                                         (0U)                                                                                                                                                                   
#define CSL_EPWM_TBPHS_MASK                                                          (0x0000ffffU)
																					
#define CSL_EPWM_TZSEL_CBCN_SHIFT                                                    (0U)
#define CSL_EPWM_TZSEL_CBCN_MASK                                                     (0x000000ffU)
#define CSL_EPWM_TZSEL_CBCN_ENABLE                                                   (1U)
#define CSL_EPWM_TZSEL_CBCN_DISABLE                                                  (0U)
																					
#define CSL_EPWM_TZSEL_OSHTN_SHIFT                                                   (8U)
#define CSL_EPWM_TZSEL_OSHTN_MASK                                                    (0x0000ff00U)
#define CSL_EPWM_TZSEL_OSHTN_ENABLE                                                  (1U)
#define CSL_EPWM_TZSEL_OSHTN_DISABLE                                                 (0U)
																					
#define CSL_EPWM_ETFLG_INT_SHIFT                                                     (0U)                                                                                                                                                                          
#define CSL_EPWM_ETFLG_INT_MASK                                                      (0x00000001U)
#define CSL_EPWM_ETFLG_INT_INTR_GENERATED                                            (1U)                                                                                                                                                       
#define CSL_EPWM_ETFLG_INT_NO_EVT                                                    (0U)
																					
#define CSL_EPWM_DBCTL_OUT_MODE_SHIFT                                                (0U)
#define CSL_EPWM_DBCTL_OUT_MODE_MASK                                                 (0x00000003U)
#define CSL_EPWM_DBCTL_OUT_MODE_ENABLED                                              (3U)
#define CSL_EPWM_DBCTL_OUT_MODE_DISABLED                                             (0U)
#define CSL_EPWM_DBCTL_OUT_MODE_DISABLE_FALLING_EDGE                                 (2U)
#define CSL_EPWM_DBCTL_OUT_MODE_DISABLE_RISING_EDGE                                  (1U)
																					
#define CSL_EPWM_DBCTL_POLSEL_SHIFT                                                  (2U)
#define CSL_EPWM_DBCTL_POLSEL_MASK                                                   (0x0000000cU)
#define CSL_EPWM_DBCTL_POLSEL_ACTIVE_HIGH_COMPLEMENTARY                              (2U)
#define CSL_EPWM_DBCTL_POLSEL_ACTIVE_LOW                                             (3U)
#define CSL_EPWM_DBCTL_POLSEL_ACTIVE_HIGH                                            (0U)
#define CSL_EPWM_DBCTL_POLSEL_ACTIVE_LOW_COMPLEMENTARY                               (1U)
																					
#define CSL_EPWM_DBCTL_IN_MODE_SHIFT                                                 (4U)
#define CSL_EPWM_DBCTL_IN_MODE_MASK                                                  (0x00000030U)
#define CSL_EPWM_DBCTL_IN_MODE_SRC_ARED_AFED                                         (0U)
#define CSL_EPWM_DBCTL_IN_MODE_SRC_ARED_BFED                                         (2U)
#define CSL_EPWM_DBCTL_IN_MODE_SRC_BRED_AFED                                         (1U)
#define CSL_EPWM_DBCTL_IN_MODE_SRC_BRED_BFED                                         (3U)
																					
#define CSL_EPWM_TZFLG_INT_SHIFT                                                     (0U)
#define CSL_EPWM_TZFLG_INT_MASK                                                      (0x00000001U)
#define CSL_EPWM_TZFLG_INT_GENERATED                                                 (1U)
#define CSL_EPWM_TZFLG_INT_NOT_GENERATED                                             (0U)
																					
#define CSL_EPWM_TZFLG_CBC_SHIFT                                                     (1U)
#define CSL_EPWM_TZFLG_CBC_MASK                                                      (0x00000002U)
#define CSL_EPWM_TZFLG_CBC_NO_TRIP                                                   (0U)
#define CSL_EPWM_TZFLG_CBC_TRIP                                                      (1U)
																					
#define CSL_EPWM_TZFLG_OST_SHIFT                                                     (2U)
#define CSL_EPWM_TZFLG_OST_MASK                                                      (0x00000004U)
#define CSL_EPWM_TZFLG_OST_NO_TRIP                                                   (0U)
#define CSL_EPWM_TZFLG_OST_TRIP                                                      (1U)
																					
#define CSL_EPWM_TBPRD_SHIFT                                                         (0U)                                                                                                                                                                         
#define CSL_EPWM_TBPRD_MASK                                                          (0x0000ffffU)
#define CSL_EPWM_CMPB_SHIFT                                                          (0U)                                                                                                                                                                            
#define CSL_EPWM_CMPB_MASK                                                           (0x0000ffffU)
																					
#define CSL_EPWM_TZCLR_INT_SHIFT                                                     (0U)
#define CSL_EPWM_TZCLR_INT_MASK                                                      (0x00000001U)
#define CSL_EPWM_TZCLR_INT_CLEAR                                                     (1U)
#define CSL_EPWM_TZCLR_INT_NO_EFFECT                                                 (0U)
																					
#define CSL_EPWM_TZCLR_CBC_SHIFT                                                     (1U)
#define CSL_EPWM_TZCLR_CBC_MASK                                                      (0x00000002U)
#define CSL_EPWM_TZCLR_CBC_NO_EFFECT                                                 (0U)
#define CSL_EPWM_TZCLR_CBC_CLEAR                                                     (1U)
																					
#define CSL_EPWM_TZCLR_OST_SHIFT                                                     (2U)
#define CSL_EPWM_TZCLR_OST_MASK                                                      (0x00000004U)
#define CSL_EPWM_TZCLR_OST_NO_EFFECT                                                 (0U)
#define CSL_EPWM_TZCLR_OST_CLEAR                                                     (1U)
																					
#define CSL_EPWM_DCTRIPSEL_DCAHCOMPSEL_MASK                             			 (0x0000000FU)
#define CSL_EPWM_DCTRIPSEL_DCAHCOMPSEL_SHIFT                            			 (0x00U)
																					
#define CSL_EPWM_DCTRIPSEL_DCALCOMPSEL_MASK                            				 (0x000000F0U)
#define CSL_EPWM_DCTRIPSEL_DCALCOMPSEL_SHIFT                           				 (0x04U)
																					
#define CSL_EPWM_DCTRIPSEL_DCBHCOMPSEL_MASK                            				 (0x00000F00U)
#define CSL_EPWM_DCTRIPSEL_DCBHCOMPSEL_SHIFT                           				 (0x08U)
																					
#define CSL_EPWM_DCTRIPSEL_DCBLCOMPSEL_MASK                            				 (0x0000F000U)
#define CSL_EPWM_DCTRIPSEL_DCBLCOMPSEL_SHIFT                           				 (0x0CU)
																					
#define CSL_EPWM_DCACTL_EVT1SRCSEL_MASK                             				 (0x00000001U)
#define CSL_EPWM_DCACTL_EVT1SRCSEL_SHIFT                             				 (0x00U)
																					
#define CSL_EPWM_DCACTL_EVT1FRC_SYNCSEL_MASK                             			 (0x00000002U)
#define CSL_EPWM_DCACTL_EVT1FRC_SYNCSEL_SHIFT                             			 (0x01U)
																					
																					
#define CSL_EPWM_DCACTL_EVT1SOCE_MASK                             					 (0x00000004U)
#define CSL_EPWM_DCACTL_EVT1SOCE_SHIFT                           					 (0x02U)
																					
#define CSL_EPWM_DCACTL_EVT1SYNCE_MASK                           					 (0x00000008U)
#define CSL_EPWM_DCACTL_EVT1SYNCE_SHIFT                             				 (0x03U)
																					
#define CSL_EPWM_DCACTL_RESERVED_1_MASK                             				(0x000000F0U)
#define CSL_EPWM_DCACTL_RESERVED_1_SHIFT                             				(0x04U)
																					
#define CSL_EPWM_DCACTL_EVT2SRCSEL_MASK                             				(0x00000100U)
#define CSL_EPWM_DCACTL_EVT2SRCSEL_SHIFT                             				(0x08U)
																					
																					
#define CSL_EPWM_DCACTL_EVT2FRC_SYNCSEL_MASK                             			(0x00000200U)
#define CSL_EPWM_DCACTL_EVT2FRC_SYNCSEL_SHIFT                             			(0x09U)
																					
#define CSL_EPWM_DCACTL_RESERVED_2_MASK                             				(0x0000FC00U)
#define CSL_EPWM_DCACTL_RESERVED_2_SHIFT                             				(0x0AU)
																					
																					
#define CSL_EPWM_DCFCTL_SRCSEL_MASK                             					(0x00000003U)
#define CSL_EPWM_DCFCTL_SRCSEL_SHIFT                        	  					(0x00U)
																					
																					
#define CSL_EPWM_DCFCTL_BLANKE_MASK                             					(0x00000004U)
#define CSL_EPWM_DCFCTL_BLANKE_SHIFT                        	    				(0x02U)
																					
#define CSL_EPWM_DCFCTL_BLANKINV_MASK                             					(0x0008U)
#define CSL_EPWM_DCFCTL_BLANKINV_SHIFT                        	  					(0x03U)
																					
																					
#define CSL_EPWM_DCFCTL_PULSESEL_MASK                             					(0x00000030U)
#define CSL_EPWM_DCFCTL_PULSESEL_SHIFT                        	    				(0x04U)
																					
																					
#define CSL_EPWM_DCFCTL_RESERVED_1_MASK                             				(0x00000040U)
#define CSL_EPWM_DCFCTL_RESERVED_1_SHIFT                        	  				(0x06U)
																					
#define CSL_EPWM_DCFCTL_RESERVED_2_MASK                             				(0x00000080U)
#define CSL_EPWM_DCFCTL_RESERVED_2_SHIFT                        	    			(0x07U)
																					
#define CSL_EPWM_DCFCTL_RESERVED_3_MASK                             				(0x00001F00U)
#define CSL_EPWM_DCFCTL_RESERVED_3_SHIFT                        	  				(0x08U)
																					
#define CSL_EPWM_DCFCTL_RESERVED_4_MASK                             				(0x0000E000U)
#define CSL_EPWM_DCFCTL_RESERVED_4_SHIFT                        	    			(0x0DU)
																					
																					
#define CSL_EPWM_DCCAPCTL_CAPE_MASK                      	    					(0x0000001U)
#define CSL_EPWM_DCCAPCTL_CAPE_SHIFT                    		 					(0x00U)
																					
																					
#define CSL_EPWM_DCCAPCTL_SHDWMODE_MASK                      	    				(0x0000002U)
#define CSL_EPWM_DCCAPCTL_SHDWMODE_SHIFT                    		 				(0x01U)
																					
																					
#define CSL_EPWM_DCCAPCTL_RESERVED_1_MASK                      	       				(0x000FFFCU)
#define CSL_EPWM_DCCAPCTL_RESERVED_1_SHIFT                    		 				(0x02U)
																					
#define CSL_EPWM_DCFWINDOW_MASK                      	   							(0x00000FFU)
#define CSL_EPWM_DCFWINDOW_SHIFT                    								(0x00U)
																					
																					
#define CSL_EPWM_DCFWINDOW_RESERVED_MASK                      	   					(0x000FF00U)
#define CSL_EPWM_DCFWINDOW_RESERVED_SHIFT                    						(0x08U)
																					
#define CSL_EPWM_DCFOFFSETCNT_MASK                      							(0x000FFFFU)
#define CSL_EPWM_DCFOFFSETCNT_SHIFT                    								(0x00U)
																					
																					
#define CSL_EPWM_DCCAP_MASK                     		 							(0x000FFFFU)
#define CSL_EPWM_DCCAP_SHIFT                   										(0x00U)
																					
#define CSL_EPWM_DCFWINDOWCNT_MASK                     								(0x00000FFU)
#define CSL_EPWM_DCFWINDOWCNT_SHIFT                   								(0x00U)
																					
																					
#define CSL_EPWM_DCFWINDOWCNT_RESERVED_MASK                     					(0x000FF00U)
#define CSL_EPWM_DCFWINDOWCNT_RESERVED_SHIFT                   						(0x08U)

#ifdef __cplusplus
}
#endif
#endif



















 