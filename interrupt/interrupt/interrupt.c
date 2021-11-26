
./*
 * interrupt.c
 *
 * Created: 01-09-2019 13:59:44
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include <compat/deprecated.h>

int gsm_data_count=0,i;
char gsm_data[100];
int main(void)
{
	DDRD=255;
	DDRB=255;
	DDRA=255;
	lcd_initialisation();
	USART_Init();
	sei();                //it calls interrupts
    while(1)
    {
        //TODO:: Please write your application code 
		for(i=0;i<100;i++)
		{
			if(gsm_data[i]=='C'&& gsm_data[i+1]=='M'&& gsm_data[i+2]=='T'&& gsm_data[i+3]=='I')
			{
				_delay_ms(100);
			}
			while(gsm_data[i]!=',')
			{
				i++;
            }
			int j=i;
			wrdata(gsm_data[j+1]);        //j ki value pe "," hai..j+1 karne par value milengi address of our msgs
			for(i=0;i<100;i++)
			{
			    gsm_data[i]=0;	
            }
		}
	}
}			
ISR (USART_RXC_vect)
{
	
	gsm_data[gsm_data_count]=UDR;
	gsm_data_count++;
}
void USART_Init()
{
	/* Set baud rate */
	UBRRH = 0;
	UBRRL =51;
	/* Enable receiver and transmitter */
	UCSRB|= (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data---ucsz0=1,ucsz1=1, 1stop bit ---usbs=0*/
	UCSRC |= (1 << URSEL)|(3<<UCSZ0);
	UCSRA |= (1<<RXCIE);
}

//Transmission
void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = data;
}
unsigned char usart_string(unsigned char *string)
{
	while(*string)
	{
		USART_Transmit(*string++);
		_delay_ms(10);
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
	wrcommand(0X0C);  }  //curser off
	/*wrcommand(0X0E);    //curser is on
	wrcommand(0X0F);    //curser blink  */

