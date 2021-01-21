#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,k;
if(b>a&&a>=10&&b<=1000)
{
	scanf("%d%d",&a,&b);
    k=(int)sqrt(x*1.0);
		for(i=2;i<=k;i++)
		{	
			if(x%k==0)
			break;
		}
			if (i>k)
				printf("%d is a prime",x);
			else
			 printf("%d is not a prime.\n",x);
	}
	return 0;
}输出a，b之间的质数
#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,k,m,i,z=0;
	scanf("%d%d",&a,&b);
	if (a>=b)
	printf("error input!");
	else
	for (i=a+1;i<b;i++)
	{
		k=sqrt(i);
		m= 0;
		for (c=2;c<=k;c++)
		{
			if (i%c==0)
			m= 1;
		}
		if (m==0)
		{
			printf("%5d",i);
			z++;
			if (z%5==0)
			printf("\n");
		}
	}
	printf("\n");
    return 0;
}
