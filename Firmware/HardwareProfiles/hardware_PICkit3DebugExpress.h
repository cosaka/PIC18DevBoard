/*
   File:   hardware_PICkit3DebugExpress.h
   Author: Cesar Osaka

   Created on 12 de Janeiro de 2012, 09:50
 */

#ifndef HARDWARE_PICKIT3DEBUGEXPRESS_H
#define HARDWARE_PICKIT3DEBUGEXPRESS_H

#include <p18f45k20.h>

#include "io_driver.h"

#define FOSC 4000000ul

#define LED1_TRIS   TRISDbits.TRISD0
#define LED1        LATDbits.LATD0

#define LED2_TRIS   TRISDbits.TRISD1
#define LED2        LATDbits.LATD1

#define LED3_TRIS   TRISDbits.TRISD2
#define LED3        LATDbits.LATD2

#define LED4_TRIS   TRISDbits.TRISD3
#define LED4        LATDbits.LATD3

#define LED5_TRIS   TRISDbits.TRISD4
#define LED5        LATDbits.LATD4

#define LED6_TRIS   TRISDbits.TRISD5
#define LED6        LATDbits.LATD5

#define LED7_TRIS   TRISDbits.TRISD6
#define LED7        LATDbits.LATD6

#define LED8_TRIS   TRISDbits.TRISD7
#define LED8        LATDbits.LATD7

#define LED_OFF     IO_LOW
#define LED_ON      IO_HIGH

#define SW1_TRIS    TRISBbits.TRISB0
#define SW1         PORTBbits.RB0

#define SW2_TRIS    TRISBbits.TRISB1
#define SW2         PORTBbits.RB1

#define SW3_TRIS    TRISBbits.TRISB2
#define SW3         PORTBbits.RB2

#define SW4_TRIS    TRISBbits.TRISB3
#define SW4         PORTBbits.RB3

#define SW_PRESSED  IO_LOW

#endif // HARDWARE_PICKIT3DEBUGEXPRESS_H
