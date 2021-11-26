/*
 * main_lcd2.c
 *
 * Created: 14-06-2019 11:20:20
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#include <compat/deprecated.h>
int main(void)
{
	DDRD=255;
	DDRB=255;
	lcd_initialisation();
    while(1)
    {
        //TODO:: Please write your application code 
		for(int i=0;i<1000;i++)
		{
			wrcommand(0X80);
			wrdata(i/100 + 48);
			wrdata((i/10)%10+48);
			wrdata(i%10+48);
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
	wrcommand(0X0C);    //curser off
	/*wrcommand(0X0E);    //curser is on
	wrcommand(0X0F);    //curser blink  */
}

/*void lcd_string(unsigned char *string)
{
	while(*string)   //while is 1 till last alphabet.. after that due to '\0' it will end
	wrdata(*string++);   // it is taking a single letter at a time
}*/