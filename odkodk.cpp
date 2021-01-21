#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE*fp;
	char ch;
	fp=fopen("D:\f1.txt","w");
	if(fp==0)
	{
		printf("file error!\n");
		exit(1);
	}
	printf("Enter a text(end with '#'):\n");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	fclose(fp);
	fp=fopen("D:\f1.txt","r");
	if(fp==0)
	{
		printf("file error!\n");
		exit(1);
	}
	while((ch=fgetc(fp)!=EOF))
	{
		putchar(fp);
	}
	putchar('\n');
	fclose(fp);
	return 0;
}
