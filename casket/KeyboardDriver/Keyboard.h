/*
 * Keyboard.h
 *
 * Created: 19.02.2021 11:53:44
 *  Author: Alexander
 */ 


#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <avr/io.h>

#include "ManagingPins.h"
#include "PasswordEntry.h"

void KeyInit (uint8_t* contactInput, uint8_t* contactOutput);

uint8_t KeyRead(uint8_t* contactInput, uint8_t* contactOutput, uint8_t* reserveButtonSymbol);

uint8_t KeyLayout(uint8_t row, uint8_t column, uint8_t* buttonSymbol);

void KeyFood(uint8_t contactOutput, uint8_t pinCondition);


#endif /* KEYBOARD_H_ */