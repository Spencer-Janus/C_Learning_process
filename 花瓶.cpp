#include<stdio.h>
int main()
{
   int i,j,a[4];
   for (i=0;i<4;i++)
   {
     for (j=0;j<4;j++)
     if (j==i) a[j]=1;
     else a[j]=0;
     if(a[3]+a[1]==1&&a[1]+a[2]==1&&a[0]+a[1]==1)
     {
        printf("打碎花瓶的人是:");
        for(j=0;j<=3;j++)
        if (a[j])  
       printf("%d.",j);
       printf("\n");
      }
  }
}