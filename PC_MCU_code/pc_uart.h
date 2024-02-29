#ifndef PC_UART_H

#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "commonDef.h"

/*Com Port Rx and TX buffer lenght*/
#define G_BUFFER_SIZE 1100
/*the tansmit data chunk size*/
#define G_CHUNK_SIZE  256

/* UART Configurations*/
#define baudRate      2400
#define stopBit       0
#define parity        0
#define dataFramSize  8  

const static char G_ENDKEY[] = "5555";

/********************** APIs *********************************/

/*PC COM PORT Init and De-Init APIs*/
void handleInit();
void handleDeInit();

/*serial port configuration API*/
void serialportConfig();

/*PC COM port send data and receive data APIs*/
void sendMsgToMCU();
void receivRespFrmMCU();

/*other APIs*/
void dataTransferRate(clock_t l_start, clock_t l_end, UINT l_totalBytes, e_com_mode hal_comType);
void printError(HANDLE L_serial, const char *msg);


#endif/*PC_UART_H*/