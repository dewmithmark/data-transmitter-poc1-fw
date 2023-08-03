/**
 * @file ADC.h
 * @author Dewmith Ranasinghe (dewmithrana@gmail.com)
 * @brief HAL level APIs to configure and read ADC channels
 * @version 0.1
 * @date 01-08-2023
 *  
 */

#ifndef _ADC_H_
#define _ADC_H_

#include <stdint.h>


/**
 * @brief            
 *
 */
void ADC_INIT();

/**
 * @brief            
 *
 * @param 
 *
 * @return 
 */
uint16_t ADC_READ(uint8_t channel);

#endif