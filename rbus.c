#include "Dp8051xp.h"
#include "SunReg.h"

unsigned char* RBUS_Read(unsigned long addr)
{
		unsigned char idata value[4];
		unsigned short idata Rbus_addr_l;
		unsigned char idata Rbus_addr_3;
		unsigned char idata Rbus_addr_2;
		unsigned long idata rbdata;
		EA = 0; //close global interrupt switch

		Rbus_addr_l=    (unsigned short)(addr&0x0000FFFF);
		Rbus_addr_3=(unsigned char)((addr&0xFF000000)>>24);
		Rbus_addr_2=(unsigned char)((addr&0x00FF0000)>>16);

		CACHE_CONTROL|=0x02;
		while((CACHE_CONTROL&0x02)==0x02);
		Fill_DCache_1KB();

		CACHE_CONTROL|=0x01;

		//OFFSET2B=Rbus_addr_2;
		//OFFSET2C=Rbus_addr_3;

		XDM_Bank_ADR_HH = Rbus_addr_3;
		XDM_Bank_ADR_HL = Rbus_addr_2;

		rbdata=*((unsigned long xdata *)(Rbus_addr_l));
		CACHE_CONTROL=(CACHE_CONTROL&0xFE);

		value[3]=(unsigned char)(rbdata);
		value[2]=(unsigned char)((rbdata&0x0000FF00)>>8);
		value[1]=(unsigned char)((rbdata&0x00FF0000)>>16);
		value[0]=(unsigned char)((rbdata&0xFF000000)>>24);

		CACHE_CONTROL|=0x02;
		while((CACHE_CONTROL&0x02)==0x02);
		Fill_DCache_1KB();
		CACHE_CONTROL|=0x01;
		OFFSET2B=0x00;
		OFFSET2C=0x00;
		CACHE_CONTROL=(CACHE_CONTROL&0xFE);

		EA = 1; //open global interrupt switch

		return &value;
}


void  RBUS_Write(unsigned long addr, unsigned long value)
{
		unsigned short idata Rbus_addr_l;
		unsigned char idata Rbus_addr_3;
		unsigned char idata Rbus_addr_2;
		EA = 0; //close global interrupt switch

		Rbus_addr_l=(unsigned short)(addr&0x0000FFFF);
		Rbus_addr_3=(unsigned char)((addr&0xFF000000)>>24);
		Rbus_addr_2=(unsigned char)((addr&0x00FF0000)>>16);

		#if 0
		XDMDATA_OUT_LL=(unsigned char)(value&0x000000FF);
		XDMDATA_OUT_LH=(unsigned char)((value&0x0000FF00)>>8);
		XDMDATA_OUT_HL=(unsigned char)((value&0x00FF0000)>>16);
		XDMDATA_OUT_HH=(unsigned char)((value&0xFF000000)>>24);
		#else
		XDMDATA_OUT_HH=(unsigned char)((value&0xFF000000)>>24);
		XDMDATA_OUT_HL=(unsigned char)((value&0x00FF0000)>>16);
		XDMDATA_OUT_LH=(unsigned char)((value&0x0000FF00)>>8);
		XDMDATA_OUT_LL=(unsigned char)(value&0x000000FF);
		#endif

		CACHE_CONTROL|=0x02;
		while((CACHE_CONTROL&0x02)==0x02);
		Fill_DCache_1KB();
		CACHE_CONTROL|=0x01;

		//OFFSET2B=Rbus_addr_2;
		//OFFSET2C=Rbus_addr_3;

		XDM_Bank_ADR_HH = Rbus_addr_3;
		XDM_Bank_ADR_HL = Rbus_addr_2;

		*((unsigned char xdata *)(Rbus_addr_l))=XDMDATA_OUT_LL;

		CACHE_CONTROL=(CACHE_CONTROL&0xFE);

		CACHE_CONTROL|=0x02;
		while((CACHE_CONTROL&0x02)==0x02);
		Fill_DCache_1KB();
		
		CACHE_CONTROL|=0x01;
		OFFSET2B=0x00;
		OFFSET2C=0x00;
		CACHE_CONTROL=(CACHE_CONTROL&0xFE);
		EA = 1; //open global interrupt switch
}