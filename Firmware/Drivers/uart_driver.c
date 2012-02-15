#include "drivers_config.h"
#include "isr_driver.h"

/* UART FIFO (por enquanto este código fica aqui */

struct UART_FIFO
{
	unsigned char start;
	unsigned char end;
	unsigned char count;
	#ifdef ENABLE_UART_DEBUG
	unsigned char max;
	#endif
	unsigned char length;
	char *buff;
};

char buffTx1[UART1_TX_BUFFER_LENGTH];
struct UART_FIFO fifoTx1 =
{
    0, 0, 0,
    #ifdef ENABLE_UART_DEBUG
    0,
    #endif
    sizeof(buffTx1), buffTx1
};

char buffRx1[UART1_RX_BUFFER_LENGTH];
struct UART_FIFO fifoRx1 =
{
    0, 0, 0,
    #ifdef ENABLE_UART_DEBUG
    0,
    #endif
    sizeof(buffRx1), buffRx1
};

int fifoEnqueue(
    struct UART_FIFO *pFifo,
    char dt)
{
	if ( pFifo->count < pFifo->length )
	{
		pFifo->buff[pFifo->end++] = dt;

		if ( pFifo->end == pFifo->length )
			pFifo->end = 0;

		pFifo->count++;

		#ifdef ENABLE_UART_DEBUG

		if ( pFifo->count > pFifo->max )
			pFifo->max = pFifo->count;

		#endif

		return 0;
	}

	return -1;
}

int fifoDequeue(
    struct UART_FIFO *pFifo,
    char *pData)
{
	if ( pFifo->count )
	{
		*pData = pFifo->buff[pFifo->start++];

		if ( pFifo->start == pFifo->length )
			pFifo->start = 0;

		pFifo->count--;

		return 0;
	}

	return -1;
}

int fifoEmpty(
    struct UART_FIFO *pFifo)
{
	if ( pFifo->count == 0 )
		return 1;
	else
		return 0;
}

/**/

#define BusyUTX() (PIR1bits.TXIF == 0b0)
#define DisableIntUTX() (PIE1bits.TXIE = 0b0)
#define EnableIntUTX() (PIE1bits.TXIE = 0b1)
#define PushUTXBuffer(byte) (TXREG = byte)

void uart_open(unsigned long baudRate)
{
    unsigned short baudRateGen;

    // The pins of the Enhanced USART are multiplexed with PORTC. In order to
    // configure RC6/TX/CK and RC7/RX/DT as an EUSART:
    TRISCbits.TRISC7 = 0b1;
    TRISCbits.TRISC6 = 0b1;

    TXSTA = 0x00;
    RCSTA = 0x00;
    BAUDCON = 0x00;

    PIE1bits.TXIE = 0b0; // desabilita interrupção de TX
    PIE1bits.RCIE = 0b0; // desabilita interrupção de RX

    TXSTAbits.TXEN = 0b1; // habilita TX
    TXSTAbits.BRGH = 0b1; // [TODO] - implementar esta opção

    RCSTAbits.CREN = 0b1; // habilita RX

    BAUDCONbits.BRG16 = 0b1; // [TODO] - implementar esta opção

    // [TODO] - implementar mais opções de baud rate
    // Baud Rate = FOSC/[4 (n + 1)]
    baudRateGen = ((FOSC/baudRate)/4) - 1;
    SPBRGH = baudRateGen / 256;
    SPBRG = baudRateGen % 256;

    //PIE1bits.TXIE = 0b1; // habilita interrupção de TX
    //PIE1bits.RCIE = 0b1; // habilita interrupção de RX

    RCSTAbits.SPEN = 0b1; // habilita porta serial (pinos em modo TX e RX)

    isr_init();
}

void uart_close(void)
{
    TXSTA = 0x00;
    RCSTA = 0x00;
    BAUDCON = 0x00;
}

unsigned int uart_write_data(const char *buffer, unsigned int length)
{
    unsigned int i;

    DisableIntUTX();

    for (i = 0; i < length; i++)
    {
        if (fifoEnqueue(&fifoTx1, buffer[i]))
            break;
    }

    if (!fifoEmpty(&fifoTx1))
    {
        // habilita início de transmissão
        EnableIntUTX();
    }
    /*
    else
    {
        DisableIntUTX();
    }
    */

    return i;
}

void uart_flush(void)
{
    char byte;

    DisableIntUTX();

    while (!fifoDequeue(&fifoTx1, &byte))
    {
        while (BusyUTX());

        // manda escrever
        PushUTXBuffer(byte);
    }
}

unsigned int uart_print_str(const char *str)
{
    unsigned int length;

    for (length = 0; str[length] != '\0'; length++);

    return uart_write_data(str, length);
}

void uart_driver_tx_interrupt(void)
{
    char byte;

    if (!fifoDequeue(&fifoTx1, &byte))
    {
        // manda escrever
        PushUTXBuffer(byte);
    }

    if (fifoEmpty(&fifoTx1))
    {
        DisableIntUTX();
    }
}

void uart_driver_rx_interrupt(void)
{
    //
}
