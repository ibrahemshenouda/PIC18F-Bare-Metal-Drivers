
/* 
 * File:   mcal_external_interrupt.c
 * Author: Ibrahim Shenouda
 *
 * Created on 14 Mar, 2025, 03:30 
 */
#include "mcal_external_interrupt.h"


static void (*INT0_InterruptHandler)(void) = NULL;
static void (*INT1_InterruptHandler)(void) = NULL;
static void (*INT2_InterruptHandler)(void) = NULL;

static void (*RB4_InterruptHandler_HIGH)(void) = NULL;
static void (*RB4_InterruptHandler_LOW) (void) = NULL;
static void (*RB5_InterruptHandler_HIGH)(void) = NULL;
static void (*RB5_InterruptHandler_LOW) (void) = NULL;
static void (*RB6_InterruptHandler_HIGH)(void) = NULL;
static void (*RB6_InterruptHandler_LOW) (void) = NULL;
static void (*RB7_InterruptHandler_HIGH)(void) = NULL;
static void (*RB7_InterruptHandler_LOW) (void) = NULL;


/*************Helper Functions Prototypes*************/
static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj);

static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj);

static Std_ReturnType Interrupt_RBx_Enable(const interrupt_RBx_t *int_obj);
static Std_ReturnType Interrupt_RBx_Disable(const interrupt_RBx_t *int_obj);
static Std_ReturnType Interrupt_RBx_Priority_Init(const interrupt_RBx_t *int_obj);
static Std_ReturnType Interrupt_RBx_Pin_Init(const interrupt_RBx_t *int_obj);



void INT0_ISR(void)
{
    /*Interrupt clear*/
    EXT_INT0_Interrupt_FlagClear();
    /*code*/
     
    /*callback */
    if(NULL != INT0_InterruptHandler)
    {
        INT0_InterruptHandler();
    }
}
void INT1_ISR(void)
{
    /*Interrupt clear*/
    EXT_INT1_Interrupt_FlagClear();
    /*code*/
    
    /*callback */
    if(NULL != INT1_InterruptHandler)
    {
        INT1_InterruptHandler();
    }
}
void INT2_ISR(void)
{
    /*Interrupt flag clear*/
    EXT_INT2_Interrupt_FlagClear();
    /*code*/
    
    /*callback */
    if(NULL != INT2_InterruptHandler)
    {
        INT2_InterruptHandler();
    }
}

void RB4_ISR(uint8 source)
{
    
    EXT_RBx_Interrupt_FlagClear();
    
    if((1 == source) && (NULL != RB4_InterruptHandler_HIGH))
    {
        RB4_InterruptHandler_HIGH();
    }
    else if((0 == source) && (NULL != RB4_InterruptHandler_LOW))
    {
        RB4_InterruptHandler_LOW();
    }
    else{/*Nothing*/}
}
void RB5_ISR(uint8 source)
{
    
    EXT_RBx_Interrupt_FlagClear();
    
    if((1 == source) && (NULL != RB5_InterruptHandler_HIGH))
    {
        RB5_InterruptHandler_HIGH();
    }
    else if((0 == source) && (NULL != RB5_InterruptHandler_LOW))
    {
        RB5_InterruptHandler_LOW();
    }
    else{/*Nothing*/}
}

void RB6_ISR(uint8 source)
{
    
    EXT_RBx_Interrupt_FlagClear();
    
    if((1 == source) && (NULL != RB6_InterruptHandler_HIGH))
    {
        RB6_InterruptHandler_HIGH();
    }
    else if((0 == source) && (NULL != RB6_InterruptHandler_LOW))
    {
        RB6_InterruptHandler_LOW();
    }
    else{/*Nothing*/}
}

void RB7_ISR(uint8 source)
{
    
    EXT_RBx_Interrupt_FlagClear();
    
    if((1 == source) && (NULL != RB7_InterruptHandler_HIGH))
    {
        RB7_InterruptHandler_HIGH();
    }
    else if((0 == source) && (NULL != RB7_InterruptHandler_LOW))
    {
        RB7_InterruptHandler_LOW();
    }
    else{/*Nothing*/}
}

Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*Disable the External Interrupt*/
        ret = Interrupt_INTx_Disable(int_obj);
        /*Clear this Interrupt Flag*/
        ret = Interrupt_INTx_Clear_Flag(int_obj);
        /*Configure External Interrupt Edge*/
        ret = Interrupt_INTx_Edge_Init(int_obj);
        /*Configure External Interrupt Priority*/
        #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        ret = Interrupt_INTx_Priority_Init(int_obj);
        #endif
        /*Configure External Interrupt I/O pin*/
        ret = Interrupt_INTx_Pin_Init(int_obj);
        /*Configure Default  Interrupt CallBack*/
        ret = Interrupt_INTx_SetInterruptHandler(int_obj);
        /*Enable the External Interrupt*/
        ret = Interrupt_INTx_Enable(int_obj);
    }
    return ret;
}

Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = Interrupt_INTx_Disable(int_obj);
    }
    return ret;
}


Std_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        EXT_RBx_Interrupt_Disable();
        EXT_RBx_Interrupt_FlagClear();
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PriorityLevelEnable();
        if(INTERRUPT_HIGH_PRIORITY == int_obj->priority)
        {
            INTERRUPT_GlobalInterruptHighEnable();
            EXT_RBx_PriorityHigh();
        }
        else if(INTERRUPT_LOW_PRIORITY == int_obj->priority)
        {
            INTERRUPT_GlobalInterruptLowEnable();
            EXT_RBx_PriorityLow();
        }
        else{ /*Nothing*/ }
