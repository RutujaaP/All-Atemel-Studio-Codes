/*
 * gsm.c
 *
 * Created: 25-08-2019 16:01:06
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <compat/deprecated.h>

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
unsigned char sms[150],sms1[150],rsms[150],msg[3];
unsigned char j=0,l=0;

unsigned char x=0,y=0,ms=0;

unsigned char i,value;

unsigned char p,keycode,C=0,K=0;





void SMS_receive(unsigned char j)
{
	unsigned char i=0,nopes=0,temp=0,valu=0,temp1=0,end=0,a=0,final=0,w=0;
	UCSRB|= (1<<RXEN)|(1<<TXEN);
	_delay_ms(10);

	usart_string("AT+CMGF=1");
	USART_Transmit(13);
	_delay_ms(10);

	usart_string("AT+CMGR=");

	if(j<10)
	USART_Transmit((j%10)+48);
	else
	{
		USART_Transmit(((j/10)%10)+48);
		USART_Transmit((j%10)+48);
	}

	_delay_ms(10);
	USART_Transmit(13);
	temp=0;

	while(final==0)
	{
		temp=USART_Receive();

		if(temp=='R')
		{
			temp1=1;
		}
		else if(temp1==1 && temp=='E')
		{
			temp1=2;
		}
		else if(temp1==2 && temp=='A')
		{
			temp1=3;
		}
		else if(temp1==3 && temp=='D')
		{
			temp1=4;
		}
		else if(temp1==4 && temp=='"')
		{
			temp1=5;
		}
		else if(temp1==5 && temp==',')
		{
			temp1=6;
		}
		else if(temp1==6 && temp=='"')
		{
			temp1=7;
			
			while(i<100)
			{
				sms[i]=USART_Receive();

				if(end==1)
				{
					rsms[a]=sms[i];
					a++;
				}

				if((sms[i]==0x0a) && end==0)
				{
					end=1;
				}
				else if((sms[i]==0x0d) && end==1)
				{
					final=1;
					break;
				}
				else
				i++;
			}

			wrcommand(0x80);
			for(unsigned char w=0;w<32;w++)
			{
				if(w<16)             //16 COLOUMNS ARE THERE IN LCD
				wrdata(rsms[w]);
				else if(w==16)
				{
					wrcommand(0xc0);
					wrdata(rsms[w]);
				}
				else
				wrdata(rsms[w]);
			}
		
		}
	}
}




check_sms()
{
	unsigned char i=0,nopes=0,temp=0,valu=0,temp1=0,end=0,a=0,j=0,x1=0,index_no=0;
	UCSRB|= (1<<RXEN)|(1<<TXEN);
	_delay_ms(10);

	while(i<10)
	{
		temp=USART_Receive();

		 if(temp1==0 && temp=='C')
		{
			temp1=2;
		}
		else if(temp1==2 && temp=='M')
		{
			temp1=3;
		}
		else if(temp1==3 && temp=='T')
		{
			temp1=4;
		}
		else if(temp1==4 && temp=='I')
		{
			temp1=5;
		}
		else if(temp1==5 && temp==':')
		{
			temp1=6;
		}
		else if(temp1==6 && temp==' ')
		{
			temp1=7;
			
			while(1)
			{
				sms[i]=USART_Receive();

				if((sms[i]==0x0d)  )
				{
					break;
				}
				
				else
				i++;
			}

			
			for(unsigned char x=5;x<i;x++)
			{
				x1++;
			}

			if(x1==1)
			index_no= ((sms[5]-48)*1 );

			else if(x1==2)
			{
				index_no=(( (sms[5]-48)*10 ) + ( (sms[6]-48)*1 ) );
			}

			else;

			

			SMS_receive(index_no);
			
			
		}
	}

}













/*store_value(unsigned char value)
{
	a[k]=value;
	wrcommand(0xc0+k);
	wrdata(value);
	k++;
}*/
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

int main(void)
{
	char A;
	DDRA = 255;
	DDRB = 255;
	USART_Init();
	_delay_ms(1000);
	//while(1)
	
		//TODO:: Please write your application code
		/*usart_string("AT+CMGF=1\r");
		_delay_ms(8000);
		usart_string("AT+CMGS=\"9822278273\"\r");
		_delay_ms(8000);
		usart_string("HI!");
		USART_Transmit(26);*/
lcd_initialisation();
wrdata('A');
//	SMS_receive();
//usart_string("AT\r");
//_delay_ms(8000);
//usart_string("ATE0\r");
//_delay_ms(8000);
while(1)
{

check_sms();
}
	
}