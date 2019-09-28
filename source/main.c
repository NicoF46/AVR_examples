#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "funciones.h"


int TemperaturaReferencia = 255;

int main(void)
{
    static float TemperaturaTermistor=255;
    static float TemperaturaAmbiente=0;
    static modo_t modo = CALIBRACION;
    static uint8_t ValorPWM=0;
    static float Kp = 7.8*1.1;
    static float Ki = 0.127;
    static float Kd = 1.959;
    static float Realimentacion=0;
    Pin_SetUp();
    apagar(&TemperaturaReferencia);
    PWM_configuration_init();
    usart_configuration_init();
    ADC_configuration_init();
    uint8_t msj[]={'P','e','r','k'};
    while(1){
      /*TemperaturaTermistor = SensarTemperatura();*/
      usart_transmit('t');
      usart_float_transmit(msj);
      _delay_ms(100);
  }
/*
    while(1){
      TemperaturaAmbiente=SensarTemperatura();
      TemperaturaTermistor = SensarTemperatura();
      usart_transmit('t');
      usart_float_transmit(TemperaturaTermistor);
      _delay_ms(50);
      if (TemperaturaReferencia != 255){
        modo = definir_modo(TemperaturaAmbiente, TemperaturaReferencia);
        TemperaturaTermistor = SensarTemperatura();
        Realimentacion = ControladorPID(TemperaturaReferencia,TemperaturaTermistor, Kp, Ki, Kd,0,0,modo);
        if(modo == FRIO)
          ValorPWM=Realimentacion*(-1);
        else if (modo == CALOR)
          ValorPWM=Realimentacion;
        PWM_set_modo(ValorPWM,modo);
        usart_transmit('p');
        usart_transmit(ValorPWM);
}
    }
*/
    return(0);
}



void ISR(USART_RXC_vect){
  uint8_t modo = receive();
  switch(modo){
      case('r'):
        TemperaturaReferencia = receive();
        break;
      case('s'):
        apagar(&TemperaturaReferencia);
        break;
    }


}
