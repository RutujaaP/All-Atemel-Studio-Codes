/*
 * anticlock_stepper.c
 *
 * Created: 25-06-2019 08:59:07
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#define delayv 10
int main(void)
{
	int i;
	DDRA=0b11111111;
    while(1)
    {
        //TODO:: Please write your application code 
		
			for(int i=0;i<100;i++){            //clockwise
				PORTA=0b00000001;
				_delay_ms(delayv);
				PORTA=0b00001001;
				_delay_ms(delayv);
				PORTA=0b00001000;
				_delay_ms(delayv); 
				PORTA=0b00001100;
				_delay_ms(delayv);
				PORTA=0b00000100;
				_delay_ms(delayv);
				PORTA=0b00000110;
				_delay_ms(delayv);
				PORTA=0b00000010;
				_delay_ms(delayv);
				PORTA=0b00000011;
				_delay_ms(delayv);
				
			 }
			 _delay_ms(2000);
			for(int i=0;i<100;i++){                 //anticlockwise
			PORTA=0b00000001;
			_delay_ms(delayv);
			PORTA=0b00000011;
			_delay_ms(delayv);
			PORTA=0b00000010;
			_delay_ms(delayv);
			PORTA=0b00000110;
			_delay_ms(delayv);
			PORTA=0b00000100;
			_delay_ms(delayv);
			PORTA=0b00001100;
			_delay_ms(delayv);
			PORTA=0b00001000;
			_delay_ms(delayv);
			PORTA=0b00001001;
			_delay_ms(delayv);
		   }
		   _delay_ms(2000);
	}    
}