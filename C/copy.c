//#define _unicode
#include <stdio.h>

#include <TCHAR.h>
#include <locale.h>

int func(void) 
{
	int i = 5; 
	
	if (++i >= 6) {
		i = 0;
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "chs"); 
	wchar_t c = '中';
	printf("%x\n", c);
	
	int a = '中';
	
	_tprintf("中\n", c);
	
	
	return 0;
}#include <2.c>
