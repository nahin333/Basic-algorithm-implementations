#include<iostream>
#include<map>
#include<vector >
#include<stdio.h>
typedef long long int ll;

using namespace std;

int finishingtime[10000];
vector<int>vec[100];
map<int,string>color;
int visited[1000];
vector<int>v;
int startingtime[1000];
int time=0,n;
int DFS_VISIT(int);
void DFS(int n)
{
    for(int i=1; i<=n; i++)
    {
        color[i]="white";
    }
    for(int i=0; i<n; i++)
    {
        if(color[i]=="white")
        {
            DFS_VISIT(i);
        }
    }
}
int DFS_VISIT(int node)
{
    color[node]="gray";
    time++;
    startingtime[node]=time;
    for(int i=0; i<vec[node].size(); i++)
    {
        if(color[vec[node][i]]=="white")DFS_VISIT(vec[node][i]);
    }
    v.push_back(node);
    color[node]="black";
    time++;
    finishingtime[node]=time;
}
int main()
{
    freopen("in.txt","r",stdin);

    int m;
    cin>>m;
    int a,b;
    while(cin>>a>>b)
    {
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    DFS(m);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }




}
