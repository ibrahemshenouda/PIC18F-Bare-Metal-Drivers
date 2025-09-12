/* 
 * File:   mcal_interrupt_cfg.h
 * Author: Ibrahim Shenouda
 *
 * Created on 14 Mar, 2025, 03:29 
 */

#ifndef MCAL_INTERRUPT_CFG_H
#define	MCAL_INTERRUPT_CFG_H

 /******************Section: Includes**********************/
#include "../mcal_std_types.h"
#include "mcal_interrupt_gen_cfg.h"
#include "../GPIO/hal_gpio.h"

/******************Section: Macros Declarations***********/
#define INTERRUPT_ENABLE                 1
#define INTERRUPT_DISABLE                0
#define INTERRUPT_OCCUR                  1
#define INTERRUPT_NOT_OCCUR              0
#define INTERRUPT_PRIORITY_ENABLE        1
#define INTERRUPT_PRIORITY_DISABLE       0

/******************Section: Macros Functions Declarations*/
/*NOTE: GIE/GIEH are the same bit, GIEL/PEIE also the same, difference between names for explain*/
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/*Enable Priority Levels on interrupt */
#define INTERRUPT_PriorityLevelEnable()              (RCONbits.IPEN = 1)
/*Disable Priority Levels on interrupt */
#define INTERRUPT_PriorityLevelDisable()             (RCONbits.IPEN = 0 )
/*High Priority Global interrupt Enable */
#define INTERRUPT_GlobalInterruptHighEnable()        (INTCONbits.GIEH = 1)
/*High Priority Global interrupt Disable */
#define INTERRUPT_GlobalInterruptHighDisable()       (INTCONbits.GIEH = 0)

/*Low Priority Global interrupt Enable */
#define INTERRUPT_GlobalInterruptLowEnable()         (INTCONbits.GIEL = 1)
/*Low Priority Global interrupt Disable */
#define INTERRUPT_GlobalInterruptLowDisable()        (INTCONbits.GIEL = 0)

#else 

/*Global interrupt Enable */
#define INTERRUPT_GlobalInterruptEnable()        (INTCONbits.GIE = 1)
/*Global interrupt Disable */
#define INTERRUPT_GlobalInterruptDisable()       (INTCONbits.GIE = 0)
/*PEripheral Interrupt Enable */
#define INTERRUPT_PeripheralInterruptEnable()        (INTCONbits.PEIE = 1)
/*PEripheral Interrupt Disable */
#define INTERRUPT_PeripheralInterruptDisable()       (INTCONbits.PEIE = 0)

#endif


/******************Section: Data Types Declarations*******/
typedef enum 
{
    INTERRUPT_LOW_PRIORITY = 0,
    INTERRUPT_HIGH_PRIORITY        
}interrupt_priority_cfg;
/******************Section: Functions Declarations********/
#endif	/* MCAL_INTERRUPT_CFG_H */

