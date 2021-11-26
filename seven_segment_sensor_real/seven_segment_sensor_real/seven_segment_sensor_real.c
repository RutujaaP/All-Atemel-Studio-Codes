/*
 * lcd_sensor_real.c
 *
 * Created: 18-06-2019 17:14:34
 *  Author: Shweta
 */ 


#include <avr/io.h>
#include <avr/delay.h>

int a[10]={0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1111000,0b0000000,0b0010000};
int b[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};
	
int main(void)
{
	int x,i=0;
	int temp=0;
	DDRD= 0b11111111;
	DDRA=0b11111111;
	DDRC=0b00000000;
	int u,t;
	while(1)
    {
        //TODO:: Please write your application code 
		x=PINC;
		x=x&0b00000001;
		if(x==0&& temp==0)
		{
			temp=1;
			
			//_delay_ms(1000);
		}
		else if(x==1&& temp==1)
		{
			i++;
			//PORTB=i;
			t=i/10;
			tens(t);
			u=i%10;
			unit(u);
			temp=0;
			_delay_ms(500);
		}
    }
}
void unit(int k)
{
	PORTA=a[k];
}
void tens(int l)
{
	PORTD=b[l];
}