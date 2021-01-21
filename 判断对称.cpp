#include<stdio.h>
int judge(int a[3][3]);
int main()
{
	int n,i,j,array[3][3];
	printf("ÇëÊäÈëÒ»¸ö3*3½×¾ØÕó");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
	scanf("%d",&array[i][j]);
	n=judge(array);
		printf("%d",n);
return 0;
}
int judge(int a[3][3])
{
   int i,j;
   	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(a[i][j]!=a[j][i])
				return 0;
  return 1;
}

	
