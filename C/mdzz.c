#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK		1
#define ERROR	0

typedef char ElemType;
typedef int Status;


typedef struct  BiTNode {
	ElemType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode;

typedef BiTNode* BiTree;

typedef struct stack {
	BiTree t;
	int flag;
	//struct Node* node;
	struct stack* next;
	struct stack* link;
}Stack;
typedef Stack* StackNode;

typedef struct QNode {
	BiTree t;
	struct QNode* next;
}QNode;
typedef QNode* QueuePtr;

typedef struct LinkQueue{
	QueuePtr  front;
	QueuePtr  rear;
}LinkQueue;

typedef struct LinkStack {//������ջ�ṹ ����ʵ����һ�����޵ĵ�����
	ElemType data;
	struct LinkStack* next;
}LinkStack;

LinkStack* Init(LinkStack* top)
{//��ʼ��һ������ͷ������ջ  top=(LinkStack *)malloc(sizeof(LinkStack));
	top->next = NULL;  return top;
}

//1.��ջ����
void Push(StackNode *top, BiTree *tree) {//�������ջ
	Stack* p;//����ָ��
	p = (Stack*)malloc(sizeof(Stack)); //����ջ���
	p->t = *tree;//������ջ
	p->next = *top;//��ջ���ָ��ջ��
	*top = p;//ջ��Ϊ�½��
}
//2.��ջ����
void Pop(StackNode *top, BiTree *tree)
//��ջ,ջ��Ԫ�ظ�ֵ�������
{
	StackNode p = *top;//����ָ��
	if (*top == NULL)//��ջ
		*tree = NULL;
	else {   //ջ�ǿ�
		*tree = (*top)->t;//ջ�����Ԫ�ظ�ֵ�������
		*top = (*top)->next;//ջ��ָ����һ������,��ɳ�ջ
		free(p);//�ͷ�ջ�����ռ�
	}
}

//3.��ʼ�������к���
Status InitQueue(LinkQueue *Q) {
	//����һ�������ӱ�ͷ���Ŀ�������Q
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front) return ERROR;
	Q->front->next = NULL;
	return OK;
}

//4.���Ӻ���
Status EnQueue(LinkQueue Q, BiTree e) {
	//��Ԫ��e���뵽��ͷ����������Q��
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) return ERROR;
	p->t = e; p->next = NULL;
	Q.rear->next = p; Q.rear = p;
	return OK;
}

//5.���Ӻ���
Status DeQueue(LinkQueue Q, BiTree *e) {
	//�����в���,�����Ԫ�س�����,��e������ֵ,����k,���򷵻� ERROR
	QueuePtr p;
	if (Q.rear - Q.front)
		return ERROR;
	p - Q.front->next;
	*e = p->t;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}

//6.�������,�ݹ鷽��
void re_PreOrder(BiTNode* tree) {
	if (tree != NULL) { //��Ϊ������ʱ�ݹ����
		printf("%c", tree->data);//���ʸ����
		re_PreOrder(tree->lchild);//�������������
		re_PreOrder(tree->rchild);//�������������
	}
}
//7.�������,�ݹ鷽��
void re_MidOrder(BiTNode* tree) {
	if (tree != NULL) {//��Ϊ������ʱ�ݹ����
		re_MidOrder(tree->lchild);//�������������
		printf("%c", tree->data);//���ʸ����
		re_MidOrder(tree->rchild);//�������������
	}
}
//8.�������,�ݹ鷽��
void re_PostOrder(BiTNode* tree) {
	if (tree != NULL) {//��Ϊ������ʱ�ݹ����
		re_PostOrder(tree->lchild);//�Ⱥ������������
		re_PostOrder(tree->rchild);//�ٺ������������
		printf("%c", tree->data);//�����ʸ����
	}
}
//9.�������,������ջ�ĵ�������
void st_PreOrder(BiTNode* tree)
{
	StackNode top;//ջ��ָ��
	top = NULL;//��ʼ��Ϊ��ջ
    while (tree != NULL || top != NULL) {  //ѭ������Ϊ��������δ������,��ջ�ǿ�
        if (tree) {
            Push(&top, &tree->rchild);
            Push(&top, &tree->lchild);
            //Push(&top, &tree);
            printf("%c", tree->data);

        }
        if (top != NULL)
        {
            Pop(&top, &tree);
        }
    }
}



