/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: 27-May-2025
 *      Author: @hieu0902
 */
#include "stm32f407xx.h"
#include <stdint.h>
#include "stm32f407xx_gpio_driver.h"

/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, Peripheral_ClockState_t ClockState)
{
    /* Check user input */
    assert_param(IS_GPIO_ALL_INSTANCE(pGPIOx));
    if ( ClockState == CLOCK_ENABLE )
    {
        if (pGPIOx == GPIOA) GPIOA_PCLK_EN();
        else if (pGPIOx == GPIOB) GPIOB_PCLK_EN();
        else if (pGPIOx == GPIOC) GPIOC_PCLK_EN();
        else if (pGPIOx == GPIOD) GPIOD_PCLK_EN();
        else if (pGPIOx == GPIOE) GPIOE_PCLK_EN();
        else if (pGPIOx == GPIOF) GPIOF_PCLK_EN();
        else if (pGPIOx == GPIOG) GPIOG_PCLK_EN();
        else if (pGPIOx == GPIOH) GPIOH_PCLK_EN();
        else if (pGPIOx == GPIOI) GPIOI_PCLK_EN();
    } else {
        if (pGPIOx == GPIOA) GPIOA_PCLK_DI();
        else if (pGPIOx == GPIOB) GPIOB_PCLK_DI();
        else if (pGPIOx == GPIOC) GPIOC_PCLK_DI();
        else if (pGPIOx == GPIOD) GPIOD_PCLK_DI();
        else if (pGPIOx == GPIOE) GPIOE_PCLK_DI();
        else if (pGPIOx == GPIOF) GPIOF_PCLK_DI();
        else if (pGPIOx == GPIOG) GPIOG_PCLK_DI();
        else if (pGPIOx == GPIOH) GPIOH_PCLK_DI();
        else if (pGPIOx == GPIOI) GPIOI_PCLK_DI();
    }
}

/*
 * Init and De-init
 */
void GPIO_Init(GPIO_RegDef_t *pGPIOx, GPIO_PinConfig_t *PinConfig)
{

}
void GPIO_Deinit(GPIO_RegDef_t *pGPIOx, uint16_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_INSTANCE(pGPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

}
void GPIO_Port_Deinit(GPIO_RegDef_t *pGPIOx)
{
    assert_param(IS_GPIO_ALL_INSTANCE(pGPIOx));
    if (pGPIOx == GPIOA) GPIOA_REG_RESET();
    else if (pGPIOx == GPIOB) GPIOB_REG_RESET();
    else if (pGPIOx == GPIOC) GPIOC_REG_RESET();
    else if (pGPIOx == GPIOD) GPIOD_REG_RESET();
    else if (pGPIOx == GPIOE) GPIOE_REG_RESET();
    else if (pGPIOx == GPIOF) GPIOF_REG_RESET();
    else if (pGPIOx == GPIOG) GPIOG_REG_RESET();
    else if (pGPIOx == GPIOH) GPIOH_REG_RESET();
    else if (pGPIOx == GPIOI) GPIOI_REG_RESET();
}

/*
 * Data read and write
 */

GPIO_PinState_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint16_t GPIO_Pin)
{
    GPIO_PinState_t retval;
    /* Check user input */
    assert_param(IS_GPIO_ALL_INSTANCE(pGPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    if ((pGPIOx->IDR & (uint32_t)GPIO_Pin) != ((uint32_t)GPIO_PIN_RESET))
    {
        retval = GPIO_PIN_SET;
    } else {
        retval = GPIO_PIN_RESET;
    }
    return retval;
}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
    uint16_t retval;

    /* Check user input */
    assert_param(IS_GPIO_ALL_INSTANCE(pGPIOx));

    retval = (uint16_t)(pGPIOx->IDR);
    return retval;
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint16_t GPIO_Pin, GPIO_PinState_t PinState)
{
    /* Check user input */
    assert_param(IS_GPIO_ALL_INSTANCE(pGPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));
    assert_param(IS_GPIO_PIN_ACTION(PinState));

    if (PinState == GPIO_PIN_SET)
        pGPIOx->BSRR |= GPIO_Pin;
    else {
        pGPIOx->BSRR |= ((uint32_t)GPIO_Pin << 16U);
    }
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t PortState)
{
    assert_param(IS_GPIO_ALL_INSTANCE(pGPIOx));
    assert_param(IS_GPIO_PIN_ACTION(PortState));

    pGPIOx->ODR = PortState;
}

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint16_t GPIO_Pin)
{
    uint32_t odr;
    /* Check user input */
    assert_param(IS_GPIO_ALL_INSTANCE(pGPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));
    
    odr = pGPIOx->ODR;
    /* Set selected pins that were at low level, and reset ones that were high */
    pGPIOx->BSRR = ((odr & GPIO_Pin) << GPIO_NUMBER) | (~odr & GPIO_Pin);
}

HAL_StatusTypeDef_t GPIO_LockPin(GPIO_RegDef_t *pGPIOx, uint16_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_INSTANCE(pGPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    HAL_StatusTypeDef_t retval;
    uint16_t tmp = GPIO_LCKR_LCKK | GPIO_Pin;
    pGPIOx->LCKR |= tmp;
    pGPIOx->LCKR |= GPIO_Pin;
    pGPIOx->LCKR |= tmp;
    if ( pGPIOx->LCKR & GPIO_LCKR_LCKK ){
        retval = HAL_OK;
    } else {
        retval = HAL_ERROR;
    }
    return retval;
}
/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQInterruptConfig(IRQ_TypeDef_t IRQNumber, HAL_ConfigState_t EnorDi)
{
    if ( EnorDi == ENABLE)
    {
        if (IRQNumber < 32) {
            /* ISER0 */
            NVIC->ISER[0] |= (1U << IRQNumber);
        } else if (IRQNumber < 64) {
            /* ISER1 */
            NVIC->ISER[1] |= (1U << (IRQNumber % 32U));
        } else if (IRQNumber < 96) {
            /* ISER2 */
            NVIC->ISER[2] |= (1U << (IRQNumber % 64U));
        }
    } else {
        if (IRQNumber < 32) {
            /* ICER0 */
            NVIC->ICER[0] |= (1U << IRQNumber);
        } else if (IRQNumber < 64) {
            /* ICER1 */
            NVIC->ICER[1] |= (1U << (IRQNumber % 32U));
        } else if (IRQNumber < 96) {
            /* ICER2 */
            NVIC->ICER[2] |= (1U << (IRQNumber % 64U));
        }
    }
}
void GPIO_IRQPriorityConfig(IRQ_TypeDef_t IRQNumber, uint32_t IRQPriority)
{

}
void GPIO_IRQHandler(uint16_t GPIO_Pin)
{
    if(EXTI->PR & ( 1 << GPIO_Pin))
	{
        /* Clear the EXTI line pending bit */
		EXTI->PR |= ( 1 << GPIO_Pin);
        /* Call the callback function to handle the interrupt */
        GPIO_IRQ_Callback(GPIO_Pin);
	}
}

__weak GPIO_IRQ_Callback(uint16_t GPIO_Pin)
{
    /* This is a weak implementation. The user application may override this function. */
}
/*
 * Revision history 
    * 27-May-2025: Initial version
*/
