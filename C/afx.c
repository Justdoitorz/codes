#include <stdio.h>

int main()
{
int t;
scanf("%d",&t);
while(t--)
{
	int a,b,c,m,n,d=0;
	scanf("%d%d%d%d%d",&a,&b,&c,&n,&m);
	for(a=0;a<=m;a++)
	{
	for(b=0;b<=m-a;b++)
	{
	for(c=0;c<=m-a-b;c++)
	{
	if(a+b+c==n&&1*a+2*b+5*c==m)
	{
	d++;
	}
	}
	}
	}
	printf("%d\n",d);
}
return 0;
}
