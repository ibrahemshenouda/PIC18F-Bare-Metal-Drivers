/* 
 * File:   hal_eeprom.c
 * Author: Ibrahim Shenouda
 *
 * Created on 03 Apr, 2025, 04:59 ?
 */

#include "hal_eeprom.h"

Std_ReturnType Data_EEPROM_WriteByte(uint16 bAdd, uint8 bData)
{
    Std_ReturnType ret = E_OK;
    /*Read interrupt status "Enabled or Disabled"*/
    uint8 Global_Interrupt_Status = INTCONbits.GIE;
    /*Update the address registers*/
    EEADRH = (uint8)((bAdd >> 8) & (0x03));
    EEADR  = (uint8)((bAdd) & (0xFF));
    /*Update the data registers*/
    EEDATA = bData;
    /*Select access data EEPROM memory*/
    
    /*Allows write cycles to flash program/data EEPROM*/
    /*Disable all interrupts "general interrupts"*/
    /*Write the required sequence : 0x55 -> 0xAA*/
    /*Initiates a data EEPROM erase/write cycle */
    /*Wait for write to complete*/
    /*Inhibits write cycles to flash program/data EEPROM*/
    /*Restore the interrupt Status "Enabled or disabled*/
    return ret;
}
Std_ReturnType Data_EEPROM_ReadByte(uint16 bAdd, uint8 *bData)
{
    Std_ReturnType ret = E_OK;
    if(NULL == bData)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
    }
    return ret;    
}
