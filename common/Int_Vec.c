#include "Int_Vec.h"
#include "common.h"

/*Declaratins*/
/******************************************************************************/
/*                Timer 0 interrupt service function                          */
/*          executes each 100us @  MHz Instruction Clock               */
/******************************************************************************/
unsigned int t0_isr_counter = 0;
unsigned char t1_isr_counter = 0;

#if defined(TIME0_MODE0) || defined(TIME1_MODE0) //Timer0/1  mode0
#define T 3200
#endif

#if defined(TIME0_MODE1) || defined(TIME1_MODE1) //Timer0/1 mode1
#define T 57600
#endif

#if defined(TIME0_MODE2) || defined(TIME1_MODE2) //Timer0/1 mode2
#define T 200
#endif

#ifdef TIME0_MODE3 //Timer0 mode3
#define TL 225
#define TH 235
#endif

//void timer0(void) interrupt 1 using 1 {   /* Int Vector at 000BH, Reg Bank 1 */
void timer0_isr (void) INTERRUPT_VECTOR 1
{   /* Int Vector at 000BH*/

	TF0=0;	//clear the interrupt flag

	t0_isr_counter++;
#ifdef TIME0_MODE0 //Timer0 mode0
	TL0 = (8192 - T) % 32;
	TH0 = (8192 - T) / 32;
#endif

#ifdef TIME0_MODE1 //Timer0 mode1
	TL0 = 65536 - T;
	TH0 = (65536-T) >> 8;
#endif

#ifdef TIME0_MODE2 //Timer0 mode2
	TL0 = TH0 = 256 - T;
#endif

#ifdef TIME0_MODE3 //Timer0 mode3
	TL0 = 255 - TL;
#endif
	if(t0_isr_counter == 65500)
	{
		t0_isr_counter = 0;
	}
#ifdef DEBUG_ENABLE
	print_data();
#endif
}


void timer1_isr (void) INTERRUPT_VECTOR 3
{   /* Int Vector at 001BH*/

	TF1=0;	//clear the interrupt flag

	t1_isr_counter++;

#ifdef TIME1_MODE0 //Timer1 mode0
	TL1 = (8192 - T) % 32;
	TH1 = (8192 - T) / 32;
#endif

#ifdef TIME1_MODE1 //Timer1 mode1
	TL1 = 65536 - T;
	TH1 = (65536-T) >> 8;
#endif

#ifdef TIME1_MODE2 //Timer1 mode2
	TL1 = TH1 = 255 - T;
#endif

}

unsigned char ex0_isr_counter = 0;
unsigned char ex1_isr_counter = 0;

void ex0_isr (void) INTERRUPT_VECTOR 0
{
	/* Int Vector at 0003H*/

	if((IntFlag&Int_Bit0_Timer2)==Int_Bit0_Timer2)
	{
		IntFlag = Int_Bit0_Timer2;
		ex0_isr_counter++;   // Increment the count
	}
	else if((IntFlag&Int_Bit1_Timer1)==Int_Bit1_Timer1)
	{
		IntFlag = Int_Bit1_Timer1;
		ex1_isr_counter++;   // Increment the count
	}
}
