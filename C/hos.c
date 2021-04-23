#include <stdio.h>
#include <string.h>

int PAI[10000];
int main()
{
    int N, F, i, k, cnt, maxi = 0;
    double max = 0.0, l, r, mid;
    scanf("%d%d", &N, &F);

    for (i = 0; i < N; ++i) {
        scanf("%d", PAI+i);
        PAI[i] *= PAI[i];
        if (PAI[i] > maxi) {
            maxi = PAI[i];
        }
    }

    l = 0.0;
    r = maxi;
    while (r-l > 0.000001) {
        mid = (l+r)/2;
        cnt = 0;
        for (k = 0; k < N; ++k) {
            cnt += (int)(PAI[k]/mid);
            if (cnt >= F+1) {
                break;
            }
        }

        if (cnt >= F+1) {
            max = l = mid;
        } else {
            r = mid;
        }
    }

    printf("%.3f", max*3.141592653589793);

    return 0;
}
