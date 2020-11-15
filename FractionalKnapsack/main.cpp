#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int> >iteminfo(1000);
priority_queue<pair<double,int> >pq;

int main()
{
    ifstream input("input.txt");

    if(!input.is_open())
    {
         cout<<"Cant open this file\n";
    }

    int knapsack,weight,profit,index=1;
    input>>knapsack;

    while(input>>weight>>profit)
    {
         iteminfo[index++] = make_pair(weight,profit);

    }

//    for(int i=1;i<index;i++)
//    {
//         cout<<"Item: "<<i<<" weight: "<<iteminfo[i].first<<" profit: "<<iteminfo[i].second<<endl;
//
//    }
    double unit_profit;
    for(int i=1;i<index;i++)
    {
         unit_profit = (float)(iteminfo[i].second/iteminfo[i].first);
         pq.push(make_pair(unit_profit,i));

    }

    double totalprofit = 0;
    while(!pq.empty() && knapsack!=0)
    {
         pair<double,int>frnt = pq.top();
         pq.pop();
         int itemweight = iteminfo[frnt.second].first;

         if(itemweight<=knapsack)
         {
              totalprofit += iteminfo[frnt.second].second;
              cout<<"select item: "<<frnt.second<<" weight: "<<iteminfo[frnt.second].first<<" profit: "<<iteminfo[frnt.second].second<<endl;
              knapsack -= itemweight;
         }

         else
         {
              totalprofit += knapsack*frnt.first;
              cout<<"select item: "<<frnt.second<<" weight: "<<knapsack<<" profit: "<<knapsack*frnt.first<<" fraction: "<<knapsack<<"/"<<itemweight<<endl;
              break;
         }

    }

    cout<<"total profit: "<<totalprofit;

    return 0;
}
