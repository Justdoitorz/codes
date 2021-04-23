#include <stdio.h>

int func(int a) 
{
	int b = 0x10203495;

	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);


	return a|b;
}

int main()
{
	int arr[] = {1, 2, 3, 4};

	printf("func() = %x\n", func(3));

	return 0;
}