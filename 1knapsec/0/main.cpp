#include<bits/stdc++.h>

using namespace std;

int dp[100][100],weight[100],cost[100],n,capacity;

int napsack(int i,int w)
{
    if(i==n+1)
    {
        return 0;
    }
    if(dp[i][w]!=-1)return dp[i][w];

    int profit1=0,profit2=0;

    if((w+weight[i])<=capacity)
    {
        profit1=cost[i]+napsack(i+1,w+weight[i]);
    }

    profit2=napsack(i+1,w);

    dp[i][w]=max(profit1,profit2);

    return dp[i][w];
}
int main()
{


    ifstream input("input.txt");

    memset(dp,-1,sizeof dp);

    input>>n>>capacity;

    for(int i=1; i<=n; i++)
    {
        input>>weight[i]>>cost[i];
    }

    cout<<napsack(1,0);

}
`
