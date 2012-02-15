/*
   File:   io_driver.h
   Author: Cesar Osaka

   Title:  Input/Output PIC18 driver

   [TODO]:
   - Implementar funções/macros trabalhar com I/Os.
 */

#ifndef IO_DRIVER_H
#define IO_DRIVER_H

// Definições gerais de I/Os
#define IO_LOW  0b0
#define IO_HIGH 0b1

#define TRIS_OUTPUT 0b0
#define TRIS_INPUT  0b1

#define TRIS_ALL_OUTPUT 0x00
#define TRIS_ALL_INPUT  0xFF

#define GET_BIT(var, bit) ((var >> bit) & 0b1)

#endif // IO_DRIVER_H
