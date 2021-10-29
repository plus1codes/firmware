/*--------------------------------------------------------------------------
	Copyright (c) 2018 Sunplus technology co. Ltd.All right reserved!

	Registers definition

	Create by Leon        2018/04/11
-------------------------------------------------------------------------- */
#ifndef _SUNREG_H_
#define _SUNREG_H_


//General Purpose Input (Read only)

sfr GPIO_PORT0_IN = 0xD4;
sfr GPIO_PORT1_IN = 0xD5;
sfr GPIO_PORT2_IN = 0xD6;
sfr GPIO_PORT3_IN = 0xD7;
sfr GPIO_PORT4_IN = 0xDC;
sfr GPIO_PORT5_IN = 0xDD;
sfr GPIO_PORT6_IN = 0xDE;
sfr GPIO_PORT7_IN = 0xDF;
sfr GPIO_PORT8_IN = 0xE4;
sfr GPIO_PORT9_IN = 0xE5;
sfr GPIO_PORT10_IN = 0xE6;
sfr GPIO_PORT11_IN = 0xE7;
sfr GPIO_PORT12_IN = 0xEC;
sfr GPIO_PORT13_IN = 0xED;
sfr GPIO_PORT14_IN = 0xEE;
sfr GPIO_PORT15_IN = 0xEF;

//General Purpose Output   (Read/Write)
sfr GPIO_PORT0_OUT = 0xC0;
//sbit P0_0 = GPIO_PORT0_OUT ^ 0;

sfr GPIO_PORT1_OUT = 0xC1;
sfr GPIO_PORT2_OUT = 0xC2;
sfr GPIO_PORT3_OUT = 0xC3;
sfr GPIO_PORT4_OUT = 0xC4;
sfr GPIO_PORT5_OUT = 0xC5;
sfr GPIO_PORT6_OUT = 0xC6;
sfr GPIO_PORT7_OUT = 0xC7;
sfr GPIO_PORT8_OUT = 0xC8;
sfr GPIO_PORT9_OUT = 0xC9;
sfr GPIO_PORT10_OUT = 0xCA;
sfr GPIO_PORT11_OUT = 0xCB;
sfr GPIO_PORT12_OUT = 0xCC;
sfr GPIO_PORT13_OUT = 0xCD;
sfr GPIO_PORT14_OUT = 0xCE;
sfr GPIO_PORT15_OUT = 0xCF;


//General Purpose Output Enable  (Read/Write)
//"1" for Output and "0" for Input
sfr GPIO_IO0_CFG = 0xB0;
sfr GPIO_IO1_CFG = 0xB1;
sfr GPIO_IO2_CFG = 0xB2;
sfr GPIO_IO3_CFG = 0xB3;
sfr GPIO_IO4_CFG = 0xB4;
sfr GPIO_IO5_CFG = 0xB5;
sfr GPIO_IO6_CFG = 0xB6;
sfr GPIO_IO7_CFG = 0xB7;
sfr GPIO_IO8_CFG = 0x98;
sfr GPIO_IO9_CFG = 0x99;
sfr GPIO_IO10_CFG = 0x9A;
sfr GPIO_IO11_CFG = 0x9B;
sfr GPIO_IO12_CFG = 0x9C;
sfr GPIO_IO13_CFG = 0x9D;
sfr GPIO_IO14_CFG = 0x9E;
sfr GPIO_IO15_CFG = 0x9F;





//Setting for the Addressing mode
extern unsigned char idata OFFSET1A;
extern unsigned char idata OFFSET1B;
extern unsigned char idata OFFSET1C;
extern unsigned char idata OFFSET1D;
extern unsigned char idata OFFSET2A;
extern unsigned char idata OFFSET2B;
extern unsigned char idata OFFSET2C;
extern unsigned char idata ADDR_32BIT;

//0x0037[0]     SYS_MAP_EN      RO      0x0     1: System permit IOP to use 32-bit addressing mode, 0: not permit.
//0x0037[1]     IOP_MAP_EN      RW      0x0     0: 16-bit mode 1: IOP try to use 32-bit mode




