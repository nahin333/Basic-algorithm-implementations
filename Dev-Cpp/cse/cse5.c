#include<stdio.h>
void add(int,int);
int main()
{
   int a,b;
   add(a,b);
   return 0;
}
void add(int a,int b)
{
    scanf("%d %d",&a,&b);
    printf("%d\n",a+b);
    return a+b;
}



