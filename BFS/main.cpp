#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int>vec[100];
int level[100];
void BFS(int start){
int visited[100]={0};
queue<int>q;
q.push(start);
level[start]=0;
visited[start]=1;
while(!q.empty()){
     int u=q.front();
     q.pop();
     for(int i=0;i<vec[u].size();i++){
          int v=vec[u][i];
          if(!visited[v]){
               visited[v]=1;
               level[v]=level[u]+1;
               q.push(v);
          }
     }

}


}
int main()
{
     int node,edge;
     cin>>node>>edge;
     for(int i=0;i<edge;i++){
          int a,b;cin>>a>>b;
          vec[a].push_back(b);
          vec[b].push_back(a);
     }
     BFS(1);
     for(int i=1;i<=node;i++)cout<<i<<" : "<<level[i]<<endl;
}
