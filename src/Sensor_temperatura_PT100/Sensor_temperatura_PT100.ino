 * /************************************************************* 
 *  AQUISIÇÃO DOS DADOS DE TEMPERATURA DO SENSOR PT100       *
 *  AUTOR: NATHALIA NASCIMENTO                               *
 *  DATA : 13/10/2019                                        *
 *  V1.0                                                     * 
 *************************************************************/

/* (PINS LED 0.96')
GND: GND
Vcc: 2.8 à 5.5VDC
D0: CLK Clock
D1: MOSI Data
RST: Reset
DC: Data/Command
CS: Chip Select
*/
#include <SPI.h>
#include "SSD1306_SPI.h"

//#include<avr/io.h>

#define USE_FRAME_BUFFER

#ifdef USE_FRAME_BUFFER
SSD1306_SPI_FB oled;
#else
SSD1306_SPI oled;
#endif


void print_ad(void) {
  
}
//  
//void adc1_setup(void){
//
//ADMUX = 0b000100001;    
//
//ADCSRA |= (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN);     //PRESCALER FREQ E DESABILITA ADC
//
//}
//
//int ler_ad(void){
//  
//  ADCSRA |= (1 << ADSC);
//  
//  while (ADCSRA & (1 << ADSC));
// 
//  return ADCH;
//}

void setup(void){
  oled.begin();
  oled.print("Sensor temperatura PT100");

  #ifdef USE_FRAME_BUFFER
  oled.renderAll();
  #endif

  delay(1000);
  oled.clear();
}
  
void loop(void){
  size_t len;
  oled.gotoXY(5,3);
  oled.print("PT100: ");
 }
