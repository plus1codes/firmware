#ifndef __COMMON_H
#define __COMMON_H

#if defined (SDCC)
#include "8051.h"
#else
#include "dp8051xp.h"
#endif
#include "sunplus8051.h"

/*  printf out enable, store data in IOP_DATA8, output by arm926 */
#define DEBUG_ENABLE  

/* timer select */
#define TIME0_MODE0              /*  118.51us */
//#define TIME0_MODE1            /*  2133.33us */
//#define TIME0_MODE2            /*  7.4us */
//#define TIME0_MODE3            /*  8.33us */
//#define TIME1_MODE0            /*  7.4us */
//#define TIME1_MODE1            /*  118.51us */
//#define TIME1_MODE2            /*  2133.33us */


#ifdef DEBUG_ENABLE

    #define diag_printf                         printf

    #define PRINTF_REG_IOP_2_RISC               IOP_DATA8_L
    #define PRINTF_DATA_IOP_2_RISC              IOP_DATA8_H

    #define PRINTF_TX_EMPTY_POS                 0
    #define PRINTF_TX_EMPTY_MASK                (1<<PRINTF_TX_EMPTY_POS)

    #define PRINTF_TX_FLAG_POS                  1
    #define PRINTF_TX_FLAG_MASK                 (1<<PRINTF_TX_FLAG_POS)
    /*----------------------------------------------------------------------------------------------------
    |PRINTF_DATA_IOP_2_RISC   | 7:0 |   data            write by IOP,read by RISC
    |                                                   this register is used for transmit data from IOP to RISC
    ----------------------------------------------------------------------------------------------------
    |PRINTF_REG_IOP_2_RISC    | 7:2 |   reserved
    |                         |  1  |   tx flag         read/write by RISC or IOP
    |                                                   1:IOP send 1byte data in IOP_DATA_8_H to RISC. set to 1;
    |                                                   0:RISC have read temp buf from IOP. clear to 0;
    |                         |  0  |   tx empty flag   read/write by IOP only
    |                                                   1:tx buf is empty, not send data to RISC
    |                                                   0:tx buf is not empty.
    ----------------------------------------------------------------------------------------------------*/
    void print_data();
#else
    #define diag_printf
#endif


void timer_init(void);

#endif
