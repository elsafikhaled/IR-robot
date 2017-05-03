/*
 * tracking.c
 *
 *  Created on: ??�/??�/????
 *      Author: El-safi
 */

#include "tracking.h"

extern void IR_Init(void){
	//input pins IR connected to them
	DDRC&=~(1<<PC0);
	DDRC&=~(1<<PC1);
	DDRC&=~(1<<PC2);
}

extern void Motor_Init(void){
	//output pins for Motor control driver
	DDRB|=(1<<PB0);
	DDRB|=(1<<PB1);
	DDRB|=(1<<PB2);
	DDRB|=(1<<PB3);

	// Timer operates in PWM mode so make PD4,PD5 AS OC1A + OC1B output
	DDRD|=(1<<PD4);
	DDRD|=(1<<PD5);
}


extern void Brake(void)
{
	PORTB|=(1<<PB0);
	PORTB|=(1<<PB1);
	PORTB|=(1<<PB2);
	PORTB|=(1<<PB3);
}

extern void Forward_direction(void)
{
	// motor A forward

	PORTB|=(1<<PB0);
	PORTB&=~(1<<PB1);

	// motor B forward

	PORTB|=(1<<PB2);
	PORTB&=~(1<<PB3);


}

extern void Backword_direction(void)
{
	// motor A backward

	PORTB|=(1<<PB1);
	PORTB&=~(1<<PB0);

	// motor B backward

	PORTB|=(1<<PB3);
	PORTB&=~(1<<PB2);


}


extern void Right_direction(void)
{
	// motor A backward

	PORTB|=(1<<PB1);
	PORTB&=~(1<<PB0);

	// motor B forward

	PORTB|=(1<<PB2);
	PORTB&=~(1<<PB3);


}

extern void Left_direction(void)
{
	// motor A forward

	PORTB|=(1<<PB0);
	PORTB&=~(1<<PB1);

	// motor B backward

	PORTB|=(1<<PB3);
	PORTB&=~(1<<PB2);



}



