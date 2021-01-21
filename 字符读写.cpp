#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp1,*fp2;char ch;
	fp1=fopen("D:\\demo.txt","r");
    if(fp1==0)
	{
		printf("File error\n");
			exit(1);
	}
    fp2=fopen("D:\\new.txt","a+");

	    if(fp2==0)
	{
		printf("file error\n");
			exit(1);
	}
		while((ch=fgetc(fp1))!=EOF)
		{
			fputc(ch,fp2);
		}
      return 0;
}