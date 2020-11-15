#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int roll;
    char name[20];


    ///write on file
    ofstream myfile("test.txt");
    //  myfile.open("test.txt");

    if (myfile.is_open())
    {
        cout<<"file created\n";
        myfile<<"shamim sir xoss"<<endl;

        for(int i=0; i<3; i++)
        {
            cin>>roll>>name;
            myfile<<roll<<" "<<name<<endl;
        }

    }
    else
    {
        cout<<"error";
    }


///read from file

    ifstream yourfile("test1.txt");

    if(yourfile.is_open())
    {

        while(yourfile>>roll>>name)
        {
            cout<<roll<<" "<<name<<endl;
        }

    }
    else
        cout<<"file not exists";





    return 0;
}
