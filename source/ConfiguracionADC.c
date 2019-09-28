#include "ConfiguracionADC.h"
#include <math.h>
void ADC_configuration_init(){
  /*Configuro el ADC1 PC1 con AVCC de referencia*/
  /*Configuro a 125 kHz*/
  ADMUX |= ((1<<REFS0)|(1<<MUX2)|(1<<MUX0));
  ADCSRA |= ((1<<ADEN)|(1<<ADPS1)|(1<<ADPS1));

}

uint16_t ReadADC(){
  uint16_t ValorLeido=0;
    ADCSRA|=(1<<ADSC);
    while((ADCSRA &(1>>ADIF))==0);
    ValorLeido=(ADCH << 8) + ADCL;
    return ValorLeido;
}
