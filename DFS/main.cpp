#include <iostream>
#include<vector>
#include<map>
using namespace std;
void DFS_VISIT(int start);
vector<int>vec[100];
map<int ,string>color;
int DFS(int node){
for(int i=1;i<=node;i++)
     color[i]="white";
 for(int i=1;i<=node;i++){
     if(color[i]=="white")DFS_VISIT(i);
 }

}
void DFS_VISIT(int start){
     color[start]="gray";
     for(int i=0;i<vec[start].size();i++){
               int v=vec[start][i];
          if(color[v]=="white")DFS_VISIT(v);
     }
     color[start]="black";


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
     DFS(1);
}
