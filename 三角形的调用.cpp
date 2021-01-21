#include<stdio.h>
void DrawTriangle (int n,char c);
int main()
{
	int m,a;char n,b;
    m=5;n=42;
    DrawTriangle(m,n);
	a=10;b=35;
	DrawTriangle(a,b);
return 0;
}
void DrawTriangle (int n,char c)
{
	int i,b;
	for(i=1;i<=(n+1)/2;i++)
	{
		for(b=1;b<=(n+1)/2-i;b++)
		{
			printf(" ");
		}
		for(b=1;b<=2*i-1;b++)
		{
			printf("%c",c);
		}
	printf("\n");
	}
	for(i=((n+1)/2)-1;i>=1;i--)
	{
		for(b=1;b<=(n+1)/2-i;b++)
		{
			printf(" ");
		}
		for(b=1;b<=2*i-1;b++)
		{
		printf("%c",c);
		}
	printf("\n");
	}
}