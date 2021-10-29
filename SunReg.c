
//#include "SunReg.h"
/*Declaratins*/
/* ----------------------------------------------------------------------- */
/* ----------------------------------------------------------------------- */
/*===================================================================
					Register map for IOP
====================================================================*/

//Setting for the Addressing mode
unsigned char idata OFFSET1A                            _at_            0x30;
unsigned char idata OFFSET1B                            _at_            0x31;
unsigned char idata OFFSET1C                            _at_            0x32;
unsigned char idata OFFSET1D                            _at_            0x33;
unsigned char idata OFFSET2A                            _at_            0x34;
unsigned char idata OFFSET2B                            _at_            0x35;
unsigned char idata OFFSET2C                            _at_            0x36;
unsigned char idata ADDR_32BIT                          _at_            0x37;






//Setting for Interrupt
unsigned char idata IntMask                             _at_            0x38;
unsigned char idata IntFlag                             _at_            0x39;
unsigned char idata Reset_RISC                          _at_            0x3A;




//Cache Control
unsigned char idata XDM_Cache_Flush_LINE_NO             _at_            0x3B;

unsigned char idata CACHE_CONTROL                       _at_            0x3C;




//Hardware Infrared
unsigned char idata HW_IR                               _at_            0x3D;




//Internal Timer
unsigned char idata TimerA_Lo                           _at_            0x3E;
unsigned char idata TimerA_Hi                           _at_            0x3F;
unsigned char idata TimerB_Lo                           _at_            0x40;
unsigned char idata TimerB_Hi                           _at_            0x41;
unsigned char idata Timer_Enable                        _at_            0x42;




//For System Resume
unsigned char idata IOP_WATCH_DOG_RST_EN                _at_            0x44;
unsigned char idata IOP_RESUME_PCL_0                    _at_            0x45;
unsigned char idata IOP_RESUME_PCL_1                    _at_            0x46;
unsigned char idata IOP_RESUME_PCH_0                    _at_            0x47;
unsigned char idata IOP_RESUME_PCH_1                    _at_            0x48;



unsigned char idata IOP_INT_MASK1_B                     _at_            0x49;
unsigned char idata IOP_INT_FLAG1                       _at_            0x4A;

unsigned char idata IOP_INT_MASK2_B                     _at_            0x4B;
unsigned char idata IOP_INT_FLAG2                       _at_            0x4C;
unsigned char idata IOP_INT_MASK3_B                     _at_            0x4D;
unsigned char idata IOP_INT_FLAG3                       _at_            0x4E;






/*=====================================================================
MailBox
should pay attentation to the using of mailbox
including addressig mode
=====================================================================*/

unsigned char idata IOP_DATA0_L                         _at_            0x50;
unsigned char idata IOP_DATA0_H                         _at_            0x51;
unsigned char idata IOP_DATA1_L                         _at_            0x52;
unsigned char idata IOP_DATA1_H                         _at_            0x53;
unsigned char idata IOP_DATA2_L                         _at_            0x54;
unsigned char idata IOP_DATA2_H                         _at_            0x55;
unsigned char idata IOP_DATA3_L                         _at_            0x56;
unsigned char idata IOP_DATA3_H                         _at_            0x57;
unsigned char idata IOP_DATA4_L                         _at_            0x58;
unsigned char idata IOP_DATA4_H                         _at_            0x59;
unsigned char idata IOP_DATA5_L                         _at_            0x5A;
unsigned char idata IOP_DATA5_H                         _at_            0x5B;
unsigned char idata IOP_DATA6_L                         _at_            0x5C;
unsigned char idata IOP_DATA6_H                         _at_            0x5D;
unsigned char idata IOP_DATA7_L                         _at_            0x5E;
unsigned char idata IOP_DATA7_H                         _at_            0x5F;
unsigned char idata IOP_DATA8_L                         _at_            0x60;
unsigned char idata IOP_DATA8_H                         _at_            0x61;
unsigned char idata IOP_DATA9_L                         _at_            0x62;
unsigned char idata IOP_DATA9_H                         _at_            0x63;
unsigned char idata IOP_DATA10_L                        _at_            0x64;
unsigned char idata IOP_DATA10_H                        _at_            0x65;
unsigned char idata IOP_DATA11_L                        _at_            0x66;
unsigned char idata IOP_DATA11_H                        _at_            0x67;

