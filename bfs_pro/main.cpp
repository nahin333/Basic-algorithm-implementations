#include <iostream>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

class nodeproperty
{
public:

    int nodeid;
    char color;
    int distance;
    int parent;

    nodeproperty(int nid,char c,int d,int p)
    {
        nodeid = nid;
        color = c;
        distance = d;
        parent = p;
    }
};

vector<nodeproperty>node;
vector<int>path;

int stenodeproperty(int nid,char c,int d,int p)
{
     vector<nodeproperty>::iterator i;

    for(i=node.begin(); i!=node.end(); i++)
    {
         advance(i,nid);
         (*i).color = c;
         (*i).distance = d;
         (*i).parent = p;
         break;
    }
    return 0;
}

int isvisited(int v)
{
    vector<nodeproperty>::iterator i;

    for(i=node.begin(); i!=node.end(); i++)
    {
        advance(i,v);
        if((*i).color != 'w')
           return (*i).distance;

    }
    return 0;
}

int distanceofU(int u)
{
    vector<nodeproperty>::iterator i;

    for(i=node.begin(); i!=node.end(); i++)
    {
        advance(i,u);

        return (*i).distance;
    }
    return 0;
}

int colorchangeofU(int v)
{
    vector<nodeproperty>::iterator i;

    for(i=node.begin(); i!=node.end(); i++)
    {
        advance(i,v);
        (*i).color = 'b';
        break;


    }
    return 0;
}
int destpath(int nid)
{
     vector<nodeproperty>::iterator i;

    for(i=node.begin(); i!=node.end(); i++)
    {
         advance(i,nid);
         return (*i).parent;
    }
    return 0;
}

int searchpath(int dest)
{
     vector<nodeproperty>::iterator i;

    for(i=node.begin(); i!=node.end(); i++)
    {
         advance(i,dest);
    /*
        if((*i).distance!=555)
         cout<<"Distance: "<<(*i).distance;

        else
         {
              cout<<"Not reached\n";
              break;
         }
         */
         int parent = (*i).parent;
         path.push_back(dest);
         path.push_back(parent);
         while(1)
         {
              parent = destpath(parent);
              if(parent== -1)
              break;
              path.push_back(parent);

         }
         cout<<"\n Path: ";
         for(int m=path.size()-1;m>=0;m--)
         {
              cout<<path[m];
              if(m!=0)
               cout<<" -> ";
         }
         break;
    }
     return 0;
}


int BFS(vector<list<int> >adjList, int source)
{
     stenodeproperty(source,'g',0,-1);
     int queuesize = adjList.size();
     int nodequeue[queuesize];
     for(int n=0;n<queuesize;n++)
     {
          nodequeue[n]=-1;
     }
     int insertpoint = 0, deletepoint = 0;
     nodequeue[insertpoint++] = source;

     while(deletepoint!= queuesize)
     {
          int u = nodequeue[deletepoint++];

          if(u==-1)
               break;
          vector<list<int> >::iterator i;

          for(i=adjList.begin();i!=adjList.end();i++)
          {
               advance(i,u);
               list<int> li= *i;
               list<int>::iterator iter;

               for(iter=li.begin();iter!=li.end();iter++)
               {
                    bool visit = isvisited(*iter);
                    if(!visit)
                    {
                         int d = distanceofU(u);
                         stenodeproperty(*iter,'g',d+1,u);
                         nodequeue[insertpoint++] = *iter;
                    }
               }
               colorchangeofU(u);
               break;
          }
           for(int n=0;n<queuesize; n++)
           cout<<nodequeue[n]<<" ";
           cout<<endl;

     }
     return 0;
}

int main()
{
    int totalnode,node1,node2,source,destination;
    ifstream input("input.txt");
    input>>totalnode;
    vector<list<int> >adjList(totalnode);

    while(input>>node1>>node2)
    {
        adjList[node1].push_back(node2);
    }
    input.close();

    for(int m=0; m<totalnode; m++)
    {
        node.push_back(nodeproperty(m,'w',555,-1));
    }

/*    vector<nodeproperty>::iterator i;

    for(i=node.begin(); i!=node.end(); i++)
    {
        cout<<"["<<(*i).nodeid<<","<<(*i).color<<","<<(*i).distance<<","<<(*i).parent<<"]";
        cout<<endl;
    }
*/

    cout<<"Entr Source: ";
    cin>>source;
    BFS(adjList,source);
    vector<nodeproperty>::iterator i;

    cout<<"Entr destination: ";
    cin>>destination ;
    if(destination == source)
    {
         cout<<"Source & destination are same\n";

    }
    else
    searchpath(destination);

    return 0;
}

/*
9
0 1
0 2
0 5
1 2
1 6
2 5
3 2
4 2
4 3
4 7
5 3
6 2
6 4
7 3
7 8
8 2
8 6
*/
