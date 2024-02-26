#include "halUart.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

UART_HandleTypeDef huart1;
static uint16_t gRxBufferSize=0;

/* UART configuration parameters for handle structure */
void halUartInit(void)
{
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 2400;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {

  }
  /*enable Interrupt*/
  HAL_NVIC_SetPriority(USART1_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(USART1_IRQn);

}

/**
 * @fn    - halUartgetRxCounte
 * @brief - This function calculates the bytes received at UART  
 * @param - none
 * 
 * @return - uint16_t
 */
uint16_t halUartgetRxCounter(void)
{
  return gRxBufferSize-huart1.RxXferCount;
}

/**
 * @fn    - halUartSend
 * @brief - This function is to send data from USARTx bus 
 * @param - data 
 * @param - size 
 * 
 * @return - none
 */
void halUartSend(uint8_t* data, uint16_t size)
{
     HAL_UART_Transmit(&huart1,(uint8_t*) data, size, 10000);
}

/**
 * @fn    - halUartRecieve
 * @brief - This function is to Receive data from USARTx bus using Interrupt 
 * @param - data 
 * @param - size 
 * 
 * @return - none
 */
void halUartRecieve (uint8_t* data, uint16_t size)
{
  gRxBufferSize=size;
  HAL_UART_Receive_IT(&huart1, data, size);
}

