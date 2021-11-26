/*
 * lcd.c
 *
 * Created: 12-06-2019 10:06:25
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRD=0b1111111;
	int number[10]={0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};   //common cathode
	/*PORTD=0b0000110;
	_delay_ms(500);
	PORTD=0b1011011;
	_delay_ms(500);
	PORTD=0b1001111;
	_delay_ms(500);
	PORTD=0b1100110;  */
    while(1)
    {
        //TODO:: Please write your application code 
		for(int i=0;i<10;i++)
		{
			PORTD=number[i];
			_delay_ms(500);
		}
		
    }
}