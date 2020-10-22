/*
 * motors.c
 *
 *  Created on: Oct 20, 2020
 *      Author: amr essam
 */
#include <avr/io.h>
#include <util/delay.h>
#include "motors.h"
void pwd(unsigned char COM)
{
OCR0=COM;
DDRB |=(1<<3);
TCCR0 &=~ (1<<7) ;
TCCR0 &=~ (1<<4) ;
TCCR0 |= (1<<3) |(1<<6) |(1<<5) |(1<<1);
}

motor_init()
{
	MOTOR_DDR |=(1<<0) |(1<<1)|(1<<2)|(1<<3);

	pwd(150);
}
void set_direction(unsigned char ir_right ,unsigned char ir_left)
{

	if((ir_right==0)&&(ir_left==0))
		{
		FORWARD_MODE();
		}
    else if((ir_right==0)&&(ir_left==2))
    	{
    	RIGHT_MODE();
    	}
    else if((ir_right==1)&&(ir_left==0))
    	{
    	LEFT_MODE();
    	}
    else
    {
    	FORWARD_MODE();
    }
}
