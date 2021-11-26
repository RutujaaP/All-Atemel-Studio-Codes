/*
 * adr.c
 *
 * Created: 26-06-2019 10:10:18
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#include <compat/deprecated.h>
int main(void)
{
	ADCSRA=0XE3;     //PORTA is input  ADCSR(A)
	ADMUX=0X61;
	unsigned char x;
	
	DDRD=0b11111111;    //led or lcd
	DDRB=0b11111111;   //rs,rw,en
	lcd_initialisation();
	
    while(1)
    {
        //TODO:: Please write your application code 
		x=ADCH;
		wrcommand(0X80);
		wrdata(x/100 + 48);
		wrdata((x/10)%10+48);
		wrdata(x%10+48);
		if(x>151)
		{
			//PORTD=0XFF;
			
			
		}
		else
		PORTD=0X00;
		
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