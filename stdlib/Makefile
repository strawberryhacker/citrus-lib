# Copyright (C) strawberryhacker

TOP      = $(shell pwd)
BUILDDIR = $(TOP)/build
LIBNAME  = libcitrus

# Cross-compiler for ARM
CC = arm-none-eabi-gcc
AR = arm-none-eabi-ar

# Flags
CFLAGS   += -x c -O1 -g3 -fdata-sections -mlong-calls -Wall -Wno-unused-function
CFLAGS   += -std=gnu99 -c -ffunction-sections -march=armv7-a -ffreestanding
CFLAGS   += -mfpu=vfpv4-d16 -mfloat-abi=hard -marm -Wno-unused-variable

CPFLAGS  += -I$(TOP)/include

ASMFLAGS += -march=armv7-a -g3 -mfpu=vfpv4-d16 -mfloat-abi=hard

# Add the objects
OBJ :=

include $(TOP)/src/Makefile

BUILDOBJ = $(addprefix $(BUILDDIR)/, $(OBJ))

.SECONDARY: $(BUILDOBJ)
.PHONY: all clean

all: $(BUILDDIR)/$(LIBNAME).a

$(BUILDDIR)/%.a: $(BUILDOBJ)
	@echo
	@echo Building library: $(notdir $@)
	@mkdir -p $(dir $@)
	@$(AR) -rcs $@ $^
	

$(BUILDDIR)/%.o: $(TOP)/%.c
	@echo " >" $(patsubst $(TOP)/%, %, $^)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPFLAGS) -o $@ -c $<

clean:
	@rm -f -r $(BUILDDIR)
