/************************************************************
*  @file conversion.h
*  @descripition declare itoa and atoi functions to perfom
* 	the conversion between ASCII and Integer
*  @authour Yue Wei
*  @date Feb 04 2018
*************************************************************/
#ifndef _CONVERSION_H_
#define _CONVERSION_H_

#include <stdint.h>
#include <stdlib.h>
/************************************************************
*  my_itoa() - Integer to ASCII needs to convert data from a
*       standard integer type into an ASCII string.
*  Inputs:
*       int32_t data:  Integer
*       uint8_t * ptr: Copy the converted character string
*       uint32_t base: Base 2-16
*  Return: Return string length
*************************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/************************************************************
*  my_atoi() - ASCII to Integer needs to convert data back
*       from an ASCII represented string into an integer type.
*  Inputs:
*       uint8_t * ptr:  Charactor string
*       uint8_t digits: Used for integer that converted
*       uint32_t base:  Tell the ASCII string represents what
*       base number.
*  Return: Return an integer value
*************************************************************/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/************************************************************
*  power() - Compute base1^exp
*  Inputs:
*       uint8_t exp: The power
*       uint32_t base1: Base number
*  Return: Return a result of base1^exp
*************************************************************/
int32_t power(uint32_t base1, uint8_t exp);

#endif /*_CONVERSION_H_*/
