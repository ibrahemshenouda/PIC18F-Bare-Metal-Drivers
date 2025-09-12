/* 
 * File:   application.c
 * Author: Ibrahim Shenouda
 *
 * Created on 22 Nov, 2024, 03:13 ?
 */
#include "application.h"




/***********************************************************/

int main() {
    application_initializetion();
    Std_ReturnType ret = E_NOT_OK;
    
    
    while(1)
    {
        
    }
    return (EXIT_SUCCESS); 
}
void application_initializetion()
{
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_initialize();
}
