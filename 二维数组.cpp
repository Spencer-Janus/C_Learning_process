#include<stdio.h>
void input(int a[][3],int n);
void output(int a[][3],int n);
void transpose(int a[][3],int n);
void diagramsum(int a[][3],int n);
void input(int a[][3],int n)
{
 int i,j;
	printf("�������������\n");
  for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
			  scanf("%d",&a[i][j]);

}
void output(int a[][3],int n)
{
	int i,j;
	printf("�����������\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
}
void transpose(int a[][3],int n)
{
	int brray[3][3],i,j;
  printf("ת�þ���Ϊ\n");
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
		  brray[i][j]=a[j][i];
  for(i=0;i<n;i++)
  {
	  for(j=0;j<n;j++)
		  printf("%4d",brray[i][j]);
          printf("\n");
  }
}
void diagramsum(int a[][3],int n)
{
	int i ,j,sum=0;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
		  if(i==j)
			  sum+=a[i][j];
printf("�Խ���֮��Ϊ%d",sum);
}	
int main()
{
  int array[3][3];
input(array,3);
output(array,3);
transpose(array,3);
diagramsum(array,3);
return 0;
}