/*
   File:   isr_driver.h
   Author: Cesar Osaka

   Title:  Interrupt service routine PIC18 driver
 */

typedef struct INT_STATUS_
{
    unsigned GIEH: 1;
    unsigned GIEL: 1;
} INT_STATUS;

void isr_init(void);
INT_STATUS isr_disable_all(void);
//void isr_restore_all(INT_STATUS intStatus);
