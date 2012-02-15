/*
   File:   main.c
   Author: Cesar Osaka

   Created on 10 de Janeiro de 2012, 16:51
 */

#include "hardware_profile.h"

#include "io_driver.h"

/*
 * main()
 */
void main(void)
{
    // Inicialização de baixo nível para o hardware
    hw_basic_setup();

    /* Configurando direção dos I/Os */

    // LEDs como saída
    LED1_TRIS = TRIS_OUTPUT;
    LED2_TRIS = TRIS_OUTPUT;
    LED3_TRIS = TRIS_OUTPUT;
    LED4_TRIS = TRIS_OUTPUT;

    // Switches como entrada
    SW1_TRIS = TRIS_INPUT;
    SW2_TRIS = TRIS_INPUT;
    SW3_TRIS = TRIS_INPUT;
    SW4_TRIS = TRIS_INPUT;

    /**/

    /* Laço infinito */

    for (;;)
    {
        if (SW1 == SW_PRESSED)
            LED1 = LED_ON;
        else
            LED1 = LED_OFF;

        if (SW2 == SW_PRESSED)
            LED2 = LED_ON;
        else
            LED2 = LED_OFF;

        if (SW3 == SW_PRESSED)
            LED3 = LED_ON;
        else
            LED3 = LED_OFF;

        if (SW4 == SW_PRESSED)
            LED4 = LED_ON;
        else
            LED4 = LED_OFF;
    }

    /**/
}
