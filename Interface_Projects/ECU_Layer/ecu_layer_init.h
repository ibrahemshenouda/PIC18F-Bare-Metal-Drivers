/* 
 * File:   ecu_layer_init.h
 * Author: Ibrahim Shenouda
 *
 * Created on 15 ??????, 2024, 10:27 ?
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H
/***************************Includes Section***********************/
#include "../MCAL_Layer/GPIO/hal_gpio.h"
#include "LED/ecu_led.h"
#include "button/ecu_button.h"
#include "Relay/ecu_relay.h"
#include "DC_Motor/ecu_dc_motor.h"
#include "7_Segment/ecu_seven_segment.h"
#include "KeyPad/ecu_keypad.h"
#include "Chr_LCD/ecu_chr_lcd.h"


/******************Section: Macros Functions Declarations*/
#define ENABLE                1
#define DISABLE               0
#define KEYPAD_CONFIG         DISABLE
#define LCD_4_BIT_CONFIG      ENABLE
#define LCD_8_BIT_CONFIG      ENABLE

#define _XTAL_FREQ                    4000000UL
/*************************Extern Section**************************/
extern keypad_t keypad_1;
extern chr_lcd_8bit_t lcd_2 ;
extern chr_lcd_4bit_t lcd_1;

/************************Functions Decleration Section********** */
void ecu_layer_initialize();

#endif	/* ECU_LAYER_INIT_H */

