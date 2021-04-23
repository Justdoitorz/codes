#include <stdio.h>

int func(int a) 
{
	a += 1;
	return a;
}

int main()
{
	int a = 1;
	
	printf("a = %d\n", a);
	func(a);
	printf("a = %d\n", a);
	
	func(1);

	return 0;
}