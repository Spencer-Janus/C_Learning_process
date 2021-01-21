#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char mima[100]="0";
	printf("ÇëÊäÈë5Î»µÇÂ½ÃÜÂë\n");
	gets(mima);
	while(1)
	{
		if(strcmp(mima,"njupt")==0)
			break;
		else
			printf("ÃÜÂë´íÎó£¬ÇëÖØĞÂÊäÈëÃÜÂë\n");
			gets(mima);
	}
	return 0;
}