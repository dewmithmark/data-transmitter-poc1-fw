/*
 * GPIO.h
 *
 * Created: 8/11/2023 9:48:52 AM
 *  Author: Dewmith
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include <stdbool.h>

enum _PORTS
{
	_PORTB = 1,
	_PORTC,
	_PORTD
};

//#define PORTC 1

#define INPUT			0
#define OUTPUT			1
#define INPUT_PULLUP	2

#define LOW		0b00
#define ANY		0b01
#define FALLING	0b10
#define RISING	0b11

#define RESET	0
#define SET		1

/**
 * @brief 
 *
 * @param
 *
 * @retval
 */
void GPIO_SET_PIN(uint8_t pin, uint8_t port, uint8_t status);

/**
 * @brief 
 *
 * @param
 *
 * @retval
 */
void GPIO_WRITE_PIN(uint8_t pin, uint8_t port, uint8_t status);

/**
 * @brief 
 *
 * @param
 *
 * @retval
 */
bool GPIO_READ_PIN(uint8_t pin, uint8_t port);

/**
 * @brief 
 *
 * @param
 *
 * @retval
 */
void GPIO_PCINT_SET(uint8_t pin, uint8_t port);

/**
 * @brief 
 *
 * @param
 *
 * @retval
 */
void GPIO_EXTINT_SET(uint8_t int_type, uint8_t trigger_edge);



#endif /* GPIO_H_ */