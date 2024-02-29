#include "pc_app.h"

/*********************************************************************
 * @file  : main.c
 * @brief : main program body
 * ******************************************************************
*/

int main()
{   
    /*intializing the appPeriodic process with first state*/ 
     appInit();
     while(1)
     {
       appPeriodicProcess();
     }  
     
     /*De-initalzing the PC COM port*/
    handleDeInit();

    return 0;
}