/*
 * ManagingPins.c
 *
 * Created: 19.02.2021 11:46:17
 *  Author: Alexander
 */ 
#include "ManagingPins.h"
#include "Usart.h"

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

void PinWrite (uint8_t pinNumber, uint8_t pinCondition)
{
	if (pinNumber <= 13)
	{
		if (pinCondition == 1)
		{
			if ((pinNumber <= 13)&&(pinNumber >= 8))
			{
				PORTB |= (1 << (pinNumber-8));
			}
			else if ((pinNumber <= 8)&&(pinNumber >= 0))
			{
				PORTD |= (1 << pinNumber);
			}
		}
		else if (pinCondition == 0)
		{
			if ((pinNumber <= 13)&&(pinNumber >= 8))
			{
				PORTB &= ~(1 << (pinNumber-8));
			}
			else if ((pinNumber <= 8)&&(pinNumber >= 0))
			{
				PORTD &= ~(1 << pinNumber);
			}
		}
	}
	else
	{
		//Error
	}
}

uint8_t PinRead (uint8_t pinNumber)
{
	uint8_t pinCondition = 0;
	uint8_t pin;
	
	if (pinNumber <= 13)
	{
		if ((pinNumber >= 8)&&(pinNumber <= 13))
		{
			pinNumber -=8;
			pin = 1 << pinNumber;
			if (pin == (PINB & pin))
			{
				pinCondition = 1;
			}
			else
			{
				//printf("pinNumber = %d\r\n", pinNumber + 8);
				pinCondition = 0;
			}
		}
		else if ((pinNumber <= 7)&&(pinNumber >= 0))
		{
			pin = 1 << pinNumber;
			if (pin == (PIND & pin))
			{
				pinCondition = 1;
			}
			else
			{
				//printf("pinNumber = %d\r\n", pinNumber);
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
