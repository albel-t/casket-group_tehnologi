/*
 * PWM_Timer2.c
 * Created: 19.02.2021 11:16:04
 *  Author: Alexander
 */ 
#include "PWM_Timer2.h"


void Timer2Init()
{
	//DDRB |= (1 << 3); //инициализация 11 пина на выход
	DDRD |= (1 << 3);
			  /*подключение 11 выхода*/
	TCCR2A |= /*(1 << COM2A1)|(0 << COM2A0)|*/(1 << COM2B1)|(0 << COM2B0)|(1 << WGM21)|(1 << WGM20);
}


void SetPD3_PWM(uint8_t value)
{
	OCR2B = value;
}
/*
void SetPD5_PWM(uint8_t value)
{
	OCR0B = value;
}
*/
void Start_PWM_T2()
{
	SetPD3_PWM(19);
	//SetPB3_PWM(19);
	TCCR2B |= (1 << CS22)|(1 << CS21)|(1 << CS20); //OCR2B = 127;
}

void Stop_PWM_T2()
{
	TCCR2B &= ~(1 << CS22)|(1 << CS21)|(1 << CS20);
}


