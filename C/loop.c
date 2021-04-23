#include <stdio.h>
#include <string.h>
#include <stdint.h>

int llToStr(char *dst, uint64_t value, int minLen)
{
    char buf[32];
    char *p = &buf[32-1];
    int len = 0;

	*p = '\0';
    while (value || minLen > 0) {
        *(--p)= value%10 + '0';
        value /= 10;
        minLen--;
        len++;
    }
    strcpy(dst, p);
    return len;
}


void Insert (char c, int pos, char *src)
{
    int i, L;
    L = (int)strlen((char *)src);

    if (L < pos)
    {
        src[L] = c;
        src[L + 1] = '\0';
    }
    else
    {
        for (i = L; i > pos; i --)
        {
            src[i] = src[i - 1];
        }
        src[pos] = c;
        src[L + 1] = '\0';
    }
}


void DisplayFloatNum_ex(uint64_t value, uint32_t sign,uint32_t xPow10, uint32_t keepDot, char *result)
{
    int idx = 0;
    char fmt[8];


	if (xPow10 > 16 || keepDot > 16) {
		result[0] = '\0';
		return;
	}
    if (sign && value) {//1st: 符号
        result[idx++] = '-';
    }

    //2nd: 将value转为字符串， 长度大于等于xPow1
    //sprintf(fmt, "%%0%dlld", xPow10+1);
    //idx += sprintf((char *)result+idx, fmt, value);
    idx += llToStr(result+idx, value, xPow10+1);
    //3rd: insert .
    if (keepDot) {
        Insert('.', idx-xPow10, result);
        idx++;
    }

    //last: 尾巴处理
    int supL = keepDot-xPow10;
    //supL > 0时，需要补'0'，其余情况不会执行下面循环
    for (int i = 0; i < supL; i++) {
        result[idx+i] = '0';
    }

    result[idx + supL] = '\0';
}

void DisplayFloatNum(uint64_t value,uint32_t dotLen,uint32_t decimalBit,uint32_t offset,uint32_t sign,char * retV)
{
    DisplayFloatNum_ex(value, sign, dotLen, decimalBit ? decimalBit-1:dotLen, retV);
}

int main()
{
	unsigned long long a = 12345;
    char buf[128];

    DisplayFloatNum(a, 4, 0, 0, 0, buf);

    printf("%s\n", buf);
    return 0;
}


