#ifndef __COMMON_H
#define __COMMON_H

#include "Dp8051xp.h"
#include "SunReg.h"

unsigned char* RBUS_Read(unsigned long addr);
void  RBUS_Write(unsigned long addr, unsigned long value);


#endif