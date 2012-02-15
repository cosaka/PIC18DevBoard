/*
   File:   adc_driver.h
   Author: Cesar Osaka

   Title:  A/D converter PIC18 driver

   Notas:
 */

#ifndef ADC_DRIVER_H
#define ADC_DRIVER_H

enum ADC_PCFG
{
    ADC_AN0_12 = 0b0000,
    ADC_AN0_11 = 0b0011,
    ADC_AN0_10,
    ADC_AN0_9,
    ADC_AN0_8,
    ADC_AN0_7,
    ADC_AN0_6,
    ADC_AN0_5,
    ADC_AN0_4,
    ADC_AN0_3,
    ADC_AN0_2,
    ADC_AN0_1,
    ADC_AN0,
    ADC_ALL_PINS_DIGITAL = 0b1111
};

enum ADC_ANSEL_BIT
{
    ADC_ANSEL_ANS0 = 0,
    ADC_ANSEL_ANS1,
    ADC_ANSEL_ANS2,
    ADC_ANSEL_ANS3,
    ADC_ANSEL_ANS4,
    ADC_ANSEL_ANS5,
    ADC_ANSEL_ANS6,
    ADC_ANSEL_ANS7,
    ADC_ANSEL_ANS8,
    ADC_ANSEL_ANS9,
    ADC_ANSEL_ANS10,
    ADC_ANSEL_ANS11,
    ADC_ANSEL_ANS12
};

enum ADC_CH
{
    ADC_CH0 = 0b0000,
    ADC_CH1,
    ADC_CH2,
    ADC_CH3,
    ADC_CH4,
    ADC_CH5,
    ADC_CH6,
    ADC_CH7,
    ADC_CH8,
    ADC_CH9,
    ADC_CH10,
    ADC_CH11,
    ADC_CH12
};

#if defined __18F4520
void adc_set_an_pins(enum ADC_PCFG pcfg);
#elif defined __18F45K20
void adc_set_an_pin(enum ADC_ANSEL_BIT anselBit);
#endif
unsigned int adc_read(enum ADC_CH channel);

#endif // ADC_DRIVER_H
