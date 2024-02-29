#ifndef PC_UART_H

#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "commonDef.h"

#define G_BUFFER_SIZE 1100
#define G_CHUNK_SIZE  256
#define G_DATA_SIZE     8

/* UART Configurations*/
#define baudRate      2400
#define stopBit       0
#define parity        0
#define dataFramSize  8  

const static char G_ENDKEY[] = "5555";

/* APIs */

void handleInit();
void handleDeInit();

void serialportConfig();

void sendMsgToMCU();
void receivRespFrmMCU();

void dataTransferRate(clock_t l_start, clock_t l_end, UINT l_totalBytes, e_com_mode hal_comType);
void printError(HANDLE L_serial, const char *msg);


#endif/*PC_UART_H*/