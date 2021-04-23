#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void preBadChar(int *badChar, const char *sub)
{
    for (int i = 0; *sub; i++, sub++) {
        badChar[*sub] = i;
    }
}

void genGoodSuffix(int *suffix, char *prefix, const char *sub, int len)
{
    int i, j, k;
    for (i = 0; i < len-1; i++){
        j = i;
        k = 0;
        while (j >= 0 && sub[j] == sub[m-1-k]) {
            j--;
            k++;
            suffix[k] = j+1;
        }

        if (j == -1) {
            prefix[k] = 1;
        }
    }
}

int Boyer_Moore(const char *str, const char *sub)
{
    int strLen = strlen(str);
    int subLen = strlen(sub);
    int *badChar = (int *)malloc(sizeof(int)*256);
    int *suffix = (int *)malloc(sizeof(int)*subLen);
    char *prefix = (char *)malloc(sizeof(char)*subLen);

    memset(badChar, 0xff, sizeof(int)*256);
    memset(suffix, 0xff, sizeof(int)*subLen);
    memset(prefix, 0, sizeof(char)*subLen);

    preBadChar(badChar, sub);


    int i = 0, j;
    while (i <= strLen-subLen) {
        for (j = subLen-1;  j >= 0 && str[i+j] == sub[j]; j--) {
        }
        if (j < 0) {
            return i;
        }

        i += j-badChar[str[i+j]];
    }
    return -1;
}


int main()
{
    int idx = Boyer_Moore("Hello world", "orld");
    printf("idx = %d\n", idx);
    return 0;
}
