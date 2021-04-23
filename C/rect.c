#include <stdio.h>

typedef unsigned short   uint16_t;

typedef struct SHAPE_RECT {
    uint16_t x, y, width, height;
}shape_rect_t;


#define MAX(x, y)   (((x)>(y))?(x):(y))
#define MIN(x, y)   (((x)<(y))?(x):(y))


int rect_overlap(shape_rect_t *rectA, shape_rect_t *rectB)
{
    return (rectA->x < rectB->x + rectB->width)
        && (rectB->x < rectA->x + rectA->width)
        && (rectA->y < rectB->y + rectB->height)
        && (rectB->y < rectA->y + rectA->height);
}

uint16_t overlap_area(shape_rect_t *rectA, shape_rect_t *rectB)
{
    if (rect_overlap(rectA, rectB)) {
        return (MIN(rectA->x+rectA->width, rectB->x+rectB->width)-MAX(rectA->x, rectB->x))
              *(MIN(rectA->y+rectA->height, rectB->y+rectB->height)-MAX(rectA->y, rectB->y));
    } else {
        return 0;
    }
}



int main()
{
    shape_rect_t A = {4, 4, 4, 4}, B = {3, 3, 6, 6};

    printf("%d\n", rect_overlap(&A, &B));
    printf("%d\n", overlap_area(&A, &B));
    return 0;
}