//Setting for Interrupt
extern unsigned char idata IntMask;
extern unsigned char idata IntFlag;
extern unsigned char idata Reset_RISC;

#define Int_Bit0_Timer2                                 1<<0
#define Int_Bit1_Timer1                                 1<<1
#define Int_Bit2_IR                                     1<<2
#define Int_Bit3_DM_Cache_Miss                          1<<3
#define Int_Bit4_Access_XDM                             1<<4
#define Int_Bit5_IM_Cache_Miss                          1<<5

//0x0038  IOP_INT_MASK  RW  Mask for INT_FLAG
//0x0039  IOP_INT_FLAG
//bit 0 : Timer 2 INT
//bit 1 : Timer 1 INT
//bit 2 : IR INT
//bit 3 : DM cache miss in power down mode
//bit 4 : Access XDM during cache flushing
//bit 5 : IM cache miss in power down mode


//INT_RISCA_bit                                         equ             0
//INT_RISCB_bit                                         equ             1


//Cache Control
extern unsigned char idata XDM_Cache_Flush_LINE_NO;
extern unsigned char idata CACHE_CONTROL;

//0x003C[0]     Upper Cache Disable     RW      0x0     0: Not disable, 1: Disable
//0x003C[1]     Flush                   RW      0x0     Write 1: Flush;
//Read 1: Flushing, 0: Normal. ( Will be ignored when upper cache disable)
//FLUSH_CACHE                                           equ             %00000010
//FLUSH_CACHE_bit                                       equ             1


//Hardware Infrared
extern unsigned char idata HW_IR;

//0x003D[0]     IR                      RO      0x0     equals IR_IN ^ IR_IN_POLARITY
//0x003D[1]     IR_IN_POLARITY          RW      0x0     0: Normal 1: Invert IR's polarity
//0x003D[2]     PMC_IR_LATCH            RO      0x0     IR from PMC
//0x003D[3]     PMC_SYS_RTC_LATCH       RO      0x0     RTC from PMC
//0x003D[4]     Reserved                RW      0x0
//0x003D[5]     Reserved                RW      0x0
//0x003D[6]     CLR_PMC_IR_LATCH        W1C     0x0     Clear PMC IR latch
//0x003D[7]     CLR_PMC_SYS_RTC_LATCH   W1C     0x0     Clear PMC SYS_RTC latch
//PMC_IR_LATCH_bit                              equ             2
//PMC_SYS_RTC_LATCH_bit                         equ             3
//CLR_PMC_IR_LATCH_bit                          equ             6
//CLR_PMC_SYS_RTC_LATCH_bit                     equ             7


//Internal Timer
extern unsigned char idata TimerA_Lo;
extern unsigned char idata TimerA_Hi;
extern unsigned char idata TimerB_Lo;
extern unsigned char idata TimerB_Hi;
extern unsigned char idata Timer_Enable;

//0x0042[0]     TIMER2_EN       RW      0x0     1: Enable
//0x0042[1]     TIMER1_EN       RW      0x0     1: Enable
//INT_TIMER_B                                           equ             %00000001
//INT_TIMER_A                                           equ             %00000010
//INT_TIMER_B_bit                                       equ             0
//INT_TIMER_A_bit                                       equ             1


//For System Resume
extern unsigned char idata IOP_WATCH_DOG_RST_EN;
extern unsigned char idata IOP_RESUME_PCL_0;
extern unsigned char idata IOP_RESUME_PCL_1;
extern unsigned char idata IOP_RESUME_PCH_0;
extern unsigned char idata IOP_RESUME_PCH_1;

//;;0x0044  IOP_WATCH_DOG_RST_EN  RW  0x0  IOP Enable WatchDog Reset IOP
//IOP_WATCH_DOG_RST_EN_MASK                     equ             %00000001
//IOP_SYS_RST_DIS                               equ             %00000010
//IOP_WATCH_DOG_RST_EN_bit                      equ             0
//IOP_SYS_RST_DIS_bit                           equ             1

