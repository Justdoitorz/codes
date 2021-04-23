#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROE 0
#define OVERFLOW -2
typedef int Status;
typedef int QElemType;
typedef struct Node
{
    QElemType data;
    struct Node *next;
} QNode;
/* ����ʽ���е�ͷβ�ڵ�ָ�붨���Ϊһ�������Ľṹ��,�����������ڵ�ʱռ�ù���Ŀռ� */
typedef struct
{
    QNode *front;
    QNode *rear;
} LinkQueue;
Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QNode *)malloc(sizeof(QNode));
    if (!Q->front)
        exit(OVERFLOW);
    Q->rear->next = NULL; //rear.nextʼ��ָ��NULL,ͷ���front����
    return OK;
}
Status InQueue (LinkQueue *Q, int elem)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    p->data = elem;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}
Status PrintQueue(LinkQueue Q)
{
    QNode *p;
    p = Q.front->next;
    printf("the queue is:");
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    return OK;
}
Status OutQueue(LinkQueue *Q)
{
    QNode *p;
    int i;
    printf("\nthe number of out queue:");
    scanf("%d", &i);
    while(i != 0)
    {
        p = Q->front;
        Q->front = Q->front->next;
        free(p);
        i--;
    }
    p = NULL;
    return OK;
}
Status EmptyQueue(LinkQueue Q)
{
    if (Q.front->next == NULL)
        printf("\nThe queue is empty!\n");
    return OK;
}
int main()
{
    LinkQueue queue;
    InitQueue(&queue);
    int elem;
    printf("input:");
    while(scanf("%d", &elem) != EOF)
    {
        InQueue(&queue, elem);
    }
    PrintQueue(queue);
    OutQueue(&queue);
    PrintQueue(queue);
    EmptyQueue(queue);
    return OK;
}
