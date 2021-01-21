#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct           
{
	int n;
	int maxLength;
	ElemType*element;
}SeqList;        /*  ˳���Ķ���*/
#define ERROR 0
#define OK 1
#define Overflow 2/*����*/
#define Underflow 3/*����*/
#define Notpresent 4/*Ԫ�ز�����*/
#define Duplicate 5/*���ظ�*/
typedef int Status;
Status Init(SeqList *L,int mSize)   /*��ʼ��*/
{
	L->maxLength=mSize;
	L->n=0;
	L->element=(ElemType *)malloc(sizeof(ElemType)*mSize);      /*��̬����һά����ռ�*/
	if (!L->element)
		return ERROR;
	return OK;
}
Status Find(SeqList L,int i,ElemType *x)/*����*/
{
	if(i<0||i>L.n-1)
	return ERROR;             /*�ж��Ƿ�Խ��*/
	*x=L.element[i];          /*ͨ��x��������ֵ*/
	printf("%d",*x);
	return OK;
}
Status Insert(SeqList *L,int i,ElemType x)/*����*/
{
	int j;
	if(i<-1||i>L->n-1)
		return ERROR;          /*�ж��±��Ƿ�Խ��*/
	if(L->n==L->maxLength)     /*�ж�˳���洢�ռ��Ƿ�����*/
		return ERROR;
	for(j=L->n-1;j>i;j--)
		L->element[j+1]=L->element[j];
	L->element[i+1]=x;
	L->n=L->n+1;
	return OK;
}
Status Delete(SeqList*L,int i)/*ɾ��*/
{
	int j;
	if(i<0||i>L->n-1)
		return ERROR;/*�ж��Ƿ�Խ��*/
	if(!L->n)/*˳����Ƿ�Ϊ��*/
		return ERROR;
	for(j=i+1;j<L->n;j++)
		L->element[j-1]=L->element[j]; /*ǰ��ÿһ��Ԫ��*/
	L->n--;
	return OK;
}
Status Output(SeqList *L)/*���*/

{
	int i;
	if(L->n==0)
		return ERROR;
	for(i=0;i<L->n-1;i++)
		printf("%d ",L->element[i]);/*������*/
	printf("\n");
	return OK;
}
void Destroy(SeqList*L)    /*����*/
{	
	L->n=0;
	L->maxLength=0;
	free(L->element);
}
void main()
{
	int i;ElemType y;
	SeqList list;
	Init(&list,15);
	for(i=0;i<10;i++)
	   Insert(&list,i-1,i);
	Output(&list);
	Delete(&list,5);/*ɾ�������Ԫ��*/
    Output(&list);
	 Find(list,5,&y);/*�±�Ϊ5��Ԫ��*/
	Destroy(&list);

}






