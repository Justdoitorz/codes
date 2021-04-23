#include <stdlib.h>
#include <stdio.h>
typedef int datatype;
typedef struct link_node{
   datatype info;
   struct link_node *next;
}node;
typedef node *linklist;



linklist creatbystack()
{
  linklist head,s;
  datatype x;
  head=(linklist)malloc(sizeof(node));
  head->next=NULL;
  printf("���������������У�\n");
  scanf("%d",&x);
  while (x!=0)
  {
    s=(linklist)malloc(sizeof(node));
    s->info=x;
    s->next=head->next;
    head->next=s;
    scanf("%d",&x);
  }
  return head;
}

linklist creatbyqueue()
{
  linklist head,r,s;
  datatype x;
  head=(linklist)malloc(sizeof(node));
  head->next=r=NULL;
  printf("�����������������У�\n");
  scanf("%d",&x);
  while(x!=0)
  {
    s=(linklist)malloc(sizeof(node));
    s->info=x;
    if(head->next==NULL)
         head->next=s;
     else
         r->next=s;
    r=s;
    scanf("%d",&x);
  }
   if (r) r->next=NULL;
  return head;
}

void print(linklist head)
{
  linklist p;
  int i=0;
  p=head->next;
  printf("List is:\n");
  while(p)
  {
    printf("%5d",p->info);
    p=p->next;
    i++;
    if (i%10==0) printf("\n");
  }
  printf("\n");
}

void delList(linklist head)
{
  linklist p=head->next;
  while(p)
  {
    head->next=p->next;
    free(p);
    p=head->next;
  }
}


void delx(linklist head,datatype x)    //������void����Ϊ������ܷ���ֵ��Ҫ��linklist�� ��ͷ�ļ�ʱ if������������==�����жϣ�
{
    linklist p,pre=head;
    p=head->next;
    if(!p)
    {
        printf("��ͷ���ĵ������ǿյ�");
      // return head;
    }
    while(p&&p->info!=x)
    {
        pre=p;
        p=p->next;
    }
    if(p)
    {
        pre->next=p->next;
        free(p);

    }

}
int main()
{
    datatype x;
    linklist head;
    head=creatbyqueue();
    print(head);
    printf("������Ҫɾ����ֵ��");
    scanf("%d",&x);
    delx(head,x);
    print(head);
    delList(head);
    return 0;
}

