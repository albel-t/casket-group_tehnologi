/*
 * Keyboard.c
 *
 * Created: 19.02.2021 11:53:33
 *  Author: Alexander
 */ 

#include "Keyboard.h"

void KeyInit (uint8_t* contactInput, uint8_t* contactOutput)
{
	for(int i = 0; i <= 3; i++)
	{
		PinInit (contactInput[i], 0);
		PinInit (contactOutput[i], 1);
	}
}

uint8_t KeyRead(uint8_t* contactInput, uint8_t* contactOutput, uint8_t* reserveButtonSymbol)
{
	uint8_t row;
	uint8_t column;
	uint8_t buttonSymbol = 255;
	uint8_t letGo;
	
	for(row = 0; row <= 3; row++)
	{
		KeyFood(contactOutput[row], 1);
		for(column = 0; column <= 2; column++)
		{
			if (PinRead(contactInput[column]) == 1)
			{
				buttonSymbol = KeyLayout(row, column, &buttonSymbol);
			}
		}
		KeyFood(contactOutput[row], 0);
	}
	
	while(letGo)
	{
		for(row = 0; row <= 3; row++)
		{
			KeyFood(contactOutput[row], 1);
			for(column = 0; column <= 2; column++)
			{
				if (PinRead(contactInput[column]) == 1)
				{
					letGo = 1;
				}
			}
			KeyFood(contactOutput[row], 0);
		}
	}
	
	return buttonSymbol;
}

uint8_t KeyLayout(uint8_t row, uint8_t column, uint8_t* buttonSymbol)
{
	uint8_t bSymbol = 255;

	switch(row)
	{
		case 0:
		bSymbol = 1;
		break;
		case 1:
		bSymbol = 4;
		break;
		case 2:
		bSymbol = 7;
		break;
		case 3:
		bSymbol = 100;
		break;
	}
	switch(column)
	{
		case 0:
		bSymbol += 0;
		break;
		case 1:
		bSymbol += 1;
		break;
		case 2:
		bSymbol += 2;
		break;
	}
	
	if (bSymbol == 104)
	{
		bSymbol = 0;
	}

	return bSymbol;
}

void KeyFood(uint8_t contactOutput, uint8_t pinCondition)
{
	PinWrite(contactOutput, pinCondition);
}