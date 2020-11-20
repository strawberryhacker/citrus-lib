// Copyright (C) strawberryhacker

#ifndef THREAD_H
#define THREAD_H

#include <ctypes.h>

typedef u32 pid_t;

// Thread flags
#define SCHED_RT    0b000
#define SCHED_FAIR  0b001
#define SCHED_BACK  0b010
#define SCHED_IDLE  0b011

void sleep(u32 ms);

i32 create_thread(pid_t* pid, i32 (*func)(void *), u32 stack_words, 
    const char* name, void* arg, u32 flags);

#endif
