#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int totalnode,node1,node2,weight;
    int mat[10][10] = {0};

    ifstream input("input.txt");


    if(input.is_open())
    {
        cout<<"File opened\n";
        input>>totalnode;

        while(input>>node1>>node2>>weight)
        {
            mat[node1][node2] = weight;
        }


        ofstream output("output.txt");

        if(output.is_open())
        {
            cout<<"created\n";

            for(int i=1; i<=totalnode; i++)
            {
                 for(int j=1; j<= totalnode; j++)

                      output<<mat[i][j]<<" ";
                      output<<endl;

            }


        }

        else
        {
             cout<<"not created";
        }

    }

    else
    {
         cout<<"not opened";
    }

}
