/**
 * @file SPI.c
 * @author Dewmith Ranasinghe (dewmithrana@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-08-2023
 *  
 */

#include <avr/io.h>

void SPI_INIT() {
    
    DDRB |= (1 << DDB3) | (1 << DDB5) | (1 << DDB2);
    DDRB &= ~(1 << DDB4);
    
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}


uint8_t SPI_TRANSFER(uint8_t data)
{
 
    SPDR = data;

    while (!(SPSR & (1 << SPIF)));
    
    return SPDR;
}

void spi_select_slave()
{
   
    PORTB &= ~(1 << PB2);
}


void spi_deselect_slave() 
{
    PORTB |= (1 << PB2);
}


uint8_t spi_receive() 
{
    return spi_transfer(0x00);
}

uint8_t spi_transceive(uint8_t data) {
    return spi_transfer(data);
}

