/*
 * lcd_sensor2.c
 *
 * Created: 15-06-2019 16:49:54
 *  Author: Shweta
 */ 


#include <avr/io.h>
//#include <avr/delay.h>

int main(void)
{
	DDRC=0b00000000;  //to detect input from pin
	DDRA=0b11111111;  // lcd 1 common anode
	DDRD=0b11111111;  // lcd 2 common cathode
	int temp = 0;
    int a[10]={0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000};    //common anode connected to porta
	int b[10]={0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};    //common cathod connected to portd
    while(1)
    {
        //TODO:: Please write your application code 
		for(int i=0;i<10;i++)
		{
			PORTD=b[i];
			for(int count=1;count<10;count++)
			{
				int x = PINC & 0b00000001;
				if(x==0 && temp==0)
				{
					temp=1;
				}
				else if(x==1 && temp==1)
				{
					PORTA=a[count];
					temp=0;
					//_delay_ms(500);
				}
			}
		}
		
			/*int x = PINA & 0b00000001;
			if(x==0 && temp==0)
			{
				temp=1;
			}
			else if(x==1 && temp==1)
			{
				count++;
				PORTA=count;
				temp=0;
				for(int i=0;i<10;i++)
				{
					PORTD=b[i];
					for(int j=0;j<10;j++)
					{
						PORTA=a[j];
						_delay_ms(500);
					}
				} */

    }
}