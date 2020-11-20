// Copyright (C) strawberryhacker

#include <regmap.h>
#include <stddef.h>
#include <ctypes.h>
#include <cthread.h>

void print(const char* data)
{
    while (*data) {
        while (!(UART1->SR & (1 << 1)));
        UART1->THR = *data++;
    }
}

i32 thread(void* arg)
{
    while (1) {
        print("CHILD THREAD\n");
        sleep(400);
    }
}

i32 main(void* arg)
{
    //create_cthread(thread, 500, "child-thread", NULL, SCHED_RT);
    
    while (1) {
        print("------------------------------\n");
        sleep(1000);
    }
}
