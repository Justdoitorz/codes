#include <stdio.h>
#include <math.h>

int main()
{
    int weight, choose;
    double price, total;
    scanf("%d%d", &weight, &choose);

    if (choose == 1) {
        price = 4.5;
    } else {
        price = 7.0;
    }

    if (weight <= 1000) {
        total = price*(weight/200 + !!(weight%200));
    } else {
        total = price*5;
        weight -= 1000;
        price += 1.5;
        total += price*(weight/300 + !!(weight%300));
    }

    printf("%.2f", total);
    return 0;
}
