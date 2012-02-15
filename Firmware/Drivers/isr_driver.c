#include "drivers_config.h"
#include "isr_driver.h"

// Protótipos externos
extern void uart_driver_tx_interrupt(void);
extern void uart_driver_rx_interrupt(void);

#if defined __18CXX
void low_isr(void);
void high_isr(void);
#endif

void isr_init(void)
{
    RCONbits.IPEN = 0b1;

    INTCONbits.GIEH = 0b1;
    INTCONbits.GIEL = 0b1;
}

/*
INT_STATUS isr_disable_all(void)
{
    INT_STATUS intStatus;

    intStatus.GIEH = INTCONbits.GIEH;
    intStatus.GIEL = INTCONbits.GIEL;

    INTCONbits.GIEH = 0b0;
    INTCONbits.GIEL = 0b0;

    return intStatus;
}

INT_STATUS isr_enable_all(void)
{
    INT_STATUS intStatus;

    intStatus.GIEH = INTCONbits.GIEH;
    intStatus.GIEL = INTCONbits.GIEL;

    INTCONbits.GIEH = 0b1;
    INTCONbits.GIEL = 0b1;

    return intStatus;
}

INT_STATUS isr_disable_high(void)
{
    INT_STATUS intStatus;

    intStatus.GIEH = INTCONbits.GIEH;
    intStatus.GIEL = INTCONbits.GIEL;

    INTCONbits.GIEH = 0b0;

    return intStatus;
}

INT_STATUS isr_enable_high(void)
{
    INT_STATUS intStatus;

    intStatus.GIEH = INTCONbits.GIEH;
    intStatus.GIEL = INTCONbits.GIEL;

    INTCONbits.GIEH = 0b1;

    return intStatus;
}

INT_STATUS isr_disable_low(void)
{
    INT_STATUS intStatus;

    intStatus.GIEH = INTCONbits.GIEH;
    intStatus.GIEL = INTCONbits.GIEL;

    INTCONbits.GIEL = 0b0;

    return intStatus;
}

INT_STATUS isr_enable_low(void)
{
    INT_STATUS intStatus;

    intStatus.GIEH = INTCONbits.GIEH;
    intStatus.GIEL = INTCONbits.GIEL;

    INTCONbits.GIEL = 0b1;

    return intStatus;
}

void isr_restore_all(INT_STATUS intStatus)
{
    INTCONbits.GIEH = intStatus.GIEH;
    INTCONbits.GIEL = intStatus.GIEL;
}
*/

/*
 For PIC18 devices the low interrupt vector is found at
 00000018h. The following code will branch to the
 low_interrupt_service_routine function to handle
 interrupts that occur at the low vector.
 */
#if defined __18CXX
#pragma code low_vector=0x18
void interrupt_at_low_vector(void)
{
  _asm GOTO low_isr _endasm
}
#endif

/*
 For PIC18 devices the high interrupt vector is found at
 00000008h. The following code will branch to the
 high_interrupt_service_routine function to handle
 interrupts that occur at the high vector.
 */
#if defined __18CXX
#pragma code high_vector=0x08
void interrupt_at_high_vector(void)
{
  _asm GOTO high_isr _endasm
}
#endif

#if defined __18CXX
#pragma code /* return to the default code section */
#pragma interruptlow low_isr
void low_isr (void)
#else //elif defined SDCC
void low_isr(void) __interrupt 2
#endif
{
    if (PIR1bits.TXIF == 0b1)
    {
        uart_driver_tx_interrupt();
    }

    if (PIR1bits.RCIF == 0b1)
    {
        uart_driver_rx_interrupt();
    }
}

#if defined __18CXX
#pragma code /* return to the default code section */
#pragma interrupt high_isr
void high_isr (void)
#else //elif defined SDCC
void high_isr(void) __interrupt 1
#endif
{
    if (PIR1bits.TXIF == 0b1)
    {
        uart_driver_tx_interrupt();
    }

    if (PIR1bits.RCIF == 0b1)
    {
        uart_driver_rx_interrupt();
    }
}
