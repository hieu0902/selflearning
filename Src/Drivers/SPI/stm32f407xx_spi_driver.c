/*
 * stm32f407xx_spi_driver.c
 *
 *  Created on: 27-May-2025
 *      Author: HieuNDM
 */
#include "stm32f407xx.h"
#include "stm32f407xx_spi_driver.h"


void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, HAL_State_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(pSPIx == SPI1)
        {
            SPI1_PCLK_EN();
        }
        else if(pSPIx == SPI2)
        {
            SPI2_PCLK_EN();
        }
        else if(pSPIx == SPI3)
        {
            SPI3_PCLK_EN();
        }
    }
    else
    {
        if(pSPIx == SPI1)
        {
            SPI1_PCLK_DI();
        }
        else if(pSPIx == SPI2)
        {
            SPI2_PCLK_DI();
        }
        else if(pSPIx == SPI3)
        {
            SPI3_PCLK_DI();
        }
    }
}
/*
 * Revision history 
    * 27-May-2025: Initial version
*/