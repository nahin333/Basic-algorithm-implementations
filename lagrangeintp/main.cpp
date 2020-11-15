#include<bits/stdc++.h>
using namespace std;

int main()
{
    float x[10],y[10],temp=1,f[10],sum,p;
    int i,n,j,k=0,c;
    cout<<"no of record: ";
    cin>>n;

    for(i=0; i<n; i++)
    {
        cout<<"\nenter the value of x"<<i<<":";
        cin>>x[i];
        cout<<"\nenter the value of f(x"<<i<<"):";
        cin>>y[i];
    }
    cout<<"\nEnter X for finding f(x): ";
    cin>>p;

    for(i=0; i<n; i++)
    {
        temp = 1;
        k = i;
        for(j=0; j<n; j++)
        {
            if(k==j)
            {
                continue;
            }
            else
            {
                temp = temp * ((p-x[j])/(x[k]-x[j]));
            }
        }
        f[i]=y[i]*temp;
    }

    for(i=0; i<n; i++)
    {
        sum = sum + f[i];
    }
    cout<<"f("<<p<<") ="<<sum<<endl;

}
