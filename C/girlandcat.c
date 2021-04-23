#include <stdio.h>
#include <string.h>

enum {
    INIT_DIRECTION = 0,
    LEFT_DIRECTION,
    RIGHT_DIRECTION,
    UP_DIRECTION,
    DOWN_DIRECTION,
};

char buf[1000][1000];


void func(int *cnt, int i, int j, int n, int m, const char *name, int deep, int len, int direction)
{
    if (buf[i][j] == name[deep]) {
        if (deep < len-1) {
            if ( (j-1 >= 0) && direction != RIGHT_DIRECTION) {
                func(cnt, i, j-1, n, m, name, deep+1, len, LEFT_DIRECTION);
            }
            if ( (j+1 < m) && direction != LEFT_DIRECTION) {
                func(cnt, i, j+1, n, m, name, deep+1, len, RIGHT_DIRECTION);
            }
            if ( (i-1 >= 0) && direction != DOWN_DIRECTION) {
                func(cnt, i-1, j, n, m, name, deep+1, len, UP_DIRECTION);
            }
            if ( (i+1 < n) && direction != UP_DIRECTION) {
                func(cnt, i+1, j, n, m, name, deep+1, len, DOWN_DIRECTION);
            }
        }
        else {
            (*cnt)++;
        }
    }
    return ;
}


int get_cnt(int i, int j, int n, int m, const char *name)
{
    int cnt = 0;
    func(&cnt, i, j, n, m, name, 0, strlen(name), INIT_DIRECTION);
    return cnt;
}

int main()
{
    int times, n, m;
    int i, j, girl = 0, cat = 0;

    scanf("%d", &times);

    while (times--) {
        scanf("%d%d", &n, &m);
        getchar();
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                buf[i][j] = getchar();
            }
            getchar();
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                girl += get_cnt(i, j, n, m, "girl");
                cat += get_cnt(i, j, n, m, "cat");
            }
        }
        printf("%d %d\n", girl, cat);
    }

    return 0;
}
