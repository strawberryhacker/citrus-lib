// Copyright (C) strawberryhacker

#include <citrus.h>
#include <regmap.h>
#include <stddef.h>

void print(const char* data)
{
    while (*data) {
        while (!(UART1->SR & (1 << 1)));
        UART1->THR = *data++;
    }
}

i8 thread(void* arg)
{
    while (1) {
        print("CHILD THREAD\n");
        sleep(400);
    }
}

i8 main(void* arg)
{
    create_thread(thread, 500, "child-thread", NULL, SCHED_RT);
    
    while (1) {
        print("------------------------------\n");
        sleep(1000);
    }
}
