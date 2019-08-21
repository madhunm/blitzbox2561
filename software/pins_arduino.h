/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/
/* modified for 2561 with fewer ports  RWP 2015 */

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            46
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  ((p < 8) ? (p) + 46 : -1)
#define digitalPinHasPWM(p)         (p==3 || p==4 || p==5 || p==12 || p==13 || p==14 || p==15 || p==45)

static const uint8_t SS   = 8;
static const uint8_t MOSI = 10;
static const uint8_t MISO = 11;
static const uint8_t SCK  = 9;

static const uint8_t SDA = 17;
static const uint8_t SCL = 16;
static const uint8_t LED_BUILTIN = 9;

static const uint8_t A0 = 46;
static const uint8_t A1 = 47;
static const uint8_t A2 = 48;
static const uint8_t A3 = 49;
static const uint8_t A4 = 50;
static const uint8_t A5 = 51;
static const uint8_t A6 = 52;
static const uint8_t A7 = 53;


// A majority of the pins are NOT PCINTs, SO BE WARNED (i.e. you cannot use them as receive pins)
// Only pins available for RECEIVE (TRANSMIT can be on any pin):
// (I've deliberately left out pin mapping to the Hardware USARTs - seems senseless to me)
// 2560: Pins: 10, 11, 12, 13,  50, 51, 52, 53,  62, 63, 64, 65, 66, 67, 68, 69
// 2561 PCINTs: 8-15, all on PORTB  - I DON"T KNOW WHAT TO DO HERE

#define digitalPinToInterrupt(p) ((p) == 16 ? 0 : ((p) == 17 ? 1 : ((p) == 18 ? 2 : ((p) == 19 ? 3 :((p) == 4 ? 4 : ((p) == 5 ? 5 : ((p) == 6 ? 6 : ((p) == 7 ? 7 : NOT_AN_INTERRUPT))))))))	

#define digitalPinToPCICR(p)    (((p) >= 8) && ((p) <= 15)) ? (&PCICR) : ((uint8_t *)0) )

#define digitalPinToPCICRbit(p) (((p) >= 8) && ((p) <= 15)) ? 0 : ???? ) //What to return when it's not a valid pin? 0? In which case this could be shortened to 0. 

#define digitalPinToPCMSK(p)    (((p) >= 8) && ((p) <= 15)) ? (&PCMSK0) : ((uint8_t *)0) )
#define digitalPinToPCMSKbit(p) (((p) >= 8) && ((p) <= 15)) ? p-8 : ??? ) //again, as above... 


#ifdef ARDUINO_MAIN

