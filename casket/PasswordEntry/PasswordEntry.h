/*
 * PasswordEntry.h
 *
 * Created: 19.02.2021 17:33:07
 *  Author: Alexander
 */ 


#ifndef PASSWORDENTRY_H_
#define PASSWORDENTRY_H_

#include <avr/io.h>
#include <avr/eeprom.h>

#include "Keyboard.h"
#include "Servo.h"
#include "ManagingPins.h"
#include "Methods.h"

uint8_t ButtonSymbol;
uint16_t RightPassword;
uint16_t IntroducedPassword;

void Password();
void OpenDoor(uint16_t IntroducedPassword);
uint8_t ResetPassword(uint8_t IntroducedPassword);
void ReadPassword(uint16_t* introducedPasseord, uint8_t symbol);
void WriteRightPassword(uint16_t rightPassword);
uint16_t ReadRightPassword();
void WritePassword(uint16_t rightPassword);
void GlobalReset();


uint16_t ReadRightPassword();



#endif /* PASSWORDENTRY_H_ */