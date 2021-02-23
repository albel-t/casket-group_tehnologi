/*
 * ManagingPins.h
 *
 * Created: 19.02.2021 11:46:27
 *  Author: Alexander
 */ 


#ifndef MANAGINGPINS_H_
#define MANAGINGPINS_H_

#include <avr/io.h>

#define OUTPUT 1
#define INPUT 0

#define TRUE 1
#define FALSE 0

#define HIGH 1
#define LOW 0

void PinInit (uint8_t pinNumber, uint8_t pinCondition);

void PinWrite (uint8_t pinNumber, uint8_t pinCondition);

uint8_t PinRead (uint8_t pinNumber);


#endif /* MANAGINGPINS_H_ */