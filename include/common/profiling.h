/***************************************************************
*  @file profiling.h
*  @description declare macros and functions for profiling.c
*  @author Yue Wei
*  @date  Apr 2, 2018
****************************************************************/
#ifndef _PROFILING_H_
#define _PROFILING_H_

#include <string.h>
#include "gpio.h"
#include "memory.h"
#include <sys/time.h>
#include "dma.h"
#include "logger.h"
//#include "MKL25Z4.h"
#define KL25Z_PLATFORM
//#define BBB_PLATFORM

#ifdef KL25Z_PLATFORM
#define SYSTICK_COUNT() (SysTick->VAL)
#define SYSTICK_ZERO() (SysTick->VAL = 0UL) /*Reload Current Value register when 0 is reached*/
#define CORE_CLOCK (48000000)
#define SYSTICK_FREQUENCY (1000)   /*ticks per second*/
#endif

#ifdef BBB_PLATFORM
#define SYSTICK_COUNT() (BBB_timer())
#define SYSTICK_ZERO() (0) /*Reload Current Value register when 0 is reached*/
#endif

/*********************************************************
* uint32_t BBB_timer() - This function will get the time
* 	when running in BBB_timer platform
* Inputs:
* 	No inputs
* Return:
*   Current time
**********************************************************/
uint32_t BBB_timer();

/*********************************************************
* void Systick_Configure() - This function will configure
* 	Systick
* Inputs:
* 	No inputs
* Return:
*   Nothing
**********************************************************/
void Systick_Configure();

/*********************************************************
* void profile_memmove() - This function does profiling
* 	for the Standard Library Version memmove()
* Inputs:
* 	src: source pointer
* 	dst: designation pointer
* Return:
*   Nothing
**********************************************************/
void profile_memmove(void * src, void * dst);

/*********************************************************
* void profile_my_memmove() - This function does profiling
* 	for the Non-DMA Version my_memmove()
* Inputs:
* 	src: source pointer
* 	dst: designation pointer
* Return:
*   Nothing
**********************************************************/
void profile_my_memmove(uint8_t * src,uint8_t * dst);

/*********************************************************
* void profile_memmove_dma() - This function does profiling
* 	for the DMA Version my_memmove_dma()
* Inputs:
* 	src: source pointer
* 	dst: designation pointer
* Return:
*   Nothing
**********************************************************/
void profile_memmove_dma(uint8_t * src,uint8_t * dst);

/*********************************************************
* void profile_memset() - This function does profiling
* 	for the Standard Library Version memset()
* Inputs:
* 	src: source pointer
* Return:
*   Nothing
**********************************************************/
void profile_memset(uint8_t * src);

/*********************************************************
* void profile_my_memset() - This function does profiling
* 	for the Non-DMA Version my_memset()
* Inputs:
* 	src: source pointer
* Return:
*   Nothing
**********************************************************/
void profile_my_memset(uint8_t * src);

/*********************************************************
* void profile_memset_dma() - This function does profiling
* 	for the DMA Version my_memset_dma()
* Inputs:
* 	src: source pointer
* Return:
*   Nothing
**********************************************************/
void profile_memset_dma(uint8_t * src);

/*********************************************************
* void FRDM_profile_functions() - This function will call
* 	all of the profiling functions for FRDM platform
* Inputs:
* 	src: source pointer
* 	dst: designation pointer
* Return:
*   Nothing
**********************************************************/
void FRDM_profile_functions(uint8_t * src, uint8_t * dst);


/*********************************************************
* void BBB_profile_functions() - This function will call
* 	all of the profiling functions for BBB platform. This
* 	function contains printf(), but needs #define BBB
* Inputs:
* 	src: source pointer
* 	dst: designation pointer
* Return:
*   Nothing
**********************************************************/
void BBB_profile_functions(uint8_t * src, uint8_t * dst);

#endif /* _PROFILING_H_ */
