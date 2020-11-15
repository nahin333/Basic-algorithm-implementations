#include <bits/stdc++.h>

using namespace std;
map<int,bool> visit;
bool is_visited(int node)
{
    if (visit[node]== true) return true;
    else return false;
}

int main()
{
    ifstream input("input.txt");
    if (!input.is_open())
    {
        cout << "could not open the file...\n";
        return -1;
    }
    int totalnode,totaledge,node1,node2,weight;
    input >> totalnode >> totaledge;
    map<int,list<pair<int,int>>> mymap;
    for (int i=0; i<totaledge; i++)
    {
        input >> node1 >> node2 >> weight;
        mymap[node1].push_back(make_pair(node2,weight));
        mymap[node2].push_back(make_pair(node1,weight));
        visit[node1] = false;
        visit[node2] = false;
    }
    cout << "Enter the source node : ";
    int src;
    cin >> src;

    vector<int> container;
    container.push_back(src);
    visit[src]=true;

    int edge_count=0,smallest = 9999999;
    list<pair<int,int>>::iterator it;
    while(edge_count<totalnode-1)
    {
        for (int i=0; i<container.size(); i++)
        {
            src = container[i];
            for (it=mymap[src].begin(); it!=mymap[src].end(); it++)
            {
                if ((*it).second < smallest &&  !is_visited((*it).first))
                {
                    node1 = src;
                    node2 = (*it).first;
                    smallest = (*it).second;
                }
            }
        }
        visit[node2]=true;
        container.push_back(node2);//cout << "pushing : " << node1 << endl;
        cout << node1 << " " << node2 << " " << smallest << endl;
        edge_count++;
        smallest = 9999999;
    }

    return 0;
}
