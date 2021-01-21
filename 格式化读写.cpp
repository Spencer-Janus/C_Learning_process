#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct students
{
	int id;
	char name[20];
	double score;
	int rank;
}STU;
int readfile(char*fname,STU st[]);
void sortrank(STU st[],int n);
void writefile(char*fname,STU at[],int n);
int main()
{
	STU stu[N];
	char filename[20];
	int num=0;
	printf("输入原始数据文件名");
	scanf("%s",filename);
	num=readfile(filename,stu);
	sortrank(stu,num);
	printf("输入排序后的文件名");
	scanf("%s",filename);
	writefile(filename,stu,num);
	return 0;
}
int readfile(char*fname,STU st[])
{
	int i=0;
	FILE *fp;
	fp=fopen(fname,"r");
	if(fp==0);
	{
		printf("error");
	    exit(1);
	}
	fscanf(fp,"%d%s%lf%d",st[i].name,&st[i].id,&st[i].score,&st[i].rank);
		while(!feof(fp))
		{
			i++;
			fscanf(fp,"%d%s%lf%d",st[i].name,&st[i].id,&st[i].score,&st[i].rank);
		}
		fclose(fp);
		return i;
}
void sortrank(STU st[],int n)
{
	int i,j,k;
	STU temp;
	for(i=0;i<n-i;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(st[j].score>st[k].score)
				k=j;
		if(k!=j)
		{
			temp=st[i];
			st[i]=st[k];
			st[k]=temp;
		}
	}
	st[0].rank=1;
	for(i=1;i<n;i++)
	{
		if(st[i].score==st[i-1].score)
			st[i].rank=st[i-1].rank;
		else
			st[i].rank=i+1;
	}
}
void writefile(char*fname,STU st[],int n)
{
	int i;
	FILE*fp;
	fp=fopen(fname,"w");
	if(fp==0)
	{
		printf("create new file error\n");
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%d%-8s\t%.2f%6d\n",st[i].id,st[i].name,st[i].score,st[i].rank);
		printf("%d%-8s\t%.2f%6d\n",st[i].id,st[i].name,st[i].score,st[i].rank);
	}
	fclose(fp);
}

