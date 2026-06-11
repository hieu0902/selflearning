/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: 17-Apr-2024
 *      Author: HieuNDM
 */
#ifndef STM32F407XX_GPIO_DRIVER_H
#define STM32F407XX_GPIO_DRIVER_H

#include "stm32f407xx.h"

/* GPIO pin configuration structure */
typedef struct 
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_PinPuPdControl;
    uint8_t GPIO_PinOSpeed;
    uint8_t GPIO_PinOPType;
    uint8_t GPIO_PinAltFunMode;
} GPIO_InitTypeDef_t;

/* Pin state */

typedef enum
{
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET
} GPIO_PinState_t;

/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_0      ((uint16_t)0x0001U)
#define GPIO_PIN_1      ((uint16_t)0x0002U)
#define GPIO_PIN_2      ((uint16_t)0x0004U)
#define GPIO_PIN_3      ((uint16_t)0x0008U)
#define GPIO_PIN_4      ((uint16_t)0x0010U)
#define GPIO_PIN_5      ((uint16_t)0x0020U)
#define GPIO_PIN_6      ((uint16_t)0x0040U)
#define GPIO_PIN_7      ((uint16_t)0x0080U)
#define GPIO_PIN_8      ((uint16_t)0x0100U)
#define GPIO_PIN_9      ((uint16_t)0x0200U)
#define GPIO_PIN_10     ((uint16_t)0x0400U)
#define GPIO_PIN_11     ((uint16_t)0x0800U)
#define GPIO_PIN_12     ((uint16_t)0x1000U)
#define GPIO_PIN_13     ((uint16_t)0x2000U)
#define GPIO_PIN_14     ((uint16_t)0x4000U)
#define GPIO_PIN_15     ((uint16_t)0x8000U)
#define GPIO_PIN_ALL    ((uint16_t)0xFFFFU)
#define GPIO_PIN_MASK   0x0000FFFFU

#define GPIO_NUMBER     16U
/*
 * @GPIO_PIN_MODES
 * GPIO pin modes
 */
#define GPIO_MODE_INPUT              0
#define GPIO_MODE_OUTPUT             1
#define GPIO_MODE_ALTFN              2
#define GPIO_MODE_ANALOG             3
#define GPIO_MODE_IT_FT              4
#define GPIO_MODE_IT_RT              5
#define GPIO_MODE_IT_RFT             6

/*
 * @GPIO_PIN_OUTPUT_TYPES
 * GPIO pin output types
 */
#define GPIO_OP_TYPE_PP              (0x00000000U)
#define GPIO_OP_TYPE_OD              (0x00000001U)

/*
 * @GPIO_PIN_SPEED
 * GPIO pin output speeds
 */
#define GPIO_SPEED_LOW               (0x00000000U)
#define GPIO_SPEED_MEDIUM            (0x00000001U)
#define GPIO_SPEED_FAST              (0x00000002U)
#define GPIO_SPEED_HIGH              (0x00000003U)

/*
 * @GPIO_PIN_PUPD
 * GPIO pin pull-up/pull-down configurations
 */
#define GPIO_PUPD_NO                 (0x00000000U)
#define GPIO_PUPD_UP                 (0x00000001U)
#define GPIO_PUPD_DOWN               (0x00000002U)

/* GPIO Private Constants -> for later development */

// #define GPIO_MODE_Pos                (0U)
// #define GPIO_MODE_Msk                (3U << GPIO_MODE_Pos)
// #define GPIO_MODE_INPUT              (0U << GPIO_MODE_Pos)
// #define GPIO_MODE_OUTPUT             (1U << GPIO_MODE_Pos)
// #define GPIO_MODE_ALTFN              (2U << GPIO_MODE_Pos)
// #define GPIO_MODE_ANALOG             (3U << GPIO_MODE_Pos)

// #define GPIO_OTYPE_Pos              (4U)
// #define GPIO_OTYPE_Msk              (1U << GPIO_OTYPE_Pos)
// #define GPIO_OTYPE_PP               (0U << GPIO_OTYPE_Pos)
// #define GPIO_OTYPE_OD               (1U << GPIO_OTYPE_Pos)

// #define GPIO_EXTI_MODE_Pos              (16U)
// #define GPIO_EXTI_MODE_Msk              (7U << GPIO_EXTI_MODE_Pos)

/*
 * GPIO Private Macros
 */

#define IS_GPIO_PIN_ACTION(ACTION) (((ACTION) == (GPIO_PIN_SET)) || ((ACTION) == (GPIO_PIN_RESET)))
#define IS_GPIO_PIN(PIN) (((((uint32_t)PIN) & GPIO_PIN_MASK) != 0x00U) && ((((uint32_t)PIN) & ~GPIO_PIN_MASK) == 0x00U))
#define IS_GPIO_MODE(MODE) ((MODE == GPIO_MODE_INPUT)   || \
                            (MODE == GPIO_MODE_OUTPUT)  || \
                            (MODE == GPIO_MODE_ALTFN)   || \
                            (MODE == GPIO_MODE_ANALOG)  || \
                            (MODE == GPIO_MODE_IT_FT)   || \
                            (MODE == GPIO_MODE_IT_RT)   || \
                            (MODE == GPIO_MODE_IT_RFT))
#define IS_GPIO_OP_TYPE(TYPE) ((TYPE) == GPIO_OP_TYPE_PP || (TYPE) == GPIO_OP_TYPE_OD)
#define IS_GPIO_SPEED(SPEED) ((SPEED) == GPIO_SPEED_LOW     || \
                              (SPEED) == GPIO_SPEED_MEDIUM  || \
                              (SPEED) == GPIO_SPEED_FAST    || \
                              (SPEED) == GPIO_SPEED_HIGH)
#define IS_GPIO_PUPD(PUPD) ((PUPD) == GPIO_PUPD_NO || \
                            (PUPD) == GPIO_PUPD_UP || \
                            (PUPD) == GPIO_PUPD_DOWN)
/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/

 
/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, HAL_ConfigState_t EnorDi);

/*
 * Init and De-init
 */
void GPIO_Init(GPIO_RegDef_t *pGPIOx, GPIO_InitTypeDef_t *InitConfig);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx, uint16_t GPIO_Pin);
void GPIO_Port_Deinit(GPIO_RegDef_t *pGPIOx);
/*
 * Data read and write
 */
GPIO_PinState_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint16_t GPIO_Pin, GPIO_PinState_t PinState);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t PortState);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef_t GPIO_LockPin(GPIO_RegDef_t *pGPIOx, uint16_t GPIO_Pin);
/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQInterruptConfig(IRQ_TypeDef_t IRQNumber, HAL_ConfigState_t EnorDi);
void GPIO_IRQPriorityConfig(IRQ_TypeDef_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);
__weak void GPIO_IRQ_Callback(uint16_t GPIO_Pin);

#endif /* STM32F407XX_GPIO_DRIVER_H */
/*
 * Revision history 
    * 17-Apr-2024: Initial version
*/

