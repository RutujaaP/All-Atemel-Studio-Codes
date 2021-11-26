/*
 * two_lcd.c
 *
 * Created: 12-06-2019 11:12:56
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRA=0b11111111;
	DDRD=0b11111111;
	int a[10]={0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000};    //common anode ... it is connected to porta
	int b[10]={0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};    //common cathode ... it is connected to portd
    while(1)
    {
        //TODO:: Please write your application code 
		
		for(int i=0;i<10;i++)
		{
			PORTD=b[i];
			for(int j=0;j<10;j++)
			{
				PORTA=a[j];
				_delay_ms(500);
			}
		}
    }
}