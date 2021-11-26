/*
 * ascending_glow_led.c
 *
 * Created: 11-06-2019 10:33:28
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#include <math.h>

int main(void)
{
	DDRA=0b11111111;
    while(1)
    {
        //TODO:: Please write your application code 
		/*PORTA=0b10000000;
		_delay_ms(1000);
		PORTA=0b01000000;
		_delay_ms(1000);
		PORTA=0b00100000;
		_delay_ms(1000);
		PORTA=0b00010000;
		_delay_ms(1000);
		PORTA=0b00001000;
		_delay_ms(1000);
		PORTA=0b00000100;
		_delay_ms(1000);
		PORTA=0b00000010;
		_delay_ms(1000);
		PORTA=0b00000001;
		_delay_ms(1000); */
		
		/*for(int i = 0 ; i<8 ; i++)   
		{
			PORTA=1<<i;
			_delay_ms(500);
		}		*/
		
		/*int a[8] = {1,2,4,8,16,32,64,128};     //using array     we can also write porta = 2 , porta= 4 etc.. in decimal form also ..
		for(int i = 0 ; i<8 ; i++)            //                 so when we are writing in decimal then no need to write 0b there..only number can also work
		{
			PORTA=a[i];                       // another method is using for loop i=0-7 and inside it we can write 2^i  
			_delay_ms(500);
		}
		for(int i =7 ; i>=0 ; i--)
		{
			PORTA=a[i];
			_delay_ms(500);
		}  */
		                                     //                 so when we are writing in decimal then no need to write 0b there..only number can also work
		
			                                // another method is using for loop i=0-7 and inside it we can write 2^i
			
    }
}