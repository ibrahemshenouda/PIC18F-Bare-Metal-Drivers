/* 
 * File:   ecu_keypad.h
 * Author: Ibrahim Shenouda
 *
 * Created on 15 ??????, 2024, 09:26 ?
 */

#include "ecu_keypad.h"

static const uint8  btn_vlaues[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS] = {
                                                                       {'7', '8', '9', '/'},
                                                                       {'4', '5', '6', '*'},
                                                                       {'1', '2', '3', '-'},
                                                                       {'#', '0', '=', '+'}
                                                                      };

/**
 * @preif :
 * @param :_keypad_obj
 * @return: status of the function 
 *         (E_OK): the function done successfully 
 *         (E_NOT_OK): the function has issue to perform this action
 */
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj)
{
    Std_ReturnType ret = E_OK;
    uint8 rows_counter = ZERO_INIT, columns_counter = ZERO_INIT;
    if(NULL == _keypad_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        for(rows_counter = ZERO_INIT; rows_counter < ECU_KEYPAD_ROWS; rows_counter++)
        {
            gpio_pin_intialize(&(_keypad_obj->keypad_rows_pins[rows_counter]));
        }
        
        for(columns_counter = ZERO_INIT; columns_counter < ECU_KEYPAD_COLUMNS; columns_counter++)
        {
            gpio_pin_direction_intialize(&(_keypad_obj->keypad_columns_pins[columns_counter]));
        }
    }
    return ret;
}


/**
 * @preif :
 * @param : _keypad_obj
 * @param : value 
 * @return: status of the function 
 *         (E_OK): the function done successfully 
 *         (E_NOT_OK): the function has issue to perform this action
 */
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj, uint8 *value)
{
    Std_ReturnType ret = E_OK;
    uint8 rows_counter = ZERO_INIT, columns_counter = ZERO_INIT, counter = ZERO_INIT;
    uint8 column_logic = ZERO_INIT;
    if((NULL == _keypad_obj) || (NULL == value))
    {
        ret = E_NOT_OK;
    }
    else
    {
        for(rows_counter = ZERO_INIT; rows_counter < ECU_KEYPAD_ROWS; rows_counter++)
        {
            for(counter = ZERO_INIT; counter < ECU_KEYPAD_ROWS; counter++)
            {
                ret = gpio_pin_write_logic(&(_keypad_obj->keypad_rows_pins[counter]), GPIO_LOW);
            }
            ret = gpio_pin_write_logic(&(_keypad_obj->keypad_rows_pins[rows_counter]), GPIO_HIGH);
            for(columns_counter = ZERO_INIT; columns_counter < ECU_KEYPAD_COLUMNS; columns_counter++)
            {
                ret = gpio_pin_read_logic(&(_keypad_obj->keypad_columns_pins[columns_counter]),&column_logic);
                if(GPIO_HIGH == column_logic)
                {
                    *value = btn_vlaues[rows_counter][columns_counter];
                }
            }
        }
        
        
    }
    return ret;
}
