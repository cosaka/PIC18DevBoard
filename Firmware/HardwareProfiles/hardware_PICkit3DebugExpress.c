/*
   File:   hardware_PICkit3DebugExpress.c
   Author: Cesar Osaka

   Created on 12 de Janeiro de 2012, 10:04
 */

#include "hardware_profile.h"

#ifdef _HARDWARE_PICKIT3DEBUGEXPRESS

// Configuration Bits

#if defined __18CXX

#pragma config FOSC = INTIO67   // Oscilador externo com ganho intermediário (sem PLL)
#pragma config WDTEN = OFF      // Watch Dog Timer desabilitado
#pragma config LVP = OFF        // Single-Supply ICSP desablitado

#else

#error "Compilador não suportado."

#endif

void hw_basic_setup(void)
{
    // Desabilita buffers analógicos

    ANSEL = 0x00;
    ANSELH = 0x00;
}

#endif // _HARDWARE_PICKIT3DEBUGEXPRESS