//;;0x0045  IOP_RESUME_PCL (0)  RW  0x00  RISC Resume PC low byte0
//;;0x0046  IOP_RESUME_PCL (1)  RW  0x00  RISC Resume PC low byte1
//;;0x0047  IOP_RESUME_PCH (0)  RW  0x00  RISC Resume PC high byte0
//;;0x0048  IOP_RESUME_PCH (1)  RW  0x00  RISC Resume PC high byte1

//extern unsigned char idata PI_GPIO_INT_CFG;

extern unsigned char idata IOP_INT_MASK1_B;
extern unsigned char idata IOP_INT_FLAG1;
extern unsigned char idata IOP_INT_MASK2_B;
extern unsigned char idata IOP_INT_FLAG2;
extern unsigned char idata IOP_INT_MASK3_B;
extern unsigned char idata IOP_INT_FLAG3;
//extern unsigned char idata IOP_INT_MASK4_FLAG4;


//0x0043[0]  PI_GPIO_INT0_EDGE  RW  0:level triggered 1:edge triggered
//0x0043[1]  PI_GPIO_INT1_EDGE  RW
//0x0043[2]  PI_GPIO_INT2_EDGE  RW
//0x0043[3]  PI_GPIO_INT3_EDGE  RW
//0x0043[4]  PI_GPIO_INT0_POLARITY  RW 0:high level/rising edge active 1:low level/falling edge active
//0x0043[5]  PI_GPIO_INT1_POLARITY  RW
//0x0043[6]  PI_GPIO_INT2_POLARITY  RW
//0x0043[7]  PI_GPIO_INT3_POLARITY  RW

#define Int1_Bit0_SPI_IOP_INT1_0                                                        1<<0
#define Int1_Bit1_SPI_IOP_INT1_1                                                        1<<1
#define Int1_Bit2_SPI_IOP_INT1_2                                                        1<<2
#define Int1_Bit3_SPI_IOP_INT1_3                                                        1<<3
#define Int1_Bit4_SPI_IOP_INT2_0                                                        1<<4
#define Int1_Bit5_SPI_IOP_INT2_1                                                        1<<5
#define Int1_Bit6_SPI_IOP_INT2_2                                                        1<<6
#define Int1_Bit7_SPI_IOP_INT2_3                                                        1<<7



//0x0049  IOP_INT_MASK1_B RW  Mask for INT_FLAG1
//0x004A  IOP_INT_FLAG1  RO
//bit 0 : SPI_IOP_INT1_0; SPI_IOP_INT1 for Q633
//bit 1 : SPI_IOP_INT1_1
//bit 2 : SPI_IOP_INT1_2
//bit 3 : SPI_IOP_INT1_3
//bit 4 : SPI_IOP_INT2_0; SPI_IOP_INT2 for Q633
//bit 5 : SPI_IOP_INT2_1
//bit 6 : SPI_IOP_INT2_2
//bit 7 : SPI_IOP_INT2_3

#define Int2_Bit0_TGEN0_IOP_FIELD_END                                                   1<<0
#define Int2_Bit1_TGEN0_IOP_FIELD_START                                                 1<<1
#define Int2_Bit2_TGEN0_IOP_USER                                                        1<<2
#define Int2_Bit3_TGEN1_IOP_FIELD_END                                                   1<<3
#define Int2_Bit4_TGEN1_IOP_FIELD_START                                                 1<<4
#define Int2_Bit5_TGEN1_IOP_USER                                                        1<<5
#define Int2_Bit6_V656IN_IOP_INT_FIELD_END_0                                            1<<6
#define Int2_Bit7_V656IN_IOP_INT_FIELD_START_0                                          1<<7


