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

uint8_t contactInput[3];
uint8_t contactOutput[4];

void KeyInit ();

uint8_t KeyRead();

uint8_t KeyLayout(uint8_t row, uint8_t column, uint8_t* buttonSymbol);

void KeyFeed(uint8_t contactOutput, uint8_t pinCondition);


#endif /* KEYBOARD_H_ */