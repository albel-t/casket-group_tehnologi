/*
 * ManagingPins.c
 *
 * Created: 19.02.2021 11:46:17
 *  Author: Alexander
 */ 
#include "ManagingPins.h"

void PinInit (uint8_t pinNumber, uint8_t pinCondition)
{
	if (pinNumber <= 13)
	{
		if (pinCondition == 1)
		{
			if ((pinNumber <= 13)&&(pinNumber >= 8))
			{
				DDRB |= (1 << (pinNumber-8));
			}
			else if ((pinNumber <= 7)&&(pinNumber >= 0))
			{
				DDRD |= (1 << pinNumber);
			}
		}
		else if (pinCondition == 0)
		{
			if ((pinNumber <= 13)&&(pinNumber >= 8))
			{
				DDRB &= ~(1 << (pinNumber-8));
			}
			else if ((pinNumber <= 7)&&(pinNumber >= 0))
			{
				DDRD &= ~(1 << pinNumber);
			}
		}
	}
	else
	{
		//Error
	}
}

void PinWrite (uint8_t pinNomber, uint8_t pinCondition)
{
	if (pinNomber <= 13)
	{
		if (pinCondition == 1)
		{
			if ((pinNomber <= 13)&&(pinNomber >= 8))
			{
				PORTB |= (1 << (pinNomber-8));
			}
			else if ((pinNomber <= 8)&&(pinNomber >= 0))
			{
				PORTD |= (1 << pinNomber);
			}
		}
		else if (pinCondition == 0)
		{
			if ((pinNomber <= 13)&&(pinNomber >= 8))
			{
				PORTB &= ~(1 << (pinNomber-8));
			}
			else if ((pinNomber <= 8)&&(pinNomber >= 0))
			{
				PORTD &= ~(1 << pinNomber);
			}
		}
	}
	else
	{
		//Error
	}
}

uint8_t PinRead (uint8_t pinNomber)
{
	uint8_t pinCondition = 0;
	
	if (pinNomber <= 13)
	{
		if ((pinNomber <= 13)&&(pinNomber >= 8))
		{
			if ((pinNomber-8) == (PINB & (pinNomber-8)))
			{
				pinCondition = 1;
			}
			else if (!(pinNomber == (PINB & pinNomber)))
			{
				pinCondition = 0;
			}
		}
		else if ((pinNomber <= 8)&&(pinNomber >= 0))
		{
			if (pinNomber == (PIND & pinNomber))
			{
				pinCondition = 1;
			}
			else if (!(pinNomber == (PIND & pinNomber)))
			{
				pinCondition = 0;
			}
		}
	}
	else
	{
		//Error
	}
	return pinCondition;
}
