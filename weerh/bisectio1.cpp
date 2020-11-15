#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return x*x-4*x-10;
}
int main()
{
    int x,y,z,a,b,c,d,e;
    b=1,a=-4,c=-10;
    z=sqrt((a/b)*(a/b)-2*(c/b));
    d=-z;
    int k[z-d],q[z-d];
    for(int i=-6,j=0; i<=6; i++,j++)
    {
        q[j]=i;
        y=i;
        x=((b*(y*y))+a*y+c);
        k[j]=x;
        cout<<q[j]<<":"<<k[j]<<"\n";
    }
    cout<<endl;
    {
        for(int i=0; i<12; i++)
        {
            if(k[i]*k[i+1]<0)
            {
                double r=q[i],s=q[i+1];
                double n=r;
                double t;
                int j=0;
                while (1)
                {
                    j++;
                    t=(r+s)/2;
                    if (t==0) break;
                    else if (f(r)*f(t)<0) s=t;
                    else r=t;
                    if (abs((n-t)/t)<0.00000001) break;
                    n=t;
                }
                cout << "Root:" << t << endl;
                cout << "Loop:" << j << endl;
            }
        }
    }
    return 0;
}
