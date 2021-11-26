/*
 * adch.c
 *
 * Created: 27-06-2019 09:07:45
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#include <compat/deprecated.h>
int main(void)
{
	unsigned char a,b;
	DDRB=255;              //rs,rw,en
	DDRD=255;              //lcd
	ADCSRA=0XE3;
	
	lcd_initialisation();
    while(1)
    {
        //TODO:: Please write your application code 
		
		ADMUX=0X60;
		_delay_ms(10);
		a=ADCH;
		wrcommand(0X80);
		wrdata(a/100 + 48);
		wrdata((a/10)%10+48);
		wrdata(a%10+48);
		
		
		ADMUX=0X61;
		_delay_ms(10);
		b=ADCH;
		wrcommand(0X80+8);
		wrdata(b/100 + 48);
		wrdata((b/10)%10+48);
		wrdata(b%10+48);
		
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
	wrcommand(0X0C);    //curser off
	/*wrcommand(0X0E);    //curser is on
	wrcommand(0X0F);    //curser blink  */
}