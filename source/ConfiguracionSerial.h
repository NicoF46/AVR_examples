#include <avr/io.h>
#include <math.h>
#include <string.h>
#define FOSC 16000000 // Clock Speed
#define BAUD 19200
#define MY_UBRR_REGISTER FOSC/16/BAUD-1

void usart_configuration_init();

void usart_transmit(uint8_t );
void usart_float_transmit(void* );
int8_t receive(void);
