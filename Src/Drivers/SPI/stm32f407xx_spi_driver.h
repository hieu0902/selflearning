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

/* SPI States structure */
typedef enum
{
  HAL_SPI_STATE_RESET      = 0x00U,    /*!< Peripheral not Initialized                         */
  HAL_SPI_STATE_READY      = 0x01U,    /*!< Peripheral Initialized and ready for use           */
  HAL_SPI_STATE_BUSY       = 0x02U,    /*!< an internal process is ongoing                     */
  HAL_SPI_STATE_BUSY_TX    = 0x03U,    /*!< Data Transmission process is ongoing               */
  HAL_SPI_STATE_BUSY_RX    = 0x04U,    /*!< Data Reception process is ongoing                  */
  HAL_SPI_STATE_BUSY_TX_RX = 0x05U,    /*!< Data Transmission and Reception process is ongoing */
  HAL_SPI_STATE_ERROR      = 0x06U,    /*!< SPI error state                                    */
  HAL_SPI_STATE_ABORT      = 0x07U     /*!< SPI abort is ongoing                               */
} SPI_StateTypeDef_t;

/* Handle structure for SPI peripherals*/
typedef struct {
    SPI_RegDef_t *pSPIx;
    SPI_InitTypeDef_t SPI_Init;
    const uint8_t *pTxBuf;
    uint16_t TxLen;
    __vo uint16_t TxXferCount;
    uint8_t *pRxBuf;
    uint16_t RxLen;
    __vo uint16_t RxXferCount;
    void (*RxISR)(struct __SPI_HandleTypeDef *hspi);   /*!< function pointer on Rx ISR       */
    void (*TxISR)(struct __SPI_HandleTypeDef *hspi);   /*!< function pointer on Tx ISR       */
    //DMA_HandleTypeDef          *hdmatx;        /*!< SPI Tx DMA Handle parameters             */
    //DMA_HandleTypeDef          *hdmarx;        /*!< SPI Rx DMA Handle parameters             */
    HAL_LockTypeDef            Lock;           /*!< Locking object                           */
    __vo SPI_StateTypeDef_t    State;          /*!< SPI communication state                  */
    __vo uint32_t              ErrorCode;      /*!< SPI Error code                           */
} SPI_Handle_t;
/*

*/
/*
 * Revision history 
    * 27-May-2025: Initial version
*/

#endif /* STM32F407XX_SPI_DRIVER_H */