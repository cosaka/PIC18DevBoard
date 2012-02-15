/*
   File:   main.c
   Author: Cesar Osaka

   Created on 10 de Janeiro de 2012, 16:51
 */

#include "hardware_profile.h"

#include "uart_driver.h"

const char str_Hello_serial[] = "Hello Serial!";
const char str_PIC18DevBoard[] = "PIC18DevBoard";
const char str_LF[] = "\n"; // Line Feed (LF)
const char str_CR[] = "\r"; // Carriage Return (CR)

/*
 * main()
 */
void main(void)
{
    // Inicialização de baixo nível para o hardware
    hw_basic_setup();

    uart_open(9600);

    uart_print_str(str_Hello_serial);
    uart_print_str(str_LF);
    uart_print_str(str_CR);

    uart_print_str(str_PIC18DevBoard);
    uart_print_str(str_LF);
    uart_print_str(str_CR);

    /* Laço infinito */

    for (;;)
    {
    }

    /**/
}
