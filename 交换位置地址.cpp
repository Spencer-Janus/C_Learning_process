#include<stdio.h>
#include<stdlib.h>
void swap1( int a, int b);
void swap1(int a, int b )
{  	int temp=a;
    a = b;
    b = temp; 
}
int main()
{
	int x=1,y=2;
	swap1(x,y);  /*此处依次换成另外3种调用进行观察，其余代码不变*/
	printf("x=%d,y=%d\n",x,y);
	system("pause");
	return 0;
}
