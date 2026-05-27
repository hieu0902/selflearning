/*
 * stm32f407xx.h
 *
 *  Created on: 19-May-2026
 *      Author: @hieu0902
 */
#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_


#include <stdint.h>
#include <stddef.h>
#include "stm32f407xx_gpio_driver.h"
#include "stm32f407xx_spi_driver.h"
#include "stm32f407xx_i2c_driver.h"
#include "stm32f407xx_usart_driver.h"

#define __vo volatile
#define __weak __attribute__((weak))

/**  
  * Peripheral_interrupt_number_definition
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
/**  
  *  Peripheral_registers_structures
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

/**
  * @brief SPI
  */

typedef struct
{
   __vo uint32_t CR1;       /* SPI control register 1,               Address offset: 0x00      */
   __vo uint32_t CR2;       /* SPI control register 2,               Address offset: 0x04      */
   __vo uint32_t SR;        /* SPI status register,                  Address offset: 0x08      */
   __vo uint32_t DR;        /* SPI data register,                    Address offset: 0x0C      */
   __vo uint32_t CRCPR;     /* SPI CRC polynomial register,          Address offset: 0x10      */
   __vo uint32_t RXCRCR;    /* SPI RX CRC register,                  Address offset: 0x14      */
   __vo uint32_t TXCRCR;    /* SPI TX CRC register,                  Address offset: 0x18      */
   __vo uint32_t I2SCFGR;   /* SPI_I2S configuration register,       Address offset: 0x1C      */
   __vo uint32_t I2SPR;     /* SPI_I2S prescaler register,           Address offset: 0x20      */
} SPI_RegDef_t;
/**
  * @brief I2C
  */

typedef struct
{
    __vo uint32_t CR1;       /* I2C control register 1,               Address offset: 0x00      */
    __vo uint32_t CR2;       /* I2C control register 2,               Address offset: 0x04      */
    __vo uint32_t OAR1;      /* I2C own address register 1,           Address offset: 0x08      */
    __vo uint32_t OAR2;      /* I2C own address register 2,           Address offset: 0x0C      */
    __vo uint32_t DR;        /* I2C data register,                    Address offset: 0x10      */
    __vo uint32_t SR1;       /* I2C status register 1,                Address offset: 0x14      */
    __vo uint32_t SR2;       /* I2C status register 2,                Address offset: 0x18      */
    __vo uint32_t CCR;       /* I2C clock control register,           Address offset: 0x1C      */
    __vo uint32_t TRISE;     /* I2C TRISE register,                   Address offset: 0x20      */
} I2C_RegDef_t;
/**
  * @brief USART
  */
typedef struct
{
    __vo uint32_t SR;        /* USART Status register,                Address offset: 0x00      */
    __vo uint32_t DR;        /* USART Data register,                  Address offset: 0x04      */
    __vo uint32_t BRR;       /* USART Baud rate register,             Address offset: 0x08      */
    __vo uint32_t CR1;       /* USART Control register 1,             Address offset: 0x0C      */
    __vo uint32_t CR2;       /* USART Control register 2,             Address offset: 0x10      */
    __vo uint32_t CR3;       /* USART Control register 3,             Address offset: 0x14      */
    __vo uint32_t GTPR;      /* USART Guard time and prescaler register, Address offset: 0x18   */
} USART_RegDef_t;

/**
  * @brief RCC
  */

typedef struct
{
    __vo uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
    __vo uint32_t PLLCFGR;       /*!< RCC PLL configuratvon register,                              Address offset: 0x04 */
    __vo uint32_t CFGR;          /*!< RCC clock configuratvon register,                            Address offset: 0x08 */
    __vo uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
    __vo uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
    __vo uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
    __vo uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
    uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
    __vo uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
    __vo uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
    uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
    __vo uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
    __vo uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
    __vo uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
    uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
    __vo uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
    __vo uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
    uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
    __vo uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
    __vo uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
    __vo uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
    uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
    __vo uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
    __vo uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
    uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
    __vo uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
    __vo uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
    uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
    __vo uint32_t SSCGR;         /*!< RCC spread spectrum clock generatvon register,               Address offset: 0x80 */
    __vo uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
} RCC_RegDef_t;

/**
  * @brief SYSCFG
  */

typedef struct
{
    __vo uint32_t MEMRMP;    /* SYSCFG memory remap register,         Address offset: 0x00      */
    __vo uint32_t PMC;       /* SYSCFG peripheral mode configuration register, Address offset: 0x04 */
    __vo uint32_t EXTICR[4]; /* SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
    uint32_t RESERVED[2];   /* Reserved, 0x18-0x1C */
    __vo uint32_t CMPCR;     /* SYSCFG Compensation cell control register, Address offset: 0x20      */
} SYSCFG_RegDef_t;

