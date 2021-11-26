/*
 * motor1.c
 *
 * Created: 22-06-2019 08:50:53
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>
int main(void)
{
	int x;
	
	DDRA=0b11111111;
	DDRD=0b00000000;
	//PORTA=0b00001010;
	PORTA=0b00000000;
	while(1)
	{
	x = PIND & 0b00000001;
	if(x==0)
	{
	      PORTA=0b00001010;	
		  _delay_ms(500);
		/*PORTA=0b00000000;   //stop
		_delay_ms(5000);
		PORTA=0b00000101;   //back
		_delay_ms(5000);
		PORTA=0b00001011;   //right
		_delay_ms(5000);*/
	}
	}	
	/*PORTA=0b00001010;
	_delay_ms(10000);
	PORTA=0b00001011;
	_delay_ms(10000);
	//PORTA=0b00001010;
	//_delay_ms(1000);
	//int i = 0;
	/*while(i<10)
	{
		PORTA=0b00001010;
		i++;
	}
	if(i==10)
	{
		PORTA=0b00001011;
	}
    while(1)
    {
        //TODO:: Please write your application code 
		/*for(int i = 0;i<10;i++)
		{
		   PORTA=0b00001011;
		   i++;
		}	*/	
		
    
	
}