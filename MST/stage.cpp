#include<iostream>
using namespace std;
int main()
{
    long long int i,j,c1,c2,n,m,a;

    cin>>n>>m>>a;

    if(n%a==0)
     c1=n/a;
    else
     c1=n/a+1;
    if(m%a==0)
     c2 = m/a;
    else
     c2 = m/a+1;
    cout<<c1*c2<<endl;
    return 0;
}




/*
main()
{
    long long int x,y,i,_j,j;
    scanf("%lld %lld %lld",&x,&y,&j);
    if(x%j)
        i=x/j+1;
    else
        i=x/j;
    if(y%j)
        _j=y/j+1;
    else
        _j=y/j;
    printf("%lld",i*_j);
}
*/
