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

typedef struct LinkStack {//定义链栈结构 ，其实质是一个受限的单链表
	ElemType data;
	struct LinkStack* next;
}LinkStack;

LinkStack* Init(LinkStack* top)
{//初始化一个带有头结点的链栈  top=(LinkStack *)malloc(sizeof(LinkStack));
	top->next = NULL;  return top;
}

//1.进栈函数
void Push(StackNode *top, BiTree *tree) {//树结点入栈
	Stack* p;//工作指针
	p = (Stack*)malloc(sizeof(Stack)); //申请栈结点
	p->t = *tree;//根结点进栈
	p->next = *top;//新栈结点指向栈顶
	*top = p;//栈顶为新结点
}
//2.出栈函数
void Pop(StackNode *top, BiTree *tree)
//出栈,栈内元素赋值给树结点
{
	StackNode p = *top;//工作指针
	if (*top == NULL)//空栈
		*tree = NULL;
	else {   //栈非空
		*tree = (*top)->t;//栈顶结点元素赋值给树结点
		*top = (*top)->next;//栈顶指向下一个链接,完成出栈
		free(p);//释放栈顶结点空间
	}
}

//3.初始化链队列函数
Status InitQueue(LinkQueue *Q) {
	//创建一个带附加表头结点的空链队列Q
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front) return ERROR;
	Q->front->next = NULL;
	return OK;
}

//4.进队函数
Status EnQueue(LinkQueue Q, BiTree e) {
	//将元素e插入到带头结点的链队列Q中
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) return ERROR;
	p->t = e; p->next = NULL;
	Q.rear->next = p; Q.rear = p;
	return OK;
}

//5.出队函数
Status DeQueue(LinkQueue Q, BiTree *e) {
	//若队列不空,则队首元素出队列,用e返回其值,返回k,否则返回 ERROR
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

//6.先序遍历,递归方法
void re_PreOrder(BiTNode* tree) {
	if (tree != NULL) { //不为空子树时递归遍历
		printf("%c", tree->data);//访问根结点
		re_PreOrder(tree->lchild);//先序遍历左子树
		re_PreOrder(tree->rchild);//先序遍历右子树
	}
}
//7.中序遍历,递归方法
void re_MidOrder(BiTNode* tree) {
	if (tree != NULL) {//不为空子树时递归遍历
		re_MidOrder(tree->lchild);//先序遍历左子树
		printf("%c", tree->data);//访问根结点
		re_MidOrder(tree->rchild);//先序遍历右子树
	}
}
//8.后序遍历,递归方法
void re_PostOrder(BiTNode* tree) {
	if (tree != NULL) {//不为空子树时递归遍历
		re_PostOrder(tree->lchild);//先后序遍历左子树
		re_PostOrder(tree->rchild);//再后序遍历右子树
		printf("%c", tree->data);//最后访问根结点
	}
}
//9.先序遍历,采用链栈的迭代方法
void st_PreOrder(BiTNode* tree)
{
	StackNode top;//栈顶指针
	top = NULL;//初始化为空栈
    while (tree != NULL || top != NULL) {  //循环条件为二叉树还未遍历完,或栈非空
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



//10.中序遍历,采用链栈的迭代方法
void st_MidOrder(BiTNode* tree)
{
	StackNode top;//栈顶指针
	top = NULL;//初始化为空栈
    while (tree != NULL || top != NULL) {  //循环条件为二叉树还未遍历完,或栈非空
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
//后序遍历,采用链接栈的送代方法
void st_PostOrder(BiTree tree)
{
	StackNode top;//栈顶指针
	top = NULL;//初始化为空栈
    while (tree != NULL || top != NULL) {  //循环条件为二叉树还未遍历完,或栈非空
        if (tree) {
            Push(&top, &tree);
            Push(&top, &tree->rchild);
            Push(&top, &tree->lchild);
        }
        if (top != NULL)
        {     //左子树点入栈结束,且栈非空
            Pop(&top, &tree);//树结点出栈
            if (tree) {
                printf("%c", tree->data);
            }
            if (top != NULL) {
                Pop(&top, &tree);
            }
        }
    }
}
//12.二叉树的层序遍历
void LevelOrder(BiTNode* root) {
	LinkQueue Q;
	BiTree P = root;
	if (root != NULL) {
		InitQueue(&Q);
		EnQueue(Q,P);
		while (Q.front != Q.rear) {
			//循环条件为队非空
			DeQueue(Q, &P);
            printf("%c", P->data);
            if (P->lchild != NULL) EnQueue(Q, P->lchild);
            if (P->rchild != NULL) EnQueue(Q, P->rchild);
        }

	}//While
	printf("\n");
}//if
//LevelOrder
//13.创建二叉树
void createBitree(BiTree *T)
{//先序递归遍历方式创建一棵二叉树
	char ch;
	scanf("\n%c", &ch);//输入根结点的值
	if (ch == '#')
		//终止项
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));//创建根结点
		if (!*T)
			exit(-1);
		(*T)->data = ch;
		printf("\n输入%c结点的左子结点(#表无):", (*T)->data);//先序遍历创建左子树
		createBitree(&(*T)->lchild);
		printf("\n请输入%c结点的右子结点(#表无):", (*T)->data);//先遍历创建右子树
		createBitree(&(*T)->rchild);
	}
}
//14.以括号表示格式输出二叉树
void OutputBiTree(BiTree T)
{//先序递输出括号表示的二叉树
    //printf("T = %p\n", T);
	if (T != NULL)//终止项
		printf("%c", T->data);//访问根结点
    else {
        return;
    }
    //printf("T2 = %p\n", T);
	if (T->lchild != NULL || T->rchild != NULL)
	{
		printf("(");//根的孩子用圆括号对括
		OutputBiTree(T->lchild);//先序遍历输出左子树
		if (T->rchild != NULL)
			printf(", ");//根的左右孩子以“,”分隔
		OutputBiTree(T->rchild);//先序遍历输出右子树
		printf(")");//根的孩子用圆括号对括
	}
}
//(2)主函数
//本程序实现了二叉查找树的先序遍历,中序遍历,后序遍历的递归和迭代方法
int main()
{
	BiTNode* proot;//定义树
	proot = NULL;//初始化为空树
	printf("输入结点元素(#表无):");
	createBitree(&proot);//创建二叉树
	printf("\n(1)二叉树创建成功,其括号表示格式输出:\n\t");
	OutputBiTree(proot);


	printf("\n(2)先序遍历,递归方法\n\t");
	re_PreOrder(proot);//先序遍历,递归方法

	printf("\n(3)中序遍历,递归方法\n\t");
	re_MidOrder(proot);//中序遍历,递归方法
	printf("\n(4)后序遍历,递归方法\n\t");
	re_PostOrder(proot);//后序遍历,递归方法
	printf("\n(5)先序遍历,链接栈的迭代方法\n\t");
	st_PreOrder(proot);
	//先序遍历,采用链接栈的迭代方法
	printf("\n(6)中序遍历,链接栈的迭代方法\n\t");
	st_MidOrder(proot);//中序遍历,采用链接栈的迭代方法
	printf("\n(7)后序遍历,链接栈的迭代方法\n\t");
	//st_PostOrder(proot);//后序遍历,采用链接栈的迭代方法
	printf("\n(8)层序遍历,链队列的迭代方法\n\t");
	LevelOrder(proot);//后序遍历,采用链接栈的迭代方法

	return 0;
}
