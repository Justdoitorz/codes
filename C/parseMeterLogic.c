#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void test(char *addr)
{
    for (int i = 0; i < 4; i++) {
        printf("%x\n", addr[i]);
    }
}

unsigned char hex2value(char hex)
{
    if (hex >= '0' && hex <= '9') {
        return hex & 0x0F;
    } else if ((hex >= 'a' && hex <= 'f') || (hex >= 'A' && hex <= 'F')) {
        return (hex & 0x4F) - 'A' + 10;
    } else {
        return 0;
    }
}

unsigned char getValue(char *buf)
{
    return (hex2value(buf[0])<<4) + hex2value(buf[1]);
}

unsigned int getData(char *buf, int len)
{
    unsigned int result = 0;
    for (int i = 0; i < len; i++) {
        //dst[i] = getValue(buf + i*2);
        result |= getValue(buf + i*2) << i*8;
    }
    return result;
}

int getBitsVaild(unsigned int value)
{
    int cnt = 0;
    while (value) {
        value &= value - 1;
        cnt++;
    }
    return cnt;
}

const char *warnType[] = {
    "Enable",
    "Open",
    "Short",
    "Open&Short",
};

int getWarnAndShow(unsigned int value, int idx, int errCnt)
{
    //
    int cnt = 0;
    //value &= 0xFF;
    //printf("value = %x \t", value);
    if ((value&0xF0) == 0xA0) {
        printf("err = %d .. idx: %d,, Warn Type: %s\n", errCnt, idx, warnType[value&3]);
        cnt += (value&3) == 3 ? 2 : 1;
    }
    return cnt;
}

int number[] = {
    300, 30, 20,
    30, 20,
    30, 20,
    30, 20,
    30, 20,

    30, 20,
    30, 20,

    300, 30, 20,
    30, 20,
    30, 20,
    30, 20,
    30, 20,

    30, 20,
    30, 20,

    204,
};

const char *name[] = {
    "Virtual load",
    "Meter load",
    "Meter seosor",

    "Front load",
    "Front sensor",
    "Back load",
    "Back sensor",
    "Top load",
    "Top sensor",
    "Middle load",
    "Middle sensor",

    "Power load",
    "Power sensor",
    "PowerCtrl load",
    "PowerCtrl sensor",

    "Virtual load 2",
    "Meter load 2",
    "Meter seosor 2",

    "Front load 2",
    "Front sensor 2",
    "Back load 2",
    "Back sensor 2" ,
    "Top load 2",
    "Top sensor 2",
    "Middle load 2",
    "Middle sensor 2",

    "Power load 2",
    "Power sensor 2",
    "PowerCtrl load 2 ",
    "PowerCtrl sensor 2",
    "user",
};

#define ARR_LEN(arr)    (sizeof(arr)/sizeof(arr[0]))

int main()
{
    char buf[1024], *p;
    //int number[] = {300, 30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 204};
    int errCnt = 0, newErr;
    unsigned int sysConfig = 0, icoIdx = 0, idx = 0, icoValue, line = 0, last = -1;
    FILE *fp = fopen("MeterLogic.txt", "rb");
    if (NULL == fp) {
        printf("fopen error\n");
        exit(1);
    }
    int ttt = 0;
    while (1) {
        fgets(buf, 1024, fp);
        if (strncmp("[SysConfig]", buf, 11) == 0) {
            sysConfig = getData(buf+11, 4);
            printf("%d\n", sysConfig);
            errCnt += getBitsVaild(sysConfig);
            printf("Modules = %d\n", errCnt);
            break;
        }
    }

    while (line < 65) {
        fgets(buf, 1024, fp);
        if (strncmp("[IcoWarnConfig]", buf, 15) == 0) {
            printf("%s\n", buf);



            line++;
            p = buf+15;

            while (*p && *p != '\r') {
                //printf("*p = %d, %d\n", *p, '\n');
                if (last != icoIdx) {
                    idx = 0;
                    printf("\nIn %s ... idx = %d\n", name[icoIdx], idx);
                    last = icoIdx;

                }

                icoValue = getData(p, 2);

                newErr = getWarnAndShow(icoValue, icoIdx == 0 ? idx+8:idx, errCnt);

                errCnt += newErr;


                idx++;
                if (idx >= number[icoIdx]) {
                    icoIdx++;
                }
                p += 4;
            }

            //printf("idx = %d\n", idx);
            //break;
        }
    }

    printf("Total warn = %d\n", errCnt);

}
