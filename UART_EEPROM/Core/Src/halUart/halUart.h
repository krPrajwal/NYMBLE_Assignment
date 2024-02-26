#ifndef HAL_UART_H_
#define HAL_UART_H_

#include <stdint.h>

/*UART init API*/
void halUartInit(void);

/*UART Send data and Receive data APIs*/
void halUartSend(uint8_t* data, uint16_t size);

void halUartRecieve (uint8_t* data, uint16_t size);

/* Data Transmission control API*/
uint16_t halUartgetRxCounter(void);


#endif /*HAL_UART_H_*/