/// Copyright (C) strawberryhacker

#ifndef SYSCALL_H
#define SYSCALL_H

#include <types.h>

#define SVC_ATTR __attribute__((naked)) __attribute__((noinline))

void SVC_ATTR syscall_sleep(u32 us);

i8 SVC_ATTR syscall_create_thread(i8 (*func)(void *), u32 stack_size,
    const char* name, void* args, u32 flags);

u32 SVC_ATTR syscall_sbrk(u32 bytes);

#endif
