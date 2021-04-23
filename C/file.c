#include <stdio.h>

typedef struct _iobuf
{
	char*	_ptr;
	int	_cnt;
	char*	_base;
	int	_flag;
	int	_file;
	int	_charbuf;
	int	_bufsiz;
	char*	_tmpfname;
}

void print_fp_info(FILE *fp)
{
    printf("_ptr = %p\n", fp->_ptr);
    printf("_cnt = %d\n", fp->_cnt);
    printf("_base = %p\n", fp->_base);
    printf("_flag = %x\n", fp->_flag);
    printf("_file = %d\n", fp->_file);
    printf("_charbuf = %d\n", fp->_charbuf);
    printf("_bufsiz = %d\n", fp->_bufsiz);
    printf("_tmpfname = %s\n", fp->_tmpfname);
}
int main()
{
    FILE *fp;
    fp = fopen("file.c", "rb+");
    print_fp_info(fp);

    return 0;
}
