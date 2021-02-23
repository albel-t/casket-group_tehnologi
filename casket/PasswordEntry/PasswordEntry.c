/*
 * PasswordEntry.c
 *
 * Created: 19.02.2021 17:32:59
 *  Author: Alexander
 */ 
#include "PasswordEntry.h"


void Password()
{
	if (eeprom_read_byte((uint8_t*)3) == 255)
	{
		eeprom_write_byte((uint8_t*)3, 0);
		WriteRightPassword(7777);
	}
	RightPassword = ReadRightPassword();
	enter_password:
	ButtonSymbol = KeyRead(contactInput, contactOutput, &ButtonSymbol);
	if ((ButtonSymbol>=0) || (ButtonSymbol<=9))
	{
		IntroducedPassword = ReadPassword(ButtonSymbol);
		ButtonSymbol = ResetPassword(IntroducedPassword);
		if (ButtonSymbol==100)
		{
			IntroducedPassword=0;
			goto enter_password;
		} 
		else if (ButtonSymbol==102)
		{
			OpenDoor(IntroducedPassword);
		}
	}
	else if (ButtonSymbol==102)
	{
		goto enter_password;
	}
	Sleep();
}

void OpenDoor(uint16_t IntroducedPassword)
{
	uint8_t LED = 0;
	if (ReadRightPassword() == IntroducedPassword)
	{
		open();
		enter_new_password:
		ButtonSymbol = KeyRead(contactInput, contactOutput, &ButtonSymbol);
		if ((ButtonSymbol>=0) || (ButtonSymbol<=9))
		{
			IntroducedPassword = ReadPassword(ButtonSymbol);
			ButtonSymbol = ResetPassword(IntroducedPassword);
			if (ButtonSymbol==100)
			{
				IntroducedPassword=0;
				goto enter_new_password;
			}
			else if (ButtonSymbol==102)
			{
				RightPassword = IntroducedPassword;
				goto enter_new_password;
			}
		}
		else if (ButtonSymbol==100)
		{
			if (LED == 0)
			{
				LED_ON();
				LED = 1;
			}
			
			if (LED == 1)
			{
				LED_OFF();
				LED = 0;
			}
			goto enter_new_password;
		}
		else if (ButtonSymbol==102)
		{
			close();
		}
	}
	Sleep();
}

uint8_t ResetPassword(uint8_t IntroducedPassword)
{
	uint8_t thisButtonSymbol;
	thisButtonSymbol = KeyRead(contactInput, contactOutput, &ButtonSymbol);
	if (IntroducedPassword == 1862)
	{
		if((thisButtonSymbol>=0)&&(thisButtonSymbol<=9))
		{
			IntroducedPassword = (IntroducedPassword*10) + ButtonSymbol;
			
			if (IntroducedPassword == 18625)
			{
				GlobalReset();
			}
		}
		else
		{
			return thisButtonSymbol;
		}
	}
	else
	{
		return thisButtonSymbol;
	}
}

uint16_t ReadPassword(uint8_t ButtonSymbol)
{
	uint16_t thisIntroducedPassword;
	uint8_t thisButtonSymbol = ButtonSymbol;
	for (;ButtonSymbol<=9;)
	{
		if (IntroducedPassword > 9999)
		{
			thisIntroducedPassword = thisButtonSymbol;
		}
		else
		{
			thisIntroducedPassword = (IntroducedPassword*10) + thisButtonSymbol;
		}
		thisButtonSymbol = KeyRead(contactInput, contactOutput, &ButtonSymbol);
	}
	return thisIntroducedPassword;
}


void WriteRightPassword(uint16_t rightPassword)
{
	if (eeprom_read_word((uint16_t*)0) != rightPassword)
	{
		eeprom_write_word((uint16_t*)0, rightPassword);
	}
}
uint16_t ReadRightPassword()
{
	return eeprom_read_word((uint16_t*)0);
}
void WritePassword(uint16_t rightPassword)
{
	if (eeprom_read_byte((uint8_t*)3) == 255)
	{
		eeprom_write_byte((uint8_t*)3, 1);
		WriteRightPassword(7777);
	}
	else
	{
		WriteRightPassword(rightPassword);
	}
}
void GlobalReset()
{
	eeprom_write_byte((uint8_t*)3, 255);
	eeprom_write_word((uint16_t*)0, 7777);
}


