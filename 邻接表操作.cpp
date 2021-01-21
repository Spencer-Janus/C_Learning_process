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
typedef struct eNode
{
	int adjVex;
	int w;
	struct eNode*nextArc;
}eNode;
typedef struct
{
	int n;
	int e;
	eNode**a;
}LGraph;
int Init(LGraph*lg,int nSize)
{
	int i;
	lg->n=nSize;
	lg->e=0;
	lg->a=(eNode**)malloc(nSize*sizeof(eNode*));
	if(!lg->a)
		return ERROR;
	else
	{
		for(i=0;i<lg->n;i++)
			lg->a[i]=NULL;
		return OK;
	}
}
void Destroy(LGraph*lg)
{
	int i;
	eNode*p,*q;
	for(i=0;i<lg->n;i++)
	{
		p=lg->a[i];
		q=p;
		while(p)
		{
			p=p->nextArc;
			free(q);
			q=p;
		}
	}
	free(lg->a);
}
int Exist(LGraph*lg,int u,int v)
{
	eNode*p;
	if(u<0||v<0||u>lg->n-1||v>lg->n-1||u==v)
		return ERROR;
	p=lg->a[u];
	while(p&&p->adjVex!=v)
		p=p->nextArc;
	if(!p)
		return ERROR;
	else
		return OK;
}
int Insert(LGraph*lg,int u,int v,int w)
{
	eNode*p;
	if(u<0||v<0||u>lg->n-1||v>lg->n-1||u==v)
		return ERROR;
	if(Exist(lg,u,v))
		return Duplicate;
	p=(eNode*)malloc(sizeof(eNode));
	p->adjVex=v;
	p->w=w;
	p->nextArc=lg->a[u];
	lg->a[u]=p;
	lg->e++;
	return OK;
}
int Remove(LGraph*lg,int u,int v)
{
	eNode*p,*q;
	if(u<0||v<0||u>lg->n-1||v>lg->n-1||u==v)
		return ERROR;
	p=lg->a[u],q=NULL;
	while(p&&p->adjVex!=v)
	{
		q=p;
		p=p->nextArc;
	}
	if(!p)
		return Notpresent;
	if(q)
		q->nextArc=p->nextArc;
	else
		lg->a[u]=p->nextArc;
	free(p);
	lg->e--;
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
void DFS(int v,int visited[],LGraph g)
{
	eNode*w;
	printf("%d ",v);
	visited[v]=1;
	for(w=g.a[v];w;w=w->nextArc)
		if(!visited[w->adjVex])
			DFS(w->adjVex,visited,g);
}
void DFSGraph(LGraph g)
{
	int i;
	int *visited=(int*)malloc(g.n*sizeof(int));
	for(i=0;i<g.n;i++)
		visited[i]=0;
	for(i=0;i<g.n;i++)
		if(!visited[i])
			DFS(i,visited,g);
	free(visited);
}
void BFS(int v,int visited[],LGraph g)
{
	eNode*w;
	Queue q;
	create(&q,g.n);
	visited[v]=1;
	printf("%d ",v);
	EnQueue(&q,v);
	while(!IsEmpty(&q))
	{
		Front(&q,&v);
		DeQueue(&q);
		for(w=g.a[v];w;w=w->nextArc)
			if(!visited[w->adjVex])
			{
				visited[w->adjVex]=1;
				printf("%d ",w->adjVex);
				EnQueue(&q,w->adjVex);
			}
	}
}
void BFSGraph(LGraph g)
{
	int i;
	int*visited=(int*)malloc(g.n*sizeof(int));
	for(i=0;i<g.n;i++)
		visited[i]=0;
	for(i=0;i<g.n;i++)
		if(!visited[i])
			BFS(i,visited,g);
	free(visited);
}
int main()
{
	LGraph lg;
	int n,a,b,c,i;
	printf("输入n：\n");
	scanf("%d",&n);
	Init(&lg,n);
	printf("请输入要插入的边及其权值：\n");
	scanf("%d %d %d",&a,&b,&c);
	Insert(&lg,a,b,c);

	printf("深度：\n");
	DFSGraph(lg);
	printf("\n");
	printf("宽度：\n");
	BFSGraph(lg);
	printf("\n");
	Exist(&lg,a,b);
	Remove(&lg,a,b);
	printf("移除边后：\n");
	printf("深度：\n");
	DFSGraph(lg);
	printf("\n");
	printf("宽度：\n");
	BFSGraph(lg);
	Destroy(&lg);
	return 0;
}