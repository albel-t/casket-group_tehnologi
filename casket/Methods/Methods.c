/*
 * Methods.c
 *
 * Created: 19.02.2021 21:12:10
 *  Author: Alexander
 */ 
#include "Methods.h"

void Sleep()
{
	WritePassword(RightPassword);
	PinWrite(4, 0);
}

void ServoInit()
{
	Start_PWM_T2();
 SetPD3_PWM(OPEN_ANGLE);
  SetPD3_PWM(CLOSE_ANGLE);

}

void open()
{
	ServoWrite(OPEN_ANGLE);
}

void close()
{
	ServoWrite(CLOSE_ANGLE);
	LED_OFF();
}

void LED_ON()
{
	PinWrite(13, 1);
}
void LED_OFF()
{
	PinWrite(13, 0);
}
void LED_Init()
{
	PinInit(13, 1);
}