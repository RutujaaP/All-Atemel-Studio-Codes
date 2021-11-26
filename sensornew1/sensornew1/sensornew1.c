/*
 * sensornew1.c
 *
 * Created: 13-06-2019 11:38:39
 *  Author: Shweta
 */ 


#include <avr/io.h>

int main(void)
{
	DDRA=0b00000000;   // to detect the input
	DDRB=0b11111111;   //to detect the output (glowing of led)
	int count = 0, temp = 0;
    while(1)
    {
        //TODO:: Please write your application code 
		int x = PINA & 0b00000001;
		if(x==0 && temp==0)
		{
			temp=1;
		}
		else if(x==1 && temp==1)
		{
			count++;
			PORTB=count;
			temp=0;
			//_delay_ms(1000);
		}
    }
}