#include <stdio.h>

#define Q_SIZE  100

//循环队列
typedef struct {
    int data[Q_SIZE];
    //rd 出队位置， wt入队位置
    int rd, wt;
}Queue_t;


typedef struct BTree {
    struct BTree *Lchild, *Rchild;
    int data;
}BTree_t;

//初始化队列
void init_queue(Queue_t *q)
{
    q->rd = q->wt = 0;
}

//队列空
int is_empty(Queue_t *q)
{
    return q->rd == q->wt;
}


//队列满
int is_full(Queue_t *q)
{
    return q->rd == (q->wt+1)%Q_SIZE;
}

//入队
void into_queue(Queue_t *q, int data)
{
    if (!is_full(q)) {
        q->data[q->wt++] = data;
        q->wt %= Q_SIZE;
    }
}

//出队
int out_queue(Queue_t *q)
{
    if (!is_empty) {
        int data =  q->data[q->rd++];
        q->rd %= Q_SIZE;
        return data;
    }
    return 0;
}




int main()
{

}
