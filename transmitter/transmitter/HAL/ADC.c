/**
 * @file ADC.c
 * @author Dewmith Ranasinghe (dewmithrana@gmail.com)
 * @brief HAL level APIs to configure and read ADC channels
 * @version 0.1
 * @date 01-08-2023
 *  
 */

#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"

/**
 * @brief            
 *
 */
void ADC_INIT() {

    ADMUX |= (1 << REFS0);
    ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

/**
 * @brief            
 *
 * @param 
 *
 * @return 
 */
uint16_t ADC_READ(uint8_t channel) {

    static uint16_t adc_value = 0;
    
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);   
    ADCSRA |= (1 << ADSC);    
    while (ADCSRA & (1 << ADSC));
    adc_value = ADCL | (ADCH << 8);
	
    return adc_value;
}

