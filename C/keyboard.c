#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int times = 16;
    keybd_event(VK_SHIFT, 0x00, 0, 0);
    while (times--) {
        //keybd_event(VK_SHIFT, 0x00, 0, 0);
        keybd_event('A', 0x1E, 0, 0);
        keybd_event('A', 0x1E, 2, 0);
        //keybd_event(VK_SHIFT, 0x00, 2, 0);
        Sleep(1000);
    }
    keybd_event(VK_SHIFT, 0x00, 2, 0);
    printf("end\n");

    return 0;
}


