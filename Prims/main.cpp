#include <bits/stdc++.h>

using namespace std;

int totalnode,node1,node2,weight;
vector<vector<pair<int,int> > >Adjlist(1000);
vector<int> visited;
priority_queue<pair<int,pair<int,int> > >pq;


int process(int vtx)
{
     visited[vtx] = 1;
     for(int j=0;j<Adjlist[vtx].size();j++)
     {
          pair<int,int> v = Adjlist[vtx][j];
          if(!visited[v.first])
          {
               pq.push(make_pair(-v.second,make_pair(-v.first,-vtx)));
          }
     }
     return 0;
}

int main()
{
     ifstream input ("input.txt");

     if(!input.is_open())
     {
          cout<<"File not open\n";

     }

     input>>totalnode;

     while(input>>node1>>node2>>weight)
     {
          Adjlist[node1].push_back(make_pair(node2,weight));
          Adjlist[node2].push_back(make_pair(node1,weight));

     }

//     for(int i=0;i<totalnode;i++)
//     {
//          for(int j=0;j<Adjlist[i].size();j++)
//          {
//               pair<int,int> v = Adjlist[i][j];
//               cout<<v.first<<"("<<v.second<<")->";
//          }
//          cout<<endl;
//     }

     visited.assign(totalnode,0);
     int source;
     cout<<"Enter Source Node: ";
     cin>>source;
     process(source);
     int mst_cost = 0;

     while(!pq.empty())
     {
          pair<int,pair<int,int> > frnt = pq.top();
          pq.pop();
          int v,w,u;
          u=-frnt.second.second;
          v=-frnt.second.first;
          w=-frnt.first;

          if(!visited[v])
          {
               mst_cost+=w;
               cout<<u<<"->"<<v<<"("<<w<<")";
               process(v);
          }
          cout<<endl;

     }
     cout<<"Mst cost"<<mst_cost;

}

