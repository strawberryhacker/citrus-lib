// Copyright (C) strawberryhacker

#include <types.h>

/// Thread flags
#define SCHED_RT    0b000
#define SCHED_FAIR  0b001
#define SCHED_BACK  0b010
#define SCHED_IDLE  0b011

void sleep(u32 ms);

i8 create_thread(i8 (*func)(void *), u32 stack_size, const char* name,
    void* args, u32 flags);
