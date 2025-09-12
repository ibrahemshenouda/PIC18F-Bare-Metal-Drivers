/* 
 * File:   mcal_interrupt_manager.h
 * Author: Ibrahim Shenouda
 *
 * Created on 14 Mar, 2025, 03:31 
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H


/******************Section: Includes**********************/
#include "mcal_interrupt_cfg.h"

/******************Section: Macros Declarations***********/

/******************Section: Macros Functions Declarations*/

/******************Section: Data Types Declarations*******/

/******************Section: Functions Declarations********/
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8 source);
void RB5_ISR(uint8 source);
void RB6_ISR(uint8 source);
void RB7_ISR(uint8 source);


#endif	/* MCAL_INTERRUPT_MANAGER_H */

