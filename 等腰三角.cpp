#include<stdio.h>
void DrawTriangle (int n,char c);
int main()
{
	int m,a;char n,b;
    m=60;n=42;
    DrawTriangle(m,n);
	a=10;b=35;
	DrawTriangle(a,b);
return 0;
}
void DrawTriangle (int n,char c)
{
	int i,b;
	for(i=1;i<=n;i++)
	{
		for(b=1;b<=n-i;b++)
			printf(" ");
		for(b=1;b<=2*i-1;b++)
			printf("%c",c);
		printf("\n");
	}
}