//For RTC Timer
unsigned char idata SYS_RTC_TIMER_A                     _at_            0x68;
unsigned char idata SYS_RTC_TIMER_B                     _at_            0x69;
unsigned char idata SYS_RTC_TIMER_C                     _at_            0x6A;
unsigned char idata SYS_RTC_TIMER_D                     _at_            0x6B;
unsigned char idata SYS_RTC_ONTIME_SET_A                _at_            0x6C;
unsigned char idata SYS_RTC_ONTIME_SET_B                _at_            0x6D;
unsigned char idata SYS_RTC_ONTIME_SET_C                _at_            0x6E;
unsigned char idata SYS_RTC_ONTIME_SET_D                _at_            0x6F;


unsigned char idata XDMDATA_OUT_HH                      _at_            0x70;
unsigned char idata XDMDATA_OUT_HL                      _at_            0x71;
unsigned char idata XDMDATA_OUT_LH                      _at_            0x72;
unsigned char idata XDMDATA_OUT_LL                      _at_            0x73;

unsigned char idata XDMDATA_IN_LL                       _at_            0x74;
unsigned char idata XDMDATA_IN_LH                       _at_            0x75;
unsigned char idata XDMDATA_IN_HL                       _at_            0x76;
unsigned char idata XDMDATA_IN_HH                       _at_            0x77;


unsigned char idata XDM_Bank_ADR_HH                     _at_            0x78;
unsigned char idata XDM_Bank_ADR_HL                     _at_            0x79;


unsigned char idata DataIrFormat                        _at_            0x80;



void Fill_DCache_1KB(void)
{

	unsigned char xdata tmp0=22;
	unsigned char xdata tmp1=22;
	unsigned char xdata tmp2=22;
	unsigned char xdata tmp3=22;
	unsigned char xdata tmp4=22;
	unsigned char xdata tmp5=22;
	unsigned char xdata tmp6=22;
	unsigned char xdata tmp7=22;
	unsigned char xdata tmp8=22;
	unsigned char xdata tmp9=22;
	unsigned char xdata tmpa=22;
	unsigned char xdata tmpb=22;
	unsigned char xdata tmpc=22;
	unsigned char xdata tmpd=22;
	unsigned char xdata tmpe=22;
	unsigned char xdata tmpf=22;

	tmp0=(unsigned char)*((unsigned char xdata *)(0x0000));
	tmp1=(unsigned char)*((unsigned char xdata *)(0x0020));
	tmp2=(unsigned char)*((unsigned char xdata *)(0x0040));
	tmp3=(unsigned char)*((unsigned char xdata *)(0x0060));
	tmp4=(unsigned char)*((unsigned char xdata *)(0x0080));
	tmp5=(unsigned char)*((unsigned char xdata *)(0x00A0));
	tmp6=(unsigned char)*((unsigned char xdata *)(0x00C0));
	tmp7=(unsigned char)*((unsigned char xdata *)(0x00E0));
	tmp8=(unsigned char)*((unsigned char xdata *)(0x0100));
	tmp9=(unsigned char)*((unsigned char xdata *)(0x0120));
	tmpa=(unsigned char)*((unsigned char xdata *)(0x0140));
	tmpb=(unsigned char)*((unsigned char xdata *)(0x0160));
	tmpc=(unsigned char)*((unsigned char xdata *)(0x0180));
	tmpd=(unsigned char)*((unsigned char xdata *)(0x01A0));
	tmpe=(unsigned char)*((unsigned char xdata *)(0x01C0));
	tmpf=(unsigned char)*((unsigned char xdata *)(0x01E0));

	tmp0=(unsigned char)*((unsigned char xdata *)(0x0200));
	tmp1=(unsigned char)*((unsigned char xdata *)(0x0220));
	tmp2=(unsigned char)*((unsigned char xdata *)(0x0240));
	tmp3=(unsigned char)*((unsigned char xdata *)(0x0260));
	tmp4=(unsigned char)*((unsigned char xdata *)(0x0280));
	tmp5=(unsigned char)*((unsigned char xdata *)(0x02A0));
	tmp6=(unsigned char)*((unsigned char xdata *)(0x02C0));
	tmp7=(unsigned char)*((unsigned char xdata *)(0x02E0));
	tmp8=(unsigned char)*((unsigned char xdata *)(0x0300));
	tmp9=(unsigned char)*((unsigned char xdata *)(0x0320));
	tmpa=(unsigned char)*((unsigned char xdata *)(0x0340));
	tmpb=(unsigned char)*((unsigned char xdata *)(0x0360));
	tmpc=(unsigned char)*((unsigned char xdata *)(0x0380));
	tmpd=(unsigned char)*((unsigned char xdata *)(0x03A0));
	tmpe=(unsigned char)*((unsigned char xdata *)(0x03C0));
	tmpf=(unsigned char)*((unsigned char xdata *)(0x03E0));

}


