/// Copyright (C) strawberryhacker

#include <syscall.h>

#define SYSCALL_SLEEP         0
#define SYSCALL_CREATE_THREAD 1
#define SYSCALL_SBRK          2

#define __syscall_tmp(x)          \
    asm volatile ("svc #"#x"\n"); \
    asm volatile ("bx lr");

#define __syscall(x) __syscall_tmp(x)

void __swi syscall_sleep(u32 us)
{
    __syscall(SYSCALL_SLEEP);
}

i32 __swi syscall_create_thread(pid_t* pid, i32 (*func)(void *), u32 stack_size,
    const char* name, void* arg, u32 flags)
{
    __syscall(SYSCALL_CREATE_THREAD);
}

u32 __swi syscall_sbrk(u32 bytes)
{
    __syscall(SYSCALL_SBRK);
}
