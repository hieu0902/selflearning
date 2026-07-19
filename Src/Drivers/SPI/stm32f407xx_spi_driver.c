/*
 * stm32f407xx_spi_driver.c
 *
 *  Created on: 27-May-2025
 *      Author: HieuNDM
 */
#include "stm32f407xx.h"
#include "stm32f407xx_spi_driver.h"


void SPI_PeriClockControl(SPI_HandleTypeDef_t *pSPIHandle, HAL_StateTypeDef_t ClockState)
{
    if(ClockState == ENABLE)
    {
        if(pSPIHandle->pSPIx == SPI1)
        {
            SPI1_PCLK_EN();
        }
        else if(pSPIHandle->pSPIx == SPI2)
        {
            SPI2_PCLK_EN();
        }
        else if(pSPIHandle->pSPIx == SPI3)
        {
            SPI3_PCLK_EN();
        }
    }
    else
    {
        if(pSPIHandle->pSPIx == SPI1)
        {
            SPI1_PCLK_DI();
        }
        else if(pSPIHandle->pSPIx == SPI2)
        {
            SPI2_PCLK_DI();
        }
        else if(pSPIHandle->pSPIx == SPI3)
        {
            SPI3_PCLK_DI();
        }
    }
}

/*
 * Init and De-init
 */
HAL_StatusTypeDef_t SPI_Init(SPI_HandleTypeDef_t *pSPIHandle)
{
    if ( pSPIHandle == NULL )
    {
        return HAL_ERROR;
    }

    assert_param(IS_SPI_ALL_INSTANCE(pSPIHandle->pSPIx));
    assert_param(IS_SPI_MODE(pSPIHandle->SPI_Init.SPI_Mode));
    assert_param(IS_SPI_DIRECTION(pSPIHandle->SPI_Init.SPI_Direction));
    assert_param(IS_SPI_DFF(pSPIHandle->SPI_Init.SPI_DFF));
    assert_param(IS_SPI_CPOL(pSPIHandle->SPI_Init.SPI_CPOL));
    assert_param(IS_SPI_CPHA(pSPIHandle->SPI_Init.SPI_CPHA));
    assert_param(IS_SPI_SSM(pSPIHandle->SPI_Init.SPI_SSM));
    assert_param(IS_SPI_FIRSTBIT(pSPIHandle->SPI_Init.SPI_BitOrder));

    if (pSPIHandle->SPI_Init.SPI_TIMode == SPI_TIMODE_ENABLE)
    {
        assert_param(IS_SPI_TIMODE(pSPIHandle->SPI_Init.SPI_TIMode));

        if(pSPIHandle->SPI_Init.SPI_Mode == SPI_MODE_MASTER)
        {
            assert_param(IS_SPI_BAUDRATE_PRESCALER(pSPIHandle->SPI_Init.SPI_BaudRatePrescaler));
        } 
        else 
        {
            pSPIHandle->SPI_Init.SPI_BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
        }
    }
    else
    {
        assert_param(IS_SPI_BAUDRATE_PRESCALER(pSPIHandle->SPI_Init.SPI_BaudRatePrescaler));

        pSPIHandle->SPI_Init.SPI_CPHA = SPI_CPHA_1EDGE;
        pSPIHandle->SPI_Init.SPI_CPOL = SPI_CPOL_LOW;
    }

    // SPI DISABLE
    pSPIHandle->State = SPI_STATE_BUSY;

/*----------------------- SPIx CR1 & CR2 Configuration ---------------------*/
/* Configure : SPI Mode, Communication Mode, Data size, Clock polarity and phase, NSS management,
  Communication speed, First bit and CRC calculation state */
    uint32_t temp_reg = 0;
    temp_reg |= SPI_CR1_MSTR;
    temp_reg |= SPI_CR1_CPHA;
}
HAL_StatusTypeDef_t SPI_DeInit(SPI_HandleTypeDef_t *pSPIHandle);

/*
 * Revision history 
    * 27-May-2025: Initial version
*/