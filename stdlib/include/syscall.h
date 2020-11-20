/// Copyright (C) strawberryhacker

#ifndef SYSCALL_H
#define SYSCALL_H

#include <ctypes.h>
#include <cthread.h>

#define __swi __attribute__((naked)) __attribute__((noinline))

void __swi syscall_sleep(u32 us);

i32 __swi syscall_create_thread(pid_t* pid, i32 (*func)(void *), u32 stack_size,
    const char* name, void* arg, u32 flags);

u32 __swi syscall_sbrk(u32 bytes);

#endif
