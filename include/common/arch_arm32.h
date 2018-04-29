/***************************************************************
*  @file arch_arm32.h
*  @ description declare function to interact with registers
*  @author Yue Wei
*  @date Feb 10 2018
****************************************************************/
#ifndef _ARCH_ARM32_H_
#define _ARCH_ARM32_H_

#include <stdint.h>
#define __SCB_ADDRESS (0xE000ED00) /*System Control Block base address*/
#define __AIRCR_ADDRESS_OFFSET (0xE000ED0C)
/*uint32_t points to the address of __AIRCR_ADDRESS,
**then dereference it using the star in front.*/
#define __AIRCR (*((volatile uint32_t*)__AIRCR_ADDRESS_OFFSET))
#define __AIRCR_ENDIANNESS_OFFSET (15)
#define __AIRCR_ENDIANNESS_MASK (0x00008000)

#define __CPUID_ADDRESS_OFFSET (0xE000ED00)
#define __CPUID (*((volatile uint32_t*)__CPUID_ADDRESS_OFFSET))
#define __CPUID_PART_NO_OFFSET (4)
#define __CPUID_PART_NO_MASK (0x0000FFF0)

#define __CCR_ADDRESS_OFFSET (0xE000ED14)
#define __CCR (*((volatile uint32_t*)__CCR_ADDRESS_OFFSET))
#define __CCR_STK_ALIGNMENT_OFFSET (9)
#define __CCR_STK_ALIGNMENT_MASK (0x00000200)
#define __CCR_UNALIGNED_ACCESS_TRAP_OFFSET (3)
#define __CCR_UNALIGNED_ACCESS_TRAP_MASK (0x00000008)
#define __CCR_DIVIDE_BY_ZERO_TRAP_OFFSET (4)
#define __CCR_DIVIDE_BY_ZERO_TRAP_MASK (0x00000010)


/*********************************************************
* ARM32_AIRCR_get_endianness_setting() - This function
* 	reads AIRCR and return endianness value of the
*  	currently configured ARM processor.
* Inputs:
* 	Not inputs
* Return:
* 	Return the endianness value
**********************************************************/
__attribute__((always_inline)) inline uint32_t ARM32_AIRCR_get_endianness_setting();

/*********************************************************
* ARM32_CCR_get_stack_alignment() - This function needs
*   to read the ARM Configuration and Control Register
*   (CCR) and return the stack alignment value of the
*   current configured ARM processor.
* Inputs:
* 	Not inputs
* Return:
* 	0 = 4byte aligned
* 	1 = 8byte aligned
**********************************************************/
__attribute__((always_inline)) inline uint32_t ARM32_CCR_get_stack_alignment();

/*********************************************************
* ARM32_CPUID_get_part_number() - This function needs
*   to read the ARM CPU ID Register (CPUID) and return
*   the value of Part Number for the current ARM processor.
* Inputs:
* 	Not inputs
* Return:
*   The the value of Part Number,
*   Cortex-M3 should return 0xC23
*   Cortex-M4 should return 0xC24
**********************************************************/
__attribute__((always_inline)) inline uint32_t ARM32_CPUID_get_part_number();

/*********************************************************
* ARM32_CCR_enable_divide_by_zero_trap() - This function
* 	needs to write to the ARM Configuration and Control
* 	Register (CCR) to set a divide by zero trap by writing
* 	a 1 to the correct bit location of DIV_0_TRP.
* Inputs:
* 	Not inputs
* Return:
*   0
**********************************************************/
__attribute__((always_inline)) inline uint32_t ARM32_CCR_enable_divide_by_zero_trap();

/*********************************************************
* ARM32_CCR_enable_unligned_access_trap() - This function
* 	needs to write to the ARM Configuration and Control
* 	Register (CCR) to set an unaligned memory access trap
* 	by writing a 1 to the correct bit location of
* 	UNALIGN_TRP
* Inputs:
* 	Not inputs
* Return:
*   0
**********************************************************/
__attribute__((always_inline)) inline uint32_t ARM32_CCR_enable_unligned_access_trap();

/*********************************************************
* ARM32_create_unligned_access_trap() - This function
* 	should perform an unaligned access in order to
* 	trigger a trap or exception on the microcontroller
* Inputs:
* 	Not inputs
* Return:
*   Nothing
**********************************************************/
void ARM32_create_unligned_access_trap();

/*********************************************************
* ARM32_create_divide_by_zero_trap() - This function
* 	should perform a divide by zero in order to trigger
* 	a trap or exception on the microcontroller.
* Inputs:
* 	Not inputs
* Return:
*   Nothing
**********************************************************/
void ARM32_create_divide_by_zero_trap();


#endif /* _ARCH_ARM32_H_ */
