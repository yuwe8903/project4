/************************************************************
*  @file logger.c
*  @description This is the function defination for the
*       function declaraion in logger.h file
*  @author Yue Wei
*  @date Apr 17 2018
*************************************************************/
#include "logger.h"
uint32_t global_time_temp = 0;

void log_data(uint8_t * data, size_t len)
{
	if(data != NULL)
	{
		for(uint8_t i = 0; i < len; i++)
		{
			UART_send((data+i));
		}
#ifdef BBB_PLATFORM
		for(uint8_t i = 0; i < len; i++)
		{
			printf("%c \t",(data+i));
		}
		printf("\n");
#endif
	}
}
void log_string(uint8_t * string)
{
	uint8_t i = 0;
	while( *string != 0)
	{
		UART_send((string+i));
		i++;
	}
#ifdef BBB_PLATFORM
	while( *string != 0)
		{
			frintf("%c \t",(string+i));
			i++;
		}
	printf("\n");
#endif

}
void log_int(int32_t number)
{
	uint8_t buffer[10];
	my_itoa(number, buffer, 10);
	for(uint8_t i = 0; i < 10; i++)
	{
		UART_send((buffer+i));
	}
#ifdef BBB_PLATFORM
	for(uint8_t i = 0; i < 10; i++)
	{
		printf("%c \t",(buffer+i));
	}
	printf("\n");
#endif
}
void log_flush()
{
	return;
}
void log_struct(Logid_e log_id_, uint32_t payload_length_, uint8_t * payload_)
{
	logstructure->log_id = log_id_;
	logstructure->timestamp = log_time_stamp();
	logstructure->payload_length = payload_length_;
	logstructure->payload = payload_;
	logstructure->checksum= check_sum(log_id_);
	log_item(logstructure);
	return;
}
uint16_t check_sum(Logid_e log_id_)
{
	uint16_t result = 0;
	result = log_id_;
	return result;
}
void log_item(Logstructure_t * ptr)
{
	uint8_t * pointer = &(ptr->log_id);
	LOG_RAW_STRING(pointer);
	LOG_RAW_INT((ptr->timestamp));
	LOG_RAW_INT((ptr->payload_length));
	LOG_RAW_STRING((ptr->payload));
	LOG_RAW_INT((ptr->checksum));
	return;
}

uint32_t log_time_stamp()
{
#ifdef KL25Z_PLATFORM
	global_time_temp = read_rtcTimer();
#endif

#ifdef BBB_PLATFORM
	struct timeval * temp;
	gettimeofday(temp, NULL);
	global_time_temp = *(uint32_t*)temp;
#endif
	return global_time_temp;
}
