/*
 * Usart.c
 *
 * Created: 03.01.2021 17:01:51
 *  Author: Alexander
 */ 
/*
 * TestUARTApplication.c
 *
 * Created: 02.01.2021 18:20:44
 * Author : Alexander
 */ 
#include "Usart.h"

FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
//int uart_putchar(char c, FILE *f) __attribute__ ((noinline));
//FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

void USART_Init()
{

	UBRR0H = (uint8_t)(UBRR_VALUE>>8);
	UBRR0L = (uint8_t)UBRR_VALUE;
	
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (0<<USBS0)|(3<<UCSZ00);
}

void USART_Transmit(uint8_t data)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );
	/* Put data into buffer, sends the data */
	UDR0 = data;
}
void USART_SendString(char* stringPtr)
{
	uint8_t* strPtr = (uint8_t*)stringPtr;
	while(*strPtr != 0x00)
	{
	   USART_Transmit(*strPtr);
	   strPtr++;
	}
	
}

uint8_t USART_Receive()
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) );
	/* Get and return received data from buffer */
	return UDR0;
}
void USART_ReceiveString(uint8_t* stringPtr)
{
	USART_Flush();
	uint8_t* strPtr = stringPtr;
	while(1)
	{
		*strPtr = USART_Receive();
		if (*strPtr == '\r') break;
		strPtr++;
	}
	*strPtr = 0x00;
}

void USART_Flush()
{
	volatile uint8_t __attribute__((unused)) dummy;
	while ( UCSR0A & (1<<RXC0) ) dummy = UDR0;
}//////////////////////////////////////////////////////////////////////////////////////////////////////////int uart_putchar(char c, FILE *stream)
{

	//if(c=='\n')	uart_putchar('\r',stream);

	USART_Transmit(c);

	return 0;
}

void debugPrintf(const char* str, ...)
{
	#ifdef DEBUG_PRINTF
	va_list argptr;
	va_start(argptr, str);
	vprintf(str, argptr);
	va_end(argptr);
	#endif
}