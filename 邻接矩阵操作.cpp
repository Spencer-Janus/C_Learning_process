#include<iostream>
#include<cstdlib>
using namespace std;
#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define Notpresent 4
#define Duplicate 5
typedef struct queue
{
	int front;
	int rear;
	int maxSize;
	int *element;
}Queue;
typedef struct
{
	int **a;
	int n;
	int e;
	int noEdge;
}mGraph;
int Init(mGraph*mg,int nSize,int noEdgeValue)//邻接矩阵初始化
{
	int i,j;
	mg->n=nSize;
	mg->e=0;
	mg->noEdge=noEdgeValue;
	mg->a=(int**)malloc(nSize*sizeof(int*));
	if(!mg->a)
		return ERROR;
	for(i=0;i<mg->n;i++)
	{
		mg->a[i]=(int*)malloc(nSize*sizeof(int));
		for(j=0;j<mg->n;j++)
			mg->a[i][j]=mg->noEdge;
		mg->a[i][i]=0;
	}
	return OK;
}
void Destroy(mGraph*mg)
{
	int i;
	for(i=0;i<mg->n;i++)
		free(mg->a[i]);
	free(mg->a);
}
int Exist(mGraph*mg,int u,int v)
{
	if(u<0||v<0||u>mg->n-1||v>mg->n-1||u==v||mg->a[u][v]==mg->noEdge)
		return ERROR;
	return OK;
}
int Insert(mGraph*mg,int u,int v,int w)
{
	if(u<0||v<0||u>mg->n-1||v>mg->n-1||u==v)
		return ERROR;
	if(mg->a[u][v]!=mg->noEdge)
		return Duplicate;
	mg->a[u][v]=w;
	mg->e++;
	return OK;
}
int Remove(mGraph*mg,int u,int v)
{
	if(u<0||v<0||u>mg->n-1||v>mg->n-1||u==v)
		return ERROR;
	if(mg->a[u][v]==mg->noEdge)
		return Notpresent;
	mg->a[u][v]=mg->noEdge;
	mg->e--;
	return OK;
}
void create(Queue*Q,int mSize)
{
	Q->maxSize=mSize;
	Q->element=(int*)malloc(sizeof(int*)*mSize);
	Q->front=Q->rear=0;
}
int IsEmpty(Queue*Q)
{
	return Q->front=Q->rear;
}
int IsFULL(Queue*Q)
{
	return (Q->rear+1)%Q->maxSize==Q->front;
}
int Front(Queue*Q,int*x)
{
	if(IsEmpty(Q))
		return ERROR;
	*x=Q->element[(Q->front+1)%Q->maxSize];
	return OK;
}
int EnQueue(Queue*Q,int x)
{
	if(IsFULL(Q))
		return ERROR;
	Q->rear=(Q->rear+1)%Q->maxSize;
	Q->element[Q->rear]=x;
	return OK;
}
int DeQueue(Queue*Q)
{
	if(IsEmpty(Q))
		return ERROR;
	Q->front=(Q->front+1)%Q->maxSize;
	return OK;
}
void DFS(int x,int visited[],mGraph mg)
{
	printf("%d ",x);
	visited[x]=1;
	for(int j=0;j<mg.n;j++)
		if(mg.a[x][j]!=mg.noEdge&&!visited[j])
		{
			visited[j]=1;
			DFS(j,visited,mg);
		}
}
void DFSGraph(mGraph mg)
{
	int i;
	int*visited=(int*)malloc(mg.n*sizeof(int));
	for(i=0;i<mg.n;i++)
		visited[i]=0;
	for(i=0;i<mg.n;i++)
		if(!visited[i])
			DFS(i,visited,mg);
	free(visited);
}
void BFS(int v,int visited[],mGraph mg)
{
	int j;
	Queue q;
	create(&q,mg.n);
	visited[v]=1;
	printf("%d ",v);
	EnQueue(&q,v);
	while(!IsEmpty(&q))
	{
		Front(&q,&v);
		DeQueue(&q);
		for(j=0;j<mg.n;j++)
			if(mg.a[v][j]!=mg.noEdge&&!visited[j])
			{
				visited[j]=1;
				printf("%d ",j);
				EnQueue(&q,j);
			}
	}
}
void BFSGraph(mGraph mg)
{
	int i;
	int*visited=(int*)malloc(mg.n*sizeof(int));
	for(i=0;i<mg.n;i++)
		visited[i]=0;
	for(i=0;i<mg.n;i++)
		if(!visited[i])
			BFS(i,visited,mg);
	free(visited);
}
int main()
{
	mGraph mg;
	int n,init,a,b,c,i,j;
	printf("请输入n阶矩阵的n和初始值：\n");
	scanf("%d",&n);
	scanf("%d",&init);
	Init(&mg,n,init);
	printf("请输入插入的边及其权值：\n");
	scanf("%d %d %d",&a,&b,&c);
	Insert(&mg,a,b,c);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",mg.a[i][j]);
		printf("\n");
	}
	printf("深度遍历：\n");
	DFSGraph(mg);
	printf("\n");
	printf("宽度遍历：\n");
	BFSGraph(mg);
	printf("\n");
	Exist(&mg,a,b);
	Remove(&mg,a,b);
	printf("删边后：\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",mg.a[i][j]);
		printf("\n");
	}
	Destroy(&mg);
	return 0;
}
