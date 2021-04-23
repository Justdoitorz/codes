#include <stdio.h>

int func(int n, int no, int yes, int gg)
{
	//printf("n'p = %p\n", &n);
	if (n < 2) {
        //printf("%d\n", no);
		return no;
	} else {
		return func(n-1, yes, no+yes, 0);
	}
}

int main()
{
	int ret;

	ret = func(1024*1024, 1, 1, 0);
	printf("ret = %d\n", ret);

	return 0;
}
