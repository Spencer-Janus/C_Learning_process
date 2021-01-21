#include<stdio.h>
int main()
{
	int i,j,N,k=1,m,a[100][100];
	printf("请输入阶数\n");
	scanf("%d",&N);
		if(N%2==0)
		m=N/2;
		else
			m=N/2+1;
     for(i=0;i<m;i++)
{
	for(j=i;j<=N-1-i;j++)
		a[i][j]=k++;
    for(j=i+1;j<=N-1-i;j++)
		a[j][N-1-i]=k++;
	for(j=N-i-2;j>=i;j--)
		a[N-1-i][j]=k++;
	for(j=N-2-i;j>i;j--)
		a[j][i]=k++;
}
	 	printf("%d阶螺旋方阵为：\n",N);
	for(i=0;i<=N-1;i++)
	{	
		for(j=0;j<=N-1;j++)
		{
			printf("%4d ",a[i][j]);
		}
	   printf("\n");
	}
		return 0;
}