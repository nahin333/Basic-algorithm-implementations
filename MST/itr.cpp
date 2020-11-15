#include<iostream>
#include<vector>
using namespace std;

double ynn(double x)
{
    return (1.0/(1.0+x));
}
int main()
{
    vector<double>y;
    double a=0,b=1;
    double h=.1;
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    h=(b-a)/n;
    //double y[10000];
    int j=0;
    for(double i=a; i<=(a+n*h); i=i+h)
    {
//        y[j]=ynn(i);
        y.push_back(ynn(i));

    }
    double ans=0;
    for(int i=1; i<n; i++)
    {
        ans+=y[i];
    }
    ans=(ans*2);
    double k=(h/2.0)*(y[0]+y[n]+ans);
    cout<<"\nTrapezoidal rule: ";
    cout<<k<<endl;
    double k2=0;
    for(int i=1; i<n; i+=2)
    {
        k2+=y[i];
    }
    k2=k2*4;
    double k3=0;
    for(int i=2; i<n-1; i+=2)
    {
        k3+=y[i];
    }
    k3=(h/3.0)*((k3*2)+(y[0]+y[n])+k2);
    cout<<"\nSimpson's one third rule: ";
    cout<<k3<<endl;
    k2=0;
    k3=0;
    for(int i=1; i<=n; i++)
    {
        if(i%3==0)k2+=y[i];
        else k3+=y[i];
    }

    double ans2=((3*h)/8)*((3*k3)+(2*k2));
    cout<<"\nsimphon's three eight's rule: ";
    cout<<ans2<<endl;






}
