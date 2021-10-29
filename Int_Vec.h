#include "Dp8051xp.h"
#include "SunReg.h"

//#define PERIOD     -(3686500*0.0000625)     /* 62.5 usec interrupt period     */

#define PERIOD     0x0A     /* 62.5 usec interrupt period     */
extern unsigned char ex0_isr_counter;
extern unsigned char ex1_isr_counter;
extern unsigned int t0_isr_counter;
extern unsigned char t1_isr_counter;

