#include "common.h"

void timer_init(void)
{
#if 0 //Timer0 mode0
        #define T 3200 //Timer delay time = (1/27MHz)*3200= 118.51us
        TMOD = 0x04;    //C/T=bit2=1 : External timer, bit1=0, bit0=0 : mode 0
        TL0 = (8192 - T) % 32;
        TH0 = (8192 - T) / 32;
        EA = 1;                 //Enable global interrupts
        ET0 = 1;                //Enable Timer 0 interrupts
        TR0 = 1;                //Enable Timer 0 run control
        #endif
        #if 0 //Timer0 mode1
        #define T 57600  //Timer delay time = (1/27MHz)*57600= 2133.33us
        TMOD = 0x05;    //C/T=bit2=1 : External timer, bit1=0, bit0=1 : mode 1
        TL0 = 65536 - T;
        TH0 = (65536-T) >> 8;
        EA = 1;                 //Enable global interrupts
        ET0 = 1;                //Enable Timer 0 interrupts
        TR0 = 1;                //Enable Timer 0 run control
        #endif
				
        #if 0 //Timer0 mode2
        #define T 200  //Timer delay time = (1/27MHz)*200= 7.4us
        TMOD = 0x06;    //C/T=bit2=1 : External timer, bit1=1, bit0=0 : mode 2
        TL0 = TH0 = 256 - T;
        EA = 1;                 //Enable global interrupts
        ET0 = 1;                //Enable Timer 0 interrupts
        TR0 = 1;                //Enable Timer 0 run control
        #endif
    #if 0 //Timer0 mode3
        #define TL 225          //Timer delay time = (1/27MHz)*225= 8.33us
        #define TH 235          //Timer delay time = (1/16.6MHz)*235= 14.15us
        TMOD = 0x07;            //C/T=bit2=1 : External timer, bit1=1, bit0=1 : mode 3
        TL0 = 255-TL;
        TH0 = 255-TH;
        EA = 1;                 //Enable global interrupts
        ET0 = 1;                //Enable Timer 0 interrupts
        ET1 = 1;                //Enable Timer 1 interrupts
        TR0 = 1;                //Enable Timer 0 run control
        TR1 = 1;                //Enable Timer 1 run control
    #endif
    #if 0 //Timer1 mode0
        #define T 3200  //Timer delay time = (1/27MHz)*3200= 118.5us
        TMOD = 0x40;    //C/T=bit6=1 : External timer, bit5=0, bit4=0 : mode 0
        TL1 = (8192 - T) % 32;
        TH1 = (8192 - T) / 32;
        EA = 1;                 //Enable global interrupts
        ET1 = 1;                //Enable Timer 1 interrupts
        TR1 = 1;                //Enable Timer 1 run control
        #endif
    #if 0 //Timer1 mode1
        #define T 57600  //Timer delay time = (1/27MHz)*57600= 2133.33us
        TMOD = 0x50;    //C/T=bit6=1 : External timer, bit5=0, bit4=1 : mode 1
        TL1 = 65536 - T;
        TH1 = (65536-T) >> 8;
        EA = 1;                 //Enable global interrupts
        ET1 = 1;                //Enable Timer 1 interrupts
        TR1 = 1;                //Enable Timer 1 run control
        #endif
        #if 0 //Timer1 mode2
        #define T 200  //Timer delay time = (1/27MHz)*200= 7.4us
        TMOD = 0x60;    //C/T=bit6=1 : External timer, bit5=1, bit4=0 : mode 2
        TL1 = TH1 = 255 - T;
        EA = 1;                 //Enable global interrupts
        ET1 = 1;                //Enable Timer 1 interrupts
        TR1 = 1;                //Enable Timer 1 run control
        #endif
        #if 1 //Timer1 mode3
        #endif
        #if 0 //Timer0 mode0
        #define T 3600          //Timer delay time = (1/16.66MHz)*7200= 216us
        TMOD = 0x00;            //bit1=0, bit0=0 : mode 0
        TL0 = (8192 - T) % 32;
        TH0 = (8192 - T) / 32;
        EA = 1;                 //Enable global interrupts
        ET0 = 1;                //Enable Timer 0 interrupts
        TR0 = 1;                //Enable Timer 0 run control
        #endif

    #if 0 //Timer0 mode1
        //Fosc = 200MHz, Timer = Fosc/12=16.66MHz
        #define T 57600         //Timer delay time = (1/16.66MHz)*57600= 3457us

        TMOD = 0x01;            //bit1=0, bit0=1 : mode 1
        TL0 = 65536 - T;
        TH0 = (65536-T) >> 8;
        EA = 1;                 //Enable global interrupts
        ET0 = 1;                //Enable Timer 0 interrupts
        TR0 = 1;                //Enable Timer 0 run control
        #endif

        #if 0 //Timer0 mode2
        //Fosc = 200MHz, Timer = Fosc/12=16.66MHz
        #define T 200           //Timer delay time = (1/16.66MHz)*200= 12us

        TMOD = 0x02;            //bit1=1, bit0=0 : mode 2
        TL0 = TH0 = 256 - T;
        EA = 1;                 //Enable global interrupts
        ET0 = 1;                //Enable Timer 0 interrupts
        TR0 = 1;                //Enable Timer 0 run control
        #endif

        #if 0 //Timer0 mode3
        //Fosc = 200MHz, Timer = Fosc/12=16.66MHz
        #define TL 225          //Timer delay time = (1/16.66MHz)*225= 13.5us
        #define TH 112          //Timer delay time = (1/16.66MHz)*143= 8.5us

        TMOD = 0x03;            //bit1=1, bit0=0 : mode 2
        TL0 = 255-TL;
        TH0 = TH;
        EA = 1;                 //Enable global interrupts
        ET0 = 1;                //Enable Timer 0 interrupts
        ET1 = 1;                //Enable Timer 1 interrupts
        TR0 = 1;                //Enable Timer 0 run control
        TR1 = 1;                //Enable Timer 1 run control
        #endif

        #if 0 //Timer1 mode0
        //Fosc = 200MHz, Timer = Fosc/12=16.66MHz
        #define T 7200          //Timer delay time = (1/16.66MHz)*7200= 432us
        TMOD = 0x00;            //bit5=0, bit4=0 : mode 0
        TL1 = (8192 - T) % 32;
        TH1 = (8192 - T) / 32;
        EA = 1;                 //Enable global interrupts
        ET1 = 1;                //Enable Timer 1 interrupts
        TR1 = 1;                //Enable Timer 1 run control
        #endif

			#if 0 //Timer1 mode1
        //Fosc = 200MHz, Timer = Fosc/12=16.66MHz
        #define T 57600         //Timer delay time = (1/16.66MHz)*57600= 3457us
        TMOD = 0x10;            //bit5=0, bit4=1 : mode 1
        TL1 = 65536 - T;
        TH1 = (65536-T) >> 8;
        EA = 1;                 //Enable global interrupts
        ET1 = 1;                //Enable Timer 1 interrupts
        TR1 = 1;                //Enable Timer 1 run control
        #endif

        #if 0 //Timer1 mode2
        //Fosc = 200MHz, Timer = Fosc/12=16.66MHz
        #define T 200           //Timer delay time = (1/16.66MHz)*200= 12us
        TMOD = 0x20;            //bit5=1, bit4=0 : mode 2
        TL1 = TH1 = 256 - T;
        EA = 1;                 //Enable global interrupts
        ET1 = 1;                //Enable Timer 1 interrupts
        TR1 = 1;                //Enable Timer 1 run control
        #endif

        #if 1 //Timer1 mode3
        //Timer1 mode3 , TR1=0. Timer1 is disable.
        #endif

    #if 0 //External timer work, timer1
        IT0 = 1; //set INT0 interrupt type (1:Falling 0:Low level)
        EX0 = 1; //enable INT0 interrupt
        EA = 1; //open global interrupt switch
        //unsigned char idata TimerA_Lo         _at_            0x3E;
        //unsigned char idata TimerA_Hi         _at_            0x3F;
        //unsigned char idata TimerB_Lo         _at_            0x40;
        //unsigned char idata TimerB_Hi         _at_            0x41;
        //unsigned char idata Timer_Enable      _at_            0x42;
        TimerA_Lo=0x10;  //timer1
        TimerA_Hi=0x57;  //timer1
        //bit1=timer1, bit0=timer2
        IntMask|=Int_Bit1_Timer1;
        Timer_Enable|=Int_Bit1_Timer1;
        #endif

        #if 0 //External timer work, timer2
        IT0 = 1; //set INT0 interrupt type (1:Falling 0:Low level)
        EX0 = 1; //enable INT0 interrupt
        EA = 1; //open global interrupt switch
        //unsigned char idata TimerA_Lo         _at_            0x3E;
        //unsigned char idata TimerA_Hi         _at_            0x3F;
        //unsigned char idata TimerB_Lo         _at_            0x40;
        //unsigned char idata TimerB_Hi         _at_            0x41;
        //unsigned char idata Timer_Enable      _at_            0x42;
        TimerB_Lo=0x10;  //timer2
        TimerB_Hi=0x37;  //timer2
        //bit1=timer1, bit0=timer2
        IntMask|=Int_Bit0_Timer2;
        Timer_Enable|=Int_Bit0_Timer2;
        #endif
}