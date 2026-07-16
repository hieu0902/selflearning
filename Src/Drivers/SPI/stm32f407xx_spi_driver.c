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
    assert_param(IS_SPI_BAUDRATE_PRESCALER(pSPIHandle->SPI_Init.SPI_BaudRatePrescaler));
    assert_param(IS_SPI_FIRSTBIT(pSPIHandle->SPI_Init.SPI_BitOrder));

    

}
HAL_StatusTypeDef_t SPI_DeInit(SPI_HandleTypeDef_t *pSPIHandle);

/*
 * Revision history 
    * 27-May-2025: Initial version
*/