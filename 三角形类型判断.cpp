#include<stdio.h>
int main()
{
	int a,b,c,t;
	scanf("%d%d%d",&a,&b,&c); 
	if(a>b) 
	{ 
		t=a; a=b; b=t; 
	} 
	if(a>c) 
	{ 
		t=a; a=c; c=t; 
	} 
	if(b>c) 
    {
	t=b; b=c; c=t; 
	} 
	if(a+b>c&&a>0&&b>0&&c>0)
	{
		if(b-a<=1e-2&&c-a<=1e-2)
		{
		 printf("�ȱ�������");
		}
		else if(b-a<=1e-2||c-b<=1e-2)
		{
			printf("����������");
		}
		else if(b-a<=1e-2&&(a*a+b*b-c*c)<1e-2)
		{
			printf("����ֱ��������");
		}
		else if(a*a*+b*b-c*c<1e-2)
		{
			printf("ֱ��������");
		}
		else
		{
			printf("һ��������");
		}
	}

	else
	{
		printf("���ܹ���������");
	}
 }
