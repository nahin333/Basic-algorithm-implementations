#include<bits/stdc++.h>
using namespace std;


int board[100][100];
int n;

void  print_board()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool check(int row,int col)
{
    for(int i=0;i<col;i++)
    {
        if(board[row][i])
            return false;
    }

    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j])
            return false;
    }

    for(int i=row,j=col;i<n&&j>=0;i++,j--)
    {
        if(board[i][j])
            return false;
    }

    return true;
}

bool solve(int col)
{
    if(col==n)
    {
        print_board();
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(check(i,col))
        {
            board[i][col]=1;
            if(solve(col+1))
                return 1;
            board[i][col]=0;
        }
    }

    return 0;
}


int main()
{
    cin>>n;
    solve(0);
}

