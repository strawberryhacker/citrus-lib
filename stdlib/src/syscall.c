/// Copyright (C) strawberryhacker

#include <syscall.h>

#define SYSCALL_SLEEP         0
#define SYSCALL_CREATE_THREAD 1
#define SYSCALL_SBRK          2

#define SYSCALL_NX(x)      \
    asm volatile (         \
        "svc #"#x"  \t\n"  \
        "bx lr      \n\t"  \
    );

#define SYSCALL(x) SYSCALL_NX(x)

void SVC_ATTR syscall_sleep(u32 us)
{
    SYSCALL(SYSCALL_SLEEP);
}

i8 SVC_ATTR syscall_create_thread(i8 (*func)(void *), u32 stack_size,
    const char* name, void* args, u32 flags)
{
    SYSCALL(SYSCALL_CREATE_THREAD);
}

u32 SVC_ATTR syscall_sbrk(u32 bytes)
{
    SYSCALL(SYSCALL_SBRK);
}
