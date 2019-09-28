#include "ConfiguracionSerial.h"

void usart_configuration_init(){
  /*Configuro el Baud rate*/
  unsigned int ubrr=MY_UBRR_REGISTER;
  UBRR0H = (unsigned char)(ubrr>>8);
  UBRR0L = (unsigned char)ubrr;
  /* Configuro 8 bits de datos, 1 bit de stop */
  UCSR0C= (3<<UCSZ00);
  /*  Habilito para enviar y recibir por interrupcion */
  UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);

}

void usart_transmit(uint8_t dato){
  	while( !(UCSR0A&(1<<UDRE0)) ){}
  	UDR0 = dato;
}

void usart_float_transmit(float dato){
  int i=0;
  int NumeroDeBytes=4;
  uint8_t* ByteAtransmitir=((uint8_t*)&dato);
  for (i=0;i<NumeroDeBytes;i++){
    usart_transmit(*(ByteAtransmitir));
    ByteAtransmitir++;
  }
}

int8_t receive(void){
	while ( !(UCSR0A & (1<<RXC0)) ){}
	return UDR0;
}
