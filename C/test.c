#include <stdio.h>
#include <string.h>

typedef struct {
    char str[256];
    int realCnt;
} Real_num_t;

Real_num_t tmp;

int get_len(Real_num_t *ptr)
{
    return strlen(ptr->str);
}

void output_real(Real_num_t *ptr)
{
    char *p = ptr->str;
    int i, len = get_len(ptr);

    for (i = 0; i < len-ptr->realCnt; ++i) {
        if (i < len) {
            putchar(*p++);
        } else {
            putchar('0');
        }
    }
    if (*p) {
        putchar('.');
    }

    if (len < ptr->realCnt) {
        int zero = ptr->realCnt-len;
        while (zero--) {
            putchar('0');
        }
    }
    while (*p) {
        putchar(*p++);
    }
    putchar('\n');
}

void strmulchar(int *dst, const char *str1, const char ch)
{
    int len = strlen(str1);
    const char *end;
    int carry = 0;
    int acc;

    for (end = str1+len-1; end >= str1; --end) {
        acc = (*end - '0') * ch + *dst + carry;
        *dst++ = acc%10;
        carry = acc/10;
    }
    *dst = carry;
}

void mulstr(int *dst, const char *str1, const char *str2)
{
    int i, j, len = strlen(str2);
    for (i = len-1, j = 0; i >= 0; --i, ++j) {
        strmulchar(dst+j, str1, str2[i]-'0');
    }
}

void zero_deal(Real_num_t *pr)
{
    int len = get_len(pr);
    if (!len) {
        pr->realCnt = -1;
    }
}

void cut_tail_zero(Real_num_t *pr)
{
    int len = get_len(pr);
    char *tail = pr->str + len - 1;

    while (*tail == '0') {
        pr->realCnt--;
        *tail-- = '\0';
    }
}

void result_deal(Real_num_t *pr, const int *buf, int dot, int len)
{
    char *p = pr->str;
    int i;
    if (len > 0) {
        for (i = len-1; buf[i] == 0; --i);
        for ( ; i >= 0; --i, ++p) {
            *p = buf[i] +'0';
        }
    }
    *p = '\0';
    pr->realCnt = dot;

    zero_deal(pr);
    cut_tail_zero(pr);
}

void mulreal(const Real_num_t *pr1, const Real_num_t *pr2)
{
    int buf[256] = {0};
    int dot = pr1->realCnt + pr2->realCnt;
    mulstr(buf, pr1->str, pr2->str);
    result_deal(&tmp, buf, dot, strlen(pr1->str)+strlen(pr2->str));
}

void str2realnum(Real_num_t *pr, const char *str)
{
    int dot = 0;
    int zf = 1, df = 0;
    char *p = pr->str;
    for ( ; *str;  ++str) {
        if (*str == '.') {
            df = 1;
        } else {
            if (*str != '0') {
                zf = 0;
            }

            if (zf == 0) {
                *p++ = *str;
            }

            if (df) {
                ++dot;
            }
        }
    }
    *p = '\0';
    pr->realCnt = dot;

    if (zf) {
        pr->str[0] = '0';
        pr->str[1] = '\0';
        pr->realCnt = 0;
    }

    cut_tail_zero(pr);
}

void foo(char *instr, int n)
{
    int i;
    Real_num_t muls;
    str2realnum(&muls, instr);
    memcpy(&tmp, &muls, sizeof(Real_num_t));
    for (i = 1; i < n; ++i) {
        mulreal(&tmp, &muls);
    }

    output_real(&tmp);
}

int main()
{
    char str[8];
    int n;
    while (scanf("%s%d", str, &n) != EOF) {
        foo(str, n);
    }
    return 0;
}
