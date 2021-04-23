#include <stdio.h>

#define Q_SIZE  100

//ѭ������
typedef struct {
    int data[Q_SIZE];
    //rd ����λ�ã� wt���λ��
    int rd, wt;
}Queue_t;


typedef struct BTree {
    struct BTree *Lchild, *Rchild;
    int data;
}BTree_t;

//��ʼ������
void init_queue(Queue_t *q)
{
    q->rd = q->wt = 0;
}

//���п�
int is_empty(Queue_t *q)
{
    return q->rd == q->wt;
}


//������
int is_full(Queue_t *q)
{
    return q->rd == (q->wt+1)%Q_SIZE;
}

//���
void into_queue(Queue_t *q, int data)
{
    if (!is_full(q)) {
        q->data[q->wt++] = data;
        q->wt %= Q_SIZE;
    }
}

//����
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
