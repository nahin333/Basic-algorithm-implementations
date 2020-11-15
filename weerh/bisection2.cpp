#include<bits/stdc++.h>
using namespace std;
double x,x1,x2,p=1000,r=1000,x0;
int c=0;
double f(double x)
{
    return x*x-x-2;
}
int main(void)
{
    double a=sqrt((-1/1)*(-1/1)-(2*(-2/1)));
    for(double b=-a;b<=a;b+=1.4)
    {
         x1=b;
         x2=b+1.4;
         if(f(x1)*f(x2)>0)
         {
             continue;
         }
         r=1000;
         p=1000;
         c=0;
    while(r>.00001)
    {
        c++;
        x0=x1-(f(x1)*(x2-x1)/(f(x2)-f(x1)));
        if(f(x0)==0)
        {
            break;
        }
        else if(f(x1)*f(x0)<0)
        {
            x2=x0;
        }

        else if(f(x2)*f(x0)<0)
        {
            x1=x0;
        }
        r=fabs((x0-p)/x0);
        p=x0;
    }
    cout<<"result: "<<x0<<" iteration: "<<c<<endl;
    }
}
//hafiz031
