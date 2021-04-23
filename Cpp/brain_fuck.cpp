#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define MaxCodeLen 1000                                     //代码最大长度
#define MaxTapeLen 3000                                     //纸带最大长度

char Code[MaxCodeLen];                                      //代码
char Tape[MaxTapeLen];                                      //纸带
int St[MaxCodeLen / 2];                                     //用来匹配括号的栈
int top = 0;                                                //栈顶
int Match[MaxCodeLen];                                      //括号匹配

int isLegalInstruction(char ch)
{
    int Ret = 0;
    switch(ch)
    {
        case '>' :
        case '<' :
        case '+' :
        case '-' :
        case '.' :
        case ',' :
        case '[' :
        case ']' : Ret = 1; break;
        case '\n' :
        case ' ' :
        case '\t' : Ret = 2; break;
        default : break;
    }
    return Ret;
}

int main()
{
    freopen("Pro.txt", "r", stdin);
    char ch;
    int len = 0;
    int cur, i, cnt;
    char* p = Tape + MaxTapeLen / 2;                        //为了方便左右移动，让纸带从中间开始
    while((ch = getchar()) != EOF)
    {
        //printf("ch = %c\n", ch);
        switch(isLegalInstruction(ch))
        {
            case 0 :
                printf("illegal instruction\n");
                return 0;
            case 1 :
                Code[len++] = ch;
                break;
            default:
                break;
        }
    }
    //Code[len] = '\0';
    //printf("%s\n", Code);
    for(i = 0; i < len; i++)
    {
        if(Code[i] == '[')
        {
            St[top++] = i;
        }
        else if(Code[i] == ']')
        {
            if(top <= 0)
            {
                printf("parentheses do not match\n");           //右括号比左括号多
                return 0;
            }
            Match[i] = St[top - 1];
            Match[St[top - 1]] = i;
            top--;
        }
    }
    if(top > 0)
    {
        printf("parentheses do not match\n");                   //左括号比右括号多
        return 0;
    }
    freopen("INPUT", "r", stdin);
    cur = 0;
    while(cur < len)
    {
        switch(Code[cur])
        {
            case '>' :
                p++;
                break;
            case '<' :
                p--;
                break;
            case '+' :
                (*p)++;
                break;
            case '-' :
                (*p)--;
                break;
            case '.' :
                printf("%c", *p);
                break;
            case ',' :
                *p = getchar();
                break;
            case '[' :
                if(!(*p))
                {
                    cur = Match[cur];
                }
                break;
            case ']' :
                cur = Match[cur] - 1;
                break;
            default:
                break;
        }
        cur++;
    }
    printf("\n");
    return 0;
}
