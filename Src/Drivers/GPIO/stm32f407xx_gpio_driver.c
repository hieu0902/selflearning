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
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
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
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

}
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{

}
void GPIO_IRQHandling(uint8_t PinNumber)
{
    
}
/*
 * Revision history 
    * 27-May-2025: Initial version
*/
