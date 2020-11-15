#include<bits/stdc++.h>
using namespace std;

int board[20],cnt;
void queen(int row,int n);


///function for printing the solution
void print(int n)
{
    int i,j;

    cout<<"\n\n"<<++cnt<<"\n\n";

    for(i=1; i<=n; ++i)

        cout<<"\t"<<i;

    for(i=1; i<=n; ++i)
    {

        cout<<"\n\n"<<i;

        for(j=1; j<=n; ++j) ///for nxn board
        {
            if(board[i]==j)

                cout<<"\tQ"; ///queen at i,j position
            else

                cout<<"\t-"; ///empty slot
        }
    }
}

///funtion to check conflicts
///If no conflict for desired postion returns 1 otherwise returns 0
int place(int row,int column)
{
    int i;
    for(i=1; i<=row-1; ++i)
    {
        ///checking column and digonal conflicts
        if(board[i]==column || abs(board[i]-column)==abs(i-row))
            return 0;


    }

    return 1; ///no conflicts
}

///function to check for proper positioning of queen
void queen(int row,int n)
{
    int column;
    for(column=1; column<=n; ++column)
    {
        if(place(row,column))
        {
            board[row]=column; ///no conflicts so place queen
            if(row==n) ///dead end
                print(n); ///printing the board configuration
            else ///try queen with next position
                queen(row+1,n);
        }
    }
}


int main()
{
    int n,i,j;


    cout<<"Enter number of Queens:";
    cin>>n;
    queen(1,n);
    return 0;
}
