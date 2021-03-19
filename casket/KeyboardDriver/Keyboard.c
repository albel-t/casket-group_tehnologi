/*
 * Keyboard.c
 *
 * Created: 19.02.2021 11:53:33
 *  Author: Alexander
 */ 

#include "Keyboard.h"
#include "Usart.h"


uint8_t contactInput[3] = {8, 7, 6};         // column
uint8_t contactOutput[4] = {9, 10 , 11, 12}; // row

void KeyInit()
{
	for(int i = 0; i < 3; i++)
	{
		PinInit (contactInput[i], 0);
		PinWrite(contactInput[i], 1);
	}
	for(int i = 0; i < 4; i++)
	{
		PinInit (contactOutput[i], 1);
		PinWrite(contactOutput[i], 1);
	}
}

uint8_t KeyRead()
{
	uint8_t row;
	uint8_t column;
	uint8_t buttonSymbol = 255;
	uint8_t letGo;
	
	printf("begin keyboard read\r\n");
	while (buttonSymbol == 255)
	{
		for(row = 0; row <= 3 && buttonSymbol == 255; row++)
		{
			KeyFeed(contactOutput[row], 0);
			for(column = 0; column <= 2 && buttonSymbol == 255; column++)
			{
				//printf("\r\ncolumn = %d row = %d\r\n", column, row);
				if (PinRead(contactInput[column]) == 0)
				{
					buttonSymbol = KeyLayout(row, column, &buttonSymbol);
				}
			}
			KeyFeed(contactOutput[row], 1);
		}
	}
	//printf("key pressed\r\n");
	printf("buttonSymbol = %d\r\n", buttonSymbol);
	
	letGo = 1;
	while(letGo==1)
	{
		letGo = 0;
		for(row = 0; row <= 3; row++)
		{
			KeyFeed(contactOutput[row], 0);
			for(column = 0; column <= 2; column++)
			{
				if (PinRead(contactInput[column]) == 0)
				{
					letGo = 1;
				}
			}
			KeyFeed(contactOutput[row], 1);
		}
	}
	//printf("key unpressed\r\n");
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
	
	if (bSymbol == 101)
	{
		bSymbol = 0;
	}

	return bSymbol;
}

void KeyFeed(uint8_t contactOutput, uint8_t pinCondition)
{
	PinWrite(contactOutput, pinCondition);
}