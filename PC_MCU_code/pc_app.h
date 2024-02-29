#ifndef PC_APP_H_

#include "pc_uart.h"

/**
 * @brief communication module states,
 * determines the flow of application
 * used in @appPeriodicProcess function
 */
typedef enum
{
    E_APP_INIT,
    E_APP_SEND_MSG,
    E_APP_RECEIVE_MSG,
    E_APP_END,
}e_appStates;

void appPeriodicProcess(void);
e_status appInit(void);


#endif/*PC_APP_H_*/