#include "drivers_config.h"
#include "io_driver.h"

void pmp_sw_init(void)
{
    _6800_E_TRIS = TRIS_OUTPUT;
    _6800_R_nW_TRIS = TRIS_OUTPUT;

    _6800_E = 0b0;
    _6800_R_nW = 0b0;
}

void pmp_sw_write(const char *array, unsigned int length)
{
    unsigned int i;

    _6800_D0_7_TRIS = TRIS_ALL_OUTPUT;

    _6800_R_nW = 0b0; // Write

    for (i = 0; i < length; i++)
    {
        _6800_D0_7_LAT = array[i];

        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();

        _6800_E = 0b1;

        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();

        _6800_E = 0b0;

        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
    }
}

void pmp_sw_read(unsigned char *buffer, unsigned int length)
{
    unsigned int i;

    _6800_D0_7_TRIS = TRIS_ALL_INPUT;

    _6800_R_nW = 0b1; // Read

    for (i = 0; i < length; i++)
    {
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();

        _6800_E = 0b1;

        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();

        buffer[i] = _6800_D0_7_PORT;

        _6800_E = 0b0;

        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
    }
}
