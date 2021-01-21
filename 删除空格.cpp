#include<stdio.h>
#include<stdlib.h>
void delet(char *s);
void delet(char *s)
{
	int i=0; char*p=s;
	while(*p)
	{
		if(*p!=' ')
		{
			s[i]=*p;
	        i++;  	
		}
		p++;
	}
	s[i]='\0';
}
int main()
{
	char str[20];
     gets(str);
	 delet(str);
	 puts(str);
	 system("pause");
	 return 0;
}