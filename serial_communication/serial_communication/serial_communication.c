/*
 * serial_communication.c
 *
 * Created: 28-06-2019 11:06:18
 *  Author: Shweta
 */ 


#include <avr/io.h>

int main(void)
{
	unsigned char a;
	a=Rx();
    while(1)
    {
        //TODO:: Please write your application code 
    }
}
USART_initialisation()
{
	UCSRB=0b00011000;   //to set transmission and reception
	UCSRC=0b10000110;   //to set length of the bit
	UBRRL=51;           //to set the baud rate
	UBRRH=0;
}
void UART_Tx(unsigned char data)
{
	while(!(UCSRA & 0b00100000))
	{
		UDR=data;
	}
}
unsigned char Rx(unsigned char data)
{
	while(!(UCSRA & (1<<RXC)))
	{
		UDR=data;
		return UDR;
	}
}