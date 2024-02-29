#include "pc_app.h"

e_appStates gAppStatus_e;

void appPeriodicProcess()
{
    switch(gAppStatus_e)
    {
        case E_APP_INIT:
        {
            /*Initialize the PC COM for serial transmission */
            handleInit();
            serialportConfig();
            gAppStatus_e = E_APP_SEND_MSG;

        }
        break;
        case E_APP_SEND_MSG:
        {
            /*Recevice msg from console and send it to MCU*/
            sendMsgToMCU();
            gAppStatus_e = E_APP_RECEIVE_MSG;

        }
        break;
        case E_APP_RECEIVE_MSG:
        {
            /*Receive the response from the MCU and display on the console*/
            receivRespFrmMCU();
            gAppStatus_e = E_APP_END;

        }
        break;
        case E_APP_END:
        {   
            /*De-Intialize the PC COM port*/
            handleDeInit();
        }
        break;
        default:
        break;

    }
}

e_status appInit(void)
{
    gAppStatus_e = E_APP_INIT;
}