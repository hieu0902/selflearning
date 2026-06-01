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
} GPIO_PinConfig_t;

/* Pin state */

typedef enum
{
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET
} GPIO_PinState_t;

/* GPIO pin handle structure */
typedef struct
{
    GPIO_RegDef_t *pGPIOx;
    GPIO_PinConfig_t GPIO_PinConfig;
} GPIO_Handle_t;

/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_0      0
#define GPIO_PIN_1      1
#define GPIO_PIN_2      2
#define GPIO_PIN_3      3
#define GPIO_PIN_4      4
#define GPIO_PIN_5      5
#define GPIO_PIN_6      6
#define GPIO_PIN_7      7
#define GPIO_PIN_8      8
#define GPIO_PIN_9      9
#define GPIO_PIN_10     10
#define GPIO_PIN_11     11
#define GPIO_PIN_12     12
#define GPIO_PIN_13     13
#define GPIO_PIN_14     14
#define GPIO_PIN_15     15

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
#define GPIO_OP_TYPE_PP              0x00000000U
#define GPIO_OP_TYPE_OD              0x00000001U

/*
 * @GPIO_PIN_SPEED
 * GPIO pin output speeds
 */
#define GPIO_SPEED_LOW               0x00000000U
#define GPIO_SPEED_MEDIUM            0x00000001U
#define GPIO_SPEED_FAST              0x00000002U
#define GPIO_SPEED_HIGH              0x00000003U

/*
 * @GPIO_PIN_PUPD
 * GPIO pin pull-up/pull-down configurations
 */
#define GPIO_PUPD_NO                 0x00000000U
#define GPIO_PUPD_UP                 0x00000001U
#define GPIO_PUPD_DOWN               0x00000002U

/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/

/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and De-init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
/*
 * Revision history 
    * 17-Apr-2024: Initial version
*/

#endif /* STM32F407XX_GPIO_DRIVER_H */