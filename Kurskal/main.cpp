#include <bits/stdc++.h>

using namespace std;
int parent[100];

int find_set (int x)
{
     if(parent[x]==x)
          return x;
     else
          find_set(parent[x]);
}

int unite(int x,int y)
{
     int fx = find_set(x);
     int fy = find_set(y);
     parent[fy] = fx;
     return 0;
}


int main()
{
    int totalnode,totaledge,node1,node2,weight;
    fstream input("input.txt");

    input>>totalnode>>totaledge;

    for(int i=1;i<=totalnode; i++)
    {
         parent[i] = i;
    }

    vector < pair<int, pair<int,int> > > edges; //1 2 7 (7,(1,2))
    for (int i=1;i<=totaledge; i++)
    {
         input>>node1>>node2>>weight;
         edges.push_back(make_pair(weight,make_pair(node1,node2)));
    }

    sort(edges.begin(),edges.end());

    int mst_edges=0,edge_count=0,mst_weight=0;

    while(mst_edges<totalnode-1 || edge_count<totaledge)
    {
         node1 = edges[edge_count].second.first;
         node2 = edges[edge_count].second.second;
         weight = edges[edge_count].first;

         if(find_set(node1) != find_set(node2))
         {
              mst_weight += weight;
              cout<<node1<<" "<<node2<<" "<<weight<<endl;
              unite(node1,node2);
              mst_edges++;
         }
         edge_count++;
    }

    cout<<"Minimum Cost="<<mst_weight<<endl;
    return 0;
}
