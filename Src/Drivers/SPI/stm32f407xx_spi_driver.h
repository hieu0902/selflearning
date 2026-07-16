/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: 27-May-2025
 *      Author: HieuNDM
 */
#ifndef STM32F407XX_SPI_DRIVER_H
#define STM32F407XX_SPI_DRIVER_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f407xx.h"

/* Exported types ------------------------------------------------------------*/

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
 SPI_STATE_RESET      = 0x00U,    /*!< Peripheral not Initialized                         */
 SPI_STATE_READY      = 0x01U,    /*!< Peripheral Initialized and ready for use           */
 SPI_STATE_BUSY       = 0x02U,    /*!< an internal process is ongoing                     */
 SPI_STATE_BUSY_TX    = 0x03U,    /*!< Data Transmission process is ongoing               */
 SPI_STATE_BUSY_RX    = 0x04U,    /*!< Data Reception process is ongoing                  */
 SPI_STATE_BUSY_TX_RX = 0x05U,    /*!< Data Transmission and Reception process is ongoing */
 SPI_STATE_ERROR      = 0x06U,    /*!< SPI error state                                    */
 SPI_STATE_ABORT      = 0x07U     /*!< SPI abort is ongoing                               */
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
    //void (*RxISR)(struct __SPI_HandleTypeDef *pSPIHandle);   /*!< function pointer on Rx ISR       */
    //void (*TxISR)(struct __SPI_HandleTypeDef *pSPIHandle);   /*!< function pointer on Tx ISR       */
    //DMA_HandleTypeDef          *hdmatx;        /*!< SPI Tx DMA Handle parameters             */
    //DMA_HandleTypeDef          *hdmarx;        /*!< SPI Rx DMA Handle parameters             */
    __vo SPI_StateTypeDef_t    State;          /*!< SPI communication state                  */
    __vo uint32_t              ErrorCode;      /*!< SPI Error code                           */
} SPI_HandleTypeDef_t;
/*


/* Exported constants --------------------------------------------------------*/

/*
 * SPI Error codes
 */
#define SPI_ERROR_NONE      (0x00000000U)   /*!< No error             */
#define SPI_ERROR_MODF      (0x00000001U)   /*!< MODF error           */
#define SPI_ERROR_CRC       (0x00000002U)   /*!< CRC error             */
#define SPI_ERROR_OVR       (0x00000004U)   /*!< OVR error             */
#define SPI_ERROR_FRE       (0x00000008U)   /*!< FRE error             */
#define SPI_ERROR_DMA       (0x80000010U)   /*!< DMA error             */
#define SPI_ERROR_FLAG      (0x00000020U)   /*!< Flag error             */

/*
 * SPI Device Modes
 */
#define SPI_MODE_MASTER     (0x00000000U)   /*!< Master mode            */
#define SPI_MODE_SLAVE      (0x00000001U)   /*!< Slave mode             */

/*
 * SPI Direction Configurations
 */
#define SPI_DIRECTION_2LINES   (0x00000000U)   /*!< Full duplex             */
#define SPI_DIRECTION_2LINES_RXONLY   (0x00000001U)   /*!< Half duplex             */
#define SPI_DIRECTION_1LINE (0x00000002U)   /*!< Simplex receive only mode     */

/*
 * SPI Data Frame Format
 */
#define SPI_DFF_8BITS       (0x00000000U)   /*!< 8 bits data frame format     */
#define SPI_DFF_16BITS      (0x00000001U)   /*!< 16 bits data frame format    */

/*
 * SPI Clock Polarity
 */
#define SPI_CPOL_LOW        (0x00000000U)   /*!< Clock is low when idle       */
#define SPI_CPOL_HIGH       (0x00000001U)   /*!< Clock is high when idle      */

/*
 * SPI Clock Phase
 */
#define SPI_CPHA_LOW        (0x00000000U)   /*!< Data is captured on the first clock transition */
#define SPI_CPHA_HIGH       (0x00000001U)   /*!< Data is captured on the second clock transition */

/*
 * SPI Software Slave Management
 */
#define SPI_SSM_DI          (0x00000000U)   /*!< Software slave management disabled */
#define SPI_SSM_EN          (0x00000001U)   /*!< Software slave management enabled  */

/*
 * SPI Baud Rate Prescaler
 */
