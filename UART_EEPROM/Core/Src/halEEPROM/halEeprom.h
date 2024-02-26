#ifndef HAL_EEPROM_H_
#define HAL_EEPROM_H_

#include <stdint.h>
#include "commonDef.h"
/*EEPROM INIT API*/
e_status halEEpromInit(void);

/* EEPROM Read and Write APIs*/
e_status halEEpromWrite(uint8_t * data, uint16_t size);
e_status halEEpromRead(uint8_t * data, uint16_t size);

/*EEPROM read & write byte size API*/
uint16_t halEEpromGetWriteCounter(void);

#endif