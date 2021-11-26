/*
 * GPS.c
 *
 * Created: 04-09-2019 16:31:36
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <compat/deprecated.h>
int main(void)
{
	DDRA = 255;
	DDRB = 255;
	USART_Init();
	lcd_initialisation();
    while(1)
    {
        //TODO:: Please write your application code 
    }
	if()
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

//RX
unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
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
	PORTA=command;
	sbi(PORTB,PB1);
	_delay_ms(100);
	cbi(PORTB,PB1);
}
void wrdata(unsigned char command)
{
	sbi(PORTB,PB0);
	PORTA=command;
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
