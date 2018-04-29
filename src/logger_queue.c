
/************************************************************
*  @file logger_queue.c
*  @description This is the function defination for the
*       function declaraion in logger_queue.h file
*  @author Yue Wei
*  @date Apr 22 2018
*************************************************************/

#include <logger_queue.h>

BUFF_e BUFF_init(BUFF_t * cbuf, size_t length)
{
	cbuf->base = (int8_t *) malloc(length*sizeof(cbuf));
	if(! cbuf->base)
	{
		return BUFF_ERROR;
	}
	cbuf->length = length;
	cbuf->head = cbuf->base;
	cbuf->tail = cbuf->base;
	cbuf->count = 0;
	return BUFF_SUCCESS;
}
BUFF_e BUFF_buffer_add_item(BUFF_t * cbuf, uint8_t data)
{
	if(! cbuf || ! cbuf->head || ! cbuf->tail || ! cbuf->base)
	{
		return BUFF_NULL_POINTER;
	}
	/*check if BUFF is full*/
	if(BUFF_is_full(cbuf) == BUFF_FULL)
	{
		return BUFF_FULL;
	}
	*cbuf->head = data;
	if(cbuf->head == (cbuf->base + (cbuf->length -1) ))
	{
		cbuf->head = cbuf->base;
		cbuf->count ++;
		return BUFF_SUCCESS;
	}
	else
	{
		cbuf->head ++;
		cbuf->count ++;
		return BUFF_SUCCESS;
	}

}
BUFF_e BUFF_buffer_remove_item(BUFF_t * cbuf, uint8_t *data)
{
	if(! cbuf || ! cbuf->head || ! cbuf->tail || ! cbuf->base)
	{
		return BUFF_NULL_POINTER;
	}
	/*check if BUFF is empty*/
	if(BUFF_is_empty(cbuf) == BUFF_EMPTY)
	{
		return BUFF_EMPTY;
	}
	*data = *cbuf->tail;
	if(cbuf->tail == (cbuf->base + (cbuf->length -1) ))
	{
		cbuf->tail = cbuf->base;
		cbuf->count --;
		return BUFF_SUCCESS;
	}
	else
	{
		cbuf->tail ++;
		cbuf->count --;
		return BUFF_SUCCESS;
	}
}
BUFF_e BUFF_is_full(BUFF_t * cbuf)
{
	if(! cbuf || ! cbuf->head || ! cbuf->tail || ! cbuf->base)
	{
		return BUFF_NULL_POINTER;
	}
	if((cbuf->tail == cbuf->head +1) || (cbuf->head == cbuf->tail + (cbuf->length - 1)))
	{
		return BUFF_FULL;
	}
	else
	{
		return BUFF_NOT_FULL;
	}
}
BUFF_e BUFF_is_empty(BUFF_t * cbuf)
{
	if(! cbuf || ! cbuf->head || ! cbuf->tail || ! cbuf->base)
	{
		return BUFF_NULL_POINTER;
	}
	if(BUFF_is_full(cbuf) == BUFF_FULL)
	{
		return BUFF_NOT_EMPTY;
	}
	if(cbuf->tail == cbuf->head)
	{
		return BUFF_EMPTY;
	}
	else
	{
		return BUFF_NOT_EMPTY;
	}
}
BUFF_e BUFF_peek(BUFF_t * cbuf, uint8_t num, uint8_t * peek)
{
	if(! cbuf || ! cbuf->head || ! cbuf->tail || ! cbuf->base)
	{
		return BUFF_NULL_POINTER;
	}
	if((cbuf->head - cbuf->base) >= num)
	{
	*peek = *cbuf->head-num;
	}
	else
	{
	num = num - (cbuf->head - cbuf->base);
	*peek = * cbuf->base + (cbuf->length - num);
	}
	return BUFF_SUCCESS;

}
