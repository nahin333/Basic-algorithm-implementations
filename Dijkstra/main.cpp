#include <bits/stdc++.h>
#define inf 345353454

using namespace std;

int dis[100];
int cost[100][100];
vector<int>vec[100];
class compare
{
public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int start)
{
    priority_queue< pair< int,int >, vector<pair<int,int> >, compare > priorQ;
    for(int i=0; i<100; i++)
     dis[i]=inf;
    dis[start]=0;
    priorQ.push(make_pair(start,dis[start]));
    while(!priorQ.empty())
    {
        int u = priorQ.top().first;
        priorQ.pop();
        for(int i=0; i<vec[u].size(); i++)
        {
            int v=vec[u][i];
            if(dis[u]+cost[u][v]<dis[v])
            {
                dis[v]=dis[u]+cost[u][v];
                priorQ.push(make_pair(v,dis[v]));

            }
        }
    }
}
int main()
{
    ifstream input ("input.txt");
    int totalnode;
    input>>totalnode;
    int node1,node2,weight;
    while(input>>node1>>node2>>weight)
    {
        vec[node1].push_back(node2);
        cost[node1][node2]=weight;
    }
    dijkstra(1);
    for(int i=1; i<=totalnode; i++)
    {
        cout<<dis[i]<<" ";
    }

}
