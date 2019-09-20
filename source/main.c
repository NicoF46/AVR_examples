#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "ConfiguracionSerial.h"

#define LED_DDR     DDRB
#define LED_PIN     PINB
#define LED         PB5


int main(void)
{

    usart_configuration_init();
    LED_DDR |= _BV(LED);

    while (1)
    {
        LED_PIN |= _BV(LED);
      /*  _delay_ms(1000);*/
        usart_transmit(97);
    }

    return(0);
}


