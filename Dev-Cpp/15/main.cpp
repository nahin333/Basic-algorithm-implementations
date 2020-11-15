/*#include <iostream>

using namespace std;
class complx
{
    float x;
    float y;
public:
    void input(float a,float b)
    {
        x=a;
        y=b;
    }
    friend complx sum(complx ,complx);
    void show (complx);
};
complx sum (complx c1,complx c2)
{
    complx c3;
    c3.x=c1.x+c2.x;
    c3.y=c1.y+c2.y;
    return c3;
}
void complx::show(complx c)
{
    cout<<c.x<<endl<<c.y<<endl;
}

int main()
{
    complx A,B,C;

    A.input(3.1,5.65);
    B.input(2.75,1.2);
    C=sum(A,B);
    A.show(A);
    B.show(B);
    C.show(C);
    return 0;
}
*/
/////////////////////////////
/*
#include<iostream>
using namespace std;
class sqr;
class rctngl
{
    int width,hight;
public:
    int area()

    {
        return (width*hight);
    }
    void convrt(sqr a);
};
class sqr
{
  friend class rctngl;
  private:
      int side;
  public:
    sqr(int a){side=a;}

};
void rctngl::convrt(sqr a)
{
    width=a.side;
    hight=a.side;
}
int main()
{
rctngl rct;
sqr sq(4);
rct.convrt(sq);
cout<<rct.area();
}
*/
/////////////////////////////////////
/*
#include<iostream>
using namespace std;
class intg
{
    int m,n;
public:
    intg(int x,int y)
    {
         m=x;
        n=y;
    }

    void display()
    {
        cout<<m<<endl;;
        cout<<n<<endl;
    }
};
intg::intg(int x,int y );

int main()
{
    intg int1=intg(50,100);
    intg int2(25,75);
    int1.display();
    int2.display();

}
*/
////////////////////
/*
#include<iostream>
using namespace std;
int sum(int a,int b)
{
    return a+b;
}
double sum(int a,double b)
{
    return a+b;
}
int main()
{
    int p;
    double q;
    p=sum(10,20);
    q=sum(10,20.20);
    cout<<p<<" "<<q<<endl;
}
*/
/////////////////////////////
/*
#include<iostream>
using namespace std;
class intt
{
    int m,n;
public:
    intt(){m=1,n=1;}
    intt(int x,int y)
    {
        m=x;
        n=y;
    }
    intt(intt &i)
    {
        m=i.m;
        n=i.n;
    }
    void display()
    {
        cout<<m<<" "<<n<<endl;
    }
};
int main()
{
    intt i1;
    intt i2(10,20);
    intt i3(i2);
    i1.display();
    i2.display();
    i3.display();
    return 0;
}
*/
/////////////////////////////////////
/*
#include<iostream>
using namespace std;
class complx
{
    float x,y;
public:
    complx(){}
    complx(float a){x=y=a;}
    complx(float p,float q)
    {
        x=p;
        y=q;
    }
    friend complx sum(complx i,complx j)
    {
        complx k;
        k.x=i.x+j.x;
        k.y=i.y+j.y;
        return k;
    }
friend void disp(complx i)
    {
     cout<<i.x<<" "<<i.y<<endl;
    }
};
int main()
{
    complx a(2.7,3.5);
    complx b(1.6);
    complx c;
    c=sum(a,b);
    disp(a);
    disp(b);
    disp(c);
}
*/
//////////////////////////////
/*
#include<iostream>
using namespace std;
class st
{
    int m;
public:
  /*  st (int i=0)
    {
        m=i;
    }
st()
    {
        m=10;
    }
    void dsly()

    {
        cout<<m;
    }
};
int main()
{
    st a;
    a.dsly();
}
*/
/////////////////////////////
/*
#include<iostream>
using namespace std;
class di
{
    float sum;
    public:
    di (){}
    di(int a,int b,float c=5.4);
    di(int a,int b,int c);
    void disply();
};
di::di(int a,int b,float c )
{
    sum=a+b+c;
}
di::di(int a,int b,int c)
{
    sum=a+b+c;
}
void di::disply()
{
    cout<<sum<<endl;
}
int main()
{
    int p,q,s;
    float r;
    cin>>p>>q>>r;
    di a(p,q,r);
    cin>>p>>q>>s;
    di b(p,q,s);
    cin>>p>>q;
    di c(p,q);
    a.disply();
    b.disply();
    c.disply();
}
*/
////////////////////////////////////
/*
#include<iostream>
using namespace std;
class code
{
    int id;
public:
    code(){}
    code(int a){id=a;}
    code (code &x)
    {
        id=x.id;
    }
    void disply()
    {
        cout<<id<<endl;
    }
};
int main()
{
    code a(10);
    code b(a);
    code c=a;
    code d;
    d=a;
    a.disply();
    b.disply();
    c.disply();
    d.disply();
}
*/
/////////////////////////////////
/*
#include<iostream>
using namespace std;
class swp
{
    int a,b;
public:
     swp (int m,int n)
    {
a=m;
b=n;
    }
    void sp()
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    void dsp()
    {
        cout<<a<<" "<<b<<endl;
    }
};
int main()
        {
            int m,n;
            cin>>m>>n;
            swp a(m,n);
            a.sp();
            a.dsp();
        }
*/
////////////////////////////////////////
/*
#include<iostream>
using namespace std;
class cnt
{
    int m_cnt;
public:
    cnt (int n_cnt)
    {
        m_cnt=n_cnt;
    }
    friend cnt operator+(const cnt &c1,const cnt &c2);
    friend cnt operator-(const cnt &c1,const cnt &c2);
    int disp()
    {
        return m_cnt;
    }

};


cnt operator+(const cnt &c1,const cnt &c2)
{
    return cnt(c1.m_cnt+c2.m_cnt);
}

cnt operator-(const cnt &c1,const cnt &c2)
{
    return cnt(c1.m_cnt-c2.m_cnt);
}

int main()
{
    cnt c1(5);
    cnt c2(3);
    cnt sum=c1+c2; cnt dif=c1-c2;
    cout<<"sum:"<<sum.disp()<<endl<<"difference:"<<dif.disp()<<endl;
}
*/
//////////////////////////////////////////////
/*
#include<iostream>
using namespace std;
class cnt{
    int m_cnt;
public:
   cnt(int n_cnt){m_cnt=n_cnt;}
   friend cnt operator+(const cnt &c1,int c2)
   {
       return cnt(c1.m_cnt+c2);
   }
   friend cnt operator+(int c3,const cnt &c4)
   {
       return cnt(c3+c4.m_cnt);
   }

   int disp(){return m_cnt;}

};

int main()
{
    cnt c1=cnt(4)+6;
    cnt c2=6+cnt(4);
    cout<<"fst:"<<c1.disp()<<" "<<"snd:"<<c2.disp()<<endl;
    return 0;
}
*/
///////////////////////////
/*
#include<iostream>
using namespace std;
class MinMax
{
private:
	int m_min; // The min value seen so far
	int m_max; // The max value seen so far

public:
	MinMax(int min, int max)
	{
		m_min = min;
		m_max = max;
	}

	int getMin() { return m_min; }
	int getMax() { return m_max; }

	friend MinMax operator+(const MinMax &m1, const MinMax &m2);
	friend MinMax operator+(const MinMax &m, int value);
	friend MinMax operator+(int value, const MinMax &m);
};

MinMax operator+(const MinMax &m1, const MinMax &m2)
{
	// Get the minimum value seen in m1 and m2
	int min = m1.m_min < m2.m_min ? m1.m_min : m2.m_min;

	// Get the maximum value seen in m1 and m2
	int max = m1.m_max > m2.m_max ? m1.m_max : m2.m_max;

	return MinMax(min, max);
}

MinMax operator+(const MinMax &m, int value)
{
	// Get the minimum value seen in m and value
	int min = m.m_min < value ? m.m_min : value;

	// Get the maximum value seen in m and value
	int max = m.m_max > value ? m.m_max : value;

	return MinMax(min, max);
}

MinMax operator+(int value, const MinMax &m)
{
	// call operator+(MinMax, nValue)
	return (m + value);
}

int main()
{
	MinMax m1(10, 15);
	MinMax m2(8, 11);
	MinMax m3(3, 12);

	MinMax mFinal = m1 + m2 + 5 + 8 + m3 + 16;

	std::cout << "Result: (" << mFinal.getMin() << ", " <<
		mFinal.getMax() << ")\n";

	return 0;
}
*/
/////////////////////////////////////
/*
#include<iostream>
using namespace std;
class cnt{
     int m_cnt;
 public:
    cnt(int n_cnt){m_cnt=n_cnt;}
    cnt operator+(int n_cnt);
    int disp(){return m_cnt;}

};

cnt cnt::operator+(int n_cnt)
{
   return cnt(m_cnt+n_cnt);
}
int main()
{
    cnt c1(6);
    cnt c2=c1+4;
    cout<<c2.disp();

}
*/
/////////////////////////////////////
/*
#include<iostream>
using namespace std;
class mt{
    int real,img;
 public:
     void inp(int real,int img){
     this->real=real;
     this->img=img;}
     mt add (mt obj)
     {
         mt temp;
         temp.real=real+obj.real;
         temp.img=img+obj.img;
         return temp;
     }
     void out()
     {
         cout<<real<<"+i"<<img;
     }
};

int main()
{
    mt a,b;
    a.inp(1,2);
    b.inp(3,4);
    mt c;
    c=a.add(b);
    c.out();
    return 0;
}
*/
////////////////////////////////////
/*
#include<iostream>
using namespace std;
class mt{
    int real,img;
 public:
     void inp(int real,int img){
     this->real=real;
     this->img=img;}
     mt operator+(mt obj)
     {
         mt temp;
         temp.real=real+obj.real;
         temp.img=img+obj.img;
         return temp;
     }
      mt operator-(mt obj)
     {
         mt temp;
         temp.real=real-obj.real;
         temp.img=img-obj.img;
         return temp;
     }
     void out()
     {
         cout<<real<<"+i"<<img<<endl;
     }
};

int main()
{
    mt a,b;
    a.inp(1,2);
    b.inp(3,4);
    mt c,d;
    c=a+b;
    d=a-b;
    c.out();
    d.out();
    return 0;
}
*/
/////////////////////////////
/*
#include<iostream>
using namespace std;
class mt{
    int real,img;
 public:
     void inp(int real,int img){
     this->real=real;
     this->img=img;}
     mt operator+(mt obj)
     {
         mt temp;
         temp.real=real+obj.real;
         temp.img=img+obj.img;
         return temp;
     }
      mt operator-(mt obj)
     {
         mt temp;
         temp.real=real-obj.real;
         temp.img=img-obj.img;
         return temp;
     }
     mt operator+(int num)
     {

         mt temp;
         temp.real=real+num;
         temp.img=img;
         return temp;

     }
    friend  mt operator+(int num,mt a)
     {

         mt temp;
         temp.real=a.real+num;
         temp.img=a.img;
         return temp;

     }
     void out()
     {
         cout<<real<<"+i"<<img<<endl;
     }
};

int main()
{
    mt a,b;
    a.inp(1,2);
    b.inp(3,4);
    mt c,d;
    c=a+b;
    c.out();
    c=a+5;
    c.out();
    c=5+a;
    d=a-b;
    c.out();
    d.out();
    return 0;
}
*/
/*
  Evaluation Of postfix Expression in C++
  Input Postfix expression must be in a desired format.
  Operands must be integers and there should be space in between two operands.
  Only '+'  ,  '-'  , '*' and '/'  operators are expected.
*/
//////////////////////
/*
#include<iostream>
//#include<stack>
#include<string>
#define MAX_SIZE 100

using namespace std;
int S[MAX_SIZE];
int top = -1;
void push(int x)
{
  if(top == MAX_SIZE -1) { // overflow case.
		cout<<"Error: stack overflow\n";
		return;
	}
	S[++top] = x;
}


void pop()
{
	if(top == -1) {
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

	for(int i = 0;i< expression.length();i++) {

		// Scanning each character from left.
		// If character is a delimitter, move on.
		if(expression[i] == ' ' || expression[i] == ',') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back.
		else if(IsOperator(expression[i])) {
			// Pop two operands.
			int operand2 = S[top]; pop();
			int operand1 = S[top]; pop();
			// Perform operation
			int result = PerformOperation(expression[i], operand1, operand2);
			//Push back result of operation on stack.
			push(result);
		}
		else if(IsNumericDigit(expression[i])){
			// Extract the numeric operand from the string
			// Keep incrementing i as long as you are getting a numeric digit.
			int operand = 0;
			while(i<expression.length() && IsNumericDigit(expression[i])) {
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
	return S[top];
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
}*/
/*
#include<ios>
using namespace std;
#define MAX_SIZE=100
int S[MAX_SIZE];
int top = -1;
void push(int x)
{
  if(top == MAX_SIZE -1) { // overflow case.
		printf("Error: stack overflow\n");
		return;
	}
	S[++top] = x;
}

// Pop operation to remove an element from top of stack.
void pop()
{
	if(top == -1) { // If stack is empty, pop should throw error.
		printf("Error: No element to pop\n");
		return;
	}
	top--;
}

// Top operation to return element at top of stack.
int top()
{
	return A[top];
}

// This function will return 1 (true) if stack is empty, 0 (false) otherwise
int IsEmpty()
{
    if(top == -1) return 1;
    return 0;
}

*/
///////////////////////////////
/*

#include <iostream>
using namespace std;

class array {
    int arr[10];

    class tempClass {
        int tempInt;
    public:
        tempClass(int temp) : tempInt(temp) {   }
        int operator[](int add) {
            return tempInt+add;
        }
    };

public:
    array();
    tempClass operator[](int);
};

array::array() {
    for (int i = 1; i < 11; ++i) {
        arr[i] = i*10;
    }
}

array::tempClass array::operator[](int x) {
    return tempClass(arr[x]);
}

int main() {
    array a1;
    cout << a1[3][12] << endl;
    return 0;
}
*/
////////////////////////////
/*
#include<iostream>
using namespace std;
template <typename T> class Array2D
{
    class Proxy // this is for handling double subscript operator overloading
    {
        T* array1D;
    public:
        Proxy() {}
        void init(int maxY)
        {
            array1D=new T[maxY];
        }
        ~Proxy()
        {
            delete[] array1D;
        }
        T& operator[] (int y)
        {
            return array1D[y];
        }
    };

    Proxy* proxy1D;
    int _rows;
    int _cols;
public:
    Array2D(int maxX, int maxY)
    {
        _rows=maxX;
        _cols=maxY;
        proxy1D=new Proxy[_rows];
        for (int x=0;x<_rows;x++)
            proxy1D[x].init(_cols);
    }
    ~Array2D()
    {
        delete[] proxy1D;
    }
    Proxy& operator[] (int x)
    {
        return proxy1D[x];
    }
    int rows() { return _rows; }
    int columns() { return _cols; }
};

class Student   // An example of a user defined type that can be used with the Array2D class
{
public:
    int roll;
    string name;
    Student(int r=0, string n=""): roll(r),name(n) {}
    friend ostream& operator << (ostream& ,const Student& );
};

ostream& operator << (ostream& o,const Student& s)    // overloading the << operator for cout. You can exclude this and print each students property using dot operator
{
    o << "{ " << s.roll << "," << s.name << " }";
    return o;
}

int main()
{
    cout << "Declaring a 4 by 5 array of floats and assigning values now!" << endl;
    Array2D<float> a2D(4,5);
    for (int i=0;i<4;i++)
        for (int j=0;j<5;j++)
            a2D[i][j]=i*5+j+0.38f;
    cout << "Done successfully! Now array contains: " << endl;
    cout << "Rows: " << a2D.rows() << endl;
    cout << "Columns: " << a2D.columns() << endl;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<5;j++)
            cout << a2D[i][j] << " ";
        cout << endl;
    }

    cout << endl << "Now the real part!" << endl << endl;
    cout << "Declaring a 2 by 3 array of Students now and assigning values!" << endl;
    Array2D<Student> s2D(2,3);
    s2D[0][0]=Student(38,"Raihanul");
    s2D[0][1]=Student(6,"Rahat");
    s2D[0][2]=Student(7,"Sakib");
    s2D[1][0]=Student(5,"Sourav");
    s2D[1][1]=Student(0,"Alu");
    s2D[1][2]=Student(122,"No one XD");
    cout << "Now array contains: " << endl;
    cout << "Rows: " << s2D.rows() << endl;
    cout << "Columns: " << s2D.columns() << endl;
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<3;j++)
            cout << s2D[i][j] << "    ";
        cout << endl << endl;
    }
    cout << "Successful! :) ";
    return 0;
}
*/
/*
#include<iostream>
using namespace std;
class test
{
    static int d;
public:
    void getter(){
        cout<<d<<endl;
    }
    void setter(){
        d++;
    }
int main()
{
    test obj;
    obj.setter();
    obj.setter();
    obj.getter();
    test obj1;
    obj1.setter();
    obj1.getter();
    return 0;
}
*/
/*
#include<iostream>
using namespace std;
class stk
{
    static int d;
public:

    void str()
    {
        d++;
    }
    void disp()
    {
        cout<<d<<endl;
    }

};

int main()
{
    stk obj;
    obj.str();
    obj.str();
    obj.disp();

}
*/
/*
#include<bits/stdc++.h>
using namespace std;
class M
{
   public:
	   void display (void)
       { cout << "Class M \n";}
};
class N
{
	public:
	   void display (void)
       { cout << "Class N \n";}
};

class P : public M, public N
{
   public:
	   void display (void)
       { M :: display();}
};

int  main( )
{
	P p;
	p.display( );
}
*/
#include <iostream>
using namespace std;
class base {

protected:
int i, j; // private to base, but accessible by derived
public:
void set(int a, int b) { i=a; j=b; }
void show() { cout << i << " " << j << "\n"; }
};
class derived : public base {
int k;
public:
// derived may access base's i and j
void setk() { k=i*j; }
void showk() { cout << k << "\n"; }
};
int main()
{
derived ob;
ob.set(2, 3); // OK, known to derived
ob.show(); // OK, known to derived
ob.setk();
ob.showk();
return 0;
}
