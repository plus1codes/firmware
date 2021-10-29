#include "common.h"


int UART_tx_rdy()
{
		unsigned char* idata RegValue;
		unsigned char data_tx_rdy;
		RegValue = RBUS_Read(UART_REG_LSR);
		data_tx_rdy = *(RegValue);
		
		return ((data_tx_rdy & UART_LSR_TX_RDY) ? 1: 0);
}

void UART_putc (char c) 
{
		while (!UART_tx_rdy()) ;
		RBUS_Write(UART_REG_DATA,(unsigned long)c);
}

char putchar (char c) 
{
	char _c=(c); 
	UART_putc(_c); 
	if (_c == 0x0a) 
		UART_putc(0x0d);
	return (c);
}