#define SPI_BAUDRATEPRESCALER_2   (0x00000000U)   /*!< Baud rate prescaler 2     */
#define SPI_BAUDRATEPRESCALER_4   (0x00000001U)   /*!< Baud rate prescaler 4     */
#define SPI_BAUDRATEPRESCALER_8   (0x00000002U)   /*!< Baud rate prescaler 8     */
#define SPI_BAUDRATEPRESCALER_16  (0x00000003U)   /*!< Baud rate prescaler 16    */
#define SPI_BAUDRATEPRESCALER_32  (0x00000004U)   /*!< Baud rate prescaler 32    */
#define SPI_BAUDRATEPRESCALER_64  (0x00000005U)   /*!< Baud rate prescaler 64    */
#define SPI_BAUDRATEPRESCALER_128 (0x00000006U)   /*!< Baud rate prescaler 128   */
#define SPI_BAUDRATEPRESCALER_256 (0x00000007U)   /*!< Baud rate prescaler 256   */

/*
 * SPI Bit Order
 */
#define SPI_BITORDER_MSB_FIRST  (0x00000000U)   /*!< MSB transmitted first      */
#define SPI_BITORDER_LSB_FIRST  (0x00000001U)   /*!< LSB transmitted first      */

/*
 * SPI TI Mode
 */
#define SPI_TIMODE_DISABLE  (0x00000000U)   /*!< TI mode disabled            */
#define SPI_TIMODE_ENABLE   (0x00000001U)   /*!< TI mode enabled             */

/*
 * SPI CRC Calculation
 */
#define SPI_CRCCALCULATION_DISABLE  (0x00000000U)   /*!< CRC calculation disabled    */
#define SPI_CRCCALCULATION_ENABLE   (0x00000001U)   /*!< CRC calculation enabled     */

/*
 * SPI Interrupt Definitions
 */

#define SPI_IT_TXE        (0x00000001U)   /*!< Transmit buffer empty interrupt */
#define SPI_IT_RXNE       (0x00000002U)   /*!< Receive buffer not empty interrupt */
#define SPI_IT_ERR        (0x00000004U)   /*!< Error interrupt                 */

/* Private macros ------------------------------------------------------------*/
#define IS_SPI_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI1) || \
                                     ((INSTANCE) == SPI2) || \
                                     ((INSTANCE) == SPI3))

#define IS_SPI_MODE(__MODE__) (((__MODE__) == SPI_MODE_MASTER) || ((__MODE__) == SPI_MODE_SLAVE))

#define IS_SPI_DIRECTION(__DIRECTION__) (((__DIRECTION__) == SPI_DIRECTION_2LINES) || \
                                        ((__DIRECTION__) == SPI_DIRECTION_2LINES_RXONLY) || \
                                        ((__DIRECTION__) == SPI_DIRECTION_1LINE))

#define IS_SPI_DFF(__DFF__) (((__DFF__) == SPI_DFF_8BITS) || ((__DFF__) == SPI_DFF_16BITS))

#define IS_SPI_CPOL(__CPOL__) (((__CPOL__) == SPI_CPOL_LOW) || ((__CPOL__) == SPI_CPOL_HIGH))

#define IS_SPI_CPHA(__CPHA__) (((__CPHA__) == SPI_CPHA_LOW) || ((__CPHA__) == SPI_CPHA_HIGH))

#define IS_SPI_SSM(__SSM__) (((__SSM__) == SPI_SSM_DI) || ((__SSM__) == SPI_SSM_EN))

#define IS_SPI_BAUDRATE_PRESCALER(__PRESCALER__) (((__PRESCALER__) == SPI_BAUDRATEPRESCALER_2) || \
                                                ((__PRESCALER__) == SPI_BAUDRATEPRESCALER_4) || \
                                                ((__PRESCALER__) == SPI_BAUDRATEPRESCALER_8) || \
                                                ((__PRESCALER__) == SPI_BAUDRATEPRESCALER_16) || \
                                                ((__PRESCALER__) == SPI_BAUDRATEPRESCALER_32) || \
                                            ((__PRESCALER__) == SPI_BAUDRATEPRESCALER_64) || \
                                            ((__PRESCALER__) == SPI_BAUDRATEPRESCALER_128) || \
                                            ((__PRESCALER__) == SPI_BAUDRATEPRESCALER_256))

