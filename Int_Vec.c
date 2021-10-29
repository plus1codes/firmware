#include "Int_Vec.h"





/*Declaratins*/
/******************************************************************************/
/*                Timer 0 interrupt service function                          */
/*          executes each 100us @  MHz Instruction Clock               */
/******************************************************************************/
unsigned int t0_isr_counter = 0;
unsigned char t1_isr_counter = 0;

#if 1 //Timer0/1  mode0
#define T 3200
#endif
#if 0 //Timer0/1 mode1
#define T 57600
#endif
#if 1 //Timer0/1 mode2
#define T 200
#endif
#if 0 //Timer0 mode3
#define TL 225
#define TH 235
#endif



//void timer0(void) interrupt 1 using 1 {   /* Int Vector at 000BH, Reg Bank 1 */
void timer0_isr (void) interrupt 1
{   /* Int Vector at 000BH*/

	TF0=0;	//clear the interrupt flag

	t0_isr_counter++;

	#if 0 //Timer0 mode0
	TL0 = (8192 - T) % 32;
	TH0 = (8192 - T) / 32;
	#endif

    #if 0 //Timer0 mode1
	TL0 = 65536 - T;
	TH0 = (65536-T) >> 8;
	#endif

	#if 0 //Timer0 mode2
	TL0 = TH0 = 256 - T;
	#endif

	#if 0 //Timer0 mode3
	TL0 = 255 - TL;
	#endif
	if(t0_isr_counter == 65500){
		t0_isr_counter = 0;
		//P0_0 = !P0_0;
	}

	#if 0
	if((GPIO_PORT0_OUT & bit0) == bit0)
		GPIO_PORT0_OUT &= (!bit0);
	else
		GPIO_PORT0_OUT |= bit0;
	#endif

#if 0  //tonyh test
	if((GPIO_PORT0_OUT & 0x01) == 0x00)
		GPIO_PORT0_OUT|=0x01;
	TL0 = 0x10;
	TH0 = 0x27;
#endif

	//Counter mode, 27MHz, mode 3

	//ET0 = 1;                                     /* enable timer 0 interrupt    */
	//EA  = 1;         				// Global interrupt enable
	//TR0 = 1;                                     /* start timer 0               */
}


void timer1_isr (void) interrupt 3
{   /* Int Vector at 001BH*/

	TF1=0;	//clear the interrupt flag

	t1_isr_counter++;

	#if 0 //Timer0 mode3
	TH0 = 255-TH;
	#endif

	#if 0 //Timer1 mode0
	TL1 = (8192 - T) % 32;
	TH1 = (8192 - T) / 32;
	#endif

	#if 0 //Timer1 mode1
	TL1 = 65536 - T;
	TH1 = (65536-T) >> 8;
	#endif

	#if 0 //Timer1 mode2
	TL1 = TH1 = 255 - T;
	#endif
	//P0_1 = !P0_1;

	#if 0
	if((GPIO_PORT0_OUT & bit1) == bit1)
		GPIO_PORT0_OUT &= (!bit1);
	else
		GPIO_PORT0_OUT |= bit1;
	#endif

#if 0  //tonyh test

	TL1 = 0x10;
	TH1 = 0x27;

	if((GPIO_PORT0_OUT & 0x01) == 0x01)
		GPIO_PORT0_OUT&=~(0x01);
#endif

	//Counter mode, 27MHz, mode 3
	//ET0 = 1;                                     /* enable timer 0 interrupt    */
	//EA  = 1;         				// Global interrupt enable
	//TR1 = 1;                                     /* start timer 0               */
}

unsigned char ex0_isr_counter = 0;
unsigned char ex1_isr_counter = 0;

void ex0_isr (void) interrupt 0
{
	/* Int Vector at 0003H*/


	if((IntFlag&Int_Bit0_Timer2)==Int_Bit0_Timer2)
	{
		
		IntFlag = Int_Bit0_Timer2;
		ex0_isr_counter++;   // Increment the count
	//	P0_0 = !P0_0;
	}
	else if((IntFlag&Int_Bit1_Timer1)==Int_Bit1_Timer1)
	{
	
		IntFlag = Int_Bit1_Timer1;
		ex1_isr_counter++;   // Increment the count
	//	P0_1 = !P0_1;
	}
}

