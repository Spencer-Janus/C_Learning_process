#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 100
int a[N];            //����Ԫ��
int b[N];            //��Ԫ��ϵ
int c[N][N];int t;   //M����
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
void reflexivity(int n,int a[],int c[N][N])/*�Է���*/
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
		printf("�Է��ԣ�yes");
	else
		printf("�Է��ԣ�no");
}
void symmetry(int a,int c[N][N])/*�Գ���*/
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
		printf("�Գ��ԣ�yes");
	else
		printf("�Գ��ԣ�no");
}
void irreflexivity(int n,int a[],int c[N][N])/*���Է���*/
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
		printf("���Է��ԣ�yes");
	else
		printf("���Է��ԣ�no");
}
void antisymmetry(int a,int c[N][N])/*���Գ���*/
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
		printf("���Գ��ԣ�yes");
	else
		printf("���Գ��ԣ�no");
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
		printf("�����ԣ�yes");
	else
		printf("�����ԣ�no");
}
int main()
{
    int x,y,z,h,i,j,m,t=1;/*xΪ������Ԫ�صĸ�����yΪ��Ԫ��ϵ�ĸ���<z,h>Ϊ��Ԫ��ϵ��mΪ����Ԫ����������*/
while(t)	
 {
	 memset(a,0,sizeof(a));
	 memset(b,0,sizeof(b));
	 memset(c,0,sizeof(c));
	printf("�����뼯��Ԫ�ظ���\n");
	scanf("%d",&x);
	printf("����Ԫ��\n");
	for(i=0;i<x;i++)               //���뼯��Ԫ��
	{
		scanf("%d",&a[i]);
	}
	printf("��������\n");
	printf("{");
	for(i=0;i<x;i++)               //�������
	{
	   if(i<x-1)
		printf("%d,",a[i]);
	   else
		printf("%d",a[i]);

	}
	printf("}");
	printf("\n");
	m=max(a);
	printf("�����Ԫ��ϵԪ�صĸ���\n");
	scanf("%d",&y);
	for(i=0,j=0;i<y;i++)
	{
		scanf("%d%d",&z,&h);/*�����Ԫ��ϵ���������ִ洢��b������*/
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
    printf("����1����������0�˳�");
	scanf("%d",&t);
 }
	return 0;
}



   