/*
   File:   hardware_devboardPIC18.h
   Author: Cesar Osaka

   Created on 11 de Janeiro de 2012, 16:31
 */

#ifndef HARDWARE_DEVBOARDPIC18_H
#define HARDWARE_DEVBOARDPIC18_H

#if defined __18CXX
#include <p18cxxx.h>
#else //elif defined SDCC
#include <pic18fregs.h>
#endif

#include "io_driver.h"

#define FOSC 10000000ul

#define LED1_TRIS   TRISBbits.TRISB4
#define LED1        LATBbits.LATB4

#define LED2_TRIS   TRISBbits.TRISB5
#define LED2        LATBbits.LATB5

#define LED3_TRIS   TRISAbits.TRISA2
#define LED3        LATAbits.LATA2

#define LED4_TRIS   TRISAbits.TRISA3
#define LED4        LATAbits.LATA3

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

// LCD
#define LCT_RS_TRIS TRISEbits.TRISE2
#define LCD_RS      LATEbits.LATE2

#define _6800_E_TRIS    TRISEbits.TRISE0
#define _6800_E         LATEbits.LATE0
#define _6800_R_nW_TRIS TRISEbits.TRISE1
#define _6800_R_nW      LATEbits.LATE1

#define _6800_D0_7_TRIS TRISD
#define _6800_D0_7_PORT PORTD
#define _6800_D0_7_LAT  LATD

#endif // HARDWARE_DEVBOARDPIC18_H
