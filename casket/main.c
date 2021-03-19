/*
 * casket.c
 *
 * Created: 19.02.2021 11:00:41
 * Author : Alexander
 */ 

#include "main.h"
#include "Usart.h"

int main(void)
{
	USART_Init();
	stdout = &mystdout;
	 
	printf("Program begin\r\n");
	 
	Password();
}

