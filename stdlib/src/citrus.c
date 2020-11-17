/// Copyright (C) strawberryhacker

#include <citrus.h>
#include <syscall.h>

void sleep(u32 ms)
{
    syscall_sleep(ms);
}

i8 create_thread(i8 (*func)(void *), u32 stack_size, const char* name,
    void* args, u32 flags)
{
    return syscall_create_thread(func, stack_size, name, args, flags);
}
