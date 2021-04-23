#include <stdio.h>
#include <string.h>

void Insert (char c, int pos, char *src)
{
    int i, L;
    L = strlen(src);

    if (pos < L) {
        for (i = L; i > pos; i --)
        {
            src[i] = src[i - 1];
        }
    } else {
        pos = L;
    }

    src[pos] = c;
    src[L + 1] = '\0';
}

void DisplayFloatNum(unsigned int value,int dotLen,int decimalBit,int offset,int sign,char * retV){
    char temp[64];
    int intLen;
    int decimalValue=0;
    char * ptemp;
    int flag=0;
    const char *saveDot[8] ={"0","00","000","0000","00000","000000","0000000","00000000"};//补零个数
    const char *dotbuffer[12] ={"0.","0.0","0.00","0.000","0.0000","0.00000","0.000000","0.0000000","0.00000000","0.000000000","0.0000000000"};
    if(!dotLen && !offset){     //无符号整数
        sprintf((char*)retV, "%u", value);
    }else if(!dotLen && offset){ //有符号整数
        sprintf((char*)retV, "%u", value);
        if(sign){
            Insert('-', 0, retV);
        }
    }else if(dotLen && offset){  //有符号小数
        sprintf(temp, "%u", value);
        intLen = strlen(temp);
        if(intLen > dotLen){
            strcpy((char*)retV, temp);
            Insert('.', intLen-dotLen, retV);
        }else{
            sprintf((char*)retV, "%s%s",dotbuffer[dotLen - intLen],temp);
        }if(sign){
            //disStringData = disStringData.insert(0,'-');//
            Insert('-', 0, retV);
        }
    }else{                    //无符号小数
        sprintf(temp, "%u", value);
        intLen = strlen(temp);
        if(intLen>dotLen){
            strcpy((char*)retV, temp);
            Insert('.', intLen-dotLen, retV);
        }else{
            sprintf((char*)retV, "%s%s",dotbuffer[dotLen - intLen],temp);
        }
    }
    if(decimalBit>0){ //非默认值
        //printf(".");
        memset(temp, 0, 64);
        decimalValue = decimalBit-1;//通过手动修改的小数位数，小数位减1
        if(decimalValue > dotLen){
            strcat((char*)retV, saveDot[decimalValue-dotLen-1]);
        }else if(decimalValue < dotLen){
            ptemp = retV;
            for(int i =0; i<strlen((char*)retV);i++){
                if(*ptemp =='.'){
                    flag =i;
                }
                if(*ptemp==0)
                    break;
                ptemp++;
            }
            if(flag){
                if(decimalValue<=0){
                    strncpy(temp, (char*)retV,flag+decimalValue);//整数位，去除小数点
                }else{
                    strncpy(temp, (char*)retV,flag+1+decimalValue);//小数位，保留小数点
                }
            }else{
                strcpy(temp, (char*)retV);
            }
            memset(retV, 0, 64);
            sprintf((char*)retV, "%s",temp);
        }
    }
}



void my(unsigned int value, int sign,unsigned int xPow10,unsigned int keepDot, char *result)
{
    int idx = 0;
	//const char * const fmt[] = {"%d", "%02d", "%03d", "%04d", "%05d", "%06d", "%07d"};
	char fmt[8];


    if (sign && value) {//1st: 符号
        result[idx++] = '-';
    }
    //2nd: 将value转为字符串， 长度大于等于xPow1
    sprintf(fmt, "%%0%du", xPow10+1);
    idx += sprintf((char *)result+idx, fmt, value);

    //3rd: insert .
    if (keepDot) {
        Insert('.', idx-xPow10, result);
        idx++;
    }

    //last: 尾巴处理
    int supL = keepDot-xPow10;
    //supL > 0时，需要补0，其余情况不会执行下面循环
    for (int i = 0; i < supL; i++) {
        result[idx+i] = '0';
    }
    //printf("supL = %d\n", supL);
    result[idx + supL] = '\0';
}
void DisplayFloatNum_ex(unsigned int value,int dotLen,int decimalBit,int offset,int sign,char * retV)
{
    //printf("my(0x%08X, %d, %d, %d, buf);\r\n", value, sign, dotLen, decimalBit? decimalBit-1:dotLen);
    my(value, sign, dotLen, decimalBit ? decimalBit-1:dotLen, retV);

}

int main()
{
    char buf[1024];
    memset(buf, '%', 1024);

    my(0, 1, 0, 0, buf);
    printf("%s\n", buf);

    my(0, 1, 4, 2, buf);
    printf("%s\n", buf);

    my(0, 1, 2, 4, buf);
    printf("%s\n", buf);

    for (int i = 0; i < 10*1024*1024; i++) {
        //my(0xFFFFFFFF, 1, 3, 6, buf);
        //DisplayFloatNum_ex(0, 3, 7, 1, 1, buf);
        DisplayFloatNum(6, 4, 3, 2, 1, buf);
    }
    printf("%s\n", buf);

    my(0, 1, 6, 5, buf);
    printf("%s\n", buf);

    my(6, 1, 4, 2, buf);
    printf("%s\n", buf);

    my(123, 1, 4, 5, buf);
    printf("%s\n", buf);


    return 0;
}
