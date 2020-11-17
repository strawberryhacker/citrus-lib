/// Copyright (C) strawberryhacker

#include <citrus.h>

extern u32 _bss_s;
extern u32 _bss_e;

extern i8 main(void* arg);

i8 startup(void* arg)
{
    // Clear the BSS segment
    u8* start = (u8 *)&_bss_s;
    u8* end = (u8 *)&_bss_e;

    while (start < end) {
        *start++ = 0x00;
    }

    return main(arg);
}
