/* 
 * File:   application.h
 * Author: Ibrahim Shenouda
 *
 * Created on November 22, 2024, 4:19 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/******************Section: Includes**********************/
#include "ECU_Layer/ecu_layer_init.h"
#include "MCAL_Layer/GPIO/hal_gpio.h"
#include "MCAL_Layer/Interrupt/mcal_external_interrupt.h"
#include "MCAL_Layer/EEPROM/hal_eeprom.h"

/******************Section: Macros Declarations***********/
#define _XTAL_FREQ                    4000000UL
//#define _XTAL_FREQ                     8000000UL
/******************Section: Macros Functions Declarations*/

/******************Section: Data Types Declarations*******/

/******************Section: Functions Declarations********/
void application_initializetion();

#endif	/* APPLICATION_H */

