#include <iostream>
#include <ostream>
#include <string.h>
#include <vector>
#include <string>
#include <cstdio>
#include "test.h"

using namespace std;
const char EnBase64Tab[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    
// Base64解码表：将64个可打印字符的值作为索引，查表得到的值（范围为0-63）依次连起来得到解码结果。
// 解码表size为256，非法字符将被解码为ASCII 0
const char DeBase64Tab[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    62,        // '+'
    0, 0, 0,
    63,        // '/'
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61,        // '0'-'9'
    0, 0, 0, 0, 0, 0, 0,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,        // 'A'-'Z'
    0, 0, 0, 0, 0, 0,
    26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
    39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,        // 'a'-'z'
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
namespace Orz
{
    class LOG
    {
    public:
        /**
         * @brief 不带换行符打印
         * 
         * @param t必须可调用<<
         *  
         */
        template <typename T>
        static void print(const T &t)
        {
            cout << t;
        }

        template <typename T>
        static void println(const T &t)
        {
            print(t);
            cout << endl;
        }

        template <typename T, typename ...Args>
        static void println(const T &t, const Args&... rest)
        {
            print(t);
            print(' ');
            println(rest...);
        }
    };

    template <typename T>
    class Single
    {
    public:
        static T *getInstance()
        {
            return sin;
        }

    private:
        Single();
        ~Single() = delete;
        static T *sin;
    };
    template <typename T>
    T *Single<T>::sin = new (T);

    class CF_Base64 {
    public:
        static int encode(const unsigned char *pSrc, size_t srcLen, char *pDst, bool bChangeLine)
        {
            unsigned int uc1, uc2, uc3;
            size_t nDiv = srcLen / 3;
            size_t nMod = srcLen % 3;
            
            for (int i = 0; i < nDiv; i++) {
                uc1 = *pSrc++;
                uc2 = *pSrc++;
                uc3 = *pSrc++;

                *pDst++ = EnBase64Tab[uc1 >> 2];
                *pDst++ = EnBase64Tab[((uc1 << 4) | (uc2 >> 4)) & 0x3f];
                *pDst++ = EnBase64Tab[((uc2 << 2) | (uc3 >> 6)) & 0x3f];
                *pDst++ = EnBase64Tab[uc3 & 0x3f];
            }
        }

        static int decode(const char* pSrc, size_t nSrcLen, unsigned char* pDst)
        {
            unsigned char *pStart = pDst;           // 输出的字符计数 
            size_t i = 0; 
            while (i < nSrcLen)
            {      
                if (*pSrc != '\r' && *pSrc!='\n')
                {
                    if(i + 4 > nSrcLen)                             
                        break;           
                    int count, nValue = 0;
                    for (count = 0; count < 4 && *pSrc != '='; count++) {
                        nValue |= DeBase64Tab[int(*pSrc++)] << (3-count)*6;
                    }

                    for (int j = 1; j < count; j++) {
                        *pDst++ = nValue >> (3-j)*8;
                    }
        
                    i += 4;
                }
                else       
                {
                    pSrc++;
                    i++;
                }
            }
            *pDst = '\0'; 
            return pDst - pStart;
        }
    };
}

#define START_INFO()    Orz::LOG::println(__FILE__, "Orz framework Start...")
#define STOP_INFO()     Orz::LOG::println(__TIME__, "Orz framework End  ...", 1, 2.23154, 3)

unsigned sum(unsigned char *src, int len) 
{
    unsigned sum = 0;
    for (int i = 0; i < len; i++) {
        if (src[i] >= 128) {
            sum += src[i];
        }
    }
    return sum;
}
unsigned char getencodelen(const unsigned char *src, int len) 
{
    if (len < 3) return len;
    if (len > 127) len = 127;

    int eq = 1, tmp = 1, nflag = 1;

    for (int i = 0; i < len-1; i++) {
        if (src[i] == src[i+1]) {
            tmp = ++eq;
        } else {
            nflag = 0;
            eq = 1;
        }

        if (tmp >= 3) {
            if (tmp != eq) {
                return tmp | 0x80;
            } else if (nflag == 0) {
                return i - 1;
            }
        }
    }

    len |= (0x100 >> nflag)&0xff;
    return len;
}

int RLE_encode(const unsigned char *inbuf, int inlen, unsigned char *outbuf, int outsize)
{
    int encsize = 0, left = inlen;
    const unsigned char *src = inbuf;

    while (left > 0) {
        unsigned char count = getencodelen(src, left);
        outbuf[encsize++] = count;
        if (count & 0x80) {
            outbuf[encsize++] = *src;
        } else {
            for (int i = 0; i < count; i++) 
                outbuf[encsize++] = src[i];
        }

        src += count & 0x7F;
        left -= count & 0x7F;
    }
    return encsize;
}



int main() 
{
    START_INFO();

    unsigned char src[4096] = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 6,};
    unsigned char dst[4200];

    FILE *rfp = fopen("rle.png", "rb");
    FILE *wfp = fopen("out.rle", "wb");
    int n;

    while (n = fread(src, sizeof(char), sizeof(src), rfp)) {
        int size = RLE_encode(src, n, dst, sizeof(dst));
        fwrite(dst, sizeof(char), size, wfp);        
    }

    fclose(rfp);
    fclose(wfp);

    A a;
    //A b(2);
    a.foo();

    void *p = &a;
    //v = p;

    STOP_INFO();    
    return 0;
}