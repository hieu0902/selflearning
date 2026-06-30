/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: 27-May-2025
 *      Author: @hieu0902
 */
#include "stm32f407xx.h"
#include <stdint.h>
#include "stm32f407xx_gpio_driver.h"


#define GPIO_NUMBER 16U

#define NO_PR_BITS_IMPLEMENTED  4
/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, HAL_State_t ClockState)
{
    /* Check user input */
    assert_param(IS_GPIO_ALL_INSTANCE(pGPIOx));
    if ( ClockState == ENABLE )
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
void GPIO_Init(GPIO_RegDef_t *pGPIOx, GPIO_InitTypeDef_t *InitConfig)
{
    uint32_t position;
    uint32_t temp = 0x00U;
    uint32_t iocurrent = 0x00;
    uint32_t ioposition = 0x00;

    /* Check user input */
    assert_param(IS_GPIO_ALL_INSTANCE(pGPIOx));
    assert_param(IS_GPIO_PIN(InitConfig->GPIO_PinNumber));
    assert_param(IS_GPIO_MODE(InitConfig->GPIO_PinMode));

    for (position = 0U; position < GPIO_NUMBER; position++)
    {
        ioposition = 0x01 << position;
        iocurrent = InitConfig->GPIO_PinNumber & ioposition;
        if (iocurrent == ioposition){

            /*--------------------- GPIO Mode Configuration ------------------------*/
            if ((InitConfig->GPIO_PinMode & MODE_Msk) == MODE_OUTPUT || \
                (InitConfig->GPIO_PinMode & MODE_Msk) == MODE_ALTFN)
            {
                /* Set Output Speed for Output and Alternate Function Mode */
                temp = pGPIOx->OSPEEDR;
                temp &= ~(GPIO_OSPEEDR_OSPEED0 << (position * 2U));
                temp |= (InitConfig->GPIO_PinOSpeed << (position * 2U));
                pGPIOx->OSPEEDR = temp;

                /* Config the IO Output Type*/
                temp = pGPIOx->OTYPER;
                temp &= ~(GPIO_OTYPER_OT0 << position);
                temp |= (InitConfig->GPIO_PinMode & OTYPE_Msk) << position;
                pGPIOx->OTYPER = temp;
            }

            if ((InitConfig->GPIO_PinMode & MODE_Msk) != MODE_ANALOG)
            {
                assert_param(IS_GPIO_PUPD(InitConfig->GPIO_PinPuPdControl));
                /* Config PUPD if not in Analog Mode */
                temp = pGPIOx->PUPDR;
                temp &= ~(GPIO_PUPDR_PUPD0_Msk << (position * 2U));
                temp |= (InitConfig->GPIO_PinPuPdControl << (position * 2U));
                pGPIOx->PUPDR = temp;
            }
            
            if ((InitConfig->GPIO_PinMode & MODE_Msk) == MODE_ALTFN)
            {
                temp = pGPIOx->AFR[position >> 3];
                temp &= ~(0x0FU << ((position & 0x07U) * 4U));
                temp |= ((InitConfig->GPIO_PinAltFunMode) << (position & 0x07U) * 4U);
                pGPIOx->AFR[position >> 3] = temp;
            }
            /* Config GPIO Mode Input, Output, Analog, Alternate function*/
            temp = pGPIOx->MODER;
            temp &= ~(GPIO_MODER_MODER0_Msk << (position * 2U));
            temp |= (InitConfig->GPIO_PinMode << (position * 2U));
            pGPIOx->MODER = temp;

            /*--------------------- EXTI Mode Configuration ------------------------*/
            if ((InitConfig->GPIO_PinMode & EXTI_MODE) != 0x00U)
            {
                /* Config the GPIO port selection in SYSCFG_EXTICR */
                uint32_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOx);
                uint32_t exticr_index = position / 4U;
                uint32_t exticr_position = (position % 4U) * 4U;

                SYSCFG_PCLK_EN();
                temp = SYSCFG->EXTICR[exticr_index];
                temp &= ~(0x0FU << exticr_position);
                temp |= (portcode << exticr_position);
                SYSCFG->EXTICR[exticr_index] = temp;

                /* Config the trigger selection in EXTI */
                if ((InitConfig->GPIO_PinMode & TRIGGER_Msk) == TRIGGER_RISING)
                {
                    EXTI->RTSR |= iocurrent;
                    EXTI->FTSR &= ~iocurrent;
                } else if ((InitConfig->GPIO_PinMode & TRIGGER_Msk) == TRIGGER_FALLING)
                {
                    EXTI->FTSR |= iocurrent;
                    EXTI->RTSR &= ~iocurrent;
                } else if ((InitConfig->GPIO_PinMode & TRIGGER_Msk) == TRIGGER_BOTH)
                {
                    EXTI->RTSR |= iocurrent;
                    EXTI->FTSR |= iocurrent;
                } 
                temp = EXTI->IMR;
                temp &= ~(uint32_t)iocurrent;
                if((InitConfig->GPIO_PinMode & EXTI_IT) != 0x00U)
                {
                    
                    temp |= iocurrent; 
                } 
                EXTI->IMR = temp;

                temp = EXTI->EMR;
                temp &= ~(uint32_t)iocurrent;
                if ((InitConfig->GPIO_PinMode & EXTI_EVT) != 0x00U)
                {
                    
                    temp |= iocurrent;
                }
                EXTI->EMR = temp;
            } 
        }

        
    }
}
void GPIO_Deinit(GPIO_RegDef_t *pGPIOx, uint16_t GPIO_Pin)
{   
    uint32_t position;
    uint32_t temp = 0x00U;
    uint32_t iocurrent = 0x00U;
    uint32_t ioposition = 0x00U;

    assert_param(IS_GPIO_ALL_INSTANCE(pGPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    for (position = 0U; position < GPIO_NUMBER; position++)
    {
        ioposition = 0x01U << position;
        iocurrent = GPIO_Pin & ioposition;
        if (iocurrent == ioposition)
        {
            /*--------------------- EXTI Mode Configuration ------------------------*/
            temp = SYSCFG->EXTICR[position >> 2];
            temp &= (0x0FU << ((position & 0x03U) * 4U));
            if(temp == ((uint32_t)(GPIO_BASEADDR_TO_CODE(pGPIOx)) << (4U * (position & 0x03U))))
            {
            EXTI->IMR &= ~(uint32_t)iocurrent;
            EXTI->EMR &= ~(uint32_t)iocurrent;
            EXTI->RTSR &= ~(uint32_t)iocurrent;
            EXTI->FTSR &= ~(uint32_t)iocurrent;
            temp = (0x0FU << ((position & 0x03U) * 4U));
            SYSCFG->EXTICR[position >> 2] &= ~temp;
            }
            /*--------------------- GPIO Mode Configuration ------------------------*/
            pGPIOx->MODER &= ~(GPIO_MODER_MODER0_Msk << (position * 2U));
            pGPIOx->OTYPER &= ~(GPIO_OTYPER_OT0 << position);
            pGPIOx->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED0_Msk << (position * 2U));
            pGPIOx->PUPDR &= ~(GPIO_PUPDR_PUPD0_Msk << (position * 2U));
            pGPIOx->AFR[position / 8U] &= ~(0x0FU << ((position % 8U) * 4U));

        }
    }
    
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

    pGPIOx->ODR |= PortState;
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
void GPIO_IRQEnable(IRQ_TypeDef_t IRQNumber)
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
}
void NVIC_IRQDisable(IRQ_TypeDef_t IRQNumber)
{
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
void NVIC_IRQSetPriority(IRQ_TypeDef_t IRQNumber, uint32_t IRQPriority)
{
    uint32_t iprx = IRQNumber / 4;
    uint32_t iprx_section = IRQNumber % 4;
    uint32_t shift_amount = iprx_section * 8 + ( 8 - NO_PR_BITS_IMPLEMENTED );
	NVIC->IP[iprx] |=  ( IRQPriority << shift_amount);
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

__weak void GPIO_IRQ_Callback(uint16_t GPIO_Pin)
{
    /* This is a weak implementation. The user application may override this function. */
}
/*
 * Revision history 
    * 27-May-2025: Initial version
*/
