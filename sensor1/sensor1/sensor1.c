/*
 * sensor1.c
 *
 * Created: 13-06-2019 09:35:59
 *  Author: Shweta
 */ 


#include <avr/io.h>
//#include <avr/delay.h>

int main(void)
{
	DDRA=0b00000000;   // to detect the input
	DDRB=0b11111111;   //to detect the output (glowing of led)
    int count = 0, temp = 0;
    /*while(1)
    {
        //TODO:: Please write your application code 
		int x = PINA & 0b00000001;             //"&" is used for multiplication purpose
		if(x==0)
		{
			//count = count + 1;               //we can also use 0b00000000 instead of 0
		     //PORTB = count;
			 //PORTB = 255;                    //we can also write 255 as 0b11111111;
			}				
		}		 
		else                          
		PORTB=0;
    }*/
	/*while(1)
	{
	     int x = PINA & 0b00000001;
		 if(x == 0)                                    not working
		 {
			 count++;
			 PORTB = count;
			 _delay_ms(500);
			 break;
		 }	
		 else
		 PORTB=0; */
	  while(1)
	  {
		  int x = PINA & 0b00000001;
		  if(x==0 && temp==0)
		  {
		     temp=1;
		  }		  
		  else if(x==1 && temp==1)
		  {
			  count++;
			  PORTB=count;
			  temp=0;  
			  _delay_ms(1000);
		  }		  

	  }
	
}