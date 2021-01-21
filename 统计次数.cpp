#include<stdio.h>
int main()
{
	unsigned int m,i;
	int digit[10]={0};
	scanf("%u",&m);
	while(m)
	{
		i=m%10;
		digit[i]++;
		m=m/10;
	}
	for(i=0;i<10;i++)
	printf("%d\t",i);
	printf("\n");
	for(i=0;i<10;i++)
		printf("%d\t",digit[i]);
	return 0;
}