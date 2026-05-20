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


/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief GPIO
  */  

/** @addtogroup Base_addresses_for_peripherals
  * @{
  */  
/*
 * Define base addresses of Flash and SRAM memories
*/
#define FLASH_BASEADDR 0x08000000UL
#define SRAM1_BASEADDR 0x20000000UL
#define SRAM2_BASEADDR 0x2001C000UL
#define ROM_BASEADDR   0x1FFF0000UL
#define SRAM 		   SRAM1_BASEADDR

/*
 * Define base addresses of AHBx and APBx bus peripheral
*/

#define PERIPHERAL_BASEADDR 0x40000000UL
#define APB1_BASEADDR       PERIPHERAL_BASEADDR
#define APB2_BASEADDR       0x40010000UL
#define AHB1_BASEADDR       0x40020000UL
#define AHB2_BASEADDR       0x50000000UL
#define AHB3_BASEADDR       0xA0000000UL

/*
 * Define base addresses of timers
*/

#define TIM1_BASEADDR (APB2_BASEADDR)
#define TIM2_BASEADDR (APB1_BASEADDR)
#define TIM3_BASEADDR (APB1_BASEADDR + 0x0400UL)
#define TIM4_BASEADDR (APB1_BASEADDR + 0x0800UL)
#define TIM5_BASEADDR (APB1_BASEADDR + 0x0C00UL)
#define TIM6_BASEADDR (APB1_BASEADDR + 0x1000UL)
#define TIM7_BASEADDR (APB1_BASEADDR + 0x1400UL)
#define TIM8_BASEADDR (APB2_BASEADDR + 0x0400UL)
#define TIM9_BASEADDR (APB2_BASEADDR + 0x4000UL)
#define TIM10_BASEADDR (APB2_BASEADDR + 0x4400UL)
#define TIM11_BASEADDR (APB2_BASEADDR + 0x4800UL)
#define TIM12_BASEADDR (APB1_BASEADDR + 0x1800UL)
#define TIM13_BASEADDR (APB1_BASEADDR + 0x1C00UL)
#define TIM14_BASEADDR (APB1_BASEADDR + 0x2000UL)

#define FLASH_BASEADDR 0x08000000U
#define SRAM1_BASEADDR 0x20000000U
#define SRAM2_BASEADDR 0x2001C000U
#define ROM_BASEADDR   0x1FFF0000U

/*
 * Define base addresses of GPIOs
*/

#define GPIOA_BASEADDR                   (AHB1_BASEADDR + 0x0000UL)
#define GPIOB_BASEADDR                   (AHB1_BASEADDR + 0x0400UL)
#define GPIOC_BASEADDR 					 (AHB1_BASEADDR + 0x0800UL)
#define GPIOD_BASEADDR 					 (AHB1_BASEADDR + 0x0C00UL)
#define GPIOE_BASEADDR 					 (AHB1_BASEADDR + 0x1000UL)
#define GPIOF_BASEADDR 					 (AHB1_BASEADDR + 0x1400UL)
#define GPIOG_BASEADDR 					 (AHB1_BASEADDR + 0x1800UL)
#define GPIOH_BASEADDR 					 (AHB1_BASEADDR + 0x1C00UL)
#define GPIOI_BASEADDR 					 (AHB1_BASEADDR + 0x2000UL)

/*
 * Define base addresses of clocks
*/
#define RCC_BASEADDR 					 (AHB1_BASEADDR + 0x3800UL)

/*
 * Define base addresses of Communication interfaces
*/

#define I2C1_BASEADDR 					 (APB1_BASEADDR + 0x5400UL)
#define I2C2_BASEADDR 					 (APB1_BASEADDR + 0x5800UL)
#define I2C3_BASEADDR 					 (APB1_BASEADDR + 0x5C00UL)  

#define SPI1_BASEADDR 					 (APB2_BASEADDR + 0x3000UL)
#define SPI2_BASEADDR 					 (APB1_BASEADDR + 0x3800UL)
#define SPI3_BASEADDR 					 (APB1_BASEADDR + 0x3C00UL)

#define USART1_BASEADDR 				 (APB2_BASEADDR + 0x1000UL)
#define USART2_BASEADDR 				 (APB1_BASEADDR + 0x4400UL)
#define USART3_BASEADDR 				 (APB1_BASEADDR + 0x4800UL)
#define UART4_BASEADDR 				     (APB1_BASEADDR + 0x4C00UL)
#define UART5_BASEADDR 				     (APB1_BASEADDR + 0x5000UL)
#define USART6_BASEADDR 				 (APB2_BASEADDR + 0x1400UL)

/*
 * Define base addresses of Communication interfaces
*/
/*
 * Revision history 
    * 19-May-2026: Initial version
*/