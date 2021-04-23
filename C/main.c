#include <stdio.h>

extern int g_val;
extern int get_sg_val_ex(void);
extern int get_local(void);
extern int get_s_local_ex(void);
int main()
{
	int i;
	
	for (i = 0; i < 3; i++) {
		printf("g_val = %d\n", g_val);
	//	printf("sg_val = %d\n", sg_val);   //error
		printf("get_sg_val_ex() = %d\n", get_sg_val_ex());
		printf("get_local() = %d\n", get_local());
	//	printf("get_s_local() = %d\n", get_s_local()); //error
		printf("get_s_local_ex() = %d\n", get_s_local_ex());
	}

	return 0;
}