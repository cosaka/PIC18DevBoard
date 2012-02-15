/*
   File:   main.c
   Author: Cesar Osaka

   Created on 10 de Janeiro de 2012, 16:51
 */

#include "hardware_profile.h"

#include "lcd_driver.h"

const char str_Hello_world[] = "Hello LCD!";
const char str_PIC18DevBoard[] = "PIC18DevBoard";

/*
 * main()
 */
void main(void)
{
    // Inicialização de baixo nível para o hardware
    hw_basic_setup();

    lcd_init();

    lcd_clr();

    lcd_line_1();
    lcd_print_str(str_Hello_world);

    lcd_line_2();
    lcd_print_str(str_PIC18DevBoard);

    /* Laço infinito */

    for (;;)
    {
    }

    /**/
}
