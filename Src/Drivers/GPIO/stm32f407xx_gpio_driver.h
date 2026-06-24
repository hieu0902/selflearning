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
    uint32_t GPIO_PinNumber;
    uint32_t GPIO_PinMode;
    uint32_t GPIO_PinPuPdControl;
    uint32_t GPIO_PinOSpeed;
    uint32_t GPIO_PinAltFunMode;
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
#define GPIO_MODE_INPUT              MODE_INPUT
#define GPIO_MODE_OUTPUT_PP          (MODE_OUTPUT | OTYPE_PP)
#define GPIO_MODE_OUTPUT_OD          (MODE_OUTPUT | OTYPE_OD)
#define GPIO_MODE_AF_PP              (MODE_ALTFN | OTYPE_PP)
#define GPIO_MODE_AF_OD              (MODE_ALTFN | OTYPE_OD)

#define GPIO_MODE_ANALOG             MODE_ANALOG

#define GPIO_MODE_IT_RISING          (MODE_INPUT | EXTI_IT | TRIGGER_RISING)
#define GPIO_MODE_IT_FALLING         (MODE_INPUT | EXTI_IT | TRIGGER_FALLING)
#define GPIO_MODE_IT_BOTH            (MODE_INPUT | EXTI_IT | TRIGGER_BOTH)

#define GPIO_MODE_EVT_RISING         (MODE_INPUT | EXTI_EVT | TRIGGER_RISING)
#define GPIO_MODE_EVT_FALLING        (MODE_INPUT | EXTI_EVT | TRIGGER_FALLING)
#define GPIO_MODE_EVT_BOTH           (MODE_INPUT | EXTI_EVT | TRIGGER_BOTH)

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
 * GPIO pin pull-up/pull-down
 */
#define GPIO_PUPD_NO                 (0x00000000U)
#define GPIO_PUPD_UP                 (0x00000001U)
#define GPIO_PUPD_DOWN               (0x00000002U)

/* GPIO Private Constants  */

#define MODE_Pos                (0U)
#define MODE_Msk                (0x3UL << MODE_Pos)
#define MODE_INPUT              (0x0UL << MODE_Pos)
#define MODE_OUTPUT             (0x1UL << MODE_Pos)
#define MODE_ALTFN              (0x2UL << MODE_Pos)
#define MODE_ANALOG             (0x3UL << MODE_Pos)

#define OTYPE_Pos               (4U)
#define OTYPE_Msk               (0x1UL << OTYPE_Pos)
#define OTYPE_PP                (0x0UL << OTYPE_Pos)
#define OTYPE_OD                (0x1UL << OTYPE_Pos)

#define EXTI_MODE_Pos           (16U)
#define EXTI_MODE               (0x3UL << EXTI_MODE_Pos)
#define EXTI_IT                 (0x1UL << EXTI_MODE_Pos)
#define EXTI_EVT                (0x2UL << EXTI_MODE_Pos)

#define TRIGGER_Pos             (20U)
#define TRIGGER_Msk             (0x3UL << TRIGGER_Pos)
#define TRIGGER_RISING          (0x1UL << TRIGGER_Pos)
#define TRIGGER_FALLING         (0x2UL << TRIGGER_Pos)
#define TRIGGER_BOTH            (0x3UL << TRIGGER_Pos)
/*
 * GPIO Private Macros
 */

#define IS_GPIO_PIN_ACTION(ACTION) (((ACTION) == (GPIO_PIN_SET)) || ((ACTION) == (GPIO_PIN_RESET)))
#define IS_GPIO_PIN(PIN) (((((uint32_t)PIN) & GPIO_PIN_MASK) != 0x00U) && ((((uint32_t)PIN) & ~GPIO_PIN_MASK) == 0x00U))
#define IS_GPIO_MODE(MODE) ((MODE == GPIO_MODE_INPUT)   || \
                            (MODE == GPIO_MODE_OUTPUT_PP)  || \
                            (MODE == GPIO_MODE_OUTPUT_OD)  || \
                            (MODE == GPIO_MODE_AF_PP)   || \
                            (MODE == GPIO_MODE_AF_OD)   || \
                            (MODE == GPIO_MODE_ANALOG)  || \
                            (MODE == GPIO_MODE_IT_FALLING)   || \
                            (MODE == GPIO_MODE_IT_RISING)   || \
                            (MODE == GPIO_MODE_IT_BOTH)   || \
                            (MODE == GPIO_MODE_EVT_FALLING)   || \
                            (MODE == GPIO_MODE_EVT_RISING)   || \
                            (MODE == GPIO_MODE_EVT_BOTH))
#define IS_GPIO_OP_TYPE(TYPE) ((TYPE) == GPIO_OP_TYPE_PP || (TYPE) == GPIO_OP_TYPE_OD)
#define IS_GPIO_SPEED(SPEED) ((SPEED) == GPIO_SPEED_LOW     || \
                              (SPEED) == GPIO_SPEED_MEDIUM  || \
                              (SPEED) == GPIO_SPEED_FAST    || \
                              (SPEED) == GPIO_SPEED_HIGH)
#define IS_GPIO_PUPD(PUPD) ((PUPD == GPIO_PUPD_NO) || \
                            (PUPD == GPIO_PUPD_UP) || \
                            (PUPD == GPIO_PUPD_DOWN))
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
void NVIC_IRQEnable(IRQ_TypeDef_t IRQNumber);
void NVIC_IRQDisable(IRQ_TypeDef_t IRQNumber);
void NVIC_IRQSetPriority(IRQ_TypeDef_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandler(uint16_t GPIO_Pin);
__weak void GPIO_IRQ_Callback(uint16_t GPIO_Pin);

#endif /* STM32F407XX_GPIO_DRIVER_H */
/*
 * Revision history 
    * 17-Apr-2024: Initial version
*/

