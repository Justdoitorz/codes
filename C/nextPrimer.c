#include <stdio.h>
#include <math.h>

typedef enum{
    OrzFalse = 0,
    OrzTrue = 1,
}boolean_e;

boolean_e isPrimer(int num)
{
    if (num <= 1) {
        return OrzFalse;
    } else if (num <= 3) {
        return OrzTrue;
    }

    if (num%6 != 1 && num%6 != 5) {
        return OrzFalse;
    }

    for (int i = 5; i <= sqrt(num); i++) {
        if (num%i == 0 || num%(i+2) == 0) {
            return OrzFalse;
        }
    }
    return OrzTrue;
}

int nextPrimer(int curr)
{
    if (curr < 2) {
        return 2;
    } else if (curr < 3) {
        return 3;
    } else {
        if (curr%6 != 1 && curr%6 != 5) {
            curr = curr%6 ? (curr/6)*6+1: curr-1;
        }

        do {
            curr += curr%6 == 1 ? 4 : 2;
        } while (!isPrimer(curr));
        return curr;
    }

}

int main()
{
    int n;

    scanf("%d", &n);

    printf("%d nextPrimer is : %d\n", n, nextPrimer(n));

    return 0;
}
