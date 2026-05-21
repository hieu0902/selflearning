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

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */
typedef enum
{   
    /******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
    NonMaskableInt_IRQn        = -14,    /*!< 2 Non Maskable Interrupt                             */
    MemoryManagement_IRQn      = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt              */
    BusFault_IRQn              = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                    */
    UsageFault_IRQn            = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                  */
    SVCall_IRQn                = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                     */
    DebugMonitor_IRQn          = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                 */
    PendSV_IRQn                = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                 */         
    SysTick_IRQn               = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                 */
    /******  STM32 specific Interrupt Numbers **********************************************************************/
    WWDG_IRQn                  = 0,      /*!< Window WatchDog Interrupt                         */
    PVD_IRQn                   = 1,      /*!< PVD through EXTI Line detection Interrupt          */
    TAMP_STAMP_IRQn            = 2,      /*!< Tamper and TimeStamp interrupts                     */
    RTC_WKUP_IRQn              = 3,      /*!< RTC Wakeup interrupt through EXTI line 20 Interrupt */
    FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
    RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
    EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
    EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
    EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                              */
    EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
    EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
    DMA1_Stream0_IRQn           = 11,     /*!< DMA1 Stream 0 global Interrupt                                    */
    DMA1_Stream1_IRQn           = 12,     /*!< DMA1 Stream 1 global Interrupt                                    */
    DMA1_Stream2_IRQn           = 13,     /*!< DMA1 Stream 2 global Interrupt                                    */
    DMA1_Stream3_IRQn           = 14,     /*!< DMA1 Stream 3 global Interrupt                                    */
    DMA1_Stream4_IRQn           = 15,     /*!< DMA1 Stream 4 global Interrupt                                    */
    DMA1_Stream5_IRQn           = 16,     /*!< DMA1 Stream 5 global Interrupt                                    */
    DMA1_Stream6_IRQn           = 17,     /*!< DMA1 Stream 6 global Interrupt                                    */
    ADC_IRQn                    = 18,     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
    CAN1_TX_IRQn                = 19,     /*!< CAN1 TX Interrupt                                                 */
    CAN1_RX0_IRQn               = 20,     /*!< CAN1 RX0 Interrupt                                                */
    CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                                */
    CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                                */
    EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
    TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
    TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
    TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
    TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
    TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                             */
    TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                             */
    TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                             */
    I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                              */
    I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                              */
    I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                              */
    I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                              */
    SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                             */
    SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                             */
    USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                           */
    USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                           */
    USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                           */
    EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
    RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
    OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
    TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
    TIM8_UP_TIM13_IRQn          = 44,     /*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
    TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
    TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare global interrupt                             */
    DMA1_Stream7_IRQn           = 47,     /*!< DMA1 Stream7 Interrupt                                            */
    FSMC_IRQn                   = 48,     /*!< FSMC global Interrupt                                             */
    SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                             */
    TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                             */
    SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
    UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                                            */
    UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                                            */
    TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
    TIM7_IRQn                   = 55,     /*!< TIM7 global interrupt                                             */
    DMA2_Stream0_IRQn           = 56,     /*!< DMA2 Stream 0 global Interrupt                                    */
    DMA2_Stream1_IRQn           = 57,     /*!< DMA2 Stream 1 global Interrupt                                    */
    DMA2_Stream2_IRQn           = 58,     /*!< DMA2 Stream 2 global Interrupt                                    */
    DMA2_Stream3_IRQn           = 59,     /*!< DMA2 Stream 3 global Interrupt                                    */
    DMA2_Stream4_IRQn           = 60,     /*!< DMA2 Stream 4 global Interrupt                                    */
    ETH_IRQn                    = 61,     /*!< Ethernet global Interrupt                                         */
    ETH_WKUP_IRQn               = 62,     /*!< Ethernet Wakeup through EXTI line Interrupt                       */
    CAN2_TX_IRQn                = 63,     /*!< CAN2 TX Interrupt                                                 */
    CAN2_RX0_IRQn               = 64,     /*!< CAN2 RX0 Interrupt                                                */
    CAN2_RX1_IRQn               = 65,     /*!< CAN2 RX1 Interrupt                                                */
    CAN2_SCE_IRQn               = 66,     /*!< CAN2 SCE Interrupt                                                */
    OTG_FS_IRQn                 = 67,     /*!< USB OTG FS global Interrupt                                       */
    DMA2_Stream5_IRQn           = 68,     /*!< DMA2 Stream 5 global interrupt                                    */
    DMA2_Stream6_IRQn           = 69,     /*!< DMA2 Stream 6 global interrupt                                    */
    DMA2_Stream7_IRQn           = 70,     /*!< DMA2 Stream 7 global interrupt                                    */
    USART6_IRQn                 = 71,     /*!< USART6 global interrupt                                           */
    I2C3_EV_IRQn                = 72,     /*!< I2C3 event interrupt                                              */
    I2C3_ER_IRQn                = 73,     /*!< I2C3 error interrupt                                              */
    OTG_HS_EP1_OUT_IRQn         = 74,     /*!< USB OTG HS End Point 1 Out global interrupt                       */
    OTG_HS_EP1_IN_IRQn          = 75,     /*!< USB OTG HS End Point 1 In global interrupt                        */
    OTG_HS_WKUP_IRQn            = 76,     /*!< USB OTG HS Wakeup through EXTI interrupt                          */
    OTG_HS_IRQn                 = 77,     /*!< USB OTG HS global interrupt                                       */
    DCMI_IRQn                   = 78,     /*!< DCMI global interrupt                                             */
    RNG_IRQn                    = 80,     /*!< RNG global Interrupt                                              */
    FPU_IRQn                    = 81      /*!< FPU global interrupt                                              */
} IRQn_Type;
/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief GPIO
  */  
