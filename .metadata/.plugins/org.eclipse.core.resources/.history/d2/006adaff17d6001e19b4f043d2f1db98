

#include"app.h"
#include"api_app.h"
#include "halUart.h"
#include "halEeprom.h"

#define APP_EEPROM_READ_SIZE 2048U

/* EEPROM data buffer*/
uint8_t eepromData[APP_EEPROM_READ_SIZE];

/*UART Rx Data Buffer*/
uint8_t gBufferRx_u8a[APP_RX_BUFFERF_LENGTH]={0};

e_appStates gAppStatus_e=E_APP_INT;

/* Received Data process function*/
static e_status appProcessData(void);

/*End Key Check function*/
static e_status appCommunicationCheckForEndKey_e(uint8_t aData_u8p);

/**
 * @fn    - appInit 
 * @brief - Intializes the app periodic process
 * 
 * @return e_status 
 */
e_status appInit(void)
{

    gAppStatus_e=E_APP_INT;
    return E_STATUS_SUCCESS;
}

/**
 * @fn    - appPeriodicProcess 
 * @brief - state machine which controls the flow of communincation module
 * 
 * @return e_status 
 */
void appPeriodicProcess(void)
{
    switch(gAppStatus_e)
    {
        case E_APP_INT:
        {
           
            /* Init Eeprom*/
            halEEpromInit();
            /* Emulating EEPROM init Delay*/
            HAL_Delay(100);
            /* INIT UART */
            halUartInit();


            gAppStatus_e=E_APP_START_RECEPTION;
            

        }
        break;
        case E_APP_START_RECEPTION:
        {   
            halUartRecieve(gBufferRx_u8a,APP_RX_BUFFERF_LENGTH);
            gAppStatus_e=E_APP_PROCESS_RECIVED_DATA;
        }
        break;

        case E_APP_PROCESS_RECIVED_DATA:
        {
            if(E_STATUS_SUCCESS==appProcessData())
            {
                gAppStatus_e=E_APP_ENDKEY_DETECTED;
            }
        }
        break;
        case E_APP_ENDKEY_DETECTED:
        {
            gAppStatus_e=E_APP_SEND_DATA_FROM_EEPROM;
        }
        break;
        case E_APP_SEND_DATA_FROM_EEPROM:
        {
            uint16_t EEpromReasSize=halEEpromGetWriteCounter();
            EEpromReasSize=EEpromReasSize-APP_COMMUNICATION_END_OF_FRAME_KEY_LENGTH;
            halEEpromRead(eepromData,halEEpromGetWriteCounter());
            /* Emulating EEPROM Read Dealy*/
            HAL_Delay(1);
            halUartSend(eepromData,EEpromReasSize);
            gAppStatus_e=E_APP_END;
        }
        break;
        case E_APP_END:
        {

        }
        break;
        default :
        break;
    }
}

/**
 * @fn    - appProcessData 
 * @brief - stores the received bytes from UART
 *          
 * 
 * @return e_status 
 */
static e_status appProcessData(void)
{
    static uint16_t lastRxCounter=0U;
    uint16_t rxCounter=0U;
    /* get recived count this will give lifetime recived byte size */
    rxCounter=halUartgetRxCounter();
    e_status lreturn_e=E_STATUS_FAILED;

    uint16_t RecivedChunkSize=rxCounter-lastRxCounter;
    uint8_t tempEEpromBuffer[RecivedChunkSize];
    uint16_t lIterator_u16=0;

    for(;lastRxCounter<rxCounter;lastRxCounter++)
    {
        tempEEpromBuffer[lIterator_u16]=gBufferRx_u8a[lastRxCounter];
        lreturn_e=appCommunicationCheckForEndKey_e(gBufferRx_u8a[lastRxCounter]);
        lIterator_u16++;
    }
    halEEpromWrite(tempEEpromBuffer,RecivedChunkSize);
    /* Emulating EEPROM Write Delay*/
    HAL_Delay(10);
    return lreturn_e;


}

/**
 * @fn    - appProcessData 
 * @brief - checks for end key to terminate data reception
 *         
 * @return e_status 
 */
static e_status appCommunicationCheckForEndKey_e(uint8_t aData_u8p)
{
    e_status lReturnStatus_e=E_STATUS_FAILED;

    static uint32_t lKeyRecived=0U;
    lKeyRecived=lKeyRecived<<8;
    lKeyRecived=lKeyRecived|(aData_u8p);


    if(lKeyRecived==APP_COMMUNICATION_END_OF_FRAME_KEY)
    {
        lReturnStatus_e=E_STATUS_SUCCESS;
    }
    return lReturnStatus_e;
}



