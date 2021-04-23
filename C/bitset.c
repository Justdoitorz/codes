#include <stdio.h>

int func(unsigned char *arr, int bit_len, int srcData, int start, int byteidx)
{
    int idx = start;
    int pos =0;
    unsigned char *dst = arr + byteidx;
    while (bit_len--) {
		*dst |= (((srcData >> pos) & 1) << idx);
		++pos;
		++idx;
		if (idx >= 8) {
			idx = 0;
			++dst;
		}
	}
    return 0;
}

int func_f(unsigned char *arr, int bit_len,unsigned int srcData, int start, int byteidx)
{
    int idx = start;
    int pos =0;
    unsigned int *dst = (unsigned int *)arr + byteidx/4;
    //*dst |= ((srcData << (byteidx*8 + start)) ^ (1 >> (32-bit_len)))  ;
    return 0;
}


int main()
{
    unsigned char buf[8] = {0};
    func_f(buf, 32, 0x12345678, 0, 0);

    int i ;
    for (i = 0; i < 8; ++i) {
        printf("0x%02x\n", buf[i]);
    }

    return 0;
}
