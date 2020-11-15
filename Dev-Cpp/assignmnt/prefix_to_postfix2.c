#include<iostream>
#include<string>

using namespace std;
bool isOperator(char c)
{
    if(ch=='+' || ch=='-' || ch == '*' || ch == '/' || ch == '$' || ch == '%')  return true;
    else    return false;
}

int S[MAX_SIZE];
int top=-1;

void push(int x)
{
    S[++top]=x;
}

void pop()
{
    top--;
}

int Top()
{
    return S[top];
}

int isempty()
{
    if(top == -1)return 1;
    return 0;
}

int main()
{
    string prefix;
    cin>>prefix;
    string t1,t2;
    for(int i=prefix.length()-1; i>=0; i--)
    {
        if(isOperator(prefix[i]))
        {
            t1=Top();
            pop();
            t2=Top();
            pop();
            t2+=prefix[i];
            push(t1+t2);
        }

        else
        {
            t1=" ";
            t1+=perfix[i];
            push(t1);
        }
    }

    string postfix=Top();
    cout<<postfix<<endl;
}
