#include <stdio.h>
#include "common.h"
#include "i2c_slave_common.h"
#include "i2c_slave.h"
#include "string.h"


unsigned int xdata tx_head=0,tx_tail=0,rx_head=0,rx_tail=0;

unsigned char xdata rx_data_buf[I2C_RING_FIFO],tx_data_buf[I2C_RING_FIFO];


int store_data(int value)
{

	tx_data_buf[tx_tail] = value;
	tx_tail = (tx_tail+1)%I2C_RING_FIFO;
	
	if((REG_IOP_2_RISC & I2C_TX_EMPTY_MASK) == I2C_TX_EMPTY_MASK)
	{
		IOP_WRITE_DATA(REG_IOP_2_RISC,I2C_TX_EMPTY_MASK,0<<I2C_TX_EMPTY_POS);
	}
	return 1;
}

int load_data(void)
{
	unsigned int xdata value;
	if(rx_tail == rx_head)
	{
		return 0xFF; // iop rx buf is empty
	}
	value = rx_data_buf[rx_head];
	rx_head = (rx_head+1)%I2C_RING_FIFO;
  IOP_WRITE_DATA(REG_RISC_2_IOP,I2C_TX_EMPTY_MASK,0<<I2C_TX_EMPTY_POS);
	
	if((REG_RISC_2_IOP & I2C_RX_BUF_FULL_MASK) == I2C_RX_BUF_FULL_MASK)
	{
		IOP_WRITE_DATA(REG_RISC_2_IOP,I2C_RX_BUF_FULL_MASK,0<<I2C_RX_BUF_FULL_POS);
	}
	return value;
}


int tx_available(void)
{
	return (!(((tx_tail+1)%I2C_RING_FIFO) == tx_head));
}

int rx_available(void)
{
	return (!(((rx_tail+1)%I2C_RING_FIFO) == rx_head));
}

void i2c_slave_save_data()
{
	if((REG_IOP_2_RISC & I2C_TX_EMPTY_MASK) == I2C_TX_EMPTY_MASK)	
	{
		return;
	}

	if((REG_IOP_2_RISC & I2C_TX_FLAG_MASK) == 0x0)
	{
		DATA_IOP_2_RISC = tx_data_buf[tx_head];
		tx_head = (tx_head+1)%I2C_RING_FIFO;

		if(tx_tail == tx_head)
		{
			IOP_WRITE_DATA(REG_IOP_2_RISC,I2C_TX_EMPTY_MASK,1<<I2C_TX_EMPTY_POS);

		}
		IOP_WRITE_DATA(REG_IOP_2_RISC,I2C_TX_FLAG_MASK,1<<I2C_TX_FLAG_POS);
	}

}

void i2c_slave_get_data()
{
	// no data to get
	if((REG_RISC_2_IOP & I2C_RX_FLAG_MASK) == 0x0)
		return;
		
	// rx buf full	
	if((REG_RISC_2_IOP & I2C_RX_BUF_FULL_MASK) == I2C_RX_BUF_FULL_MASK)
	{
		return;	
	}
	rx_data_buf[rx_tail] = DATA_RISC_2_IOP;
	rx_tail = (rx_tail+1)%I2C_RING_FIFO;

	IOP_WRITE_DATA(REG_RISC_2_IOP,I2C_RX_FLAG_MASK,0<<I2C_RX_FLAG_POS);
	
	if(rx_available() == 0)
	{
		IOP_WRITE_DATA(REG_RISC_2_IOP,I2C_RX_BUF_FULL_MASK,1<<I2C_RX_BUF_FULL_POS);
		return;	
	}
}

void send_irq_to_risc()	
{
	Reset_RISC |= 0x01;
}

void clear_databuf()
{
		memset(rx_data_buf,0,I2C_RING_FIFO);
		memset(tx_data_buf,0,I2C_RING_FIFO);
}

void printf_info()
{
	int i=0;

	if(IOP_DATA4_L == 0x32)
	{
		RBUS_Write(0x9C0032E4,0x3000);
		RBUS_Write(0x9C000300,0x30000000);
		printf("=====\n rx_head = %d rx_tail=%d tx_head=%d tx_tail=%d \n",rx_head,rx_tail,tx_head,tx_tail);
		for(i=0;i<I2C_RING_FIFO;i++)
		{
			printf("rx_data_buf[%d]=0x%x \n",i,rx_data_buf[i]);
		}
		printf("=====\n");
		for(i=0;i<I2C_RING_FIFO;i++)
		{
			printf("tx_data_buf[%d]=0x%x \n",i,tx_data_buf[i]);
		}
		IOP_DATA4_L = 0;
	}
}