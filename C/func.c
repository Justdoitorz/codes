void func(int *b, int *c)
{
    for (int i = 0; i < 2; i++) {
        c[i] = b[i] = 99;
    }
}
