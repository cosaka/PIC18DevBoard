#include "drivers_config.h"
#include "adc_driver.h"

#define GET_BIT(var, bit) ((var >> bit) & 0b1)

#if defined __18F4520

void adc_set_an_pins(enum ADC_PCFG pcfg)
{
    //ADCON1bits.PCFG = pcfg;
    ADCON1bits.PCFG0 = GET_BIT(pcfg, 0);
    ADCON1bits.PCFG1 = GET_BIT(pcfg, 1);
    ADCON1bits.PCFG2 = GET_BIT(pcfg, 2);
    ADCON1bits.PCFG3 = GET_BIT(pcfg, 3);
}

#elif defined __18F45K20

void adc_set_an_pin(enum ADC_ANSEL_BIT anselBit)
{
    if (anselBit <= ADC_ANSEL_ANS7)
        ANSEL |= (0b1 << anselBit);
    else if (anselBit <= (0b1 << ADC_ANSEL_ANS12);
        ANSELH |= anselBit;
}

#endif

/*
void adc_set_vref()
{
    //
}
*/

unsigned int adc_read(enum ADC_CH channel)
{
    unsigned int result;

    //ADCON0bits.CHS = channel;
    ADCON0bits.CHS0 = GET_BIT(channel, 0);
    ADCON0bits.CHS1 = GET_BIT(channel, 1);
    ADCON0bits.CHS2 = GET_BIT(channel, 2);

    //ADCON2bits.ACQT = 0b100;
    ADCON2bits.ACQT0 = GET_BIT(0b100, 0);
    ADCON2bits.ACQT1 = GET_BIT(0b100, 1);
    ADCON2bits.ACQT2 = GET_BIT(0b100, 2);

    //ADCON2bits.ADCS = 0b010;
    ADCON2bits.ADCS0 = GET_BIT(0b010, 0);
    ADCON2bits.ADCS1 = GET_BIT(0b010, 1);
    ADCON2bits.ADCS2 = GET_BIT(0b010, 2);

    ADCON0bits.ADON = 0b1;

    // Delay
    {
        unsigned tmp;
        for (tmp = 20; tmp > 0; tmp--);
    }

    ADCON0bits.GO = 0b1;

    while (ADCON0bits.DONE != 0b0);

    result = ((ADRESL >> 6) + ((unsigned int)ADRESH << 2));

    return result;
}
