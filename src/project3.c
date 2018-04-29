/************************************************************
*  @file project3.c
*  @description This is the function defination for the
*       function declaraion in project3.h file
*  @author Yue Wei
*  @date Apr 7, 2018
*************************************************************/
#include "project3.h"

void project3_spi_nrf_interface()
{
	SPI_Configure();
	nrf_read_status();

	return;
}

void project3_profile_demo()
{

	uint8_t * src = malloc(5000);
	if(src == NULL)
	{
		LOG_STRUCT(WARNING, 0, NULL);
	}
	uint8_t * dst = malloc(5000);
	if(dst == NULL)
	{
		LOG_STRUCT(WARNING, 0, NULL);
	}
#ifdef KL25Z_PLATFORM
	Systick_Configure();
	LOG_STRUCT(GPIO_INITIALIZED, 18, "systick configured");

	FRDM_profile_functions(src, dst);
#endif


#ifdef BBB_PLATFORM
	BBB_profile_functions(src, dst);
#endif
	free(src);
	free(dst);
	return;
}
