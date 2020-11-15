#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

vector<vector<pair<int,int> > >Adjlist(1000);
vector<int>dist;
vector<int>par;
int source;

int pathfind(int dst)
{
     if(dst!=source && par[dst] == -1)
     {
          cout<<"Path not found\n";
          return 0;
     }
     else if(dst == source)
     {
          cout<<source;
          return 0;
     }
     pathfind(par[dst]);
     cout<<" "<<dst;
}

int main()
{
    int totalnode,node1,node2,weight;
    ifstream input("input.txt");

    if(!input.is_open())
    {
         cout<<"File not not found\n";
    }

    input>>totalnode;

    while(input>>node1>>node2>>weight)
    {
         Adjlist[node1].push_back(make_pair(node2,weight));
    }

 /*   for(int i=0;i<totalnode;i++)
    {
         cout<<i<<": ";
         for(int j=0;j<Adjlist[i].size();j++)
         {
              cout<<Adjlist[i][j].first<<"("<<Adjlist[i][j].second<<") ";
         }
         cout<<endl;
    }
*/
    cout<<"Enter source: ";
    cin>>source;
    dist.assign(totalnode,INF);
    par.assign(totalnode,-1);
    dist[source] = 0;

    for(int i=0; i<totalnode-1; i++)
    {
         for(int u=0; u<totalnode; u++)
         {
              for(int j=0; j<Adjlist[u].size();j++)
              {
                   pair<int,int> v = Adjlist[u][j];

                   if(dist[u] == INF)
                    continue;

                   if(dist[u]+v.second < dist[v.first])
                   {
                        dist[v.first] = dist[u]+v.second;
                        par[v.first] = u;
                   }
              }
         }
    }

    bool hascycle = false;

     for(int u=0; u<totalnode; u++)
         {
              for(int j=0; j<Adjlist[u].size();j++)
              {
                   pair<int,int> v = Adjlist[u][j];

                   if(dist[u] == INF)
                    continue;

                   if(dist[u]+v.second < dist[v.first])
                   {
                        hascycle = true;
                        break;
                   }
              }
                   if(hascycle)
                    break;
         }

         if(hascycle)
         {
              cout<<"this graph has negative weight cycle\n";
         }

         else
         {
              int dest;
              cout<<"Enter destination: ";
              cin>>dest;
              cout<<"distance: "<<dist[dest]<<endl;
              pathfind(dest);
         }

         return 0;
}
