#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char result[1024];


char * convert_t(char *s, int numRows)
{
    int i, ridx = 0, dir = 1;
    char *p[64], *p_walk[64];

    //memset(result, 0, sizeof(result));

    if (numRows == 1) {
        strcpy(result, s);
        return result;
    }

    for (i = 0; i < numRows; ++i) {
        p_walk[i] = p[i] = (char *)calloc(128, 1);
    }

    while (*s) {
        *p_walk[ridx]++ = *s++;

        if (ridx == numRows-1) {
            dir = -1;
        } else if (ridx == 0) {
            dir = 1;
        }
        ridx += dir;
    }

    for (i = 0; i < numRows; ++i) {
        strcat(result, p[i]);
    }

    for (i = 0; i < numRows; ++i) {
        free(p[i]);
        p[i] = 0;
    }

    return result;
}

char * convert_w(char * s, int numRows)
{
    if (numRows == 1) {
        return s;
    } else {
        int len = strlen(s);
        int mod = 2*numRows - 2;
        int idx = 0, sidx, i, oft;

        sidx = 0;
        while (sidx*mod < len) {
            result[idx++] = s[sidx++*mod];
        }

        for (i = 1; i < numRows-1; ++i) {
            sidx = 0;
            oft = mod-i;
            while (sidx*mod+oft < len) {
                result[idx++] = s[sidx*mod+i];
                result[idx++] = s[sidx++*mod+oft];
            }

            if (sidx*mod+i < len) {
                result[idx++] = s[sidx*mod+i];
            }
        }

        sidx = 0;
        while (sidx*mod+numRows-1 < len) {
            result[idx++] = s[sidx++*mod+numRows-1];
        }
        result[idx] = '\0';
        return result;
    }
}


char * convert(char * s_para, int numRows){
    char *s = calloc(1024, 1);
    strcpy(s, s_para);
    unsigned long conver_len = strlen(s);
    int col = 0;
    int numRow_1 = numRows-1;
    int char_count = conver_len;

    while (char_count > 0) {
        if(numRow_1==0)
        {
            col=1;
            break;
        }
        if (col%numRow_1 == 0) {
            char_count-=numRows;
        }else{
            char_count-=1;
        }
        col++;
    }
    printf("col = %d\n", col);
    char *resultChar = (char*)malloc(numRows*col);
    memset(resultChar, 0, numRows*col);
    int isDown = 1;
    int char_index = 0;
    int resultCharIndex = 0;
    int shouldBreak = 0;
    for (int col_i = 0; col_i < col; col_i++) {
        if (col_i%numRow_1 == 0) {
            /// 正行
            for (int x = 0; x < numRows; x++) {
                if (!(char_index<conver_len)) {
                    shouldBreak=1;
                    break;
                }
                //printf("resultCharIndex = %d, char_index = %d\n", resultCharIndex, char_index);
                printf("resultCharIndex = %d\n", resultCharIndex);
                resultChar[resultCharIndex] = s[char_index];
                char_index++;

                if (x<numRows-1) {
                    resultCharIndex=resultCharIndex+col;
                }

            }
        }else{
            // 分行
            resultCharIndex=resultCharIndex-col+1;
            if (!(char_index<conver_len)) {
                shouldBreak = 1;
                break;
            }
            resultChar[resultCharIndex] = s[char_index];
            char_index++;
            if (col_i % numRow_1 == numRow_1-1) {
                resultCharIndex=resultCharIndex-col+1;
            }

        }
        if (shouldBreak) {
            break;
        }
    }

    print(resultChar, numRows, col);

    int resultChar_len = numRows*col;
    char *lastresult = (char*)malloc(conver_len+1);
    memset(lastresult, 0, conver_len);
    int  lastresultIndex = 0;
    for (int i = 0; i<resultChar_len; i++) {
        if (resultChar[i] != 0) {
            //printf("%c",resultChar[i]);
            lastresult[lastresultIndex++] = resultChar[i];
        }
    }
    lastresult[lastresultIndex]='\0';
    //printf("\n");
    return lastresult;
}

void print(char *str, int row, int col)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (*(str+i*col+j)) {
                printf("%c", *(str+i*col+j));
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


int main()
{
    char str[] = "PAYPALISHIRING\0abcdefg";

    printf("len = %d\n", sizeof(str) -1);
    char *p = convert(str, 3);
    printf("%s\n", p);


    p = convert(str, 4);
    printf("%s\n", p);

    return 0;
}
