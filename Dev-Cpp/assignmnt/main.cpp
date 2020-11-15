#include<iostream>
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

int EvaluatePostfix(string expression);


int PerformOperation(char operation, int operand1, int operand2);


bool IsOperator(char C);


bool IsNumericDigit(char C);

int main()
{
	string expression;
	cout<<"Postfix Expression:";
	getline(cin,expression);
	expression=string(expression.rbegin(),expression.rend());
	int result = EvaluatePostfix(expression);
	cout<<"output:"<<result<<endl;
}


int EvaluatePostfix(string expression)
{


	for(int i = 0;i< expression.length();i++) {


		if(expression[i] == ' ' || expression[i] == ',') continue;


		else if(IsOperator(expression[i])) {
			int operand2 = Top(); pop();
			int operand1 =Top(); pop();
			int result = PerformOperation(expression[i], operand1, operand2);
			push(result);
		}
		else if(IsNumericDigit(expression[i])){
			int operand = 0;
			while(i<expression.length() && IsNumericDigit(expression[i])) {

				operand = (operand*10) + (expression[i] - '0');
				i++;
			}

			i--;
			push(operand);
		}
	}
	return Top();
}

bool IsNumericDigit(char C)
{
	if(C >= '0' && C <= '9') return true;
	return false;
}

bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}

int PerformOperation(char operation, int operand1, int operand2)
{
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else cout<<"Unexpected Error \n";
	return -1;
}
