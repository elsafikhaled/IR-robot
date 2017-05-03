/*
 * IR.c
 *
 *  Created on: ٣٠‏/٠٤‏/٢٠١٧
 *      Author: El-safi
 */
#include "tracking.h"
#include "PWM1_EKE.h"

//flags
enum CONSTAN{
	TRUE=1,
	FALSE=0,
};
struct flagSystem{
	U8_t IR1:1;
	U8_t IR2:1;
	U8_t IR3:1;
};


int main(void){

struct flagSystem flag;

// system initialization
	IR_Init();
	Motor_Init();
	PWM1_EKE_init();
	PWM1_EKE_start();

	while(1){

	   //front IR
		if(!(PINC &(1<<PC0))){
			Forward_direction();
			PWM1_EKE_duty(128);
		}
		else{
			flag.IR1=TRUE;

		}

	   //Right IR
		if(!(PINC &(1<<PC1))){
			Right_direction();
			PWM1_EKE_duty(128);
		}
		else{
			flag.IR2=TRUE;
		}
	   //left IR
		if(!(PINC &(1<<PC2))){
		    Left_direction();
		    PWM1_EKE_duty(128);
		}
		else{
			flag.IR3=TRUE;
		}
       //Check flags to BRAKE MOTORS
		if(flag.IR3==TRUE && flag.IR2==TRUE && flag.IR1==TRUE){
			Brake();
		}


	}

	return 0;
}