#define IS_SPI_FIRSTBIT(__FIRSTBIT__) (((__FIRSTBIT__) == SPI_BITORDER_MSB_FIRST) || ((__FIRSTBIT__) == SPI_BITORDER_LSB_FIRST))
#define IS_SPI_TIMODE(__TIMODE__) (((__TIMODE__) == SPI_TIMODE_DISABLE) || ((__TIMODE__) == SPI_TIMODE_ENABLE))

#define IS_SPI_CRCCALCULATION(__CRCCALCULATION__) (((__CRCCALCULATION__) == SPI_CRCCALCULATION_DISABLE) || \
                                                    ((__CRCCALCULATION__) == SPI_CRCCALCULATION_ENABLE))

#define IS_SPI_CRC_POLYNOMIAL(__POLYNOMIAL__) ((__POLYNOMIAL__) >= 0x0000U && (__POLYNOMIAL__) <= 0xFFFFU)

/* Exported functions --------------------------------------------------------*/
/*
 * Peripheral Clock setup
 */
void SPI_PeriClockControl(SPI_HandleTypeDef_t *pSPIHandle, HAL_StateTypeDef_t ClockState);

/*
 * Init and De-init
 */
HAL_StatusTypeDef_t SPI_Init(SPI_HandleTypeDef_t *pSPIHandle, SPI_InitTypeDef_t *InitConfig);
HAL_StatusTypeDef_t SPI_DeInit(SPI_HandleTypeDef_t *pSPIHandle);

/*
 * Data Send and Receive
 */
HAL_StatusTypeDef_t SPI_SendData(SPI_HandleTypeDef_t *pSPIHandle,uint8_t *pTxBuffer, uint32_t Len);
HAL_StatusTypeDef_t SPI_ReceiveData(SPI_HandleTypeDef_t *pSPIHandle, uint8_t *pRxBuffer, uint32_t Len);

HAL_StatusTypeDef_t SPI_SendDataIT(SPI_HandleTypeDef_t *pSPIHandle,uint8_t *pTxBuffer, uint32_t Len);
HAL_StatusTypeDef_t SPI_ReceiveDataIT(SPI_HandleTypeDef_t *pSPIHandle, uint8_t *pRxBuffer, uint32_t Len);

/*
 * IRQ Configuration and ISR handling
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_HandleTypeDef_t *pHandle);

/*
 * Other Peripheral Control APIs
 */
void SPI_PeripheralControl(SPI_HandleTypeDef_t *pSPIHandle, uint8_t EnOrDi);
void SPI_SSIConfig(SPI_HandleTypeDef_t *pSPIHandle, uint8_t EnOrDi);
void SPI_SSOEConfig(SPI_HandleTypeDef_t *pSPIHandle, uint8_t EnOrDi);
uint8_t SPI_GetFlagStatus(SPI_HandleTypeDef_t *pSPIHandle , uint32_t FlagName);
void SPI_ClearOVRFlag(SPI_HandleTypeDef_t *pSPIHandle);
void SPI_CloseTransmisson(SPI_HandleTypeDef_t *pSPIHandle);
void SPI_CloseReception(SPI_HandleTypeDef_t *pSPIHandle);

/*
 * Application callback
 */
void SPI_ApplicationEventCallback(SPI_HandleTypeDef_t *pSPIHandle,uint8_t AppEv);
void SPI_TxCpltCallback(SPI_HandleTypeDef_t *pSPIHandle);
void SPI_RxCpltCallback(SPI_HandleTypeDef_t *pSPIHandle);
void SPI_TxRxCpltCallback(SPI_HandleTypeDef_t *pSPIHandle);
void SPI_TxHalfCpltCallback(SPI_HandleTypeDef_t *pSPIHandle);
void SPI_RxHalfCpltCallback(SPI_HandleTypeDef_t *pSPIHandle);
void SPI_TxRxHalfCpltCallback(SPI_HandleTypeDef_t *pSPIHandle);
void SPI_ErrorCallback(SPI_HandleTypeDef_t *pSPIHandle);
void SPI_AbortCpltCallback(SPI_HandleTypeDef_t *pSPIHandle);


/* Peripheral State and Error functions ***************************************/
SPI_StateTypeDef_t HAL_SPI_GetState(const SPI_HandleTypeDef_t *hspi);
uint32_t             HAL_SPI_GetError(const SPI_HandleTypeDef_t *hspi);
/*
 * Revision history 
    * 27-May-2025: Initial version
*/

#endif /* STM32F407XX_SPI_DRIVER_H */