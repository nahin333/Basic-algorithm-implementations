#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int totalnode,node1,node2;

    ifstream input("input.txt");
    ofstream output("output.txt");

    if(input.is_open())
    {
         cout<<"File Open\n";
         input>>totalnode;
         vector< list<int> >adjlst(totalnode);

         while(input>>node1>>node2)
         {
              adjlst[node1].push_back(node2);
         }

         vector <list<int> >::iterator i;
         int c = 0;

         for(i=adjlst.begin(); i!=adjlst.end(); i++)
         {
              output<<c<<"->";
           //   cout<<c<<"->";
              list<int>li = *i;
              list<int> ::iterator iter;
              for(iter=li.begin(); iter!=li.end(); iter++)
              {
                   output<<*iter<<" ";
            //       cout<<*iter<<" ";
              }
             output<<endl;
          //   cout<<endl;
              c++;

         }
    }

    else
     cout<<"Error";

    return 0;


}
