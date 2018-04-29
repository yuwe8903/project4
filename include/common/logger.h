
/***************************************************************
*  @file logger.h
*  @description  declare macros and functions for logger.c
*  @			 logger is used in spi.c
*  @author Yue Wei
*  @date  Apr 17, 2018
****************************************************************/
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdint.h>
#include "MKL25Z4.h"
#include <stdlib.h>
#include "conversion.h"

#include "uart.h"
#include "rtc.h"


#ifdef BBB_PLATFORM
#include <sys/time.h>
#endif
#define LOG_RAW_DATA(data,len)								(log_data(data,len))
#define LOG_RAW_STRING(string)								(log_string(string))
#define LOG_RAW_INT(number)									(log_int(number))
#define LOG_FLUSH()											(log_flush())
#define LOG_RAW_ITEM(stucture)								(log_item(structure))
#define LOG_STRUCT(log_id_, payload_length_, payload_)		(log_struct(log_id_, payload_length_, payload_))

typedef enum{
	LOGGER_INITIALIZED = 1,
	GPIO_INITIALIZED = 2,
	SYSTEM_INITIALIZED = 3,
	SYSTEM_HALTED = 4,
	INFO = 5,
	WARNING = 6,
	ERROR = 7,
	PROFILING_STARTED = 8,
	PROFILING_RESULT = 9,
	PROFILING_COMPLETED = 10,
	DATA_RECEIVED = 11,
	DATA_ANALYSIS_STARTED = 12,
	DATA_ALPHA_COUNT = 13,
	DATA_NUMERIC_COUNT = 14,
	DATA_PUNCTUATION_COUNT = 15,
	DATA_MISC_COUNT = 16,
	DATA_ANALYSIS_COMPLETED = 17,
	HEARTBEAT = 18,
	DATA_INPUT_DISABLED = 19,
	DATA_INPUT_ENABLED = 20
}Logid_e;

typedef struct{
	Logid_e log_id;
	uint32_t timestamp;
	uint32_t payload_length;
	uint8_t * payload;
	uint16_t checksum;
}Logstructure_t;

Logstructure_t * logstructure;

/************************************************************
*  log_data() - Takes a pointer to sequence of bytes and
*  	length of bytes to log.
*  Inputs:
*  	unit8_t * data: Pointer to sequence of bytes
*  	size_t length : Number of bytes to log
*  Return:
*  	Nothing
*************************************************************/
void log_data(uint8_t * data, size_t len);

/************************************************************
*  log_string() - Takes a c-string and logs that to the
*  	terminal.
*  Inputs:
*  	unit32_t * data: Pointer to the string
*  Return:
*  	Nothing
*************************************************************/
void log_string(uint8_t * string);

/************************************************************
*  log_int() - Takes an integer and logs that to the
*  	terminal.
*  Inputs:
*  	unit32_t * number: an integer to log
*  Return:
*  	Nothing
*************************************************************/
void log_int(int32_t number);

/************************************************************
*  log_flush() - Blocks until the current logger buffer is empty
*  	empty.
*  Inputs:
*  	Nothing
*  Return:
*  	Nothing
*************************************************************/
void log_flush();

/************************************************************
*  log_struct() - Perform the actual log output.
*  Inputs:
*  	Logid_e log_id_  log id
*  	uint32_t payload_length_   the length of the payload
*  	uint8_t * payload_  the payload message
*  Return:
*  	Nothing
*************************************************************/
void log_struct(Logid_e log_id_, uint32_t payload_length_, uint8_t * payload_);

/************************************************************
*  check_sum() - Perform checksum.
*  Inputs:
*  	Logid_e log_id_
*  Return:
*  	A number that represent the log id
*************************************************************/
uint16_t check_sum(Logid_e log_id_);

/************************************************************
*  log_item() - Send the log information.
*  Inputs:
*  	Logstructure_t * ptr  A pointer that points to the structure
*  Return:
*  	Nothing
*************************************************************/
void log_item(Logstructure_t * ptr);

/************************************************************
*  log_time_stamp() - Record time_stamp
*  	empty.
*  Inputs:
*  	Nothing
*  Return:
*  	Time
*************************************************************/
uint32_t log_time_stamp();

#endif /* _LOGGER_H_ */
