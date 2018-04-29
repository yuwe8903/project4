
/***************************************************************
*  @file logger_queue.h
*  @description declare macros and functions for logger_queue.c
*  @author Yue Wei
*  @date  Apr 22, 2018
****************************************************************/
#ifndef _LOGGER_QUEUE_H_
#define _LOGGER_QUEUE_H_
#include <stdint.h>
#include <stdlib.h>
typedef struct{
	uint8_t * base;
	uint8_t * head;
	uint8_t * tail;
	size_t length;
	size_t count;
}BUFF_t;

typedef enum{
	BUFF_SUCCESS = 0,
	BUFF_ERROR = -1,
	BUFF_NULL_POINTER = -2,
	BUFF_ZERO_LENGTH = -3,
	BUFF_FULL = 1,
	BUFF_NOT_FULL = 2,
	BUFF_EMPTY = 3,
	BUFF_NOT_EMPTY = 4,
}BUFF_e;


/************************************************************
*  BUFF_init() - Initialize the position of head, tail,
*  		length, count.
*  Inputs:
*       BUFF_t * cbuf: Pointer to the BUFF
*       size_t length: Size of the BUFF
*  Return: The status of the BUFF.
*************************************************************/
BUFF_e BUFF_init(BUFF_t * cbuf, size_t length);

/************************************************************
*  BUFF_destroy() - free the BUFF memory.
*  Inputs:
*       BUFF_t * cbuf: Pointer to the BUFF
*  Return: Status of the BUFF.
*************************************************************/
__attribute__((always_inline)) inline BUFF_e BUFF_destroy( BUFF_t * cbuf )
{
	free(cbuf->base);
	if(! cbuf || ! cbuf->head || ! cbuf->tail || ! cbuf->base)
		{
			return BUFF_NULL_POINTER;
		}
	return BUFF_SUCCESS;
}

/************************************************************
*  BUFF_buffer_add_item() - Add data to the buffer.
*  Inputs:
*       BUFF_t * cbuf: Pointer to the BUFF
*       uint8_t data: The data that is being added to the BUFF
*  Return: The status of the BUFF.
*************************************************************/
BUFF_e BUFF_buffer_add_item(BUFF_t * cbuf, uint8_t data);

/************************************************************
*  BUFF_buffer_remove_item() - Remove data from the buffer.
*  Inputs:
*       BUFF_t * cbuf: Pointer to the BUFF
*       uint8_t * data: The data that is being removed from BUFF
*  Return: The status of the BUFF.
*************************************************************/
BUFF_e BUFF_buffer_remove_item(BUFF_t * cbuf, uint8_t *data);

/************************************************************
*  BUFF_is_full() - Check if the BUFF is full.
*  Inputs:
*       BUFF_t * cbuf: Pointer to the BUFF
*  Return: The status of the BUFF.
*************************************************************/
BUFF_e BUFF_is_full(BUFF_t * cbuf);

/************************************************************
*  BUFF_is_empty() - Check if the BUFF is empty.
*  Inputs:
*       BUFF_t * cbuf: Pointer to the BUFF
*  Return: The status of the BUFF.
*************************************************************/
BUFF_e BUFF_is_empty(BUFF_t * cbuf);

/************************************************************
*  BUFF_peek() - Peek into the BUFF in accordance to the Head.
*  Inputs:
*       BUFF_t * cbuf: Pointer to the BUFF
*       uint8_t num: In accordance to the Head,
*       			 num = 0 means peek at the head
*       			 num = 1 means peek at the head-1
*       			 		(the one before head)
*       			 num = 2 means peek at the head-2
*       uint8_t * peek: Store the peeked value into peek
*  Return: The status of the BUFF.
*************************************************************/
BUFF_e BUFF_peek(BUFF_t * cbuf, uint8_t num, uint8_t * peek);

#endif /* _LOGGER_QUEUE_H_ */
