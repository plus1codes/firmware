#include "common.h"

#ifdef DEBUG_ENABLE

#define DEBUG_BUF           128

unsigned char prn_data[DEBUG_BUF];
int prn_in = 0,prn_out=0;

void print_data()
{
    if((PRINTF_REG_IOP_2_RISC & PRINTF_TX_EMPTY_MASK) == 0x0)
    {
        return;
    }
    if(prn_out == prn_in)
    {
        PRINTF_REG_IOP_2_RISC = PRINTF_REG_IOP_2_RISC & ~(PRINTF_TX_EMPTY_MASK);
        return;
    }
    if((PRINTF_REG_IOP_2_RISC & PRINTF_TX_FLAG_MASK) == 0x0)
    {
        PRINTF_DATA_IOP_2_RISC = prn_data[prn_out];
        prn_out = (prn_out+1)%DEBUG_BUF;
        PRINTF_REG_IOP_2_RISC = PRINTF_REG_IOP_2_RISC | PRINTF_TX_FLAG_MASK;
    }
}

int putchar (int c)
{
    prn_data[prn_in] = (char)c;
    prn_in = (prn_in+1)%DEBUG_BUF;
    IOP_DATA7_H = 0x32;
    if((PRINTF_REG_IOP_2_RISC & PRINTF_TX_EMPTY_MASK) == 0x0)
    {
        PRINTF_REG_IOP_2_RISC = PRINTF_REG_IOP_2_RISC|PRINTF_TX_EMPTY_MASK;
    }
    return c;
}
#endif
