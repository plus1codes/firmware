#ifndef __I2C_SLAVE__
#define __I2C_SLAVE__

#include <stdio.h>
#include "common.h"


#define I2C_RW_POS		0
#define I2C_RW_MASK		 (1<<I2C_RW_POS)

#define I2C_TX_EMPTY_POS	1
#define I2C_TX_EMPTY_MASK		 (1<<I2C_TX_EMPTY_POS)

#define I2C_TX_FLAG_POS	2
#define I2C_TX_FLAG_MASK		 (1<<I2C_TX_FLAG_POS)

#define I2C_RX_BUF_FULL_POS	3
#define I2C_RX_BUF_FULL_MASK		 (1<<I2C_RX_BUF_FULL_POS)

#define I2C_RX_FLAG_POS	4
#define I2C_RX_FLAG_MASK		 (1<<I2C_RX_FLAG_POS)



#define I2C_RING_FIFO			32

#define REG_IOP_2_RISC	IOP_DATA11_L
#define REG_RISC_2_IOP	IOP_DATA10_L

#define DATA_IOP_2_RISC	IOP_DATA11_H
#define DATA_RISC_2_IOP	IOP_DATA10_H

#define REG_I2C_ADDR		IOP_DATA0_L
#define REG_PIN_SDA		IOP_DATA3_L
#define REG_PIN_SCL		IOP_DATA3_H

#define IOP_WRITE_DATA(ADDR,CLEARMASK,SETMASK)   (ADDR = (ADDR&(~(CLEARMASK))|(SETMASK)))


#define I2C_IN_MODE		0
#define I2C_OUT_MODE	1

#define I2C_OUT_HIGH	1
#define I2C_OUT_LOW		0


typedef enum{
    I2C_SLAVE_IDLE=0,
    I2C_SLAVE_START,
    I2C_SLAVE_READ_ADDRESS,
    I2C_SLAVE_RW_DATA,
    I2C_SLAVE_WAIT_STOP,
    I2C_SLAVE_STOP,
}st_i2c_status;	

#endif