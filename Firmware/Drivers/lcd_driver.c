#include "drivers_config.h"
#include "io_driver.h"
#include "pmp_sw_driver.h"
#include "lcd_driver.h"

void lcd_init(void)
{
    LCT_RS_TRIS = TRIS_OUTPUT;

    LCD_RS = 0b0;

    pmp_sw_init();

    // Inicialização padrão
    lcd_write_cmd(0b00000110);
    lcd_write_cmd(0b00001100);
    lcd_write_cmd(0b00111000);
}

void lcd_wait(void)
{
    char buffer = 0x80;

    LCD_RS = 0b0; // Command

    while ((buffer & 0x80))
    {
        pmp_sw_read(&buffer, 1);
    }
}

void lcd_write_data(const char *buffer, unsigned int length)
{
    unsigned int i;

    LCD_RS = 0b1; // Data

    //lcd_wait();

    for (i = 0; i < length; i++)
    {
        pmp_sw_write(&(buffer[i]), /*length*/1);
    }
}

void lcd_read_data(char *buffer, unsigned int length)
{
    unsigned int i;

    LCD_RS = 0b1; // Data

    //lcd_wait();

    for (i = 0; i < length; i++)
    {
        pmp_sw_read(&(buffer[i]), /*length*/1);
    }
}

void lcd_write_cmd(char cmd)
{
    LCD_RS = 0b0; // Command

    lcd_wait();

    pmp_sw_write(&cmd, 1);
}

void lcd_set_ddram_addr(unsigned char addr)
{
    lcd_write_cmd((LCD_DDRAM_ADDR | addr));
}

void lcd_set_position(unsigned int col, unsigned int row)
{
    lcd_set_ddram_addr((((row-1) * 0x40) + col));
}

void lcd_clr(void)
{
    lcd_write_cmd(LCD_CLR);
}

void lcd_home(void)
{
    lcd_write_cmd(LCD_SET_HOME);
}

void lcd_line_1(void)
{
    lcd_set_position(0, 1);
}

void lcd_line_2(void)
{
    lcd_set_position(0, 2);
}

void lcd_print_str(const char *str)
{
    unsigned int length;

    for (length = 0; str[length] != '\0'; length++);

    lcd_write_data(str, length);
}
