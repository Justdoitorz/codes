#include<stdio.h>
#include<stdlib.h>
#define MAXV 100
#define LIMITLESS 9999

typedef struct
{
    int no;  //������
    int info; //����������Ϣ
} VertexType;

typedef struct
{
    int n;
    int e;//������������
    int edges[MAXV][MAXV];//�ڽӾ�����������
    VertexType vexs[MAXV]; //������Ϣ
}MGraph;

void creat(MGraph *G)
{
    int i, j, k, w;
    int start, end;
    printf("�����붥�����ͱ���:\n");
    scanf("%d%d", &(G->n), &(G->e));
    getchar();
    printf("�����붥����Ϣ:\n");
    for (i = 0; i<G->n; i++)
    {
        scanf("%d%d", &(G->vexs[i].no), &(G->vexs[i].info));
    }
    for (i = 0; i<G->n; i++)
    {
        for (j = 0; j<G->n; j++)
        {
            if (i == j)
            {
                G->edges[i][j] = 0;
            }
            else
            {
                G->edges[i][j] = LIMITLESS;
            }
        }
    }
    printf("������ ͼ�Ķ��� �ߺ�����Ȩֵ:\n");
    for (k = 0; k<G->e; k++)
    {
        scanf("%d%d%d", &start, &end, &w);
        G->edges[start][end] = w;
    }
}

void print(MGraph *G)
{
    int i, j;
    printf("��������%d, ������%d\n", G->n, G->e);
    printf("%d���������Ϣ��\n", G->n);
    for (i = 0; i<G->n; i++)
    {
        printf("%5d%5d", G->vexs[i].no, G->vexs[i].info);
    }
    printf("\n������������������\n");
    printf("\t");
    for (i = 0; i<G->n; i++)
    {
        printf("[%d]\t", i);
    }
    printf("\n");
    for (i = 0; i<G->n; i++)
    {
        printf("[%d]\t", i);
        for (j = 0; j<G->n; j++)
        {
            if (G->edges[i][j] == LIMITLESS)
            {
                printf("oo\t");
            }
            else
            {
                printf("%d\t", G->edges[i][j]);
            }
        }
        printf("\n");
    }
}

void Ppath(int path[], int i, int v) //ǰ��ݹ����·���ϵĶ���
{
    int k;
    k = path[i];
    if (k == v)
    {
        return;
    }
    Ppath(path, k, v);
    printf("%d", k);
}

void Dispath(int dist[], int path[], int s[], int n, int v)
{
    int i;
    int max = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 1)
        {
            printf("��%d��%d�����·������Ϊ:%d\t·��Ϊ:", v, i, dist[i]);
            printf("%d", v);//���·���ϵ����
            Ppath(path, i, v); //���·���ϵ��м��
            printf("%d\n", i);//���·���ϵ��յ�
            if (dist[i] > max) {
                max = dist[i];
            }
        }
        else
        {

            printf("��%d��%d������·��\n", v, i);
        }
    }


}

void Dijkstra(MGraph *g, int v)
{
    int mindis, i, j, u;
    int s[MAXV]; //��ʾ��������Ƿ�������·����
    int dist[MAXV];//��ʾ��ʼ�㵽�˶���ľ���
    int path[MAXV];//��ʾ�˵����һ������һ������
    for (i = 0; i < g->n; i++)
    {
        s[i] = 0;
        dist[i] = g->edges[v][i];
        if (g->edges[v][i] < LIMITLESS)
        {
            path[i] = v;
        }
        else
        {
            path[i] = -1;
        }
    }
    s[v] = 1;
    path[v] = 0;

    for (i = 0; i < g->n; i++)
    {
        mindis = LIMITLESS;//mindis����С���ȳ�ֵ
        for (j = 0; j < g->n; j++) //ѡȡ����s���Ҿ�����С����Ķ���u
        {
            if (s[j] == 0 && dist[j] <mindis)
            {
                mindis = dist[j];
                u = j;
            }
        }
        s[u] = 1;
        for (j = 0; j < g->n; j++)
        {
            if (s[j] == 0)
            {
                if (g->edges[u][j] < LIMITLESS&&dist[u] + g->edges[u][j] < dist[j])
                {
                    dist[j] = dist[u] + g->edges[u][j];
                    path[j] = u;
                }
            }
        }
    }
    Dispath(dist, path, s, g->n, v);
}

int main(void)
{
    MGraph *g;
    g = malloc(sizeof(MGraph));
    creat(g);
    print(g);
    Dijkstra(g, 0);
    free(g);
    return 0;
}
