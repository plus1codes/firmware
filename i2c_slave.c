#include "i2c_slave_common.h"
#include "i2c_slave.h"

static volatile char idata i2c_status=I2C_SLAVE_IDLE;
unsigned char idata rw_flag = 0;  //0:write  1:read
unsigned int xdata SCL_PORT,SDA_PORT,SCL_BIT,SDA_BIT,I2C_SLAVE_ADDR;


#define I2C_SET_IN_OUT(IO_CFG,SCL_SDA,mode) \
				do{	\
					(mode == I2C_IN_MODE)?(IO_CFG &=~ (1<<SCL_SDA##_BIT)):(IO_CFG |= (1<<SCL_SDA##_BIT)); \
				}while(0)
				
#define I2C_MODE_SET(SCL_SDA,mode) \
	do{	\
		switch(SCL_SDA##_PORT){ \
			case 0: \
				I2C_SET_IN_OUT(GPIO_IO0_CFG,SCL_SDA,mode);	break; \
			case 1: \
				I2C_SET_IN_OUT(GPIO_IO1_CFG,SCL_SDA,mode);	break; \
			case 2: \
				I2C_SET_IN_OUT(GPIO_IO2_CFG,SCL_SDA,mode);	break; \
			case 3: \
				I2C_SET_IN_OUT(GPIO_IO3_CFG,SCL_SDA,mode);	break; \
			case 4: \
				I2C_SET_IN_OUT(GPIO_IO4_CFG,SCL_SDA,mode);	break; \
			case 5: \
				I2C_SET_IN_OUT(GPIO_IO5_CFG,SCL_SDA,mode);	break; \
			case 6: \
				I2C_SET_IN_OUT(GPIO_IO6_CFG,SCL_SDA,mode);	break; \
			case 7: \
				I2C_SET_IN_OUT(GPIO_IO7_CFG,SCL_SDA,mode);	break; \			
			case 8: \
				I2C_SET_IN_OUT(GPIO_IO8_CFG,SCL_SDA,mode);	break; \
			default: break; \
		}\	
	}while(0)	
	

#define I2C_SET_VALUE(PORT_OUT,SCL_SDA,level) \
				do{	\
					(level == I2C_OUT_LOW)?(PORT_OUT &=~ (1<<SCL_SDA##_BIT)):(PORT_OUT |= (1<<SCL_SDA##_BIT)); \
				}while(0)
				
#define I2C_OUTPUT_SET(SCL_SDA,level) \
	do{	\
		switch(SCL_SDA##_PORT){ \
			case 0: \
				I2C_SET_VALUE(GPIO_PORT0_OUT,SCL_SDA,level);	break; \
			case 1: \
				I2C_SET_VALUE(GPIO_PORT1_OUT,SCL_SDA,level);	break; \
			case 2: \
				I2C_SET_VALUE(GPIO_PORT2_OUT,SCL_SDA,level);	break; \
			case 3: \
				I2C_SET_VALUE(GPIO_PORT3_OUT,SCL_SDA,level);	break; \
			case 4: \
				I2C_SET_VALUE(GPIO_PORT4_OUT,SCL_SDA,level);	break; \
			case 5: \
				I2C_SET_VALUE(GPIO_PORT5_OUT,SCL_SDA,level);	break; \
			case 6: \
				I2C_SET_VALUE(GPIO_PORT6_OUT,SCL_SDA,level);	break; \
			case 7: \
				I2C_SET_VALUE(GPIO_PORT7_OUT,SCL_SDA,level);	break; \			
			case 8: \
				I2C_SET_VALUE(GPIO_PORT8_OUT,SCL_SDA,level);	break; \
			default: break; \
		}\	
	}while(0)


#define I2C_INPUT_GET_VALUE(PORT_IN,SCL_SDA)  \
				do{ \
						return (((PORT_IN&(1<<SCL_SDA##_BIT)) == (1<<SCL_SDA##_BIT))?1:0);\
					}while(0)


#define I2C_INPUT_GET(SCL_SDA) \
	do{	\
		switch(SCL_SDA##_PORT){ \
			case 0: \
				I2C_INPUT_GET_VALUE(GPIO_PORT0_IN,SCL_SDA);break; \
			case 1: \
				I2C_INPUT_GET_VALUE(GPIO_PORT1_IN,SCL_SDA);break; \
			case 2: \
				I2C_INPUT_GET_VALUE(GPIO_PORT2_IN,SCL_SDA);break; \
			case 3: \
				I2C_INPUT_GET_VALUE(GPIO_PORT3_IN,SCL_SDA);break; \
			case 4: \
				I2C_INPUT_GET_VALUE(GPIO_PORT4_IN,SCL_SDA);break; \
			case 5: \
				I2C_INPUT_GET_VALUE(GPIO_PORT5_IN,SCL_SDA);break; \
			case 6: \
				I2C_INPUT_GET_VALUE(GPIO_PORT6_IN,SCL_SDA);break; \
			case 7: \
				I2C_INPUT_GET_VALUE(GPIO_PORT7_IN,SCL_SDA);break; \			
			case 8: \
				I2C_INPUT_GET_VALUE(GPIO_PORT8_IN,SCL_SDA);break; \
			default: break; \
		}\	
	}while(0)


void i2c_scl_set_in_mode() 				{  	I2C_MODE_SET(SCL,I2C_IN_MODE);}

void i2c_sda_set_in_mode() 				{		I2C_MODE_SET(SDA,I2C_IN_MODE);}
void i2c_sda_set_out_mode()  	 		{  	I2C_MODE_SET(SDA,I2C_OUT_MODE);}

void I2C_SDA_OUT_H()							{  	I2C_OUTPUT_SET(SDA,I2C_OUT_HIGH);}
void I2C_SDA_OUT_L()  	 					{		I2C_OUTPUT_SET(SDA,I2C_OUT_LOW);}

int  I2C_SCL_GET()    						{ 	I2C_INPUT_GET(SCL);		}
int  I2C_SDA_GET()    						{ 	I2C_INPUT_GET(SDA);		}

void i2c_wait_scl_low()  					{ 	while(I2C_SCL_GET()) ;}
void i2c_wait_scl_high()      		{ 	while(!I2C_SCL_GET()) ;}


int i2c_wait_scl_low_check_staus(void)
{
    char idata ret = 0,flag=0;
    volatile int idata sda = 0;
    while(I2C_SCL_GET())
    {
        if(flag == 0)
        {
            sda = I2C_SDA_GET();
            flag = 1;
        }
        if(sda != I2C_SDA_GET())
        {
            if(sda == 0)
                i2c_status = I2C_SLAVE_STOP;
            else
                i2c_status = I2C_SLAVE_START;  
            ret = -1;
            break;
        }
    }
    return ret;
}

int i2c_send_ack()
{
		i2c_wait_scl_low();
		i2c_sda_set_out_mode();
	  I2C_SDA_OUT_L();
	  i2c_wait_scl_high();
		
		return 0;
}

int i2c_send_nack()
{
    i2c_wait_scl_low();
	  i2c_sda_set_out_mode();
    I2C_SDA_OUT_H();
    i2c_wait_scl_high();
		
		return 0;
}

int i2c_read_address(void)
{
    int xdata bitcount = 0,value=0;

    i2c_sda_set_in_mode();
		
    for(bitcount=0;bitcount<8;bitcount++)
    {
        if(i2c_wait_scl_low_check_staus())
            goto error;
        i2c_wait_scl_high();
        value = value << 1;
        value |= I2C_SDA_GET();
    }

    rw_flag = value&0x01;

    if(((value>>1)&0x7f) == I2C_SLAVE_ADDR)
    {
        i2c_send_ack();
				send_irq_to_risc();
        return 0;  
    }
error:
		i2c_sda_set_in_mode();
		i2c_status = I2C_SLAVE_IDLE;  //reset to idle status
    return -1;
}

int i2c_read_data(void)
{
    int xdata bitcount = 0,value=0;
    for(bitcount=0;bitcount<8;bitcount++)
    {
        if(i2c_wait_scl_low_check_staus())
            return -1;
				i2c_sda_set_in_mode();		
        i2c_wait_scl_high();
        value = value << 1;
        value |= I2C_SDA_GET();
    }

		i2c_send_ack();
		
		store_data(value);
    return 0; 
}

int i2c_send_data(void)
{
    int xdata bitcount = 0;   
    int xdata send_mask = 0x80;
		int xdata value = load_data();

    i2c_sda_set_out_mode();

    for(bitcount=0;bitcount < 8;bitcount++)
    {
       // i2c_wait_scl_low();
        if(i2c_wait_scl_low_check_staus())
            return -1;
        if(value & send_mask)
            I2C_SDA_OUT_H();
        else
            I2C_SDA_OUT_L();
						
        i2c_wait_scl_high();
        send_mask = send_mask >> 1;
    }

    i2c_wait_scl_low();
		
    i2c_sda_set_in_mode();;

    i2c_wait_scl_high();
    if(I2C_SDA_GET() == 0) //wait master ack
    {
				// continue to send data;
       return 0;  
    }
		//master send nack,wait stop signal;
		i2c_status = I2C_SLAVE_WAIT_STOP;
    return 1; 
}

void i2c_rw_data()
{
    if(!rw_flag)
    {
        //master write,slave read 		
        i2c_read_data();
    }
    else
    {
        //master read,slave write 
        i2c_send_data();
    }
}

//wait status change to start/stop
void i2c_wait_SS()
{
	i2c_wait_scl_low_check_staus();  //wait for sda changed in scl high state
}

void i2c_slave_protocol(void)
{
		switch(i2c_status)
		{
				case I2C_SLAVE_IDLE:
					 if((I2C_SCL_GET() == 1)&&(I2C_SDA_GET() == 0))
					 {
						 i2c_status = I2C_SLAVE_START;
					 }
				break;
				case I2C_SLAVE_START:
						if(I2C_SCL_GET() == 0)
						{
								i2c_status = I2C_SLAVE_READ_ADDRESS;
						}
				break;
				case I2C_SLAVE_READ_ADDRESS:
						if(i2c_read_address() == 0)
						{
								i2c_status = I2C_SLAVE_RW_DATA;
						}
						else
						{
								i2c_status = I2C_SLAVE_IDLE;
						}
				break;
				case I2C_SLAVE_RW_DATA:
						i2c_rw_data();
				break;
				case I2C_SLAVE_WAIT_STOP:
						i2c_wait_SS();
					break;
				case I2C_SLAVE_STOP:
						i2c_status = I2C_SLAVE_IDLE;
						i2c_sda_set_in_mode(); 
				break;
				default:
				break;
		}
}

void i2c_slave_init()
{
	printf("  i2c_slave_Init time = %s \n",__TIME__);
		
	I2C_SLAVE_ADDR = REG_I2C_ADDR & 0x7f;
	
	SDA_PORT = REG_PIN_SDA/8;
	SDA_BIT = REG_PIN_SDA%8;

	SCL_PORT = REG_PIN_SCL/8;
	SCL_BIT = REG_PIN_SCL%8;

	i2c_scl_set_in_mode();
	i2c_sda_set_in_mode();

	clear_databuf();
	
	REG_IOP_2_RISC |= 1<<I2C_TX_EMPTY_POS;
}


void i2c_slave_hanle(void)
{
	while(1)
	{
		if(i2c_status == I2C_SLAVE_IDLE)
		{
			i2c_slave_save_data();
			i2c_slave_get_data();
			//printf_info();
		}
		i2c_slave_protocol();
	}
}