const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
	(uint16_t) &DDRE,
	(uint16_t) &DDRF,
	(uint16_t) &DDRG,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
	(uint16_t) &PORTF,
	(uint16_t) &PORTG,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
	(uint16_t) &PINE,
	(uint16_t) &PINF,
	(uint16_t) &PING,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST		
	// -------------------------------------------		
	PE	, // PE 0 ** 0 ** USART0_RX	
	PE	, // PE 1 ** 1 ** USART0_TX	
	PE	, // PE 2 ** 2 ** 	
	PE	, // PE 3 ** 3 ** PWM0	
	PE	, // PE 4 ** 4 ** PWM1	
	PE	, // PE 5 ** 5 ** PWM2	
	PE	, // PE 6 ** 6 ** 	
	PE	, // PE 7 ** 7 ** 
	
	PB	, // PB 0 ** 8 ** SS	
	PB	, // PB 1 ** 9 ** SCK
	PB	, // PB 2 ** 10 ** MOSI
	PB	, // PB 3 ** 11 ** MISO
	PB	, // PB 4 ** 12 ** PWM3
	PB	, // PB 5 ** 13 ** PWM4
	PB	, // PB 6 ** 14 ** PWM5
	PB	, // PB 7 ** 15 ** PWM6
	
	PD	, // PD 0 ** 16 ** I2C - SCL - INT0	
	PD	, // PD 1 ** 17 ** I2C - SDA - INT1	
	PD	, // PD 2 ** 18 ** USART1_RX - INT2	
	PD	, // PD 3 ** 19 ** USART1_TX - INT3	
	PD	, // PD 4 ** 20 ** 
	PD	, // PD 5 ** 21 ** 	
	PD	, // PD 6 ** 22 ** 
	PD	, // PD 7 ** 23 ** 

	PA	, // PA 0 ** 24 ** D24	
	PA	, // PA 1 ** 25 ** D25	
	PA	, // PA 2 ** 26 ** D26	
	PA	, // PA 3 ** 27 ** D27	
	PA	, // PA 4 ** 28 ** D28	
	PA	, // PA 5 ** 29 ** D29	
	PA	, // PA 6 ** 30 ** D30	
	PA	, // PA 7 ** 31 ** D31
	
	PC	, // PC 0 ** 32 ** D32	
	PC	, // PC 1 ** 33 ** D33	
	PC	, // PC 2 ** 34 ** D34	
	PC	, // PC 3 ** 35 ** D35	
	PC	, // PC 4 ** 36 ** D36	
	PC	, // PC 5 ** 37 ** D37	
	PC	, // PC 6 ** 38 ** D38	
	PC	, // PC 7 ** 39 ** D39
	
	PG	, // PG 0 ** 40 ** D40	
	PG	, // PG 1 ** 41 ** D41	
	PG	, // PG 2 ** 42 ** D42	
	PG	, // PG 3 ** 43 ** D43	
	PG	, // PG 4 ** 44 ** D44	
	PG	, // PG 5 ** 45 ** D45
	
	PF	, // PF 0 ** 46 ** D46	
	PF	, // PF 1 ** 47 ** D47	
	PF	, // PF 2 ** 48 ** D48	
	PF	, // PF 3 ** 49 ** D49	
	PF	, // PF 4 ** 50 ** D50	
	PF	, // PF 5 ** 51 ** D51	
	PF	, // PF 6 ** 52 ** D52	
	PF	, // PF 7 ** 53 ** D53	
	
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT		
	// -------------------------------------------		
	_BV( 0 )	, // PE 0 ** 0 ** USART0_RX	
	_BV( 1 )	, // PE 1 ** 1 ** USART0_TX	
	_BV( 2 )	, // PE 2 ** 2 ** PWM2	
	_BV( 3 )	, // PE 3 ** 3 ** PWM3	
	_BV( 4 )	, // PE 4 ** 4 ** PWM4	
	_BV( 5 )	, // PE 5 ** 5 ** PWM5	
	_BV( 6 )	, // PE 6 ** 6 ** PWM6	
	_BV( 7 )	, // PE 7 ** 7 ** PWM7
	
	_BV( 0 )	, // PB 0 ** 8 ** PWM8	
	_BV( 1 )	, // PB 1 ** 9 ** PWM9	
	_BV( 2 )	, // PB 2 ** 10 ** PWM10	
	_BV( 3 )	, // PB 3 ** 11 ** PWM11	
	_BV( 4 )	, // PB 4 ** 12 ** PWM12	
	_BV( 5 )	, // PB 5 ** 13 ** PWM13	
	_BV( 6 )	, // PB 6 ** 14 ** USART3_TX	
	_BV( 7 )	, // PB 7 ** 15 ** USART3_RX
	
	_BV( 0 )	, // PD 0 ** 16 ** USART2_TX	
	_BV( 1 )	, // PD 1 ** 17 ** USART2_RX	
	_BV( 2 )	, // PD 2 ** 18 ** USART1_TX	
	_BV( 3 )	, // PD 3 ** 19 ** USART1_RX	
	_BV( 4 )	, // PD 4 ** 20 ** I2C_SDA	
	_BV( 5 )	, // PD 5 ** 21 ** I2C_SCL	
	_BV( 6 )	, // PD 6 ** 22 ** D22	
	_BV( 7 )	, // PD 7 ** 23 ** D23
	
	_BV( 0 )	, // PA 0 ** 24 ** D24	
	_BV( 1 )	, // PA 1 ** 25 ** D25	
	_BV( 2 )	, // PA 2 ** 26 ** D26	
	_BV( 3 )	, // PA 3 ** 27 ** D27	
	_BV( 4 )	, // PA 4 ** 28 ** D28	
	_BV( 5 )	, // PA 5 ** 29 ** D29	
	_BV( 6 )	, // PA 6 ** 30 ** D30	
	_BV( 7 )	, // PA 7 ** 31 ** D31
	
	_BV( 0 )	, // PC 0 ** 32 ** D32	
	_BV( 1 )	, // PC 1 ** 33 ** D33	
	_BV( 2 )	, // PC 2 ** 34 ** D34	
	_BV( 3 )	, // PC 3 ** 35 ** D35	
	_BV( 4 )	, // PC 4 ** 36 ** D36	
	_BV( 5 )	, // PC 5 ** 37 ** D37	
	_BV( 6 )	, // PC 6 ** 38 ** D38	
	_BV( 7 )	, // PC 7 ** 39 ** D39	

	_BV( 0 )	, // PG 0 ** 40 ** D40	
	_BV( 1 )	, // PG 1 ** 41 ** D41	
	_BV( 2 )	, // PG 2 ** 42 ** D42	
	_BV( 3 )	, // PG 3 ** 43 ** D43	
	_BV( 4 )	, // PG 4 ** 44 ** D44	
	_BV( 5 )	, // PG 5 ** 45 ** D45
	
	_BV( 0 )	, // PF 3 ** 46 ** D46 ADC0	
	_BV( 1 )	, // PF 2 ** 47 ** D47 ADC1	
	_BV( 2 )	, // PF 1 ** 48 ** D48 ADC2
	_BV( 3 )	, // PF 0 ** 49 ** D49 ADC3
	_BV( 4 )	, // PF 3 ** 50 ** D50 ADC4
	_BV( 5 )	, // PF 2 ** 51 ** D51 ADC5
	_BV( 6 )	, // PF 1 ** 52 ** D52 ADC6
	_BV( 7 )	, // PF 0 ** 53 ** D53 ADC7
	
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS		        
	// -------------------------------------------		
	NOT_ON_TIMER	, // PE 0 ** 0 ** D0	
	NOT_ON_TIMER	, // PE 1 ** 1 ** D1
	NOT_ON_TIMER	, // PE 2 ** 2 ** D2
	TIMER3A			, // PE 3 ** 3 ** D3	
	TIMER3B			, // PE 4 ** 4 ** D4	
	TIMER3C			, // PE 5 ** 5 ** D5	
	NOT_ON_TIMER	, // PE 6 ** 6 ** D6	
	NOT_ON_TIMER	, // PE 7 ** 7 ** D7
	
	NOT_ON_TIMER	, // PB 0 ** 8 ** D8	
	NOT_ON_TIMER	, // PB 1 ** 9 ** D9	
	NOT_ON_TIMER	, // PB 2 ** 10 ** D10	
	NOT_ON_TIMER	, // PB 3 ** 11 ** D11
	TIMER2A			, // PB 4 ** 12 ** D12
	TIMER1A			, // PB 5 ** 13 ** D13
	TIMER1B			, // PB 6 ** 14 ** D14
	TIMER0A			, // PB 7 ** 15 ** D15
	
	NOT_ON_TIMER	, // PD 0 ** 16 ** D16	
	NOT_ON_TIMER	, // PD 1 ** 17 ** D17	
	NOT_ON_TIMER	, // PD 2 ** 18 ** D18	
	NOT_ON_TIMER	, // PD 3 ** 19 ** D19	
	NOT_ON_TIMER	, // PD 4 ** 20 ** D20	
	NOT_ON_TIMER	, // PD 5 ** 21 ** D21
	NOT_ON_TIMER	, // PD 6 ** 22 ** D22	
	NOT_ON_TIMER	, // PD 7 ** 23 ** D23
	
	NOT_ON_TIMER	, // PA 0 ** 24 ** D24	
	NOT_ON_TIMER	, // PA 1 ** 25 ** D25	
	NOT_ON_TIMER	, // PA 2 ** 26 ** D26	
	NOT_ON_TIMER	, // PA 3 ** 27 ** D27	
	NOT_ON_TIMER	, // PA 4 ** 28 ** D28	
	NOT_ON_TIMER	, // PA 5 ** 29 ** D29	
	NOT_ON_TIMER	, // PA 6 ** 30 ** D30	
	NOT_ON_TIMER	, // PA 7 ** 31 ** D31
	
	NOT_ON_TIMER	, // PC 0 ** 32 ** D32	
	NOT_ON_TIMER	, // PC 1 ** 33 ** D33	
	NOT_ON_TIMER	, // PC 2 ** 34 ** D34	
	NOT_ON_TIMER	, // PC 3 ** 35 ** D35	
	NOT_ON_TIMER	, // PC 4 ** 36 ** D36	
	NOT_ON_TIMER	, // PC 5 ** 37 ** D37	
	NOT_ON_TIMER	, // PC 6 ** 38 ** D38	
	NOT_ON_TIMER	, // PC 7 ** 39 ** D39
	
	NOT_ON_TIMER	, // PG 0 ** 40 ** D40	
	NOT_ON_TIMER	, // PG 1 ** 41 ** D41	
	NOT_ON_TIMER	, // PG 2 ** 42 ** D42	
	NOT_ON_TIMER	, // PG 3 ** 43 ** D43	
	NOT_ON_TIMER	, // PG 4 ** 44 ** D44	
	TIMER0B			, // PG 5 ** 45 ** D45	

	NOT_ON_TIMER	, // PF 0 ** 46 ** D46	
	NOT_ON_TIMER	, // PF 1 ** 47 ** D47	
	NOT_ON_TIMER	, // PF 2 ** 48 ** D48	
	NOT_ON_TIMER	, // PF 3 ** 49 ** D49	
	NOT_ON_TIMER	, // PF 4 ** 50 ** D50	
	NOT_ON_TIMER	, // PF 5 ** 51 ** D51
	NOT_ON_TIMER	, // PF 6 ** 52 ** D52	
	NOT_ON_TIMER	, // PF 7 ** 53 ** D53
	
};

#endif

#endif