#include<bits/stdc++.h>


  float fun(float x)
  {
       return(x*x-4*x-10);
  }

int main()
{
  float x1,x2,x3,f1,f2,t;

  printf("\nEnter the value of x1: ");
  scanf("%f",&x1);
  printf("\nEnter the value of x2: ");
  scanf("%f",&x2);
  printf("\n______________________________________________\n");
  printf("\n    x1\t  x2\t  x3\t     f(x1)\t f(x2)");
  printf("\n______________________________________________\n");
  do
  {
  f1=fun(x1);
  f2=fun(x2);
  x3=x2-((f2*(x2-x1))/(f2-f1));
  printf("\n%f   %f   %f   %f   %f",x1,x2,x3,f1,f2);
  x1=x2;
  x2=x3;
  if(f2<0)
    t=fabs(f2);
  else
    t=f2;
  }while(t>0.0001);
printf("\n______________________________________________\n");
printf("\n\nroot = %f",x3);

}
