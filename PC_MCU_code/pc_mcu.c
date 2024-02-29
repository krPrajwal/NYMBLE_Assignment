#include "pc_app.h"


int main()
{ 
     appInit();
     while(1)
     {
       appPeriodicProcess();
     }  
    handleDeInit();

    return 0;
}