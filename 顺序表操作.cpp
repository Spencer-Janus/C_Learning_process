#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct           
{
	int n;
	int maxLength;
	ElemType*element;
}SeqList;        /*  顺序表的定义*/
#define ERROR 0
#define OK 1
#define Overflow 2/*上溢*/
#define Underflow 3/*下溢*/
#define Notpresent 4/*元素不存在*/
#define Duplicate 5/*有重复*/
typedef int Status;
Status Init(SeqList *L,int mSize)   /*初始化*/
{
	L->maxLength=mSize;
	L->n=0;
	L->element=(ElemType *)malloc(sizeof(ElemType)*mSize);      /*动态生成一维数组空间*/
	if (!L->element)
		return ERROR;
	return OK;
}
Status Find(SeqList L,int i,ElemType *x)/*查找*/
{
	if(i<0||i>L.n-1)
	return ERROR;             /*判断是否越界*/
	*x=L.element[i];          /*通过x返回它的值*/
	printf("%d",*x);
	return OK;
}
Status Insert(SeqList *L,int i,ElemType x)/*插入*/
{
	int j;
	if(i<-1||i>L->n-1)
		return ERROR;          /*判断下标是否越界*/
	if(L->n==L->maxLength)     /*判断顺序表存储空间是否已满*/
		return ERROR;
	for(j=L->n-1;j>i;j--)
		L->element[j+1]=L->element[j];
	L->element[i+1]=x;
	L->n=L->n+1;
	return OK;
}
Status Delete(SeqList*L,int i)/*删除*/
{
	int j;
	if(i<0||i>L->n-1)
		return ERROR;/*判断是否越界*/
	if(!L->n)/*顺序表是否为空*/
		return ERROR;
	for(j=i+1;j<L->n;j++)
		L->element[j-1]=L->element[j]; /*前移每一个元素*/
	L->n--;
	return OK;
}
Status Output(SeqList *L)/*输出*/

{
	int i;
	if(L->n==0)
		return ERROR;
	for(i=0;i<L->n-1;i++)
		printf("%d ",L->element[i]);/*逐个输出*/
	printf("\n");
	return OK;
}
void Destroy(SeqList*L)    /*撤销*/
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
	Delete(&list,5);/*删除第五个元素*/
    Output(&list);
	 Find(list,5,&y);/*下标为5的元素*/
	Destroy(&list);

}






