
#ifndef API_APP_H_
#define API_APP_H_

#include "commonDef.h"

/**
 * @brief this function will initialize communication module
 *
 * @return \ref e_status
 */
e_status appInit(void);

void appPeriodicProcess(void);



#endif /*API_APP_H_*/
