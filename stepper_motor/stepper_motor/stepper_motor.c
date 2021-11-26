/*
 * stepper_motor.c
 *
 * Created: 24-06-2019 09:15:48
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#define delayv 10
int main(void)
{
	DDRA=0b11111111;
	
	/*PORTA=0b00000001;        //glowing led of motor
	_delay_ms(500);
	PORTA=0b00000010;
	_delay_ms(500);
	PORTA=0b00000100;
	_delay_ms(500);
	PORTA=0b00001000;
	_delay_ms(500);*/
    while(1)
    {
        //TODO:: Please write your application code 
		
		if(i<100){
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
		}	}	
		/*PORTA=0b11111110;              //rotation of motor
		_delay_ms(500);
		PORTA=0b11111101;
		_delay_ms(500);
		PORTA=0b11111011;
		_delay_ms(500);
		PORTA=0b11110111;
		_delay_ms(500);*/
		
		/*PORTA=0b11111100;              //rotation of motor taking two pins at a time
		_delay_ms(500);
		PORTA=0b11111001;
		_delay_ms(500);
		PORTA=0b11110011;
		_delay_ms(500);
		PORTA=0b11110110;
		_delay_ms(500); */
		
		
		/*PORTA=0b11111000;              //rotation of motor taking three pins at a time
		_delay_ms(500);
		PORTA=0b11110001;                //not working -_-
		_delay_ms(500);
		PORTA=0b11110010;
		_delay_ms(500);
		PORTA=0b11110100;
		_delay_ms(500); */
		
		
		/*for(int i=0;i<4;i++)
		{
			PORTA=1<<i;
			_delay_ms(1000);
		}*/
    }
}