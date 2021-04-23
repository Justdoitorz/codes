#include<stdio.h>
#include<stdlib.h>
#define MAXV 100
#define LIMITLESS 9999

typedef struct
{
    int no;  //顶点编号
    int info; //顶点其他信息
} VertexType;

typedef struct
{
    int n;
    int e;//定点数，边数
    int edges[MAXV][MAXV];//邻接矩阵的数组表现
    VertexType vexs[MAXV]; //顶点信息
}MGraph;

void creat(MGraph *G)
{
    int i, j, k, w;
    int start, end;
    printf("请输入顶点数和边数:\n");
    scanf("%d%d", &(G->n), &(G->e));
    getchar();
    printf("请输入顶点信息:\n");
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
    printf("请输入 图的顶点 边和它的权值:\n");
    for (k = 0; k<G->e; k++)
    {
        scanf("%d%d%d", &start, &end, &w);
        G->edges[start][end] = w;
    }
}

void print(MGraph *G)
{
    int i, j;
    printf("顶点数：%d, 边数：%d\n", G->n, G->e);
    printf("%d个顶点的信息：\n", G->n);
    for (i = 0; i<G->n; i++)
    {
        printf("%5d%5d", G->vexs[i].no, G->vexs[i].info);
    }
    printf("\n各个顶点的连接情况：\n");
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

void Ppath(int path[], int i, int v) //前向递归查找路径上的顶点
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
            printf("从%d到%d的最短路径长度为:%d\t路径为:", v, i, dist[i]);
            printf("%d", v);//输出路径上的起点
            Ppath(path, i, v); //输出路径上的中间点
            printf("%d\n", i);//输出路径上的终点
            if (dist[i] > max) {
                max = dist[i];
            }
        }
        else
        {

            printf("从%d到%d不存在路径\n", v, i);
        }
    }


}

void Dijkstra(MGraph *g, int v)
{
    int mindis, i, j, u;
    int s[MAXV]; //表示这个顶点是否存入最短路线中
    int dist[MAXV];//表示起始点到此顶点的距离
    int path[MAXV];//表示此点的上一步是哪一个顶点
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
        mindis = LIMITLESS;//mindis置最小长度初值
        for (j = 0; j < g->n; j++) //选取不在s中且具有最小距离的顶点u
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
