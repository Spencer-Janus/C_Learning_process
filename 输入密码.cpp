#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char mima[100]="0";
	printf("������5λ��½����\n");
	gets(mima);
	while(1)
	{
		if(strcmp(mima,"njupt")==0)
			break;
		else
			printf("���������������������\n");
			gets(mima);
	}
	return 0;
}