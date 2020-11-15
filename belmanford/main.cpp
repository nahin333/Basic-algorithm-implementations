#include <bits/stdc++.h>
using namespace std;

#define INFINITE 9999999

vector<pair<int,pair<int,int> > >AdjList;
map<int,int> dis;
map<int,int> parent;


int get_parent(int x)
{
    return parent[x];
}

int main()
{
    ifstream input("input.txt");
    if (!input.is_open())
    {
        cout << "could not open file...\n";
        exit(-1);
    }

    int totalnode,totaledge,node1,node2,weight;

    input >> totalnode >> totaledge;
    for (int i=0;i<totaledge;i++)
    {
        input >> node1 >> node2 >> weight;
        AdjList.push_back(make_pair(node1,make_pair(node2,weight)));
        dis[node1] = INFINITE;
        parent[node1] = INFINITE;
    }
    input.close();

    cout << "Enter the source node : ";
    cin >> node1;
    dis[node1] = 0;

    for (int i=0;i<totalnode-1;i++)
    {
        vector<pair<int,pair<int,int> > >::iterator it = AdjList.begin();
        while(it!=AdjList.end())
        {
            node1 = (*it).first;
            node2 = (*it).second.first;
            weight = (*it).second.second;
            if (dis[node1] + weight < dis[node2])
            {
                dis[node2] = dis[node1] + weight;
                parent[node2] = node1;
            }
            it++;
        }
    }

    map<int,int>::iterator it = dis.begin();
    while(it != dis.end())
    {
        node1 = it->first;
        cout << "shortest path to " << node1 << " : " << node1;
        while(1)
        {
            if (get_parent(node1) == INFINITE) break;
            node1 = get_parent(node1);
            cout << " <- " << node1;
        }
        cout << "\n\tpath cost  : " << dis[it->first] << endl << endl;
        it++;
    }
    return 0;
}

