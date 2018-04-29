/***************************************************************
*  @file rtc.h
*  @description declare macros and functions for rtc.c
*  @author Yue Wei
*  @date  Apr 22, 2018
****************************************************************/

#ifndef _RTC_H_
#define _RTC_H_
#include <stdint.h>
#include "MKL25Z4.h"

#define SIM_SOPT1_RTC_CLKIN_MASK (0x80000u)  /*select RTC_CLKIN mask*/
#define SIM_SOPT2_MCGIRCLK_MASK (0x80u)      /*select MCGIRCLK mask*/
/************************************************************
*  RTC_Configure() - This function configures rtc module.
*  Inputs:
*  	Nothing
*  Return:
*  	Nothing
*************************************************************/
void RTC_Configure();

/************************************************************
*  read_rtcTimer() - This function will read the rtc Time
*  	Seconds Register
*  Inputs:
*  	Nothing
*  Return:
*  	32 bit timer register value
*************************************************************/
uint32_t read_rtcTimer();

/************************************************************
*  RTC_Seconds_IRQHandler() - This function is the IRQ
* 	handler for the RTC time.
*  Inputs:
*  	Nothing
*  Return:
*  	Nothing
*************************************************************/
void RTC_Seconds_IRQHandler();

#endif /* _RTC_H_ */