#else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
        ret = gpio_pin_direction_intialize(&(int_obj->mcu_pin));
        switch(int_obj->mcu_pin.pin)
        {
            case GPIO_PIN4:
                RB4_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                RB4_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                break;
            case GPIO_PIN5:
                RB5_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                RB5_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                break;
            case GPIO_PIN6:
                RB6_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                RB6_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                break;
            case GPIO_PIN7:
                RB7_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                RB7_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                break;    
            default: ret = E_NOT_OK;
        }
        EXT_RBx_Interrupt_Enable();
    }
    return ret;
}


Std_ReturnType Interrupt_RBx_DeInit(const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
    }
    return ret;
}

/*********Helper Functions***********/
static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0 :
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PriorityLevelEnable();
                INTERRUPT_GlobalInterruptHighEnable();

#else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
#endif
                EXT_INT0_Interrupt_Enable(); 
                break;
                
            case INTERRUPT_EXTERNAL_INT1 :
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PriorityLevelEnable();
                if(INTERRUPT_HIGH_PRIORITY == int_obj->priority)
                {
                    INTERRUPT_GlobalInterruptHighEnable();
                }
                else if(INTERRUPT_LOW_PRIORITY == int_obj->priority)
                {
                    INTERRUPT_GlobalInterruptLowEnable();
                }
                else{/* Nothing */}

#else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
#endif
                EXT_INT1_Interrupt_Enable(); 
                break;
                
            case INTERRUPT_EXTERNAL_INT2 :
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PriorityLevelEnable();
                if(INTERRUPT_HIGH_PRIORITY == int_obj->priority)
                {
                    INTERRUPT_GlobalInterruptHighEnable();
                }
                else if(INTERRUPT_LOW_PRIORITY == int_obj->priority)
                {
                    INTERRUPT_GlobalInterruptLowEnable();
                }
                else{/* Nothing */}

#else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
#endif
                EXT_INT2_Interrupt_Enable(); 
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
    
}
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0 : 
                EXT_INT0_Interrupt_Disable(); 
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                EXT_INT1_Interrupt_Disable(); 
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                EXT_INT2_Interrupt_Disable(); 
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT1:
                if(INTERRUPT_HIGH_PRIORITY == int_obj->priority)
                {
                    EXT_INT1_HighPrioritySet();
                }
                else if(INTERRUPT_LOW_PRIORITY  == int_obj->priority)
                {
                    EXT_INT1_LowPrioritySet();
                }
                else{/* Nothing */}
                break;
            case INTERRUPT_EXTERNAL_INT2:
                if(INTERRUPT_HIGH_PRIORITY == int_obj->priority)
                {
                    EXT_INT2_HighPrioritySet();
                }
                else if(INTERRUPT_LOW_PRIORITY == int_obj->priority)
                {
                    EXT_INT2_LowPrioritySet();
                }
                else{/* Nothing */}
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0:
                if(INTERRUPT_FALLING_EDGE == int_obj->edge)
                {
                    EXT_INT0_FallingEdgeSet();
                }
                else if(INTERRUPT_RISING_EDGE == int_obj->edge)
                {
                    EXT_INT0_RisingEdgeSet();
                }
                else{/* Nothing */}
                break;
            case INTERRUPT_EXTERNAL_INT1: 
                if(INTERRUPT_FALLING_EDGE == int_obj->edge)
                {
                    EXT_INT1_FallingEdgeSet();
                }
                else if(INTERRUPT_RISING_EDGE == int_obj->edge)
                {
                    EXT_INT1_RisingEdgeSet();
                }
                else{/* Nothing */}
                break;
            case INTERRUPT_EXTERNAL_INT2:
                if(INTERRUPT_FALLING_EDGE == int_obj->edge)
                {
                    EXT_INT2_FallingEdgeSet();
                }
                else if(INTERRUPT_RISING_EDGE == int_obj->edge)
                {
                    EXT_INT2_RisingEdgeSet();
                }
                else{/* Nothing */}
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_direction_intialize(&(int_obj->mcu_pin));
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0:
                EXT_INT0_Interrupt_FlagClear();
                break;
            case INTERRUPT_EXTERNAL_INT1:
                EXT_INT1_Interrupt_FlagClear();
                break;
            case INTERRUPT_EXTERNAL_INT2:
                EXT_INT1_Interrupt_FlagClear();
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}
static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void))
{
    Std_ReturnType ret = E_OK;
    if(NULL == InterruptHandler)
    {
        ret = E_NOT_OK;
    }
    else
    {
        INT0_InterruptHandler = InterruptHandler;
    }
    return ret;
}

static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void))
{
    Std_ReturnType ret = E_OK;
    if(NULL == InterruptHandler)
    {
        ret = E_NOT_OK;
    }
    else
    {
        INT1_InterruptHandler = InterruptHandler;
    }
    return ret;
}

static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void))
{
    Std_ReturnType ret = E_OK;
    if(NULL == InterruptHandler)
    {
        ret = E_NOT_OK;
    }
    else
    {
        INT2_InterruptHandler = InterruptHandler;
    }
    return ret;
}

static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0:
                ret = INT0_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT1:
                ret = INT1_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT2:
                ret = INT2_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

static Std_ReturnType Interrupt_RBx_Enable(const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
    }
    return ret;
}
static Std_ReturnType Interrupt_RBx_Disable(const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
    }
    return ret;   
}
static Std_ReturnType Interrupt_RBx_Priority_Init(const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
    }
    return ret;    
}
static Std_ReturnType Interrupt_RBx_Pin_Init(const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
    }
    return ret;   
}