# Copyright (C) strawberryhacker

TOP = $(shell pwd)
LIBNAME = libcitrus
BUILDDIR = $(TOP)/build

CC = arm-none-eabi-gcc
AR = arm-none-eabi-ar

# Set the compiler flags
CFLAGS   += -x c -O1 -g3 -fdata-sections -mlong-calls -Wall
CFLAGS   += -std=gnu99 -c -ffunction-sections -march=armv7-a
CFLAGS   += -mfpu=vfpv4-d16 -mfloat-abi=hard -marm
CFLAGS   += -Wno-unused-function -Wno-unused-variable
CFLAGS   += -ffreestanding

CPFLAGS  += -I$(TOP)/include

ASMFLAGS += -march=armv7-a -g3
ASMFLAGS += -mfpu=vfpv4-d16 -mfloat-abi=hard

OBJ :=

include $(TOP)/src/Makefile

BUILDOBJ = $(addprefix $(BUILDDIR)/, $(OBJ))

.SECONDARY: $(BUILDOBJ)
.PHONY: all clean

all: $(BUILDDIR)/$(LIBNAME).a

$(BUILDDIR)/%.a: $(BUILDOBJ)
	@echo
	@echo Building library $(notdir $@)
	@mkdir -p $(dir $@)
	@$(AR) -rcs $@ $^
	

$(BUILDDIR)/%.o: $(TOP)/%.c
	@echo " >" $(patsubst $(TOP)/%, %, $^)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPFLAGS) -o $@ -c $<

clean:
	@rm -f -r $(BUILDDIR)
