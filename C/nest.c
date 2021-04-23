#include <stdio.h>

int CountDigit( int number, int digit );

int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

    return 0;
}

int CountDigit( int number, int digit )
{
    char buf[1024], *p = buf, result = 0;
    sprintf(buf, "%d", number);

    while (*p) {
        if (*p == digit+'0') {
            result++;
        }
        p++;
    }
    return 0;
}
