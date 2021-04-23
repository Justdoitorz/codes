#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


typedef struct {
    int top;
    unsigned int size;
    unsigned int element[0];
}Stack_t;


HANDLE hOut;

void stack_init(Stack_t **s, unsigned int deep)
{
    *s = calloc(sizeof(Stack_t) + sizeof(unsigned int)*deep, 1);
    (*s)->top = 0;
    (*s)->size = deep;
}

void stack_deinit(Stack_t **s)
{
    free(*s);
	*s = NULL;
}

void stack_push(Stack_t *s, unsigned int para)
{
    if (s->top < s->size) {
         s->element[s->top++] = para;
    }
}

unsigned int stack_pop(Stack_t *s)
{
    unsigned int tmp;
    if (s->top) {
        s->top --;
        tmp = s->element[s->top];
        s->element[s->top] = 0;
        return tmp;
    } else {
        return 0;
    }
}

void display_stack_all_element(Stack_t *s)
{
    int n = s->top, i;
    for (i = 0; i < n; i++) {
        printf("%d ", s->element[i]);
    }
    printf("\n");
}

void hanoi_init(Stack_t **A, Stack_t **B, Stack_t **C, unsigned int deep)
{
    stack_init(A, deep);
    stack_init(B, deep);
    stack_init(C, deep);
    for(unsigned int i = deep; i > 0; i--) {
        stack_push(*A, i);
    }
}

void hanoi_deinit(Stack_t **A, Stack_t **B, Stack_t **C)
{
    stack_deinit(A);
    stack_deinit(B);
    stack_deinit(C);
}

void hanoi_stack_to_show(Stack_t *s, COORD upper_left, int who)
{
    COORD pos;
    int level = 0;
    pos.X = upper_left.X + s->size;
    pos.Y = upper_left.Y + s->size;
    SetConsoleCursorPosition(hOut, pos);
    printf("%c", 'A'+who);
    for (int i = 0; i < s->size; i++) {
        pos.X = upper_left.X + s->size - s->element[level];
        pos.Y--;
        SetConsoleCursorPosition(hOut, pos);
        if (level < s->top) {
            for (int j = 0; j < s->element[level]; j++) {
                printf("=");
            }

        }
        printf("!");
        if (level < s->top) {
            for (int j = 0; j < s->element[level]; j++) {
                printf("=");
            }
        }
        level++;
    }

    pos.X = upper_left.X + s->size;
    pos.Y = upper_left.Y + s->size;
    SetConsoleCursorPosition(hOut, pos);
    printf("\n");
    //getConsoleCursorPosition();
   // CONSOLE_SCREEN_BUFFER_INFO scr;
    //GetConsoleScreenBufferInfo(hOut, &scr);
}

COORD get_upper_left_XY(COORD cursor, int who, int deep)
{
    COORD pos;
    pos.X = who * (deep * 2 + 1 + 5);
    pos.Y = cursor.Y;
    return pos;
}

void show_hanoi_tower(Stack_t **Hanoi)
{
    CONSOLE_SCREEN_BUFFER_INFO scr;
    COORD pos;
    GetConsoleScreenBufferInfo(hOut, &scr);
    for (int i = 0; i < 3; i++) {
        pos = get_upper_left_XY(scr.dwCursorPosition, i, Hanoi[i]->size);
        hanoi_stack_to_show(Hanoi[i], pos, i);
    }
}


int main()
{

    int n, i, arr[3] = {0, 1, 2};
    unsigned int pop_tmp;

    char pillar[] = {'A', 'B', 'C'};
    char *src, *dst;
    scanf("%d", &n);
    if (!(n & 1)) {
        arr[1] = 2;
        arr[2] = 1;
    }



    Stack_t *Hanoi[3];
    Stack_t **A = Hanoi, **B = Hanoi+1, **C = Hanoi+2;
    hanoi_init(A, B, C, n);

    SetConsoleOutputCP(437);
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    //display_stack_all_element(*A);

    show_hanoi_tower(Hanoi);

    for (i = 1; i < (1<<n); i++) {
        src = pillar + arr[(i & (i - 1)) % 3];
        dst = pillar + arr[((i | (i - 1))+1) % 3];
        printf("\n%d: %c ===> %c\n", i, *src, *dst);
        pop_tmp = stack_pop(Hanoi[arr[(i & (i - 1)) % 3]]);
        stack_push(Hanoi[arr[((i | (i - 1))+1) % 3]], pop_tmp);
        show_hanoi_tower(Hanoi);
    }

	hanoi_deinit(A, B, C);
    return 0;
}
