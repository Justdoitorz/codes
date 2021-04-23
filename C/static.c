int g_val = 'g';

static int sg_val = 's';
int get_sg_val_ex(void)
{
	return sg_val;
}

int get_local(void)
{
	int local = 111;
	return local;
}

static int get_s_local(void)
{
	static int s_local = 1;
	return s_local++;
}
int get_s_local_ex(void)
{
	//return s_local;  //error
	return get_s_local();
}