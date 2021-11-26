/*
 * sensor2.c
 *
 * Created: 13-06-2019 10:56:27
 *  Author: Shweta
 */ 


#include <avr/io.h>

int main(void)
{
	DDRA=0b00000000;
	DDRB=0b11111111;
    while(1)
    {
        //TODO:: Please write your application code 
		int x = PINA & 0b00000011;
		switch(x)
		{
		case 0:
		PORTB = 255;
		break;
		case 1:
		PORTB = 0b11110000;
		break;
		case 2:
		PORTB = 0b00001111;
		break;
		case 3:
		PORTB = 0;
		break;
		default:
		break;
		}	
		/*if(x == 0)                              this is also working
		{
			PORTB = 255;
		}
		else if(x == 0b00000001)
		{
			PORTB = 0b11110000;
		}
		else if(x == 0b00000010)
		{
			PORTB = 0b00001111;
		}
		else if(x == 1)
		{
			PORTB = 0;
		} */
		
    }
}