/* 
 * File:   ecu_relay.h
 * Author: Ibrahim Shenouda
 *
 * Created on 10 ??????, 2024, 06:26 ?
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/******************Section: Includes**********************/
#include "ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/******************Section: Macros Declarations***********/
#define RELAY_OFF_STATUS   0X00U
#define RELAY_ON_STATUS    0X01U
/******************Section: Macros Functions Declarations*/

/******************Section: Data Types Declarations*******/

typedef struct
{
    uint8  relay_port   : 4;
    uint8  relay_pin    : 3;
    uint8  relay_status : 1;
}relay_t;
/******************Section: Functions Declarations********/
Std_ReturnType relay_intialize(const relay_t *_relay);
Std_ReturnType relay_turn_on(const relay_t *_relay);
Std_ReturnType relay_turn_off(const relay_t *_relay);

#endif	/* ECU_RELAY_H */

