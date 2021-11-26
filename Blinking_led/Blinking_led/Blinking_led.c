/*
 * Blinking_led.c
 *
 * Created: 11-06-2019 10:22:49
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRA=0b11111111;
    while(1)
    {
		//TODO:: Please write your application code 
		PORTA=0b11111111;
		_delay_ms(1000);
		PORTA=0b00000000;
		_delay_ms(1000);
    }
}