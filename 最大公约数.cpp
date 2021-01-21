#include<stdio.h>
int main()
{
	int a,b,c,r;
	scanf("%d%d",&a,&b);
	do
	{
    r=a%b;
	a=b;
	b=r;
	}while(r!=0);
	printf("%d",a);
	return 0;
}