/*
 * clock.c
 *
 * Created: 14-06-2019 11:04:51
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
		for(int k=0;k<24;k++)
		{
			wrcommand(0X80+6);
			wrdata(':');
			wrcommand(0X80+4);
			wrdata(k/10 + 48);
			wrdata(k%10 + 48);
			
			for(int j=0;j<60;j++)
			   {
				   wrcommand(0X80+9);
				   wrdata(':');
			       wrcommand(0X80+7);
				   wrdata(j/10 + 48);
				   wrdata(j%10 + 48);
				   
		             for(int i=0;i<60;i++)
		                  {
			                  wrcommand(0X80+10);
			                  wrdata(i/10 + 48);
			                  wrdata(i%10 + 48);
		                  }
		
		        }	
				
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