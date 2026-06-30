/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: 27-May-2025
 *      Author: HieuNDM
 */
#ifndef STM32F407XX_SPI_DRIVER_H
#define STM32F407XX_SPI_DRIVER_H

/* Configuration structure for SPI peripherals*/
typedef struct {
    uint32_t SPI_Mode;
    uint32_t SPI_Direction;      /* Bidirection or unidirection */
    uint32_t SPI_DFF;
    uint32_t SPI_CPOL;
    uint32_t SPI_CPHA;
    uint32_t SPI_SSM;
    uint32_t SPI_BaudRatePrescaler;
    uint32_t SPI_BitOrder;
    uint32_t SPI_TIMode;
    uint32_t SPI_CRCCalc;
    uint32_t SPI_Polynomial;
} SPI_InitTypeDef_t;

/* Handle structure for SPI peripherals*/
typedef struct {

} SPI_Handle_t;
/*

*/
/*
 * Revision history 
    * 27-May-2025: Initial version
*/

#endif /* STM32F407XX_SPI_DRIVER_H */