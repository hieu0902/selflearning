/*
 * stm32f407xx.h
 *
 *  Created on: 19-May-2026
 *      Author: HieuNDM
 */
#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_


#include <stdint.h>
#include <stddef.h>

#define __vo volatile
#define __weak __attribute__((weak))
/*
 * Define base addresses of Flash and SRAM memories
*/

#define FLASH_BASEADDR 0x08000000U
#define SRAM1_BASEADDR 0x20000000U
#define SRAM2_BASEADDR 0x2001C000U
#define ROM_BASEADDR   0x1FFF0000U

/*
 * Revision history 
    * 19-May-2026: Initial version
*/