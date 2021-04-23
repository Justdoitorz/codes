#include <stdio.h>

int mySqrt(int x)
{
	long long  l = 0, r = x, m;

	while (l <= r) {
		m = (l+r)/2;
		if (m*m == x) {
			return m;
		} else if (m*m > x) {
			r = m-1;
		} else {
			l = m+1;
		}
	}
	return m;
}

int main()
{
    printf("%d", mySqrt(8));
    return 0;
}
