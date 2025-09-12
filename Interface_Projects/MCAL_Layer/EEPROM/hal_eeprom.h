/* 
 * File:   hal_eeprom.h
 * Author: Ibrahim Shenouda
 *
 * Created on 03 Apr, 2025, 04:59 ?
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H


/******************Section: Includes**********************/
#include "../mcal_std_types.h"
#include "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"

/******************Section: Macros Declarations***********/

/******************Section: Macros Functions Declarations*/

/******************Section: Data Types Declarations*******/

/******************Section: Functions Declarations********/
Std_ReturnType Data_EEPROM_WriteByte(uint16 bAdd, uint8 bData);
Std_ReturnType Data_EEPROM_ReadByte(uint16 bAdd, uint8 *bData);

#endif	/* HAL_EEPROM_H */

