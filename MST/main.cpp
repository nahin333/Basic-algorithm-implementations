#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int parent[100000];

int find_set(int x)
{
    if(parent[x]==x)
    {
        return x;
    }
    else return find_set(parent[x]);
}
int unite(int x,int y)
{
    int fx=find_set(x);
    int fy=find_set(y);
    parent[fy]=fx;
    return 0;
}
int main()
{
    int totalnode,totaledge,node1,node2,weight;
    cin>>totalnode>>totaledge;
    vector<pair<int,pair<int,int>>> info;
    ofstream on("input.txt");
    on<<totalnode<<" "<<totaledge<<endl;
    for(int i=1;i<=totalnode;i++)
    {
        parent[i]=i;
    }
    for(int i=1;i<=totaledge;i++)
    {
        cin>>node1>>node2>>weight;
        on<<node1<<" "<<node2<<" "<<weight<<endl;
        info.push_back(make_pair(weight,make_pair(node1,node2)));
    }
    on.close();
    sort(info.begin(),info.end());
/*for(vector<pair<int,pair<int,int>>>::iterator it=info.begin();it!=info.end();it++)
    {
        cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
    }*/
    int mst_edge=0,edge_count=0,flag1=0,high_weight=-1,mid_weight=-1;
    while(edge_count<=totalnode-1&&mst_edge<totaledge)
    {
        int flag2=0;
        node1=info[edge_count].second.first;
        node2=info[edge_count].second.second;
        weight=info[edge_count].first;
        if(find_set(node1)!=find_set(node2))
        {
            unite(node1,node2);
            edge_count++;
            flag2=1;
            cout<<"yeah ";
        }
        if(flag2!=1)
        {
            if(weight!=high_weight||high_weight==-1)
            {
                if(flag1==1) ;
                else
                {
                    high_weight=weight;
                    flag1=1;
                }
            }
            else mid_weight=weight;
        }
        mst_edge++;
    }
    ifstream in("input.txt");
    in>>node1>>node2;
    for(int i=1;i<=totaledge;i++)
    {
        in>>node1>>node2>>weight;
        if(weight==mid_weight) cout<<"at least one"<<endl;
        else if(weight<mid_weight) cout<<"any"<<endl;
        else cout<<"none"<<endl;

    }
    return 0;
}