//10.�������,������ջ�ĵ�������
void st_MidOrder(BiTNode* tree)
{
	StackNode top;//ջ��ָ��
	top = NULL;//��ʼ��Ϊ��ջ
    while (tree != NULL || top != NULL) {  //ѭ������Ϊ��������δ������,��ջ�ǿ�
        while (tree != NULL) {
            Push(&top, &tree);
            tree = tree->lchild;
        }
        if (top != NULL)
        {
            Pop(&top, &tree);
            printf("%c", tree->data);
            tree = tree->rchild;
        }
    }
}
//�������,��������ջ���ʹ�����
void st_PostOrder(BiTree tree)
{
	StackNode top;//ջ��ָ��
	top = NULL;//��ʼ��Ϊ��ջ
    while (tree != NULL || top != NULL) {  //ѭ������Ϊ��������δ������,��ջ�ǿ�
        if (tree) {
            Push(&top, &tree);
            Push(&top, &tree->rchild);
            Push(&top, &tree->lchild);
        }
        if (top != NULL)
        {     //����������ջ����,��ջ�ǿ�
            Pop(&top, &tree);//������ջ
            if (tree) {
                printf("%c", tree->data);
            }
            if (top != NULL) {
                Pop(&top, &tree);
            }
        }
    }
}
//12.�������Ĳ������
void LevelOrder(BiTNode* root) {
	LinkQueue Q;
	BiTree P = root;
	if (root != NULL) {
		InitQueue(&Q);
		EnQueue(Q,P);
		while (Q.front != Q.rear) {
			//ѭ������Ϊ�ӷǿ�
			DeQueue(Q, &P);
            printf("%c", P->data);
            if (P->lchild != NULL) EnQueue(Q, P->lchild);
            if (P->rchild != NULL) EnQueue(Q, P->rchild);
        }

	}//While
	printf("\n");
}//if
//LevelOrder
//13.����������
void createBitree(BiTree *T)
{//����ݹ������ʽ����һ�ö�����
	char ch;
	scanf("\n%c", &ch);//���������ֵ
	if (ch == '#')
		//��ֹ��
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));//���������
		if (!*T)
			exit(-1);
		(*T)->data = ch;
		printf("\n����%c�������ӽ��(#����):", (*T)->data);//�����������������
		createBitree(&(*T)->lchild);
		printf("\n������%c�������ӽ��(#����):", (*T)->data);//�ȱ�������������
		createBitree(&(*T)->rchild);
	}
}
//14.�����ű�ʾ��ʽ���������
void OutputBiTree(BiTree T)
{//�����������ű�ʾ�Ķ�����
    //printf("T = %p\n", T);
	if (T != NULL)//��ֹ��
		printf("%c", T->data);//���ʸ����
    else {
        return;
    }
    //printf("T2 = %p\n", T);
	if (T->lchild != NULL || T->rchild != NULL)
	{
		printf("(");//���ĺ�����Բ���Ŷ���
		OutputBiTree(T->lchild);//����������������
		if (T->rchild != NULL)
			printf(", ");//�������Һ����ԡ�,���ָ�
		OutputBiTree(T->rchild);//����������������
		printf(")");//���ĺ�����Բ���Ŷ���
	}
}
//(2)������
//������ʵ���˶�����������������,�������,��������ĵݹ�͵�������
int main()
{
	BiTNode* proot;//������
	proot = NULL;//��ʼ��Ϊ����
	printf("������Ԫ��(#����):");
	createBitree(&proot);//����������
	printf("\n(1)�����������ɹ�,�����ű�ʾ��ʽ���:\n\t");
	OutputBiTree(proot);


	printf("\n(2)�������,�ݹ鷽��\n\t");
	re_PreOrder(proot);//�������,�ݹ鷽��

	printf("\n(3)�������,�ݹ鷽��\n\t");
	re_MidOrder(proot);//�������,�ݹ鷽��
	printf("\n(4)�������,�ݹ鷽��\n\t");
	re_PostOrder(proot);//�������,�ݹ鷽��
	printf("\n(5)�������,����ջ�ĵ�������\n\t");
	st_PreOrder(proot);
	//�������,��������ջ�ĵ�������
	printf("\n(6)�������,����ջ�ĵ�������\n\t");
	st_MidOrder(proot);//�������,��������ջ�ĵ�������
	printf("\n(7)�������,����ջ�ĵ�������\n\t");
	//st_PostOrder(proot);//�������,��������ջ�ĵ�������
	printf("\n(8)�������,�����еĵ�������\n\t");
	LevelOrder(proot);//�������,��������ջ�ĵ�������

	return 0;
}
