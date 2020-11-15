#include <bits/stdc++.h>
#define INF 1000000

using namespace std;
int AdjMat[100][100];
int Parent[100][100];

int pathfind(int src,int dst)
{
    if(src == dst)
    {
        cout<<"Path: "<<src;
        return 0;
    }

    pathfind(src,Parent[src][dst]);
    cout<<" "<<dst;


}

int main()
{
    int totalnode,node1,node2,weight;

    ifstream input("tst.txt");
    input>>totalnode;

    for(int i=1; i<=totalnode; i++)
    {
        for(int j=1; j<=totalnode; j++)
        {
            if(i == j)
                AdjMat[i][j] = 0;
            else

                AdjMat[i][j]=INF;
            Parent[i][j]=i;

        }
    }

    while(input>>node1>>node2>>weight)
    {
        AdjMat[node1][node2] =weight;
        //   Parent[node1][node2] = weight;
    }



    for(int k=1; k<=totalnode; k++)
    {
        for(int i=1; i<=totalnode; i++)
        {
            for(int j=1; j<=totalnode; j++)
            {
                if( AdjMat[i][k]+AdjMat[k][j] < AdjMat[i][j] )
                {
                    AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
                    Parent[i][j] = Parent[k][j];

                }
            }
        }
    }
    cout<<"AdjMat"<<endl;
    for(int i=1; i<=totalnode; i++)
    {
        for(int j=1; j<=totalnode; j++)
        {
            cout<<AdjMat[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"parent"<<endl;
    for(int i=1; i<=totalnode; i++)
    {
        for(int j=1; j<=totalnode; j++)
        {
            cout<<Parent[i][j]<<" ";
        }
        cout<<endl;
    }






    int source,dest;
    cout<<"Enter source & destination: ";
    cin>>source>>dest;
    cout<<"Distance: "<<AdjMat[source][dest]<<endl;
    pathfind(source,dest);

    return 0;
}
