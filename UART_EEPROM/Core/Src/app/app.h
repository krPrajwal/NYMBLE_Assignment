
#ifndef APP_H_
#define APP_H_


/*Rx Buffer length */
#define APP_RX_BUFFERF_LENGTH                           (2048U)

/**
 * @brief data frame end key value, 
 * assumed to detect the end of data during data-reception
 */
#define APP_COMMUNICATION_END_OF_FRAME_KEY              (0x35353535U)

/*Data frame end key size */
#define APP_COMMUNICATION_END_OF_FRAME_KEY_LENGTH       (4U)



/**
 * @brief communication module states,
 * determines the flow of application
 * used in @appPeriodicProcess function
 */
typedef enum
{
    E_APP_INT,
    E_APP_START_RECEPTION,
    E_APP_PROCESS_RECIVED_DATA,
    E_APP_RECEIVE_DATA_UNTIL_END_KEY,
    E_APP_ENDKEY_DETECTED,
    E_APP_SEND_DATA_FROM_EEPROM,
    E_APP_END,
}e_appStates;







#endif/*APP_H_*/