//0x004B  IOP_INT_MASK2_B RW  Mask for INT_FLAG2
//0x004C  IOP_INT_FLAG2  R/W1C
//bit 0 : TGEN0_IOP_FIELD_END
//bit 1 : TGEN0_IOP_FIELD_START
//bit 2 : TGEN0_IOP_USER
//bit 3 : TGEN1_IOP_FIELD_END
//bit 4 : TGEN1_IOP_FIELD_START
//bit 5 : TGEN1_IOP_USER
//bit 6 : V656IN_IOP_INT_FIELD_END_0
//bit 7 : V656IN_IOP_INT_FIELD_START_0


#define Int3_Bit0_TGEN2_IOP_FIELD_END                                                   1<<0
#define Int3_Bit1_TGEN2_IOP_FIELD_START                                                 1<<1
#define Int3_Bit2_TGEN2_IOP_USER                                                        1<<2
#define Int3_Bit3_UART_IOP_INT                                                          1<<3
#define Int3_Bit4_SPI_IOP_INT0_0                                                        1<<4
#define Int3_Bit5_SPI_IOP_INT0_1                                                        1<<5
#define Int3_Bit6_SPI_IOP_INT0_2                                                        1<<6
#define Int3_Bit7_SPI_IOP_INT0_3                                                        1<<7


//0x004D  IOP_INT_MASK3_B RW  Mask for INT_FLAG3
//0x004E   IOP_INT_FLAG2  R/W1C
//bit 0 : TGEN2_IOP_FIELD_END
//bit 1 : TGEN2_IOP_FIELD_START
//bit 2 : TGEN2_IOP_USER
//0x004E   IOP_INT_FLAG2  RO
//bit 3 : UART_IOP_INT(UA3_INT from UART3); NC in Q633
//bit 4 : SPI_IOP_INT0_0; SPI_IOP_INT0 for Q633
//bit 5 : SPI_IOP_INT0_1
//bit 6 : SPI_IOP_INT0_2
//bit 7 : SPI_IOP_INT0_3




//#define Int4_Bit4_PI_GPIO_INT0                                                        1<<4
//#define Int4_Bit5_PI_GPIO_INT1                                                        1<<5
//#define Int4_Bit6_PI_GPIO_INT2                                                        1<<6
//#define Int4_Bit7_PI_GPIO_INT3                                                        1<<7


//0x004F  IOP_INT_MASK4_FLAG4
//0x004F[3:0] RW  Mask for INT_FLAG4
//Mask should be set to "1" (INT is enabled), only after the configuration in IDM 0x43 is fixed
//Don't change the configuration in IDM 0x43 when Mask == 1'b1
//0x004F[7:4] R/W1C or RO
//bit 4 : PI_GPIO_INT0
//bit 5 : PI_GPIO_INT1
//bit 6 : PI_GPIO_INT2
//bit 7 : PI_GPIO_INT3





//Power Control
sfr POWER_CONTROL = 0xF4;

/*
;;0x00F4[0]     DEF_PWR_EN_I            RO      0x0     PWR_EN input value
;;0x00F4[1]     DEF_PWR_EN_O            RW      0x0     PWR_EN output value
;;0x00F4[2]     DEF_PWR_EN_OE           RW      0x0     PWR_EN output enable
;;0x00F4[3]     Isolation               RW      0x0     0: 不做Isolation, 1: Isolation
;;0x00F4[4]     System Reset            RW      0x0     0: Normal Mode, 1: System Reset
;;0x00F4[5]     IOP_PWR_DWN             RW      0x0     1: IOP domain power down request, Clear 0 if event wake-up
;;0x00F4[6]     IOP_PWR_GPIO_MODE       RW      0x0     將 PWR pin 當成:0:PWR_EN, 1:GPIO
;;0x00F4[7]     X_IR_SHUTDOWN_EN        RW      0x0     0: Normal, 1: Shut down enable
DEF_PWR_EN_I                                    equ             %00000001
DEF_PWR_EN_O                                    equ             %00000010
DEF_PWR_EN_OE                                   equ             %00000100
Isolation                                       equ             %00001000
System_reset                                    equ             %00010000
IOP_PWR_DWN                                     equ             %00100000
IOP_PWR_GPIO_MODE                               equ             %01000000
X_IR_SHUTDOWN_EN                                equ             %10000000

DEF_PWR_EN_I_bit                                equ             0
DEF_PWR_EN_O_bit                                equ             1
DEF_PWR_EN_OE_bit                               equ             2
Isolation_bit                                   equ             3
System_reset_bit                                equ             4
IOP_PWR_DWN_bit                                 equ             5
IOP_PWR_GPIO_MODE_bit                           equ             6
X_IR_SHUTDOWN_EN_bit                            equ             7
*/


