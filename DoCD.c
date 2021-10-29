/*****************************************************************************
  Copyright (c) 1999-2003  Digital Core Design  DCD
******************************************************************************
  Please review the terms of the license agreement before using this file.
  If you are not an authorized user, please destroy this source code file
  and notify DCD immediately that you inadvertently received an unauthorized
  copy.
******************************************************************************
------------------------------------------------------------------------------
 Project name         : DoCD
 Project description  : DoCD board demo

 File name            : docd.c
 File contents        : DoCD main file
------------------------------------------------------------------------------
 Design Engineer      : T.K.
 Version              : 3.00
 Last modification    : 2003-08-09
----------------------------------------------------------------------------*/
#include <math.h>
#include <stdio.h>
#include "docd.h"
#include "proto.h"
#include "int_vec.h"
#include "common.h"



void i2c_slave_init();
void i2c_slave_hanle(void);

void main(void)
{
			unsigned char idata temp;
			while(1)
				{		
				temp = IOP_DATA0_L;
				if((IOP_DATA0_L&0x80) == 0x80)
				{
						i2c_slave_init();
						i2c_slave_hanle();
				}
			}
}

