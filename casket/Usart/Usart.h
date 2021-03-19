/*
 * Usart.h
 *
 * Created: 03.01.2021 17:02:06
 *  Author: Alexander
 */ 


#ifndef USART_H_
#define USART_H_



#include <string.h>
#include <avr/io.h>
#include <stdio.h>
#define F_CPU 16000000
#define USART_BAUDRATE 9600
#define UBRR_VALUE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#define DEBUG_PRINTF

char message[64];

void USART_Init();

void USART_Transmit(uint8_t data);
void USART_SendString(char* stringPtr);

uint8_t USART_Receive();
void USART_ReceiveString(uint8_t* stringPtr);

void USART_Flush();


/////////////////////////////////////////////////////////////////////////////////////////////////////
FILE mystdout;
int uart_putchar(char c, FILE *f) __attribute__ ((noinline));
void debugPrintf(const char* str, ...);



#endif /* USART_H_ */