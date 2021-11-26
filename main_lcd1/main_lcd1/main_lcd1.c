/*
 * main_lcd1.c
 *
 * Created: 14-06-2019 10:03:07
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#include <compat/deprecated.h>

int main(void)
{
	
	/*lcd_data_pin = PORTD;
	RS = PB0;
	RW = 0;
	EN = PB1;  
	while(1)
	{
		//TODO:: Please write your application code
	}
	*/
	
	DDRD=255;
	DDRB=255;
	lcd_initialisation();
	wrcommand(0X80+1);
	lcd_string("SHWETA SHUKLA");
	wrcommand(0XC0+1);
	lcd_string("ANKITA MISHRA");
	/*char a[16] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
	for(int i=0;i<16;i++)
	  {
		wrdata(a[i]);
	  }	  */
	
    
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

void lcd_string(unsigned char *string)
{
	while(*string)   //while is 1 till last alphabet.. after that due to '\0' it will end
	wrdata(*string++);   // it is taking a single letter at a time
}