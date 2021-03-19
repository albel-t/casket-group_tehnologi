/*
* PasswordEntry.c
*
* Created: 19.02.2021 17:32:59
*  Author: Alexander
*/
#include "PasswordEntry.h"
#include "Usart.h"


void Password()
{
	printf("LED_Init\r\n");
	LED_Init();
	printf("KeyInit\r\n");
	KeyInit();
	printf("Timer2Init\r\n");
	Timer2Init();
	printf("ServoInit\r\n");
	ServoInit();
	printf("EndInit\r\n");
	

	if (eeprom_read_byte((uint8_t*)3) == 255)
	{
		eeprom_write_byte((uint8_t*)3, 0);
		WriteRightPassword(7777);
	}
	
	printf("ReadRightPassword begin\r\n");
	RightPassword = ReadRightPassword();
	printf("ReadRightPassword = %d\r\n", RightPassword);
	
	while(1)
	{
		ButtonSymbol = KeyRead();
		//printf("ButtonSymbol = %d\r\n", ButtonSymbol);
		
		if ((ButtonSymbol>=0) && (ButtonSymbol<=9))
		{
			ReadPassword(&IntroducedPassword, ButtonSymbol);
			printf("IntroducedPassword = %d\r\n", IntroducedPassword);
		}
		//ButtonSymbol = ResetPassword(IntroducedPassword);
		if (ButtonSymbol==100)
		{
			printf("Reset password\r\n");
			IntroducedPassword=0;
		}
		else if (ButtonSymbol==102)
		{
			printf("try OpenDoor IntroducedPassword = %d\r\n", IntroducedPassword);
/*			ButtonSymbol = ResetPassword(IntroducedPassword);
			if(ButtonSymbol==255)
			{
				ButtonSymbol = KeyRead();
			}*/
			OpenDoor(IntroducedPassword);
			
		}
	}

}


void OpenDoor(uint16_t IntroducedPassword)
{
	uint8_t LED = 0;
	if (ReadRightPassword() == IntroducedPassword)
	{
		printf("Right password\r\n");
		open();
		enter_new_password:
		while(1)
		{
		    ButtonSymbol = KeyRead();
			if ((ButtonSymbol>=0) && (ButtonSymbol<=9))
			{
				ReadPassword(&IntroducedPassword, ButtonSymbol);
				goto enter_new_password;
			}
 
			if (ButtonSymbol==1)
			{
				while(1)
				{
					ButtonSymbol = KeyRead();
					//printf("ButtonSymbol = %d\r\n", ButtonSymbol);
					
					if ((ButtonSymbol>=0) && (ButtonSymbol<=9))
					{
						ReadPassword(&IntroducedPassword, ButtonSymbol);
						printf("IntroducedPassword = %d\r\n", IntroducedPassword);
					}
					//ButtonSymbol = ResetPassword(IntroducedPassword);
					if (ButtonSymbol==100)
					{
						break;
					}
					else if (ButtonSymbol==102)
					{
						printf("IntroducedPassword = %d\r\n", IntroducedPassword);
						printf("RightPassword = IntroducedPassword\r\n", IntroducedPassword);
						RightPassword = IntroducedPassword;
					}
				}
			}
			else if (ButtonSymbol==102)
			{
				close();
				break;
			}
		 	
		 	else if (ButtonSymbol==100)
		 	{
				if(LED==0)
				{
					LED=1;
					LED_ON();
				}
				else
				{
					LED=0;
					LED_OFF();
				}
			}
		}
	}
	Sleep();
}

uint8_t ResetPassword(uint8_t IntroducedPassword)
{
	uint8_t thisButtonSymbol;
	if (IntroducedPassword == 1862)
	{
		thisButtonSymbol = KeyRead();
		if(thisButtonSymbol == 5)
		{
			GlobalReset();
		}
		else
		{
			return thisButtonSymbol;
		}
	}
	return 255;
}

void ReadPassword(uint16_t* introducedPasseord, uint8_t symbol)
{
	uint32_t thisIntroducedPassword = *introducedPasseord;
	
	thisIntroducedPassword = (thisIntroducedPassword*10) + symbol;
	
	if (thisIntroducedPassword > 9999)
	{
		thisIntroducedPassword = (uint16_t)(thisIntroducedPassword % 10000);
	}
	*introducedPasseord = thisIntroducedPassword;
}


void WriteRightPassword(uint16_t rightPassword)
{
	printf("rightPassword = %d\r\n", rightPassword);
	if (eeprom_read_word((uint16_t*)0) != rightPassword)
	{
		printf("eeprom_read_word != rightPassword\r\n");
		eeprom_write_word((uint16_t*)0, rightPassword);
	}
	else
	{
		printf("eeprom_read_word == rightPassword\r\n");
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