/**
  * @brief EXTI
  */
typedef struct
{
    __vo uint32_t IMR;       /* EXTI Interrupt mask register,         Address offset: 0x00      */
    __vo uint32_t EMR;       /* EXTI Event mask register,             Address offset: 0x04      */
    __vo uint32_t RTSR;      /* EXTI Rising trigger selection register, Address offset: 0x08      */
    __vo uint32_t FTSR;      /* EXTI Falling trigger selection register, Address offset: 0x0C      */
    __vo uint32_t SWIER;     /* EXTI Software interrupt event register, Address offset: 0x10      */
    __vo uint32_t PR;        /* EXTI Pending register,                Address offset: 0x14      */
} EXTI_RegDef_t;
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
#define SRAM 		       SRAM1_BASEADDR

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


/*
 * AHB1 bus peripherals
*/
#define GPIOA_BASEADDR               (AHB1_BASEADDR + 0x0000UL)
#define GPIOB_BASEADDR               (AHB1_BASEADDR + 0x0400UL)
#define GPIOC_BASEADDR 					     (AHB1_BASEADDR + 0x0800UL)
#define GPIOD_BASEADDR 					     (AHB1_BASEADDR + 0x0C00UL)
#define GPIOE_BASEADDR 					     (AHB1_BASEADDR + 0x1000UL)
#define GPIOF_BASEADDR 					     (AHB1_BASEADDR + 0x1400UL)
#define GPIOG_BASEADDR 					     (AHB1_BASEADDR + 0x1800UL)
#define GPIOH_BASEADDR 					     (AHB1_BASEADDR + 0x1C00UL)
#define GPIOI_BASEADDR 					     (AHB1_BASEADDR + 0x2000UL)
#define CRC_BASEADDR 					       (AHB1_BASEADDR + 0x3000UL)
#define RCC_BASEADDR 					       (AHB1_BASEADDR + 0x3800UL)
#define FLASH_INTERFACE_BASEADDR 		 (AHB1_BASEADDR + 0x3C00UL)
#define BKPSRAM_BASEADDR 				     (AHB1_BASEADDR + 0x4000UL)
#define DMA1_BASEADDR 					     (AHB1_BASEADDR + 0x6000UL)
#define DMA2_BASEADDR 					     (AHB1_BASEADDR + 0x6400UL)
#define ETH_BASEADDR 					       (AHB1_BASEADDR + 0x8000UL) 



/*
 * AHB2 bus peripherals
*/

#define USB_OTG_FS_BASEADDR 			 (AHB2_BASEADDR + 0x0000UL)
#define DCMI_BASEADDR 					   (AHB2_BASEADDR + 0x50000UL)   
#define RNG_BASEADDR 					     (AHB2_BASEADDR + 0x60800UL)

/*
 * AHB3 bus peripherals
*/

#define FMC_BASEADDR 					     (AHB3_BASEADDR + 0x0000UL)

/*
 * Peripheral definitions (Peripheral base addresses typecasted to xxx_RegDef_t)
*/

#define GPIOA               ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB               ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC               ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD               ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE               ((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF               ((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG               ((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define GPIOH               ((GPIO_RegDef_t *)GPIOH_BASEADDR)
#define GPIOI               ((GPIO_RegDef_t *)GPIOI_BASEADDR)

#define RCC                 ((RCC_RegDef_t *)RCC_BASEADDR)
#define EXTI                ((EXTI_RegDef_t *)EXTI_BASEADDR)
#define SYSCFG              ((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)

#define SPI1                ((SPI_RegDef_t *)SPI1_BASEADDR)
#define SPI2                ((SPI_RegDef_t *)SPI2_BASEADDR)
#define SPI3                ((SPI_RegDef_t *)SPI3_BASEADDR)

#define I2C1                ((I2C_RegDef_t *)I2C1_BASEADDR)
#define I2C2                ((I2C_RegDef_t *)I2C2_BASEADDR)
#define I2C3                ((I2C_RegDef_t *)I2C3_BASEADDR)

#define USART1              ((USART_RegDef_t *)USART1_BASEADDR)
#define USART2              ((USART_RegDef_t *)USART2_BASEADDR)
#define USART3              ((USART_RegDef_t *)USART3_BASEADDR) 
#define UART4               ((USART_RegDef_t *)UART4_BASEADDR)
#define UART5               ((USART_RegDef_t *)UART5_BASEADDR)
#define USART6              ((USART_RegDef_t *)USART6_BASEADDR)

