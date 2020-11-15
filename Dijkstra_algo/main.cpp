#include <bits/stdc++.h>

#define INF 100000000010

using namespace std;

int totalnode,node1,node2,weight,source;
vector<vector<pair<int,int> > >AdjList(10000);
vector<int> parent;
vector<int> dist;
priority_queue<pair<int,int> > pq;

int pathfind(int dst)
{
     if(parent[dst]==-1 && dst!= source)
     {
          cout<<"path not found\n";
         return 0;
     }

    else if(dst == source)
       {
         cout<<source;
         return 0;
       }
     pathfind(parent[dst]);
     cout<<" "<<dst;
}


int main()
{
    ifstream input("input.txt");

    if(!input.is_open())
    {
         cout<<"File not open\n";
    }
    input>>totalnode;

    while(input>>node1>>node2>>weight)
    {
         AdjList[node1].push_back(make_pair(node2,weight));
    }

    parent.assign(totalnode,-1);
    dist.assign(totalnode,INF);

    cout<<"Enter source node: ";
    cin>>source;
    dist[source] = 0;

    pq.push(make_pair(-0,-source));


    while(!pq.empty())
    {
         pair<int,int> frnt;
         frnt = pq.top();
          pq.pop();
          int d,u;
         d = -frnt.first,u = -frnt.second;
    // pq.push(make_pair(-u,-source));


         if(d>dist[u])
          continue;
         for(int i=0;i<AdjList[u].size();i++)
         {
              pair<int,int>v= AdjList[u][i];

              if(dist[u]+v.second < dist[v.first])
              {
                   dist[v.first] = dist[u]+v.second;
                   parent[v.first] = u;
                   pq.push(make_pair(-dist[v.first],-v.first));


              }
         }

    }
    int dest;
    cout<<"Enter destination: ";
    cin>>dest;
    cout<<"Cost: "<<dist[dest]<<endl;
    pathfind(dest);


         return 0;
}
