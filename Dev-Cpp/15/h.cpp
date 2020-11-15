#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    vector<int>mrbl;
    vector<int>sech;
    int m,n,x,k,c=0;
    for( ;cin>>n>>m&&m!=0&&n!=0; )
    {
        c++;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            mrbl.push_back(x);
        }
        sort(mrbl.begin(),mrbl.end());
        for(int j=0;j<m;j++)
        {
            cin>>x;
            sech.push_back(x);
        }
        cout<<"CASE# "<<c<<":"<<endl;
        for(int j=0;j<m;j++)
        {
            for(k=0;k<mrbl.size();k++)
            {
                if(mrbl[k]==sech[j])
                {
                    cout<<sech[j]<<" found at "<<k+1<<endl;
                    break;                }
            }
            if(k==mrbl.size())
            {
                cout<<sech[j]<<" not found"<<endl;
            }
        }
        mrbl.clear();
        sech.clear();

    }
    return 0;
}
