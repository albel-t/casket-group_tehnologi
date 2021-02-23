/*
 * Servo.c
 *
 * Created: 19.02.2021 11:30:20
 *  Author: Alexander
 */ 
#include "Servo.h"

void ServoWrite(uint8_t angleOfRotation)
{
	angleOfRotation = angleOfRotation + 7;
	
	if (angleOfRotation > 32)
	{
		angleOfRotation = 32;
	}
	else if (angleOfRotation < 7)
	{
		angleOfRotation = 7;
	}
	
	SetPD3_PWM(angleOfRotation);
}
