#include "pc_uart.h"

/* PC Com Port Handle structre*/
HANDLE G_Serial;

/**
 * @fn    - handleInit
 * @brief - This function intialies the User select Com port,
 *          for serial communication
 * @param - none
 * @return - none
*/
void handleInit()
{
     char comPort[10];
    int index = 0;
    char getValue;
    printf("enter COM port (eg: COM1,COM2 etc.):");
    while((getValue = getchar()) != '\n' && getValue != EOF && index < 9)
    {
        comPort[index++] = getValue;
        
    }
    comPort[index] = '\0';
    G_Serial = CreateFile(comPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if(G_Serial == INVALID_HANDLE_VALUE)
    {
        printError(G_Serial, "Error: Unable to Open Com port.\n");
    }

}

/**
 * @fn    - serialportConfig
 * @brief - This function intialies the PC Com port,
 *          with serial pin configuration to support UART communication
 * @param - none
 * @return - none
*/
void serialportConfig()
{
   
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};
        //configuring  com port
    dcbSerialParams.BaudRate = baudRate;
    dcbSerialParams.ByteSize = dataFramSize;
    dcbSerialParams.StopBits = stopBit; 
    dcbSerialParams.Parity = parity;

    if (!SetCommState(G_Serial, &dcbSerialParams)) 
    {
        printError(G_Serial, "Error: Unable to set serial port state.\n");
    }

    // Set timeout parameters
    timeouts.ReadIntervalTimeout = 500;
    timeouts.ReadTotalTimeoutConstant = 500;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 500;
    timeouts.WriteTotalTimeoutMultiplier = 10;

    if (!SetCommTimeouts(G_Serial, &timeouts)) {
        printError(G_Serial, "Error: Unable to set serial port timeouts.\n");
        CloseHandle(G_Serial);

    }

}

/**
 * @fn    - sendMsgToMCU
 * @brief - This function sends data over COM port
 * @param - none
 * @return - none
*/
void sendMsgToMCU()
{
    char l_txBuffer[G_BUFFER_SIZE];
    DWORD l_bytesWritten;
    char l_getValue;
    int l_index = 0;
    int l_newlines = 0;
    clock_t smStartTime,smEndTime, rmStartTime, rmEndTime ;
    UINT l_bufferLength = strlen(l_txBuffer);

        // Send message from console to MCU
        printf("\nEnter message (Press Enter twice to send):\n\n ");
        
        //Read multiple input
        
        while((l_getValue = getchar()) != EOF && l_index < G_BUFFER_SIZE -1)
        {
            if(l_getValue  == '\n')
            {
                if(++l_newlines == 2)
                {
                    // Exit loop when encontering two consecutive newlines
                    break;     
                } 
            }
            else
            {
               l_newlines = 0; // Reset newline count if character is not a newline
               l_txBuffer[l_index++] = l_getValue ;
            }  
        }

        l_txBuffer[l_index] = '\0'; //NULL-terminating the string after loop ends
        
        //start time for sending message
        smStartTime = clock();

        //send the buffer in chunks
        for (UINT i=0; i < l_bufferLength; i+= G_CHUNK_SIZE)
        {
            UINT chunkSize = min(l_bufferLength-i,G_CHUNK_SIZE);
            WriteFile(G_Serial, l_txBuffer + i, chunkSize, &l_bytesWritten, NULL);
        }
        //send end key
        WriteFile(G_Serial, G_ENDKEY, strlen(G_ENDKEY), &l_bytesWritten,NULL);

         //End time for sending message
         smEndTime = clock();

         //Calcualte transfer rate during sending
         dataTransferRate(smStartTime,smEndTime,strlen(l_txBuffer),data_transfer);
}


/**
 * @fn    - receivRespFrmMCU
 * @brief - This function receives data over COM port
 * @param - none
 * @return - none
*/
void receivRespFrmMCU()
{
    char l_rxBuffer[G_BUFFER_SIZE];
    DWORD l_bytesRead;
    clock_t rmStartTime, rmEndTime ;
    UINT l_totalBytesRead = 0;
  // Clear receive buffer   
        PurgeComm(G_Serial, PURGE_RXCLEAR);

        //Start time for receiving message
        rmStartTime = clock();

        // Read response from MCU
        
         do {
            // Wait until data is received or there's a timeout
            ReadFile(G_Serial, l_rxBuffer + l_totalBytesRead ,sizeof(l_rxBuffer) - l_totalBytesRead, &l_bytesRead, NULL);
            if (l_bytesRead > 0) {
                if(*(int*)(l_rxBuffer) == '\n')
                {
                 printf("%s\n",l_rxBuffer);
                }
                else{
                    printf("Received from MCU:\n %s \r\n", l_rxBuffer);
                }
                
                break; // Exit loop once data is received
            }
        } while (l_totalBytesRead < sizeof(l_rxBuffer)); // Continue loop if no data is received

        //End time for receiving message
        rmEndTime = clock();
        
        //calculate transfer rate during receiving
        dataTransferRate(rmStartTime,rmEndTime,strlen(l_rxBuffer),data_reception);
        

        //clear receive buffer again after receiving response
        PurgeComm(G_Serial, PURGE_RXCLEAR);

}

/**
 * @fn    - printError
 * @brief - This function print error message, 
 *          if any exception occured during conifguration step
 * @param - none
 * @return - none
*/
void printError(HANDLE G_serial, const char *msg)
{
    fprintf(stderr, "%s", msg);
    CloseHandle (G_serial);
    exit(1);
}

/**
 * @fn    - dataTransferRate
 * @brief - This function calculates the data transer rate or reception rate
 *          and displays output at the console
 * @param - none
 * @return - none
*/
void dataTransferRate(clock_t l_start, clock_t l_end, UINT l_totalBytes, e_com_mode l_comType)
{
    double l_dtr_timeInSec = (double) (l_end - l_start)/CLOCKS_PER_SEC;
    double l_dtr_transferRate = ((l_totalBytes * 8.0)/1024)/l_dtr_timeInSec;
    if(l_comType)
    {
         printf("Reception Rate: %.2fKbps\r\n\n",l_dtr_transferRate);
    }
    else 
    {
        printf("Transfer Rate: %.2fKbps\r\n\n",l_dtr_transferRate);
    }
}

/**
 * @fn    - andleDeInit
 * @brief - This function De-initalizes the PC COM port
 * @param - none
 * @return - none
*/
void handleDeInit()
{
    CloseHandle(G_Serial);
}