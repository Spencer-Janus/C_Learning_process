#include <stdio.h>
int main()
{
	int i,j,b;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4-i;j++)
		{
			printf(" ");

		}
		for(j=1;j<=2*i-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(i=3;i>=1;i--)
	{
		for(j=1;j<=4-i;j++)
		{
			printf(" ");
		}
		for(b=1;b<=i*2-1;b++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
