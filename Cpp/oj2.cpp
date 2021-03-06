#include <iostream>
using namespace std;

void SwapMemory(void * m1,void * m2, int size)
{
    char *cm1 = (char *)m1;
    char *cm2 = (char *)m2;
    char tmp;
    while (size--) {
        tmp = *cm1;
        *cm1++ = *cm2;
        *cm2++ = tmp;
    }
}

void PrintIntArray(int * a,int n)
{
	for(int i = 0;i < n; ++i)
		cout << a[i] << ",";
	cout << endl;
}

int main()
{
	int a[5] = {1,2,3,4,5};
	int b[5] = {10,20,30,40,50};
	SwapMemory(a,b,5 * sizeof(int));
	PrintIntArray(a,5);
	PrintIntArray(b,5);
	char s1[] = "12345";
	char s2[] = "abcde";
	SwapMemory(s1,s2,5);
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}
