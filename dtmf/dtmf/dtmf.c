/*
 * dtmf.c
 *
 * Created: 25-06-2019 09:55:47
 *  Author: Shweta
 */ 


#include <avr/io.h>

int main(void)
{
	int x;
	DDRA=0b00000000;
	DDRD=0b11111111;
    while(1)
    {
        //TODO:: Please write your application code 
		x=PINA & 0b00001111;
		//PORTB=x;
		switch(x)
		{
			case 2:
			PORTD=0b00001010;  //forward
			break;
			
			case 4:
			PORTD=0b00001110;    //left
			break;
			
			case 6: 
			PORTD=0b00001011;    //right
			break;
			
			case 8:
			PORTD=0b00000101;     //back
			break;
			
			default:
			PORTD=0b00000000;    //stop
		}	
		
		/*if(x==0b00000010)
		{
			PORTB=0b00001010;
		}*/
    }
}