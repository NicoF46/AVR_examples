/*Configuro el pwm de frio y calor para operar en modo Fast PWM a 62,5kHz*/
#include <avr/io.h>
#include "ConfiguracionPWM.h"

void PWM_configuration_init(){
/*PIN PWM FRIO PD6*/
  DDRD = 1<<DDD5;
	DDRD|=(1<<6);
	OCR0A=0;
	OCR0B=0;
	TCCR0A |= ((1<<COM0A1)|(1<<COM0B1)|(1<<WGM01)|(1<<WGM00));
  TCCR0B |= ((1<<CS00));

}


void PWM_set(uint8_t pwm){
  OCR0B=pwm;
  }
