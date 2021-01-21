#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef int Status;
#define ERROR 0
#define OK 1
#define Overflow 2/*����*/
#define Underflow 3/*����*/
#define Notpresent 4/*Ԫ�ز�����*/
#define Duplicate 5/*���ظ�*/

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
Status Init(headerList*L)   /*������ĳ�ʼ��*/
{
	L->head=(node*)malloc(sizeof(node));/*���ɱ�ͷ���*/
	if(!L->head)
	return ERROR;
	L->head->link=NULL;/*���õ�����Ϊ�ձ�*/
	L->n=0;
	return OK;
}
Status Find(headerList L,int i,ElemType *x) /*���������*/
{
	node *p;
	int j;
	if(i<0||i>L.n-1)             /*Խ����*/
		return ERROR;
	p=L.head->link;
	for(j=0;j<i;j++)            /*����ai*/
		p=p->link;
    *x=p->element;       
	return OK;
}
Status Insert(headerList *L, int i, ElemType x)/*���������*/
{
	node*p, *q;
	int j;
	if (i<-1 || i>L->n - 1)            
		return ERROR;
	p = L->head;
	for (j = 0; j <= i; j++)          /*��ͷ��㿪ʼ����*/
		p = p->link;
	q = (node*)malloc(sizeof(node));/*�����½��q*/
	q->element = x;
	q->link = p->link;           /*�½�����pָ��֮��*/
	p->link = q;
	L->n++;
	return OK;
}
Status Delete(headerList*L,int i)/*������ɾ��*/

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
	q->link=p->link;              /*ɾ��p��ָ���*/
	free(p);                    /*�ͷ�p��ָ�洢�ռ�*/
	L->n--;
	return OK;
}
Status Output(headerList *L)  /*���������*/
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
void Destroy(headerList *L)/*��������*/
{
	node*p;
	while(L->head)
	{
		p=L->head->link;
		free(L->head);
		L->head=p;
	}
}
void converse(headerList *L)         /*����������*/
{  
    node *p,*q;  
    p=L->head->link;  
    L->head->link=NULL;  
    while(p)  
    {  
        q=p;  
        p=p->link;          /*����ƶ�һ��λ��*/
        q->link=L->head->link;  /*ͷ��*/
        L->head->link=q;  
    }  
}
void sort(headerList *L)            /*��������������*/
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
	Delete(&list,0);/*ɾ���±�Ϊ0��Ԫ��*/
	printf("\nthe linklist is:");
	Output(&list);
	Find(list,0,&x); /*�����±�Ϊ0��Ԫ��*/
	printf("\nthe value is:");
	printf("%d\n ",x);
	printf("\n�����:");
	sort(&list);
	Output(&list);
	printf("\n���ú�:");
    converse(&list);
	Output(&list);
	Destroy(&list);
}








