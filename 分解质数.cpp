#include<stdio.h>
#include<math.h>
void judge (int c);
int main()
{
	int a;
	printf("�����2����2000���ڵ���ż��\n");
	scanf("%d",&a);
    judge(a);
}
void judge (int c)
{
	int i,j,k,m,n,l=1,p,q=1;
	for(i=1;i<=2000;i++)
	{
		for(j=1;j<=2000;j++)
		{
			if(i+j==c)
			{

				 printf("%d,%d\n",i,j);
			}
		}
    }
}