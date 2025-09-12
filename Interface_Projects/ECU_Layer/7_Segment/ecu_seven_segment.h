/* 
 * File:   ecu_seven_segment.h
 * Author: Ibrahim Shenouda
 *
 * Created on 14 ??????, 2024, 11:07 ?
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H

/******************Section: Includes**********************/
#include "ecu_seven_segment_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/******************Section: Macros Declarations***********/
#define SEGMENT_PIN0        0
#define SEGMENT_PIN1        1
#define SEGMENT_PIN2        2
#define SEGMENT_PIN3        3

/******************Section: Macros Functions Declarations*/

/******************Section: Data Types Declarations*******/

typedef enum
{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct
{
    pin_config_t segment_pins[4];
    segment_type_t segment_type;
}segment_t;
/******************Section: Functions Declarations********/

Std_ReturnType seven_segment_initialize(const segment_t *seg);
Std_ReturnType seven_segment_write_number(const segment_t *seg, uint8 number);

#endif	/* ECU_SEVEN_SEGMENT_H */