/*
 * Clock Enable Macros for GPIOx peripherals
*/
#define GPIOA_PCLK_EN()    (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()    (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()    (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()    (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()    (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()    (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()    (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()    (RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()    (RCC->AHB1ENR |= (1 << 8))
#define GPIOJ_PCLK_EN()    (RCC->AHB1ENR |= (1 << 9))
#define GPIOK_PCLK_EN()    (RCC->AHB1ENR |= (1 << 10))

/*
 * Clock Enable Macros for I2Cx peripherals
*/
 
#define I2C1_PCLK_EN()     (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()     (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()     (RCC->APB1ENR |= (1 << 23))


/*
 * Clock Enable Macros for SPIx peripherals
*/
 
#define SPI1_PCLK_EN()     (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()     (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()     (RCC->APB1ENR |= (1 << 15))

/*
 * Clock Enable Macros for UART peripherals
*/

#define USART1_PCLK_EN()   (RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()   (RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()   (RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN()    (RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN()    (RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN()   (RCC->APB2ENR |= (1 << 5))

/*
 * Clock Enable Macros for SYSCFG peripherals
*/

#define SYSCFG_PCLK_EN()   (RCC->APB2ENR |= (1 << 14))

/*
 * Clock Disable Macros for GPIOx peripherals
*/
#define GPIOA_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 8))

/*
 * Clock Disable Macros for I2Cx peripherals
*/
#define I2C1_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 23))

/*
 * Clock Disable Macros for SPIx peripherals
*/
#define SPI1_PCLK_DI()     (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 15))

/*
 * Clock Disable Macros for UART peripherals
*/

#define USART1_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DI()    (RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DI()    (RCC->APB1ENR &= ~(1 << 20))
#define USART6_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 5))

/*
 * Clock Disable Macros for SYSCFG peripherals
*/
#define SYSCFG_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 14))

/*
 * Macros to reset GPIOx peripherals
*/

/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                  GPIO                                      */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for GPIO_MODER register  ********************/
/********************  Bit definition for GPIO_OTYPER register  ********************/
/********************  Bit definition for GPIO_OSPEEDR register  ********************/
/********************  Bit definition for GPIO_PUPDR register  ********************/
/********************  Bit definition for GPIO_IDR register  ********************/
/********************  Bit definition for GPIO_ODR register  ********************/
/********************  Bit definition for GPIO_BSRR register  ********************/
/********************  Bit definition for GPIO_LCKR register  ********************/
/********************  Bit definition for GPIO_AFRL register  ********************/
/********************  Bit definition for GPIO_AFRH register  ********************/

/******************************************************************************/
/*                                                                            */
/*                                  SPI                                       */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for SPI_CR1 register  ********************/
/********************  Bit definition for SPI_CR2 register  ********************/
/********************  Bit definition for SPI_SR register  ********************/
/********************  Bit definition for SPI_DR register  ********************/
/********************  Bit definition for SPI_CRCPR register  ********************/
/********************  Bit definition for SPI_RXCRCR register  ********************/
/********************  Bit definition for SPI_TXCRCR register  ********************/
/********************  Bit definition for SPI_I2SCFGR register  ********************/
/********************  Bit definition for SPI_I2SPR register  ********************/

/******************************************************************************/
/*                                                                            */
/*                                  I2C                                       */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for I2C_CR1 register  ********************/
/********************  Bit definition for I2C_CR2 register  ********************/
/********************  Bit definition for I2C_OAR1 register  ********************/
/********************  Bit definition for I2C_OAR2 register  ********************/
/********************  Bit definition for I2C_DR register  **** ****************/
/********************  Bit definition for I2C_SR1 register  ********************/
/********************  Bit definition for I2C_SR2 register  ********************/
/********************  Bit definition for I2C_CCR register  ********************/
/********************  Bit definition for I2C_TRISE register  ********************/

/******************************************************************************/
/*                                                                            */
/*                                  USART                                     */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for USART_SR register  ********************/
/********************  Bit definition for USART_DR register  ********************/
/********************  Bit definition for USART_BRR register  ********************/
/********************  Bit definition for USART_CR1 register  ********************/
/********************  Bit definition for USART_CR2 register  ********************/
/********************  Bit definition for USART_CR3 register  ********************/
/********************  Bit definition for USART_GTPR register  ********************/

/******************************************************************************/
/*                         Exported Macros                                    */
/******************************************************************************/

/******************************* GPIO Instances *******************************/
/******************************* SPI Instances *******************************/
/******************************* I2C Instances *******************************/
/******************************* USART Instances *******************************/



/*
 * Revision history 
    * 19-May-2026: Initial version
*/