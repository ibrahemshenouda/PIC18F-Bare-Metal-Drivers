/* 
 * File:   mcal_external_interrupt.h
 * Author: Ibrahim Shenouda
 *
 * Created on 14 Mar, 2025, 03:30 
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/******************Section: Includes**********************/
#include "mcal_interrupt_cfg.h"

/******************Section: Macros Functions Declarations*/
#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/*Eternal interrupt 0 Enable & Disable & Flag Clear and set edge mode*/
#define EXT_INT0_Interrupt_Enable()         (INTCONbits.INT0IE   = 1)
#define EXT_INT0_Interrupt_Disable()        (INTCONbits.INT0IE   = 0)
#define EXT_INT0_Interrupt_FlagClear()      (INTCONbits.INT0IF   = 0)
#define EXT_INT0_RisingEdgeSet()            (INTCON2bits.INTEDG0 = 1)
#define EXT_INT0_FallingEdgeSet()           (INTCON2bits.INTEDG0 = 0)

/*Eternal interrupt 1 Enable & Disable & Flag Clear and set edge mode*/
#define EXT_INT1_Interrupt_Enable()         (INTCON3bits.INT1IE  = 1)
#define EXT_INT1_Interrupt_Disable()        (INTCON3bits.INT1IE  = 0)
#define EXT_INT1_Interrupt_FlagClear()      (INTCON3bits.INT1IF  = 0)
#define EXT_INT1_RisingEdgeSet()            (INTCON2bits.INTEDG1 = 1)
#define EXT_INT1_FallingEdgeSet()           (INTCON2bits.INTEDG1 = 0)

/*Eternal interrupt 2 Enable & Disable & Flag Clear and set edge mode*/
#define EXT_INT2_Interrupt_Enable()         (INTCON3bits.INT2IE  = 1)
#define EXT_INT2_Interrupt_Disable()        (INTCON3bits.INT2IE  = 0)
#define EXT_INT2_Interrupt_FlagClear()      (INTCON3bits.INT2IF  = 0)
#define EXT_INT2_RisingEdgeSet()            (INTCON2bits.INTEDG2 = 1)
#define EXT_INT2_FallingEdgeSet()           (INTCON2bits.INTEDG2 = 0)

/*set priority if general priority enabled */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/*External interrupt 1,2 only can we set priority */
/*Interrupt 1 Priority Enable & Disable*/
#define EXT_INT1_HighPrioritySet()          (INTCON3bits.INT1IP = 1)
#define EXT_INT1_LowPrioritySet()           (INTCON3bits.INT1IP = 0)

/*Interrupt 2 Priority Enable & Disable*/
#define EXT_INT2_HighPrioritySet()          (INTCON3bits.INT2IP = 1)
#define EXT_INT2_LowPrioritySet()           (INTCON3bits.INT2IP = 0)

#endif

#endif

#if EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/*PORTB Interrupt OnChange Enable & disable & Flag clear*/
#define EXT_RBx_Interrupt_Enable()          (INTCONbits.RBIE = 1)
#define EXT_RBx_Interrupt_Disable()         (INTCONbits.RBIE = 0)
#define EXT_RBx_Interrupt_FlagClear()       (INTCONbits.RBIF = 0)
/*set priority if general priority enabled */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/*PORTB Interrupt OnChange Priority settings*/
#define EXT_RBx_PriorityHigh()              (INTCON2bits.RBIP = 1)
#define EXT_RBx_PriorityLow()               (INTCON2bits.RBIP = 0)

#endif
#endif
/******************Section: Macros Declarations***********/
typedef enum{
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE        
}interrupt_INTx_edge;

typedef enum
{
    INTERRUPT_EXTERNAL_INT0 = 0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2        
}interrupt_INTx_src;

typedef struct
{
    void(* EXT_InterruptHandler)(void);  /*to callback higher layers*/
    pin_config_t mcu_pin;                /*@ref: GPIO_Driver: pin_config_t*/
    interrupt_INTx_edge edge;            /*@ref: interrupt_INTx_edge , indicates to Edge mode */
    interrupt_INTx_src source;           /*@ref: interrupt_INTx_src , indicates to INTx number*/
    interrupt_priority_cfg priority;     /*@ref: interrupt_priority_cfg , indicates to Priority level*/
}interrupt_INTx_t;

typedef struct
{
    void(* EXT_InterruptHandler_HIGH)(void); /*to callback higher layers*/
    void(* EXT_InterruptHandler_LOW)(void);
    pin_config_t mcu_pin;               /*@ref: GPIO_Driver: pin_config_t*/
    interrupt_priority_cfg priority;     /*@ref: interrupt_priority_cfg , indicates to Priority level*/
}interrupt_RBx_t;

/******************Section: Data Types Declarations*******/

/******************Section: Functions Declarations********/
Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj);
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj);
Std_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *int_obj);
Std_ReturnType Interrupt_RBx_DeInit(const interrupt_RBx_t *int_obj);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

