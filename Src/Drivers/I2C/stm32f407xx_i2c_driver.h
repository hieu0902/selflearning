/*
 * stm32f407xx_i2c_driver.h
 *
 *  Created on: 27-May-2025
 *      Author: HieuNDM
 */
#ifndef STM32F407XX_I2C_DRIVER_H
#define STM32F407XX_I2C_DRIVER_H

/*
 * I2C init structure definition
 */
typedef struct
{
    uint32_t I2C_ClockSpeed;
    uint32_t I2C_DutyCycle;
    uint32_t I2C_OwnAddress1;
    uint32_t I2C_AddressingMode;
    uint32_t I2C_DualAddressMode;
    uint32_t I2C_OwnAddress2;
    uint32_t I2C_GeneralCallMode;
    uint32_t I2C_NoStretchMode;
} I2C_InitTypeDef_t;

typedef struct
{
    I2C_RegDef_t *pI2Cx; /* This holds the base address of I2C peripheral */
    I2C_InitTypeDef_t I2C_Config; /* This holds I2C configuration settings */
	uint8_t 		*pTxBuffer; /* !< To store the app. Tx buffer address > */
	uint8_t 		*pRxBuffer;	/* !< To store the app. Rx buffer address > */
	uint32_t 		TxLen;		/* !< To store Tx len > */
	uint32_t 		RxLen;		/* !< To store Tx len > */
	uint8_t 		TxRxState;	/* !< To store Communication state > */
	uint8_t 		DevAddr;	/* !< To store slave/device address > */
    uint32_t        RxSize;		/* !< To store Rx size  > */
    uint8_t         Sr;			/* !< To store repeated start value  > */
} I2C_Handle_t;

void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, HAL_StateTypeDef_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
        if (pI2Cx == I2C1) I2C1_PCLK_EN();
        else if (pI2Cx == I2C2) I2C2_PCLK_EN();
        else if (pI2Cx == I2C3) I2C3_PCLK_EN();
    } else {
        if (pI2Cx == I2C1) I2C1_PCLK_DI();
        else if (pI2Cx == I2C2) I2C2_PCLK_DI();
        else if (pI2Cx == I2C3) I2C3_PCLK_DI();
    }
}

void I2C_Init(I2C_Handle_t *pI2CHandle);
void I2C_DeInit(I2C_RegDef_t *pI2Cx);


/*
 * Revision history 
    * 27-May-2025: Initial version
*/

#endif /* STM32F407XX_I2C_DRIVER_H */