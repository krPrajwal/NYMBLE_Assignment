#include "halEeprom.h"

/*<Emulating EEPROM with size of 2K>*/
#define HAL_EEPROM_SIZE_IN_BYTES 2048U 
uint8_t EEPROM_DATA[HAL_EEPROM_SIZE_IN_BYTES];
uint16_t writeCounter=0U;

/**
 * @fn    - halEEpromInit
 * @brief - This function Intializes the EEPROM
 * @param - none
 * 
 * @return - e_status 
 */
e_status halEEpromInit(void)
{
    /* Emulating Eeprom init and erasing EEprom memory - ignoring erase delay*/
    uint16_t lIterator_u16=0U;
    for(;lIterator_u16<HAL_EEPROM_SIZE_IN_BYTES;lIterator_u16++)
    {
        EEPROM_DATA[lIterator_u16]=0U;
    }
    writeCounter=0U;
    return E_STATUS_SUCCESS;
}

/**
 * @fn    - halEEpromWrite
 * @brief - This function write data to EEPROM
 * @param - data buffer 
 * @param - size of data buffer
 * 
 * @return - e_status 
 */
e_status halEEpromWrite(uint8_t * data, uint16_t size)
{
    /*Emulating EEPROM Write-ignoring write delay*/
    uint16_t lIterator_u16=0U;
    for(;lIterator_u16<size;lIterator_u16++)
    {
        EEPROM_DATA[writeCounter]=data[lIterator_u16];
        writeCounter++;
    }
    return E_STATUS_SUCCESS;
}

/**
 * @fn    - halEEpromRead
 * @brief - This function read data from EEPROM
 * @param - data buffer 
 * @param - size of data buffer
 * 
 * @return - e_status 
 */
e_status halEEpromRead(uint8_t * data, uint16_t size)
{
    /*Emulating EEPROM read-ignoring read delay*/
    uint16_t lIterator_u16=0U;
    for(;lIterator_u16<size;lIterator_u16++)
    {
        data[lIterator_u16]=EEPROM_DATA[lIterator_u16];
    }
    return E_STATUS_SUCCESS;
}

/**
 * @fn    - halEEpromRead
 * @brief - This function sends the size of EEPROM which holds the data
 * @param - none
 * 
 * @return - uint16_t
 */
uint16_t halEEpromGetWriteCounter(void)
{
    return writeCounter;
}