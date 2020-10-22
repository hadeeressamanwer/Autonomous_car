#include <avr/io.h>

#define  F_CPU 1000000UL
#include <util/delay.h>
#include "motors.h"
#include "LCD.h"
int main(void)
{
	   LCD_vInit();
	   motor_init();
		DDRA &=~(1<<0) ;   /*ir sensor */
		DDRA &=~(1<<1);

	unsigned short a,b,high,distance;
	DIO_vsetPINDir('D',7,1);
    while(1)
    {	
		TCCR1A = 0;
		TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */
		DIO_write('D',7,1);
		_delay_us(50);
		DIO_write('D',7,0);
	
	    TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
	    while ((TIFR&(1<<ICF1)) == 0);
	    a = ICR1;  		/* Take value of capture register */
	    TIFR = (1<<ICF1);  	/* Clear ICF flag */
	    TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
	    while ((TIFR&(1<<ICF1)) == 0);
	    b = ICR1;  		/* Take value of capture register */
	    TIFR = (1<<ICF1);  	/* Clear ICF flag */
		TCNT1=0;
	    TCCR1B = 0;  		/* Stop the timer */
		high=b-a;
		distance=((high*34600)/(F_CPU*2)) ;

		if (distance>=80)
		{
			 set_direction( PINA & 0x01 , PINA & 0x02);
			 LCD_clearscreen();
			 			LCD_vSend_string("no object");
			 			_delay_ms(500);
		}
		else
		{
			REVERSE_MODE() ;
			LCD_clearscreen();
					LCD_vSend_string("distance=");
					LCD_vSend_char((distance/10)+48);
					LCD_vSend_char((distance%10)+48);
				    LCD_vSend_string("cm");
					_delay_ms(500);
		}		
	}
}

