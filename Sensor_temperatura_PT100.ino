/************************************************************* 
 *  AQUISIÇÃO DOS DADOS DE TEMPERATURA DO SENSOR PT100       *
 *  AUTOR: NATHALIA NASCIMENTO                               *
 *  DATA : 13/10/2019                                        *
 *  V1.0                                                     * 
 *************************************************************/

#include<avr/io.h>

void setup() {
  
Serial.begin(9600);

////CONFIGURAR PINO COMO INPUT
DDRC = 0; 

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

delay(15);

uint16_t temperatura = ler_ad();

//Verificar saida
Serial.println(temperatura);

}

int ler_ad(){
  
//DESAABILITA MODO DE REDUCAO DE CONSUMO
//PRR &= (PRADC<<0);

while (ADIF == 0);

uint16_t low_bits = ADCL; 
uint16_t high_bits = ADCH;
uint16_t result = (ADCH<<8) + ADCL;

//DESAABILITA MODO DE REDUCAO DE CONSUMO
//PRR |= (PRADC<<1);

return result;
}
