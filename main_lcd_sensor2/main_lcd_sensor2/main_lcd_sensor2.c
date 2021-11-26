/*
 * main_lcd_sensor2.c
 *
 * Created: 14-06-2019 16:38:56
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#include <compat/deprecated.h>


int main(void)
{
	DDRD=255;
	DDRB=255;
	DDRA=0;
	int count = 0, temp = 0;
	lcd_initialisation();
	
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
			//PORTD=count;
			wrcommand(0X80);
			wrdata(count%10 + 48);
			temp=0;
		}
    }
}
void wrcommand(unsigned char command)
{
	cbi(PORTB,PB0);
	PORTD=command;
	sbi(PORTB,PB1);
	_delay_ms(100);
	cbi(PORTB,PB1);
}
void wrdata(unsigned char command)
{
	sbi(PORTB,PB0);
	PORTD=command;
	sbi(PORTB,PB1);
	_delay_ms(100);
	cbi(PORTB,PB1);
}
void lcd_initialisation()
{
	wrcommand(0X38);
	wrcommand(0X80);
	wrcommand(0X06);
	wrcommand(0X01);
	wrcommand(0X0C);
}
