#include<stdio.h>
#include<stdlib.h>
void english(char *s);
void num(char *s);
int main()
{	
	char a[40], b[40];
	gets(a);
	english(a);
	system("pause");
	gets(b);
	num(b);
	system("pause");
	return 0;
}
void english(char *s)
{	
    char *p=s;int i=0,n;
    while(*p)
	{
		if(('a'<=*p&&'z'>=*p)||('A'<=*p&&'Z'>=*p))
	{
		s[i]=*p;
		i++;
	}
	p++;
	}
	s[i]='\0';
		for(n=0;n<i;n++)
		if((n+1)%2==0)
        printf("%c",s[n]);
}
void num(char *s)
{	
    char *p=s;int i=0,n;
    while(*p)
	{
		if('1'<=*p&&'9'>=*p)
	{
		s[i]=*p;
		i++;
	}
	p++;
	}
	s[i]='\0';
		for(n=0;n<i;n++)
		if((n+1)%2==0)
        printf("%c",s[n]);
}
