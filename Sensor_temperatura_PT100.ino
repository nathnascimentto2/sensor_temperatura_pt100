/* 
 *  AUTOR: NATHALIA NASCIMENTO 
 *  DATA : 13/10/2019
 * CONVERSOR AD PARA SENSOR DE TEMPERATURA PT100
 */
#include<avr/io.h>

void setup() {

Serial.begin(9600);

//CONFIGURAR PINO COMO INPUT
//DDRB = 

//VOLTAGEM DE REFERENCIA A/D 1.1V, AJUSTE PARA DIREITA, ADC0 SELECIONADO
ADMUX = 0b11000000;

//CONVERSÃO HABILITADA, NAO INCIA PRIMEIRA CONVERSAO, ATUTO TRIGGER ENABLE, ADIF =0,
//ADC COMPLETE INTERRUPT ATIVADA, PREESCALER 1:128 f=(16MHz/128)=125KHz
ADCSRA = 0b10101111;

//COONVERSOR A/D EM MODO FREE RUINNING MODE
ADCSRB = 0;

//MODO DE REDUÇÃO DE CONSUMO DESABILITANDO BUFFER DE INPUT DIGITAL 
// NOS PINOS ADC1,ADC2,ADC3,ADC4 E ADC5
DIDR0 = 0b00111110;

//INICIA A PRIMEIRA CONVERSÃO
ADCSRA |= (ADSC<<1);
}

void loop() {

interrupts();

do{}while(ADIF==0);
float temperatura = conv_ad();
Serial.print(temperatura);
}

float conv_ad(){
  
  noInterrupts();
  //ADCL PRECISA SER LIDO ANTES DE ADCH(RIGHT ADJUSTED)
  uint16_t low_bits = ADCL;
  uint16_t high_bits = ADCH;
  high_bits = (high_bits<<8); 
  
  uint16_t conv = high_bits | low_bits;
  
  //Fórmula da temperatura
  float T = (conv/2.586)-252.97;
  
  //Limpar FLAG de interrupção
  ADCSRA &= (ADIF<<1);

  return(T);
  }
