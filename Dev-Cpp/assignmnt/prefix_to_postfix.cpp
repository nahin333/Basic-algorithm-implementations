#include <iostream>
#include <stack>

using namespace std;

#define MAX 100
#define OP1_FLAG '#'

bool isOperator(char ch);

int main()
{
    //prefix input expression and postfix output expression
    char prefix[MAX],postfix[MAX];
    stack<char> stk;

    cout<<"Enter the prefix expression\n";
    cin>>prefix;

    int j=0;
    for (int i=0;prefix[i];i++){
        if(isOperator(prefix[i])){
            stk.push(prefix[i]);
        }else {
            //as sequence of operand in prefix and
            //postfix expressions are same
            postfix[j]=prefix[i];
            j++;
             /*OP1_FLAG is a flag that indicates the left operand
              for this operator is already converted to postfix.
              After popping out these OP1 operators the next
              operator is marked OP1_FLAG*/
            while(!stk.empty() && stk.top()==OP1_FLAG){
                stk.pop();
                postfix[j]=stk.top();
                j++;
                stk.pop();
            }
            stk.push(OP1_FLAG);
        }
    }

        postfix[j]=0;

    cout<<"Postfix expression is ::  " << postfix << endl;

    return 0;

}

bool isOperator(char ch){
    if(ch=='+' || ch=='-' || ch == '*' || ch == '/' || ch == '$' || ch == '%')  return true;
    else    return false;
}
