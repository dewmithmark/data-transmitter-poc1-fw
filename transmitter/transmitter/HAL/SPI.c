/**
 * @file SPI.c
 * @author Dewmith Ranasinghe (dewmithrana@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-08-2023
 *  
 */

#include <avr/io.h>
#include "SPI.h"

void SPI_INIT() 
{  
    DDRB |= (1 << DDB3)|(1 << DDB5)|(1 << DDB2);
    DDRB &= ~(1 << DDB4);    
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

uint8_t SPI_TRANSFER(uint8_t data)
{ 
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));    
    return SPDR;
}

void SPI_SELECT_SLAVE()
{   
    PORTB &= ~(1 << PORTB2);
}