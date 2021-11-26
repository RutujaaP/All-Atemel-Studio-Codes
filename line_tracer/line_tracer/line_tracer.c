/*
 * line_tracer.c
 *
 * Created: 23-06-2019 09:33:41
 *  Author: Shweta
 */ 


#include <avr/io.h>
//#include <avr/delay.h>

int main(void)
{
	DDRA=0b11111111;
	DDRC=0b00000000;
	int x,y,z;
    while(1)
    {
        //TODO:: Please write your application code 
		
		y = PIND & 0b00000001;
		if(y==0)
		{
			PORTA=0b00000000;
		}
		else if(y==1)
		{
			{
				//PORTA=0b00001010;
				x = PINC & 0b00000011;
				switch(x)
				{
					case 0:
					PORTA=0b00001010;   //forward
					break;
					
					case 1:
					PORTA=0b00001011;   //right  turn
					break;
					
					case 2:
					PORTA=0b00001110;   //left   turn
					break;
					
					case 3:
					PORTA=0b00001111;   //stop
					break;
					
					default:
					PORTA=0b00000000;
					PORTA=0b00000101;
					z = PINC & 0b00000011;
					if(z==0b00000001)
					{
						PORTA=0b00001011;     //right  turn
					}
					else if(z==0b00000010)
					{
						PORTA=0b00001110;      //left  turn
					}
				}
			}
		}
		
		
    }
}