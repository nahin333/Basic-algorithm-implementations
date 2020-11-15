
#include<iostream>
#include<string>
#define MAX_SIZE 100

using namespace std;
int S[MAX_SIZE];
int top = -1;
void push(int x)
{
    if(top == MAX_SIZE -1)
    {
        cout<<"Error: stack overflow\n";
        return;
    }
    S[++top] = x;
}


void pop()
{
    if(top == -1)
    {
        cout<<"Error: No element to pop\n";
        return;
    }
    top--;
}


int Top()
{
    return S[top];
}


int IsEmpty()
{
    if(top == -1) return 1;
    return 0;
}


// Function to evaluate Postfix expression and return output
int EvaluatePostfix(string expression);

// Function to perform an operation and return output.
int PerformOperation(char operation, int operand1, int operand2);

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is numeric digit.
bool IsNumericDigit(char C);

int main()
{
    string expression;
    cout<<"Enter Postfix Expression \n";
    getline(cin,expression);
    int result = EvaluatePostfix(expression);
    cout<<"Output = "<<result<<"\n";
}

// Function to evaluate Postfix expression and return output
int EvaluatePostfix(string expression)
{
    // Declaring a Stack from Standard template library in C++.
//	stack<int> S;

    for(int i = 0; i< expression.length(); i++)
    {

        // Scanning each character from left.
        // If character is a delimitter, move on.
        if(expression[i] == ' ' || expression[i] == ',') continue;

        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if(IsOperator(expression[i]))
        {
            // Pop two operands.
            int operand2 = Top();
            pop();
            int operand1 = Top();
            pop();
            // Perform operation
            int result = PerformOperation(expression[i], operand1, operand2);
            //Push back result of operation on stack.
            push(result);
        }
        else if(IsNumericDigit(expression[i]))
        {
            // Extract the numeric operand from the string
            // Keep incrementing i as long as you are getting a numeric digit.
            int operand = 0;
            while(i<expression.length() && IsNumericDigit(expression[i]))
            {
                // For a number with more than one digits, as we are scanning from left to right.
                // Everytime , we get a digit towards right, we can multiply current total in operand by 10
                // and add the new digit.
                operand = (operand*10) + (expression[i] - '0');
                i++;
            }
            // Finally, you will come out of while loop with i set to a non-numeric character or end of string
            // decrement i because it will be incremented in increment section of loop once again.
            // We do not want to skip the non-numeric character by incrementing i twice.
            i--;

            // Push operand on stack.
            push(operand);
        }
    }
    // If expression is in correct format, Stack will finally have one element. This will be the output.
    return Top();
}

// Function to verify whether a character is numeric digit.
bool IsNumericDigit(char C)
{
    if(C >= '0' && C <= '9') return true;
    return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;

    return false;
}

// Function to perform an operation and return output.
int PerformOperation(char operation, int operand1, int operand2)
{
    if(operation == '+') return operand1 +operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / operand2;

    else cout<<"Unexpected Error \n";
    return -1;
}
*/


#include<iostream>
//#include<stack>
#include<string>
#define MAX_SIZE 100

using namespace std;

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

// Function to convert Infix expression to postfix
string InfixToPostfix(string expression);

// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
bool IsOperand(char C);

int main()
{
    string expression;
    cout<<"Enter Infix Expression \n";
    getline(cin,expression);
    string postfix = InfixToPostfix(expression);
    cout<<"Output = "<<postfix<<"\n";
}

// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
    // Declaring a Stack from Standard template library in C++.
//	stack<char> S;
    string postfix = ""; // Initialize postfix as empty string.
    for(int i = 0; i< expression.length(); i++)
    {

        // Scanning each character from left.
        // If character is a delimitter, move on.
        if(expression[i] == ' ' || expression[i] == ',') continue;

        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if(IsOperator(expression[i]))
        {
            while(!isempty() && Top() != '(' && HasHigherPrecedence(Top(),expression[i]))
            {
                postfix+= Top();
                pop();
            }
            push(expression[i]);
        }
        // Else if character is an operand
        else if(IsOperand(expression[i]))
        {
            postfix +=expression[i];
        }

        else if (expression[i] == '(')
        {
            push(expression[i]);
        }

        else if(expression[i] == ')')
        {
            while(!isempty() && Top() !=  '(')
            {
                postfix += Top();
                pop();
            }
            pop();
        }
    }

    while(!isempty())
    {
        postfix += Top();
        pop();
    }

    return postfix;
}

// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
    if(C >= '0' && C <= '9') return true;
    if(C >= 'a' && C <= 'z') return true;
    if(C >= 'A' && C <= 'Z') return true;
    return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/' || C== '^')
        return true;

    return false;
}

// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op)
{
    if(op == '^') return true;
    return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
    int weight = -1;
    switch(op)
    {
    case '+':
    case '-':
        weight = 1;
        break;
    case '*':
    case '/':
        weight = 2;
        break;
    case '^':
        weight = 3;
        break;
    }
    return weight;
}

// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if(op1Weight == op2Weight)
    {
        if(IsRightAssociative(op1)) return false;
        else return true;
    }
    return op1Weight > op2Weight ?  true: false;
}
