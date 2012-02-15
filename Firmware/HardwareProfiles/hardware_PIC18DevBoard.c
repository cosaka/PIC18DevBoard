/*
   File:   hardware_PIC18DevBoard.c
   Author: Cesar Osaka

   Created on 12 de Janeiro de 2012, 10:06
 */

#include "hardware_profile.h"

#ifdef _HARDWARE_PIC18DEVBOARD

// Configuration Bits

#if defined __18CXX

#if defined __18F4520
//#pragma config OSC = XT     // Oscilador externo com ganho intermediário (sem PLL)
    #pragma config OSC = HS     // Oscilador externo com ganho intermediário (sem PLL)
#pragma config WDT = OFF    // Watch Dog Timer desabilitado
#pragma config LVP = OFF    // Single-Supply ICSP desablitado
#elif defined __18F45K20
//#pragma config FOSC = XT    // Oscilador externo com ganho intermediário (sem PLL)
    #pragma config FOSC = HS    // Oscilador externo com ganho intermediário (sem PLL)
#pragma config WDTEN = OFF  // Watch Dog Timer desabilitado
#pragma config LVP = OFF    // Single-Supply ICSP desablitado
#endif

#else //elif defined SDCC

//__CONFIG(__CONFIG1H, _OSC_XT_1H);   // Oscilador externo com ganho intermediário (sem PLL)
    __CONFIG(__CONFIG1H, _OSC_HS_1H);   // Oscilador externo com ganho intermediário (sem PLL)
__CONFIG(__CONFIG2H, _WDT_OFF_2H);  // Watch Dog Timer desabilitado
__CONFIG(__CONFIG4L, _LVP_OFF_4L);  // Single-Supply ICSP desablitado

#endif

void hw_basic_setup(void)
{
    // Desabilita todos os buffers analógicos

    #if defined __18F4520

    //ADCON1bits.PCFG = 0b1111;
    ADCON1bits.PCFG0 = 0b1;
    ADCON1bits.PCFG1 = 0b1;
    ADCON1bits.PCFG2 = 0b1;
    ADCON1bits.PCFG3 = 0b1;

    #elif defined __18F45K20

    ANSEL = 0x00;
    ANSELH = 0x00;

    #endif
}

#endif // _HARDWARE_PIC18DEVBOARD
