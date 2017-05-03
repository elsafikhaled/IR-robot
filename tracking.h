/*
 * tracking.h
 *
 *  Created on: ??�/??�/????
 *      Author: El-safi
 */

#ifndef TRACKING_H_
#define TRACKING_H_

#include <avr/io.h>
#include <util/delay.h>

extern void Motor_Init(void);

extern void IR_Init(void);

extern void Right_direction(void);

extern void Left_direction(void);

extern void Forward_direction(void);

extern void Backword_direction(void);

extern void Brake(void);

#endif /* TRACKING_H_ */
