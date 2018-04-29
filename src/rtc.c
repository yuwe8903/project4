
/************************************************************
*  @file rtc.c
*  @description This is the function defination for the
*       function declaraion in rtc.h file
*  @author Yue Wei
*  @date Apr 22 2018
*************************************************************/

#include "rtc.h"

void RTC_Configure()
{
	MCG_C1 |= MCG_C1_IRCLKEN_MASK;	   /*MCGIRCLK active*/
	MCG_C2 &= ~(MCG_C2_IRCS_MASK); 	   /*32KHz*/
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; /*enable gate clock for portC*/
	SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;   /*enable RTC Access Control*/

	PORTC_PCR1 |= (PORT_PCR_MUX(0x1));/*select ALT1 to enable the RTC_CLKIN */
	PORTC_PCR3 |= (PORT_PCR_MUX(0x5));/*select ALT5 to enable the CLKOUT */

	SIM_SOPT1 &= ~(SIM_SOPT1_OSC32KSEL_MASK);
	SIM_SOPT1 |= SIM_SOPT1_RTC_CLKIN_MASK;		/*select RTC_CLKIN source*/
	SIM_SOPT2 &= ~(SIM_SOPT2_CLKOUTSEL_MASK);
	SIM_SOPT2 |= SIM_SOPT2_MCGIRCLK_MASK;		/*select MCGIRCLK to CLKOUT pin*/

	if (RTC_SR & RTC_SR_TIF_MASK){
		RTC_SR |= RTC_SR_TCE_MASK;
		RTC_TSR = 0;
	}

	RTC_SR |= RTC_SR_TCE_MASK;
	RTC_IER |= RTC_IER_TSIE_MASK;
	NVIC_ClearPendingIRQ(RTC_Seconds_IRQn);
	NVIC_EnableIRQ(RTC_Seconds_IRQn);

	return;
}
uint32_t read_rtcTimer()
{
	return RTC->TSR;
}
void RTC_Seconds_IRQHandler()
{
	return;
}
