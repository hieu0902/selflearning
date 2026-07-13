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
SPI_StateTypeDef_t SPI_Init(SPI_HandleTypeDef_t *pSPIHandle, SPI_InitTypeDef_t *InitConfig);
SPI_StateTypeDef_t SPI_DeInit(SPI_HandleTypeDef_t *pSPIHandle);

/*
 * Revision history 
    * 27-May-2025: Initial version
*/