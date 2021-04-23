#include <stdio.h>

const char weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2,};
const char CRC[] = "10X98765432";

const char *result[] = {
    "False",
    "True",
};


const char *check_ID(char *ID_Number)
{
    int i, sum = 0;
    for (i = 0; i < 17; i++) {
        sum += (ID_Number[i]-'0')*weight[i];
    }
    sum %= 11;
    return result[CRC[sum] == ID_Number[17]];
}

int main()
{
    char ID_Number[1024];
    scanf("%s", ID_Number);
    printf("%s\n", check_ID(ID_Number));
    return 0;
}
