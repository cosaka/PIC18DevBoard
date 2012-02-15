/*
   File:   lcd_driver.h
   Author: Cesar Osaka

   Title:  LCD display driver

   Notas:
   Implementado para LCD de 2x16, com barramento de dados de 8-bit.

   [TODO]:
   - Implementar opção de barramento de dados de 4-bit;
   - Implementar suporte para mais de 2 linhas;
   - Completar a lista de comandos.
 */

#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H

#define LCD_CLR         0x01
#define LCD_SET_HOME    0x02
#define LCD_DDRAM_ADDR  0x80

void lcd_init(void);
void lcd_write_data(const char *buffer, unsigned int length);
void lcd_read_data(char *buffer, unsigned int length);
void lcd_write_cmd(char cmd);
void lcd_set_ddram_addr(unsigned char addr);
void lcd_set_position(unsigned int col, unsigned int row);

void lcd_clr(void);
void lcd_home(void);
void lcd_line_1(void);
void lcd_line_2(void);
void lcd_print_str(const char *str);
//void lcd_print_val(unsigned int value);

#endif // LCD_DRIVER_H
