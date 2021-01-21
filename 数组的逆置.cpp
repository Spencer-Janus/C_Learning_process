#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[100],i,n,t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("ÄæÖÃÊý×éÎª£º");
	for(i=0;i<=n/2;i++)
	{	
		t=a[i];
		a[i]=a[n-i-1];
		a[n-1-i]=t;
	}
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	system("pause");
	return 0;
}