typedef struct
{
    __vo uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
    __vo uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
    __vo uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
    __vo uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    __vo uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
    __vo uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
    __vo uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
    __vo uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
    __vo uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */        
} GPIO_RegDef_t;
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
 * APB1 bus peripherals
*/

#define TIM2_BASEADDR         (APB1_BASEADDR + 0x0000UL)
#define TIM3_BASEADDR         (APB1_BASEADDR + 0x0400UL)
#define TIM4_BASEADDR         (APB1_BASEADDR + 0x0800UL)
#define TIM5_BASEADDR         (APB1_BASEADDR + 0x0C00UL)
#define TIM6_BASEADDR         (APB1_BASEADDR + 0x1000UL)
#define TIM7_BASEADDR         (APB1_BASEADDR + 0x1400UL)
#define TIM12_BASEADDR        (APB1_BASEADDR + 0x1800UL)
#define TIM13_BASEADDR        (APB1_BASEADDR + 0x1C00UL)
#define TIM14_BASEADDR        (APB1_BASEADDR + 0x2000UL)
#define RTC_BASEADDR          (APB1_BASEADDR + 0x2800UL)
#define WWDG_BASEADDR         (APB1_BASEADDR + 0x2C00UL)
#define IWDG_BASEADDR         (APB1_BASEADDR + 0x3000UL)
#define I2S2ext_BASEADDR      (APB1_BASEADDR + 0x3400UL)
#define SPI2_BASEADDR         (APB1_BASEADDR + 0x3800UL)
#define SPI3_BASEADDR         (APB1_BASEADDR + 0x3C00UL)
#define I2S3ext_BASEADDR      (APB1_BASEADDR + 0x4000UL)
#define USART2_BASEADDR       (APB1_BASEADDR + 0x4400UL)
#define USART3_BASEADDR       (APB1_BASEADDR + 0x4800UL)
#define UART4_BASEADDR        (APB1_BASEADDR + 0x4C00UL)
#define UART5_BASEADDR        (APB1_BASEADDR + 0x5000UL)
#define I2C1_BASEADDR         (APB1_BASEADDR + 0x5400UL)
#define I2C2_BASEADDR         (APB1_BASEADDR + 0x5800UL)
#define I2C3_BASEADDR         (APB1_BASEADDR + 0x5C00UL)
#define CAN1_BASEADDR         (APB1_BASEADDR + 0x6400UL)
#define CAN2_BASEADDR         (APB1_BASEADDR + 0x6800UL)
#define PWR_BASEADDR          (APB1_BASEADDR + 0x7000UL)
#define DAC_BASEADDR          (APB1_BASEADDR + 0x7400UL)


