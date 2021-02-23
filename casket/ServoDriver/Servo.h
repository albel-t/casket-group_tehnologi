/*
 * Servo.h
 *
 * Created: 19.02.2021 11:30:38
 *  Author: Alexander
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include <avr/io.h>
#define F_CPU 16000000
#include "PWM_Timer2.h"

void ServoWrite(uint8_t angleOfRotation);




#endif /* SERVO_H_ */