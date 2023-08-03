/**
 * @file UART.h
 * @author Dewmith Ranasinghe (dewmithrana@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-08-2023
 *  
 */

#ifndef _UART_H_
#define _UART_H_

#define BAUD_RATE 9600
#define UBRR_VALUE ((F_CPU / (BAUD_RATE * 16UL)) - 1)

void uart_init();

void uart_send_char(char data);


void uart_send_string(const char* data);

void send_float(float value);

#endif