/*
   File:   pmp_sw_driver.h
   Author: Cesar Osaka

   Title:  Parallel master port software driver

   Notas:
   Suporta apenas interface parelela 6800.

   [TODO]:
   - Implementar opção de barramento de dados de 4-bit.
*/

#ifndef PMP_SW_DRIVER_H
#define PMP_SW_DRIVER_H

void pmp_sw_init(void);
void pmp_sw_write(const char *array, unsigned int length);
void pmp_sw_read(char *buffer, unsigned int length);

#endif // PMP_SW_DRIVER_H
