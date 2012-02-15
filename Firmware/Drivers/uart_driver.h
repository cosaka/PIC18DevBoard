/*
   File:   uart_driver.h
   Author: Cesar Osaka

   Title:  UART PIC18 driver

   Suporta apenas interface serial universal mais utilizada: 8-N-1, sem controle
   de fluxo.
*/

#ifndef UART_DRIVER_H
#define UART_DRIVER_H

void uart_open(unsigned long baudRate);
void uart_close(void);
unsigned int uart_write_data(const char *buffer, unsigned int length);
//int uart_read_data(unsigned char *buffer, unsigned int length);
void uart_flush(void);

void uart_print_str(const char *str);
//void uart_print_val(unsigned int value);

#endif // UART_DRIVER_H
