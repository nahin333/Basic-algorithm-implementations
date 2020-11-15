#include <bits/stdc++.h>

using namespace std;
vector<int> myvec;

bool is_visited(int ch)
{
    vector<int>::iterator it8=myvec.begin();
    while(it8!=myvec.end())
    {
        if (ch==(*it8))
            return true;
        it8++;
    }
    return false;
}

map<int,int> level;
map<int,int> parent;

int main()
{
    ifstream input("graph.txt");
    if (!input.is_open())
    {
        cout << "could not open the file..\n";
        return -1;
    }

    map<int,list<int>> mymap;

    int a,b;
    while(input >> a >> b)
    {
        mymap[a].push_back(b);
    }
    input.close();

    //printing the adjacency list...

    map<int,list<int>>::iterator it = mymap.begin();

    while(it!=mymap.end())
    {
        cout << it->first  << " : ";
        list<int>::iterator itL = it->second.begin();
        while(itL != it->second.end())
        {
            cout << (*itL) << " ";
            itL++;
        }
        it++;
        cout << endl;
    }
    // BFS

    cout << "Enter source node : ";
    int src,dst;
    cin >> src;
    cout << "Enter destination node : ";
    cin >> dst;
    queue<int> Q;
    Q.push(src);
    level[src] = 0;
    parent[src] = 0;
    list<int>::iterator itt;
    while(!Q.empty())
    {
        src = Q.front();
        Q.pop();
        itt = mymap[src].begin();
        while(itt!=mymap[src].end())
        {
            if (!is_visited((*itt)))
            {
                if ((*itt)==dst)
                {
                    level[(*itt)] = level[src] + 1;
                    parent[(*itt)] = src;
                    goto A;
                }

                if ((*itt)) {
                    Q.push((*itt));
                    myvec.push_back((*itt));
                    level[(*itt)] = level[src] + 1;
                    parent[(*itt)] = src;
                }
            }
            itt++;
        }

    }
A:
    cout << "path distance : " << level[(*itt)] << endl;

    int x=dst;
    myvec.clear();
    myvec.push_back(dst);
    while(x)
    {
        x = parent[x];
        myvec.push_back(x);
    }

    if (!level[(*itt)])
    {
        cout << "there's no such path ...";
        return 0;
    }
    cout << "path : ";
    x = myvec.size() - 1;
    for (; x>=0; x--)
    {
        if (myvec[x]) cout << myvec[x] << " ";
    }

    return 0;
}
