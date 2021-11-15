#set this env to skip clear IRAM
export 	SDCC_NOGENRAMCLEAR=1

ifneq ($V,1)
 Pecho=@echo
 P=@
else
 Pecho=@:
 P=
endif

#######################################
# Build path
#######################################
BUILD_DIR  = __build
OUTPUT_DIR = out
TOOLS_DIR  = tools

DIR_COMMON = common
DIR_I2C    = driver/i2c
DIR_START  = startup

######################################
# target path
######################################
TARGET = dq8051_firmware

TARGET_OUT = $(BUILD_DIR)/$(TARGET)

#######################################
# cross compile
#######################################
PREFIX = 
CC	= $(PREFIX)sdcc
AS	= $(PREFIX)sdas8051
PACK	= $(PREFIX)packihx


MCU_MODEL = -mmcs51
RM = rm -rf


# ------------------------------------------------------
# Usually SDCC's small memory model is the best choice.  If
# you run out of internal RAM, you will need to declare
# variables as "xdata", or switch to larger model

# Memory Model (small, medium, large, huge)
MODEL  = --model-large

# ------------------------------------------------------
# Memory Layout
# code size 512KB
CODE_SIZE = --code-size 0x80000

# INT-MEM Size = 256 Bytes
#IRAM_SIZE = --idata-loc 0x0000  --iram-size 256
IRAM_SIZE = --iram-size 256 --data-loc 0x08
# EXT-MEM Size = 4K Bytes
#XRAM_SIZE = --xram-loc 0x0000 --xram-size 768
#XRAM size 512KB
XRAM_SIZE = --xram-size 0x80000

# ------------------------------------------------------
#######################################
# FLAGS
#######################################
# compile as8051 flags
# macros for gcc
# AS defines
AS_DEFS =

# C defines
C_DEFS =

ASFLAGS = -plosgff


# AS includes
AS_INCLUDES =

# C includes
C_INCLUDES = -Iinclude -Iinclude/$(DIR_COMMON) -Iinclude/$(DIR_I2C)

# libraries
LIBS =
LIBDIR =

CFLAGS = $(MCU_MODEL) $(C_DEFS) $(C_INCLUDES) $(MODEL)  --out-fmt-ihx --no-xinit-opt


ifeq ($(DEBUG), 1)
CFLAGS +=
else
CFLAGS += $(OPT)
endif

######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT =


#######################################
# LDFLAGS
#######################################
LDFLAGS = $(LIBDIR) $(LIBS) $(MCU_MODEL) $(MODEL) $(CODE_SIZE) $(IRAM_SIZE) $(XRAM_SIZE) $(STACK_ADDRESS) --out-fmt-ihx

# default action: build all

#######################################
# build the code
#######################################

VPATH		:= $(DIR_COMMON) $(DIR_I2C) $(DIR_START)

C_SOURCES = main.c
C_SOURCES += $(DIR_COMMON)/Int_Vec.c  $(DIR_COMMON)/timer.c  $(DIR_COMMON)/vitrualserial.c
C_SOURCES += $(DIR_I2C)/i2c_slave.c $(DIR_I2C)/i2c_slave_common.c

A_SOURCES = $(DIR_START)/crtstart.asm

C_OBJ_FILE = $(notdir $(C_SOURCES:.c=.c.rel) $(A_SOURCES:.asm=.asm.rel))

# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(C_OBJ_FILE))

.PHONY: all clean prepare bin_2_array

all: bin_2_array $(OBJECTS)
	$(CC) -o $(TARGET_OUT).ihx $(LDFLAGS) $(OBJECTS)
	$(PACK) $(TARGET_OUT).ihx > $(TARGET_OUT).hex
	srec_cat $(TARGET_OUT).hex -Intel -byte-swap 4 --fill 0x0 0 4096 -o $(TARGET_OUT).bin -Binary
	$(BUILD_DIR)/bin2array $(TARGET_OUT).bin $(OUTPUT_DIR)/$(TARGET).c

bin_2_array: prepare
	@gcc $(TOOLS_DIR)/bin2array.c -o $(BUILD_DIR)/bin2array

$(BUILD_DIR)/%.c.rel: %.c
	$(CC) -o $@ $(CFLAGS) -c $^

$(BUILD_DIR)/%.asm.rel: %.asm
	$(AS) $(ASFLAGS) -o $@ $^

prepare:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OUTPUT_DIR)

#######################################
# clean up
#######################################

HEADER_FILE = 8051.h
HEADER_PATH = /usr/share/sdcc/include/mcs51

disasm: $(TARGET_OUT).hex
	$(Pecho) ./tools/mcs51-disasm.pl -M $(HEADER_FILE) -I $(HEADER_PATH) -fl -rj -as $(TARGET_OUT).hex > $(TARGET_OUT).a51


clean:
	$(Pecho) "Clean....."
	@$(RM) $(BUILD_DIR)

p-%:
#	$(Pecho) "$* is '$($*)'"
	$(Pecho) '$*=$($*)'
	$(Pecho) '  origin =ls $(origin $*)'
	$(Pecho) '  value = $(value  $*)'
	$(Pecho) '  flavor = $(flavor $*)'
