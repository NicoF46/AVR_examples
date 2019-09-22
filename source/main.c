#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "ConfiguracionSerial.h"
#include "ConfiguracionPWM.h"
#define PINPWM_FRIO 6
#define PIN_PMOS_FRIO 8
#define PINPWM_CALOR 5
#define PIN_PMOS_CALOR 7



int main(void)
{
    PWM_configuration_init();
    usart_configuration_init();
    PORTB|=(1<<PB0);
    PORTD&=~(1<<PD7);

    while (1)
    {
        PWM_set(180);
    }

    return(0);
}
