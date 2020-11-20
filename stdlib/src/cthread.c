// Copyright (C) strawberryhacker

#include <syscall.h>

void sleep(u32 ms)
{
    syscall_sleep(ms);
}

i32 create_thread(pid_t* pid, i32 (*func)(void *), u32 stack_size, 
    const char* name, void* arg, u32 flags)
{
    return syscall_create_thread(pid, func, stack_size, name, arg, flags);
}
