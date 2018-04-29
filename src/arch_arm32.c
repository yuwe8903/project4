
/************************************************************
*  @file arch_arm32.c
*  @description This is the function defination for the
*       function declaraion in arch_arm32.h file
*  @author Yue Wei
*  @date Feb 10 2018
*************************************************************/
#include "arch_arm32.h"

__attribute__((always_inline)) inline uint32_t ARM32_AIRCR_get_endianness_setting()
{
  return ((__AIRCR & __AIRCR_ENDIANNESS_MASK) >>__AIRCR_ENDIANNESS_OFFSET);
}

__attribute__((always_inline)) inline uint32_t ARM32_CCR_get_stack_alignment()
{
  return((__CCR & __CCR_STK_ALIGNMENT_MASK) >> __CCR_STK_ALIGNMENT_OFFSET);
}

__attribute__((always_inline)) inline uint32_t ARM32_CPUID_get_part_number()
{
  return((__CPUID & __CPUID_PART_NO_MASK) >> __CPUID_PART_NO_OFFSET);
}
__attribute__((always_inline)) inline uint32_t ARM32_CCR_enable_divide_by_zero_trap()
{
  __CCR = __CCR | __CCR_DIVIDE_BY_ZERO_TRAP_MASK;
  return 0;
}
__attribute__((always_inline)) inline uint32_t ARM32_CCR_enable_unligned_access_trap()
{
  __CCR = __CCR | __CCR_UNALIGNED_ACCESS_TRAP_MASK;
  return 0;
}
void ARM32_create_unligned_access_trap()
{
  return;
}
void ARM32_create_divide_by_zero_trap()
{
  return;
}

