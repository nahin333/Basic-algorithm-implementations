#include <bits/stdc++.h>

using namespace std;

struct node
{
    int id;
    int distance;
    node(int _id)
    {
        id = _id;
        distance = 99999999;
    }
};

map<int,list<pair<node,int> > > mymap;
priority_queue<node> pq;
map<int,int> final_distance;

bool operator<(node a, node b)
{
    return a.distance > b.distance;
}

int main()
{
    ifstream input("input.txt");
    if (!input.is_open())
    {
        cout << "could not open the file...\n";
        return -1;
    }

    int no_of_vertex,no_of_edges,src,dest,weight;
    input >> no_of_vertex >> no_of_edges;

    for (int i=0; i<no_of_edges; i++)
    {
        input >> src >> dest >> weight;
        node ob(dest);
        mymap[src].push_back(make_pair(ob,weight));
    }
    for (int i=1;i<=no_of_vertex;i++)
    {
        final_distance[i] = 999999;
    }

    list<pair<node,int>>::iterator it;
    cout << "Enter the source : ";
    int source,src_distance;
    cin >> source;
    node obb(source);
    obb.distance = 0;
    final_distance[source] = 0;
    pq.push(obb);

    while(!pq.empty())
    {
        source = pq.top().id;
        src_distance = pq.top().distance;
        it = mymap[source].begin();
        while(it!=mymap[source].end())
        {
            if (final_distance[(*it).first.id] > ((*it).second + src_distance))
            {
                (*it).first.distance = (*it).second + src_distance;
                pq.push((*it).first);
                final_distance[(*it).first.id] = (*it).second + src_distance;
                //cout << "Node " <<(*it).first.id << " and distance " << final_distance[(*it).first.id] << endl;
            }
            it++;
        }
        pq.pop();
    }
    cout << "shortest path of the nodes from source is : \n";
    map<int,int>::iterator itt = final_distance.begin();
    while(itt!=final_distance.end())
    {
        cout << "node : " << itt->first << " distance : " << itt->second << endl;
        itt++;
    }
    input.close();
    return 0;
}
