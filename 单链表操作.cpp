#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef int Status;
#define ERROR 0
#define OK 1
#define Overflow 2/*上溢*/
#define Underflow 3/*下溢*/
#define Notpresent 4/*元素不存在*/
#define Duplicate 5/*有重复*/

typedef struct node
{
	ElemType element;
	struct node *link;
}node;
typedef struct 
{
   struct node *head;
	int n;
}headerList;
Status Init(headerList*L)   /*单链表的初始化*/
{
	L->head=(node*)malloc(sizeof(node));/*生成表头结点*/
	if(!L->head)
	return ERROR;
	L->head->link=NULL;/*设置单链表为空表*/
	L->n=0;
	return OK;
}
Status Find(headerList L,int i,ElemType *x) /*单链表查找*/
{
	node *p;
	int j;
	if(i<0||i>L.n-1)             /*越界检查*/
		return ERROR;
	p=L.head->link;
	for(j=0;j<i;j++)            /*查找ai*/
		p=p->link;
    *x=p->element;       
	return OK;
}
Status Insert(headerList *L, int i, ElemType x)/*单链表插入*/
{
	node*p, *q;
	int j;
	if (i<-1 || i>L->n - 1)            
		return ERROR;
	p = L->head;
	for (j = 0; j <= i; j++)          /*从头结点开始查找*/
		p = p->link;
	q = (node*)malloc(sizeof(node));/*生成新结点q*/
	q->element = x;
	q->link = p->link;           /*新结点插在p指针之后*/
	p->link = q;
	L->n++;
	return OK;
}
Status Delete(headerList*L,int i)/*单链表删除*/

{
	int j;
	node*p,*q;
	if(!L->n)
	return ERROR;
	if(i<0||i>L->n-1)
		return ERROR;
	q=L->head;
	for(j=0;j<i;j++)
		q=q->link;
	p=q->link;
	q->link=p->link;              /*删除p所指结点*/
	free(p);                    /*释放p所指存储空间*/
	L->n--;
	return OK;
}
Status Output(headerList *L)  /*单链表输出*/
{
	node*p;
	if(!L->n)
		return ERROR;
	p=L->head->link;
	while(p)
	{
		printf("%d ",p->element);
		p=p->link;
	}
	return OK;
}
void Destroy(headerList *L)/*单链表撤销*/
{
	node*p;
	while(L->head)
	{
		p=L->head->link;
		free(L->head);
		L->head=p;
	}
}
void converse(headerList *L)         /*单链表逆置*/
{  
    node *p,*q;  
    p=L->head->link;  
    L->head->link=NULL;  
    while(p)  
    {  
        q=p;  
        p=p->link;          /*向后移动一个位置*/
        q->link=L->head->link;  /*头插*/
        L->head->link=q;  
    }  
}
void sort(headerList *L)            /*单链表交换法排序*/
{
	node*p,*q;
	int temp;
	for(p=L->head->link;p!=NULL;p=p->link) 
	{
		for(q=p->link;q!=NULL;q=q->link)
		{
			if(p->element<q->element)
			{
				temp=q->element;
				q->element=p->element;
				p->element=temp;
			}
		}
	}
}
void main()
{
	int i;
	int x;
	headerList list;
	Init(&list);
	for(i=0;i<12;i++)
		Insert(&list,i-1,i*i);
	printf("the linklist is:");
	Output(&list);
	Delete(&list,0);/*删除下标为0的元素*/
	printf("\nthe linklist is:");
	Output(&list);
	Find(list,0,&x); /*查找下标为0的元素*/
	printf("\nthe value is:");
	printf("%d\n ",x);
	printf("\n排序后:");
	sort(&list);
	Output(&list);
	printf("\n逆置后:");
    converse(&list);
	Output(&list);
	Destroy(&list);
}