//Power Gate Control
sfr POWER_GATE = 0xF5;



//;;0x00F5[1]   REG_IOP_PWR_GATE        RW      0x0     0: 由外部電源提供電壓, 1: 由Regulator提供電壓
//REG_IOP_PWR_GATE                              equ             %00000001
//REG_IOP_PWR_GATE_bit                          equ             0


sfr DDR_IO_Retention = 0xF6;





/*=====================================================================
MailBox
should pay attentation to the using of mailbox
including addressig mode
=====================================================================*/
extern unsigned char idata IOP_DATA0_L;
extern unsigned char idata IOP_DATA0_H;
extern unsigned char idata IOP_DATA1_L;
extern unsigned char idata IOP_DATA1_H;
extern unsigned char idata IOP_DATA2_L;
extern unsigned char idata IOP_DATA2_H;
extern unsigned char idata IOP_DATA3_L;
extern unsigned char idata IOP_DATA3_H;
extern unsigned char idata IOP_DATA4_L;
extern unsigned char idata IOP_DATA4_H;
extern unsigned char idata IOP_DATA5_L;
extern unsigned char idata IOP_DATA5_H;
extern unsigned char idata IOP_DATA6_L;
extern unsigned char idata IOP_DATA6_H;
extern unsigned char idata IOP_DATA7_L;
extern unsigned char idata IOP_DATA7_H;
extern unsigned char idata IOP_DATA8_L;
extern unsigned char idata IOP_DATA8_H;
extern unsigned char idata IOP_DATA9_L;
extern unsigned char idata IOP_DATA9_H;
extern unsigned char idata IOP_DATA10_L;
extern unsigned char idata IOP_DATA10_H;
extern unsigned char idata IOP_DATA11_L;
extern unsigned char idata IOP_DATA11_H;




//For RTC Timer
extern unsigned char idata SYS_RTC_TIMER_A;
extern unsigned char idata SYS_RTC_TIMER_B;
extern unsigned char idata SYS_RTC_TIMER_C;
extern unsigned char idata SYS_RTC_TIMER_D;
extern unsigned char idata SYS_RTC_ONTIME_SET_A;
extern unsigned char idata SYS_RTC_ONTIME_SET_B;
extern unsigned char idata SYS_RTC_ONTIME_SET_C;
extern unsigned char idata SYS_RTC_ONTIME_SET_D;


extern unsigned char idata XDMDATA_OUT_HH;
extern unsigned char idata XDMDATA_OUT_HL;
extern unsigned char idata XDMDATA_OUT_LH;
extern unsigned char idata XDMDATA_OUT_LL;

extern unsigned char idata XDMDATA_IN_LL;
extern unsigned char idata XDMDATA_IN_LH;
extern unsigned char idata XDMDATA_IN_HL;
extern unsigned char idata XDMDATA_IN_HH;


extern unsigned char idata XDM_Bank_ADR_HH;
extern unsigned char idata XDM_Bank_ADR_HL;



extern unsigned char idata DataIrFormat;



extern void Fill_DCache_1KB(void);

#define MO_CLKEN2                                       0x9C00000C

#define UART_REG_LSR																		0x9c000984
#define UART_REG_DATA																		0x9c000980
#define GPIO_REG_CTL_SEL																0x9c000300   // set GPIO_P0_0/1 to IOP mode

#define UART_LSR_TX_RDY     														(1 << 0)


#endif /*_SUNREG_H_*/
