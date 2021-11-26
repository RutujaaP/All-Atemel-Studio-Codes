/*
 * try1.c
 *
 * Created: 27-06-2019 09:49:42
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>
int main(void)
{
	int x;
	DDRA=0b00000000;
	DDRD=0b11111111;
	int b[10]={0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};    //common cathod connected to portd
    while(1)
    {
        //TODO:: Please write your application code 
		x=PINA & 0b00001111;
		PORTD=b[x];
		_delay_ms(100);
    }
}