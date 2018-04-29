/************************************************************
*  @file conversion.c
*  @description These are function definations for all of the
*  	function declaraion in conversion.h file
*  @authour Yue Wei
*  @date Feb 04 2018
*************************************************************/
#include "conversion.h"
#include "memory.h"
#include <stdio.h>
/*Convert Integer to ASCII*/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  uint8_t i = 1;
  uint8_t remainder = 0;
  uint8_t sign = 0;
  /*considering the sign of input data*/
  if(data < 0)
  {
    data = -data;
    sign = 1;
  }
  *ptr = '\0';
  /*Do the data to ASCII conversion*/
  while(data != 0)
  {
    remainder = data%base;
    /*put the remainder to the pointer*/
    if(remainder > 9)
    {
      *(ptr+i) = (remainder-10)+'a';
    }
    else
    {
      *(ptr+i) = remainder+ '0';
    }
    data = data/base;
    i++;
  }
  /*Taken care of the sign, wether it's a positive or a negative sign*/
  if(sign == 1)
  {
    *(ptr+i) = '-';
    my_reverse(ptr, i+1);
    i++;
  }
  else if(sign == 0)
  {
    my_reverse(ptr, i);
  }
  return i;
}


/*Convert ASCII to Integer*/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  int8_t value = 0;
  uint8_t j;
  digits = digits - 1;
  /*If there is no negative sign at the ptr string*/
  if(*ptr != '-')
  {
    /** Do the conversion from ASCII to integer, say if input string
     ** is "10110" base 2, the computation is 0*2^0 + 1*2^1 + 1*2^2
     ** + 0*2^3 + 1*2^4 which equals 22 and returned as a value*/
    for(j = 0; j < digits; j++)
    {
      value = value + power(base, j) * (*(ptr+digits-1-j) - 48);
    }
  }
  /*if there is a negative sign at the ptr string*/
  else if(*ptr == '-')
  {
    /*Do the conversion from ASCII to integer */

    for(j = 0; j < digits-1; j++)
    {
      value = value + power(base, j) * (*(ptr+digits-1-j) - 48);
    }
    value = -value;
  }
  return value;
}


/*This power function does the exponential calculation base1^exp */
int32_t power(uint32_t base1, uint8_t exp)
{
  uint32_t result = 1;
  while(exp != 0)
  {
    result = result * base1;
    exp--;
  }
  return result;
}