#define FLASH_BASEADDR 0x08000000U
#define SRAM1_BASEADDR 0x20000000U
#define SRAM2_BASEADDR 0x2001C000U
#define ROM_BASEADDR   0x1FFF0000U

/*
 * APB2 bus peripherals
*/

#define TIM1_BASEADDR         (APB2_BASEADDR + 0x0000UL)
#define TIM8_BASEADDR         (APB2_BASEADDR + 0x0400UL)
#define USART1_BASEADDR       (APB2_BASEADDR + 0x1000UL)
#define USART6_BASEADDR       (APB2_BASEADDR + 0x1400UL)
#define ADC1_BASEADDR         (APB2_BASEADDR + 0x2000UL)
#define ADC2_BASEADDR         (APB2_BASEADDR + 0x2100UL)
#define ADC3_BASEADDR         (APB2_BASEADDR + 0x2200UL)
#define SDIO_BASEADDR         (APB2_BASEADDR + 0x2C00UL)
#define SPI1_BASEADDR         (APB2_BASEADDR + 0x3000UL)
#define SPI4_BASEADDR         (APB2_BASEADDR + 0x3400UL)
#define SYSCFG_BASEADDR       (APB2_BASEADDR + 0x3800UL)
#define EXTI_BASEADDR         (APB2_BASEADDR + 0x3C00UL)
#define TIM9_BASEADDR         (APB2_BASEADDR + 0x4000UL)
#define TIM10_BASEADDR        (APB2_BASEADDR + 0x4400UL)
#define TIM11_BASEADDR        (APB2_BASEADDR + 0x4800UL)
#define SPI5_BASEADDR         (APB2_BASEADDR + 0x5000UL)
#define SPI6_BASEADDR         (APB2_BASEADDR + 0x5400UL)
#define SAI1_BASEADDR         (APB2_BASEADDR + 0x5800UL)
#define LCD_BASEADDR          (APB2_BASEADDR + 0x6800UL)

/*
 * AHB1 bus peripherals
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
#define GPIOJ_BASEADDR 					 (AHB1_BASEADDR + 0x2400UL)
#define GPIOK_BASEADDR 					 (AHB1_BASEADDR + 0x2800UL)
#define CRC_BASEADDR 					 (AHB1_BASEADDR + 0x3000UL)
#define RCC_BASEADDR 					 (AHB1_BASEADDR + 0x3800UL)
#define FLASH_INTERFACE_BASEADDR 		 (AHB1_BASEADDR + 0x3C00UL)
#define BKPSRAM_BASEADDR 				 (AHB1_BASEADDR + 0x4000UL)
#define DMA1_BASEADDR 					 (AHB1_BASEADDR + 0x6000UL)
#define DMA2_BASEADDR 					 (AHB1_BASEADDR + 0x6400UL)
#define ETH_BASEADDR 					 (AHB1_BASEADDR + 0x8000UL) 
#define DMA2D_BASEADDR 					 (AHB1_BASEADDR + 0xB000UL)
#define USB_OTG_HS_BASEADDR 			 (AHB1_BASEADDR + 0x20000UL)


/*
 * AHB2 bus peripherals
*/

#define USB_OTG_FS_BASEADDR 			 (AHB2_BASEADDR + 0x0000UL)
#define DCMI_BASEADDR 					 (AHB2_BASEADDR + 0x50000UL)
#define CRYP_BASEADDR 					 (AHB2_BASEADDR + 0x60000UL)
#define HASH_BASEADDR 					 (AHB2_BASEADDR + 0x60400UL)    
#define RNG_BASEADDR 					 (AHB2_BASEADDR + 0x60800UL)

/*
 * AHB3 bus peripherals
*/

#define FMC_BASEADDR 					 (AHB3_BASEADDR + 0x0000UL)


/*
 * Revision history 
    * 19-May-2026: Initial version
*/