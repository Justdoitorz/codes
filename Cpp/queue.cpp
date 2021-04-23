#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define FALSE 0
#define MAX_SIZE 8

typedef int QElemType;
typedef int Status;
struct  SqQueue
{
	QElemType* base;
	int front;
	int rear;
};

void InitQueue(SqQueue& Q){
	if (!(Q.base = (QElemType*)malloc(sizeof(QElemType)*MAX_SIZE)))
		exit(0);
	Q.front = Q.rear = 0;
}

void DestroyQueue(SqQueue& Q){
	if (Q.base)
	{
		free(Q.base);
	}
	Q.base = NULL;
	Q.front = Q.rear = 0;
}

void ClearQueue(SqQueue& Q){
	Q.front = Q.rear = 0;
}

Status QueueEmpty(SqQueue& Q){
	if (Q.rear == Q.front)
	{
		return 1;
	}
	return 0;
}

Status QueueLength(SqQueue& Q){
	return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE;

}

Status GetHead(SqQueue& Q, QElemType& e){
	if (Q.rear == Q.front)
	{
		return FALSE;
	}
	return e = Q.base[Q.front];
}
void Visit(QElemType e){
	printf("%d ",e);
}

Status EnQueue(SqQueue& Q, QElemType e ){
	if ((Q.rear + 1) % MAX_SIZE == Q.front)
		return FALSE;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAX_SIZE;
	return OK;
}

Status DeQueue(SqQueue& Q, QElemType& e){
	if (Q.rear == Q.front)
		return 0;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAX_SIZE;
	return 1;
}

Status QueueTraverse(SqQueue& Q){
	int i;
	i = Q.front;

	while (i != Q.rear)
	{
		Visit(Q.base[i]);
		i = (i+1)%MAX_SIZE;
	}
	printf("\n");
	return OK;
}
int main(){
	SqQueue Q;
	QElemType E = 0;
	InitQueue(Q);

	for (int i = 5; i < 20; i++)
		EnQueue(Q, i);

	QueueTraverse(Q);

	printf("%d \n ", QueueEmpty(Q));

	DeQueue(Q, E);
	printf("出队：%d \n",E);

	QueueTraverse(Q);

	printf("长度:%d\n", QueueLength(Q));

	ClearQueue(Q);
	printf("清空后长度:%d\n", QueueLength(Q));

	DestroyQueue(Q);
	printf("\n");
	return 0;
}
