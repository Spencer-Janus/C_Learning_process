#include<stdio.h>
int fact (int a,int b);
int main()
{
	int c,d,e;
	scanf("%d%d",&c,&d);
	printf("%d",fact(c,d));
	return 0;
}
int fact(int a,int b)
{
	int c;
	if(a%b==0)
	return b;
	else return fact(b,a%b);
}