/*
   File:   main.c
   Author: Cesar Osaka

   Created on 19 de Janeiro de 2012, 15:36
 */

#if defined __18CXX
    #include <p18cxxx.h> // Utilizando compilador C18
#else //elif defined SDCC
    #include <pic18fregs.h> // Utilizando compilador SDCC
#endif

// Configuration Bits
#if defined __18CXX
    // Utilizando compilador C18
    #pragma config OSC = HS     // Oscilador externo com alto ganho (sem PLL)
    #pragma config WDT = OFF    // Watch Dog Timer desabilitado
    #pragma config LVP = OFF    // Single-Supply ICSP desablitado
#else //elif defined SDCC
    // Utilizando compilador SDCC
    __CONFIG(__CONFIG1H, _OSC_HS_1H);   // Oscilador externo com alto ganho (sem PLL)
    __CONFIG(__CONFIG2H, _WDT_OFF_2H);  // Watch Dog Timer desabilitado
    __CONFIG(__CONFIG4L, _LVP_OFF_4L);  // Single-Supply ICSP desablitado
#endif

void main(void)
{
    /* Configurando direção dos I/Os:
    Nos PICs, os resgitradores TRISx configuram a direção dos I/Os:
    0 - configurado como saída;
    1 - configurado como entrada. */

    // LED como saída
    TRISBbits.TRISB4 = 0; // LED1 no port RB4

    // Switch como entrada
    TRISBbits.TRISB0 = 1; // SW1 no port RB0

    /* Laço infinito */

    for (;;)
    {
        /* Para ler uma entrada utilizamos os registros PORTx.
        Para escrever em uma saída utilizamos os registros LATx. */

        if (PORTBbits.RB0 == 0) // Lê estado da switch (chave, botão)
        {
            LATBbits.LATB4 = 1; // Switch pressionado, acende LED
        }
        else
        {
            LATBbits.LATB4 = 0; // Switch liberado, apaga LED
        }
    }

    /**/
}
