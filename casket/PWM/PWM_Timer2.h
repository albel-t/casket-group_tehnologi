/*
 * PWM_Timer2.h
 *
 * Created: 19.02.2021 11:16:20
 *  Author: Alexander
 */ 


#ifndef PWM_TIMER2_H_
#define PWM_TIMER2_H_

#include <avr/io.h>
#define F_CPU 16000000


void Timer2Init();

void SetPD3_PWM(uint8_t value);
/*
void SetPD5_PWM(uint8_t value);
*/
void Start_PWM_T2();

void Stop_PWM_T2();





#endif /* PWM_TIMER2_H_ */