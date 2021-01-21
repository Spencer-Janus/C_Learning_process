#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 100
int a[N];            //集合元素
int b[N];            //二元关系
int c[N][N];int t;   //M矩阵
int max(int a[])
{
	int i,n;
	n=a[0];
	for(i=1;i<N;i++)
	{ 
		if(a[i]>n)
			n=a[i];
	}
    return n;
}
void reflexivity(int n,int a[],int c[N][N])/*自反性*/
{
	int d=1,b;
	for(int i=0;i<=n;i++)
	{
		b=a[i];
		if(c[b][b]!=1)
		{
			d=0;
			break;
		}
	}
	if(d==1)
		printf("自反性：yes");
	else
		printf("自反性：no");
}
void symmetry(int a,int c[N][N])/*对称性*/
{
	int s=1;
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=a;j++)
		{
			if(c[i][j]!=c[j][i])
			{
				s=0;
				break;
			}
		}
	}
	if(s==1)
		printf("对称性：yes");
	else
		printf("对称性：no");
}
void irreflexivity(int n,int a[],int c[N][N])/*反自反性*/
{
	int d=0,b;
	for(int i=0;i<=n;i++)
	{
			b=a[i];
		 if(c[b][b]=1)
		 {   d=1;
		     break;
		 }    
	}
	if(d==0)
		printf("反自反性：yes");
	else
		printf("反自反性：no");
}
void antisymmetry(int a,int c[N][N])/*反对称性*/
{
    int s=1;
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=a;j++)
		{
			if(c[i][j]==1&&c[j][i]==1)
			{
				if(i!=j)
				{
					s=0;
				}
			}
		}
	}
	if(s==1)
		printf("反对称性：yes");
	else
		printf("反对称性：no");
}
void Transitivity(int a,int c[N][N])
{
	int s=1;
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=a;j++)
		{
			for(int k=0;k<=a;k++)
			{
				if(c[i][j]==1&&c[j][k]==1&&c[i][k]!=1)
				{
					s=0;
					break;
				}
			}
		}
	}
	if(s==1)
		printf("传递性：yes");
	else
		printf("传递性：no");
}
int main()
{
    int x,y,z,h,i,j,m,t=1;/*x为集合中元素的个数，y为二元关系的个数<z,h>为二元关系，m为集合元素中最大的数*/
while(t)	
 {
	 memset(a,0,sizeof(a));
	 memset(b,0,sizeof(b));
	 memset(c,0,sizeof(c));
	printf("请输入集合元素个数\n");
	scanf("%d",&x);
	printf("输入元素\n");
	for(i=0;i<x;i++)               //输入集合元素
	{
		scanf("%d",&a[i]);
	}
	printf("集合如下\n");
	printf("{");
	for(i=0;i<x;i++)               //输出集合
	{
	   if(i<x-1)
		printf("%d,",a[i]);
	   else
		printf("%d",a[i]);

	}
	printf("}");
	printf("\n");
	m=max(a);
	printf("输入二元关系元素的个数\n");
	scanf("%d",&y);
	for(i=0,j=0;i<y;i++)
	{
		scanf("%d%d",&z,&h);/*输入二元关系，并将数字存储在b数组中*/
		c[z][h]=1;  
		b[j]=z;
		j=j+1;
		b[j]=h;
		j=j+1;
	}
	printf("{");
	for(j=0;j<2*y;j++)
	{
		if(j%2==0)
		    printf("<%d,",b[j]);
		else if(j%2!=0&&(j==2*y-1))
			printf("%d>",b[j]);
		else
			printf("%d>,",b[j]);
	}
	printf("}");
	reflexivity(x,a,c);
	symmetry(m,c);
	irreflexivity(x,a,c);
	antisymmetry(m,c);
	Transitivity(m,c);
	printf("\n");
    printf("输入1继续，输入0退出");
	scanf("%d",&t);
 }
	return 0;
}



   