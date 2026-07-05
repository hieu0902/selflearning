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

/*
 * Peripheral Clock setup
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, HAL_State_t EnorDi);

/*
 * Init and De-init
 */
void SPI_Init(SPI_RegDef_t *pSPIx, SPI_InitTypeDef_t *InitConfig);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * Data Send and Receive
 */
void SPI_SendData(SPI_RegDef_t *pSPIx,uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

uint8_t SPI_SendDataIT(SPI_Handle_t *pSPIHandle,uint8_t *pTxBuffer, uint32_t Len);
uint8_t SPI_ReceiveDataIT(SPI_Handle_t *pSPIHandle, uint8_t *pRxBuffer, uint32_t Len);

/*
 * IRQ Configuration and ISR handling
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);

/*
 * Other Peripheral Control APIs
 */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx , uint32_t FlagName);
void SPI_ClearOVRFlag(SPI_RegDef_t *pSPIx);
void SPI_CloseTransmisson(SPI_Handle_t *pSPIHandle);
void SPI_CloseReception(SPI_Handle_t *pSPIHandle);
uint8_t I2C_DeviceMode(I2C_RegDef_t *I2Cx);

/*
 * Application callback
 */
void SPI_ApplicationEventCallback(SPI_Handle_t *pSPIHandle,uint8_t AppEv);

*/
/*
 * Revision history 
    * 27-May-2025: Initial version
*/

#endif /* STM32F407XX_SPI_DRIVER_H */