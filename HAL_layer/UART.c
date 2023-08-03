/**
 * @file UART.c
 * @author Dewmith Ranasinghe (dewmithrana@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-08-2023
 *  
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h> // Include this header to resolve the sprintf warning
#include "UART.h"


void uart_init() {
	// Set baud rate
	UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
	UBRR0L = (uint8_t)(UBRR_VALUE);

	// Enable receiver and transmitter
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

	// Set frame format: 8 data, 1 stop bit
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_send_char(char data) {
	// Wait until the transmitter is ready
	while (!(UCSR0A & (1 << UDRE0)));
	;

	// Send the data
	UDR0 = data;
}

void uart_send_string(const char* data) {
	for (int i = 0; data[i] != '\0'; i++) {
		uart_send_char(data[i]);
	}
}

// Function to convert float to integer and decimal parts
void send_float(float value) {
	int integer_part = (int)value;
	int decimal_part = (int)((value - integer_part) * 1000); // Extract 3 decimal places

	char buffer[20];
	sprintf(buffer, "acceleration: %d.%d\n", integer_part, decimal_part);
	uart_send_string(buffer);
}
