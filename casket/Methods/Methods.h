/*
 * Methods.h
 *
 * Created: 19.02.2021 21:12:20
 *  Author: Alexander
 */ 


#ifndef METHODS_H_
#define METHODS_H_
#include "Servo.h"
#include "ManagingPins.h"
#include "PasswordEntry.h"

#include <avr/io.h>

#define OPEN_ANGLE 30
#define CLOSE_ANGLE 3


void Sleep();

void ServoInit();

void open();
void close();

void LED_ON();
void LED_OFF();




#endif /* METHODS_H_ */