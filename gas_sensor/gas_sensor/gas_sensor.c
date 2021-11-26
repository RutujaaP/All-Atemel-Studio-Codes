/*
 * adc_no_leftshift.c
 *
 * Created: 27-06-2019 09:59:08
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#include <compat/deprecated.h>
int main(void)
{
	unsigned int a,b;
	DDRB=255;
	DDRD=255;
	ADCSRA=0XE3;
	lcd_initialisation();
	//wrdata('A');
    while(1)
    {
        //TODO:: Please write your application code 
		//10 bit data
		ADMUX=0X40;
		_delay_ms(10);
		a=ADC;
		if(a>250)
		{
			sbi(PORTB,PB2);   //high
		}
		else
		{
			cbi(PORTB,PB2);     //low
		}
		wrcommand(0X80);
		wrdata(a/1000 + 48);
		wrdata((a/100)%10+48);
		wrdata((a/10)%10+48);
		wrdata(a%10+48);
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