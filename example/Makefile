# Copyright (C) strawberryhacker

TOP         = $(shell pwd)
BUILDDIR    = $(TOP)/build
TARGET_NAME = example

# Replace this with the library path
LIBPATH     = $(TOP)/../stdlib/build
LIBINCPATH  = $(TOP)/../stdlib/include
LIBNAME     = citrus

# Cross-compiler for ARM
CC      = arm-none-eabi-gcc
OBJDUMP = arm-none-eabi-objdump
OBJCOPY = arm-none-eabi-objcopy
ARM_ASM = arm-none-eabi-as
GDB     = arm-none-eabi-gdb

# Add the object files
OBJ :=

include $(TOP)/entry/Makefile
include $(TOP)/startup/Makefile
include $(TOP)/include/Makefile

BUILDOBJ = $(addprefix $(BUILDDIR)/, $(OBJ))

# Flags
CFLAGS   += -x c -O2 -ffunction-sections -fdata-sections -mlong-calls -Wall
CFLAGS   += -std=gnu99 -mcpu=cortex-a5 -c -ffreestanding -Wno-unused-function
CFLAGS   += -mfpu=vfpv4-d16 -mfloat-abi=hard -marm -Wno-unused-variable

CPFLAGS  += -I$(TOP)/include -I$(LIBINCPATH)

LDFLAGS  += -Wl,--start-group -Wl,--end-group -Wl,--gc-sections -mcpu=cortex-a5
LDFLAGS  += -Wl,-Map="$(BUILDDIR)/$(TARGET_NAME).map" -l$(LIBNAME) -L$(LIBPATH)
LDFLAGS  += -mfpu=vfpv4-d16 -mfloat-abi=hard -marm -nostdlib

ASMFLAGS += -mcpu=cortex-a5 -mfpu=vfpv4-d16 -mfloat-abi=hard

.SECONDARY: $(BUILDOBJ)
.PHONY: all elf bin lss clean 

# Rebuild the library first
all: elf lss bin

# Subtargets
elf: $(BUILDDIR)/$(TARGET_NAME).elf
lss: $(BUILDDIR)/$(TARGET_NAME).lss
bin: $(BUILDDIR)/$(TARGET_NAME).bin

$(BUILDDIR)/%.elf: $(BUILDOBJ)
	@echo
	@$(CC) $^ -o $@ $(LDFLAGS) -Wl,--print-memory-usage 
	@echo

$(BUILDDIR)/%.lss: $(BUILDDIR)/%.elf
	@$(OBJDUMP) -h -S $< > $@

$(BUILDDIR)/%.bin: $(BUILDDIR)/%.elf
	@$(OBJCOPY) -O binary $< $@
	@echo Build completed
	@echo

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo " >" $<
	@$(CC) $(CFLAGS) $(CPFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: %.s
	@mkdir -p $(dir $@)
	@echo " >" $<
	@$(ARM_ASM) $(ASMFLAGS) -c $< -o $@	

clean:
	@rm -r -f $(BUILDDIR)
