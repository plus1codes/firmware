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
 Project description  : 

 File name            : docd.h
 File contents        : DoCD peripherals 
------------------------------------------------------------------------------
 Design Engineer      : T.K.
 Version              : 3.00
 Last modification    : 2003-04-09
------------------------------------------------------------------------------
*/
#ifndef _DOCD_H_
#define _DOCD_H_

#define CLKFREQ 20000000
#define SW0 0x01
#define SW1 0x02
#define SW2 0x04
#define SW3 0x08

sfr DISPLAY1 = 0xD4;
sfr DISPLAY0 = 0xD5;
sfr KEYS     = 0xD6;
sfr SWITCHES = 0xD7;
sfr RTI      = 0xDC;
sfr LPTCTRL  = 0xDD;
sfr LPTDATA  = 0xDE;
sfr LPTADDR  = 0xDF;

extern void delay (unsigned char n);

#endif /*_DOCD_H_*/

