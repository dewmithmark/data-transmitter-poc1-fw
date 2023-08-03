/**
 * @file TWI.h
 * @author Dewmith Ranasinghe (dewmithrana@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-08-2023
 *  
 */

#ifndef TWI_H_
#define TWI_H_

#define SLAVE_ADDRESS 0x68
#define BIT_RATE 100000


void TWI_INIT();  

void TWI_STOP();

void TWI_START();

void TWI_REPEATED_START();

void TWI_DATA_WRITE(uint8_t data );


void TWI_ADDRESS_WRITE(uint8_t address , char mode );

uint8_t TWI_READ();

#endif