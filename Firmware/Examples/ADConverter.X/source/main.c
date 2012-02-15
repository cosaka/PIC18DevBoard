/*
   File:   main.c
   Author: Cesar Osaka

   Created on 10 de Janeiro de 2012, 16:51
 */

#include "hardware_profile.h"

#include "io_driver.h"
#include "adc_driver.h"
#include "lcd_driver.h"
#include "uart_driver.h"

const char str_ADConverter[] = "A/D converter:";
char str_Analog[] = "  0%";
const char str_LF[] = "\n"; // Line Feed (LF)
const char str_CR[] = "\r"; // Carriage Return (CR)

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

    // Canais analógicos;
    #if defined __18F4520
    adc_set_an_pins(ADC_AN0);
    #elif defined __18F45K20
    adc_set_an_pin(ADC_ANSEL_ANS0);
    #endif

    /**/

    lcd_init();

    uart_open(9600);

    lcd_clr();
    lcd_line_1();
    lcd_print_str(str_ADConverter);

    uart_print_str(str_ADConverter);

    /* Laço infinito */

    for (;;)
    {
        unsigned int analogVal;

        // Lê canal analógico AN0
        analogVal = adc_read(ADC_CH0);

        // Mostra resultado em forma de barra de LEDs
        if (analogVal > 10)
            LED1 = LED_ON;
        else
            LED1 = LED_OFF;

        if (analogVal > (1023/3))
            LED2 = LED_ON;
        else
            LED2 = LED_OFF;

        if (analogVal > (2*1023/3))
            LED3 = LED_ON;
        else
            LED3 = LED_OFF;

        if (analogVal > (1023-10))
            LED4 = LED_ON;
        else
            LED4 = LED_OFF;

        // Montando string
        str_Analog[0] = '0' + (analogVal / 1023);
        if (str_Analog[0] < '1')
            str_Analog[0] = ' ';
        str_Analog[1] = '0' + ((analogVal * 10) / 1023);
        if (str_Analog[1] < '1')
            str_Analog[1] = ' ';
        else if (str_Analog[1] > '9')
            str_Analog[1] = '0';
        str_Analog[2] = '0' + (analogVal % (1023 / 10)) / 10;
        if (str_Analog[2] > '9')
            str_Analog[2] = '0';

        // Escreve resultado no LCD
        lcd_line_2();
        lcd_print_str(str_Analog);

        // Escreve resultado na serial
        uart_print_str(str_LF);
        uart_print_str(str_CR);
        uart_print_str(str_Analog);

        // Espera esvasiar o buffer de transmissão
        uart_flush();
    }

    /**/
}
