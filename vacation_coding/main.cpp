/*

#include <iostream>
#include <string>

class Person
{
public:
    std::string m_name;
    int m_age;

    Person(std::string name = "", int age = 0)
        : m_name(name), m_age(age)
    {
    }

    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }

};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
public:
    double m_battingAverage;
    int m_homeRuns;

    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
       : m_battingAverage(battingAverage), m_homeRuns(homeRuns)
    {
    }
};

int main()
{
    // Create a new BaseballPlayer object
    BaseballPlayer joe;
    // Assign it a name (we can do this directly because m_name is public)
    joe.m_name = "Joe";
    // Print out the name
    std::cout << joe.getName() << '\n';

    return 0;
}


*/
//////////////////////////////////////////////////////////////////////////////////////////
/*

#include<iostream>
#define SIZE 100
using namespace std;


class stack{
       int stck[SIZE];
       int tos;

   public:
    void init();
    void push(int i);
    int pop();
};


//stack mystack;
void stack::init()
{
    tos=0;
}


void stack::push(int i)
{
    if(tos==SIZE)
    {
        cout<<"stack full"<<endl;
        return;
    }
    stck[tos]=i;
    tos++;
}

int stack::pop()
{
    if(tos == 0)
    {
        cout<<"stack empty"<<endl;
        return 0;
    }

    tos--;
    return stck[tos];

}

int main()
{
    stack stack1,stack2;

    stack1.init();
    stack2.init();

    stack1.push(1);
    stack2.push(2);

    stack1.push(3);
    stack2.push(4);

    cout<<stack1.pop()<<" ";
    cout<<stack1.pop()<<" ";
    cout<<stack2.pop()<<" ";
    cout<<stack2.pop()<<endl;

    return 0;
}


*/
///////////////////////////////////////
/*
#include <iostream>
using namespace std;
// abs is overloaded three ways
int abs(int i);
double abs(double d);
long abs(long l);
int main()
{
    cout << abs(-10) << "\n";
    cout << abs(-11.0) << "\n";
    cout << abs(-9L) << "\n";
    return 0;
}
int abs(int i)
{
    cout << "Using integer abs()\n";
    return i<0 ? -i : i;
}
double abs(double d)
{
    cout << "Using double abs()\n";
    return d<0.0 ? -d : d;
}
long abs(long l)
{
    cout << "Using long abs()\n";
    return l<0 ? -l : l;
}
*/


//////////////////////////////////////////////////////////////

/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void stradd(char *s1, char *s2);
void stradd(char *s1, int i);
int main()
{
char str[80];
strcpy(str, "Hello ");
stradd(str, "there");
cout << str << "\n";
stradd(str, 100);
cout << str << "\n";
return 0;
}
// concatenate two strings
void stradd(char *s1, char *s2)
{
strcat(s1, s2);
}
// concatenate a string with a "stringized" integer
void stradd(char *s1, int i)
{
char temp[80];
sprintf(temp, "%d", i);
strcat(s1, temp);
}

*/
////////////////////////////////////////////////////////
/*
///min hip max hip///
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;
    int arr[n+1];
    cout << "Enter the elements : ";
    for(int i = 1 ; i <= n ; i++)
        cin>>arr[i];
    cout<<"Min HEAP sorted array : ";
    bool flag = 0;
    while(n)
    {
        flag = 0;
        for(int i = floor(n / 2) ; i > 0 ;  i--)
        {
            int index;
            if(arr[2*i] < arr[2*i +1] || 2*i+1 > n)
                index = 2*i;
            else
                index = 2*i+1;
            if(arr[index] < arr[i] )
            {
                swap(arr[index] , arr[i]);
                flag = 1;
            }
        }
        cout<<arr[1]<<" ";
        arr[1] = arr[n];
        n--;
    }
    return 0;
}
*/
///////////////////////////////////////////////////////////
/*
#include<bits/stdc++.h>
using namespace std;

class ABC;

class XYZ
{
    int data;

public:
    setvalu(int val)
    {
        data=val;
    }

    void disp()
    {
        cout<<data<<endl;
    }

    friend int add(XYZ,ABC);

    friend int exchange(XYZ &,ABC &);
};

class ABC
{
    int data;

public:
    setvalu(int val)
    {
        data=val;
    }

    void disp()
    {
        cout<<data<<endl;
    }


    friend int add(XYZ,ABC);

    friend int exchange(XYZ &,ABC &);
};

int add (XYZ obj1,ABC obj2)
{
    return (obj1.data+obj2.data);
}

int exchange(XYZ & obj1,ABC & obj2)
{
    int temp=obj1.data;
    obj1.data=obj2.data;
    obj2.data=temp;
}

int main()
{
    ABC A;
    XYZ X;
    X.setvalu(5);
    A.setvalu(10);
    cout<<add(X,A)<<endl;
    exchange(X,A);
    X.disp();
    A.disp();
    return 0;

}

*/
///////////////////////////////////////////////////////////
/*
#include<bits/stdc++.h>

using namespace std;


class A
{
    int C;
    float P;
 public:
  void  gt(int c,float p )
  {
      C=c;
      P=p;
  }

  void dsp()
  {
      cout<<C<<" "<<P<<endl;
  }
};

int main()
{
    A x;
    A *ptr=&x;
    x.gt(10,30.5);
    x.dsp();
    ptr->gt(100,300.5);
    ptr->dsp();
    return 0;
}

*/
//////////////////////
/*

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int *ptr1=new int(5);
    int *ptr2=new int {10};
    delete ptr1;
    delete ptr2;
    cout<<*ptr1<<" "<<*ptr2<<endl;
}
*/
//////////////////////////////////////////////
/*
#include <iostream>
using namespace std; 
int main()
{
    int *ptr = new int; // dynamically allocate an integer
    *ptr = 7; // put a value in that memory location
 
    delete ptr; // return the memory to the operating system.  ptr is now a dangling pointer.
 
    std::cout << *ptr; // Dereferencing a dangling pointer will cause undefined behavior
    delete ptr; // trying to deallocate the memory again will also lead to undefined behavior.
 
    return 0;
}


*/
//////////////////////////////////////////////////////
/*
#include <iostream>

	using namespace std;

struct absValue
{
	float operator()(float f) {
		return f > 0 ? f : -f;
	}
};
int main( )
{
	float f = -123.45;
	absValue aObj;
	float abs_f = aObj(f);
	cout << "f = " << f << " abs_f = " << abs_f << endl;
	return 0;
}
*/
///////////////////////////////////////////////////////
/*
#include<bits/stdc++.h>

using namespace std;
int main()
{
    try
    {
        // Statements that may throw exceptions you want to handle now go here
        throw -1;
    }
    catch (int)
    {
        // Any exceptions of type int thrown within the above try block get sent here
        cerr << "We caught an exception of type int" << endl;
    }
    catch (double)
    {
        // Any exceptions of type double thrown within the above try block get sent here
        cerr << "We caught an exception of type double" << endl;
    }
 
    return 0;
}
*/
////////////////////////////////////////////////////////////////
/*
#include<bits/stdc++.h>

using namespace std;


template<class T>
class Auto_ptr1
{
    T* m_ptr;
public:
// Pass in a pointer to "own" via the constructor
    Auto_ptr1(T* ptr=nullptr)
        :m_ptr(ptr)
    {
    }
// The destructor will make sure it gets deallocated
    ~Auto_ptr1()
    {
        delete m_ptr;
    }
     
// Access to the underlying pointer/data if desired (for completeness)
    T& operator*() const
    {
        return *m_ptr;
    }
    T* operator->() const
    {
        return m_ptr;
    }
};

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
Auto_ptr1<Resource> res(new Resource); // Note the allocation of memory here
 
        // ... but no explicit delete needed
 
// Also note that the Resource in angled braces doesn't need a * symbol, since that's supplied by the template
 
return 0;
} // res goes out of scope here, and destroys the allocated Resource for us

*/


#include <iostream>

using namespace std;
int bst_creation(int);
int pre_order();
int in_order();
int post_order();
class bst
{
public:
    int info;
    bst *left,*right,*next;
};
bst *root=NULL,*top=NULL;
int main()
{
    int item;
    cout<<"Wntr item:";
    while(1)
    {
        cin>>item;
        if(item==0)
            break;
        else
            bst_creation(item);
    }
    cout<<"\n1 for preorder"<<endl<<"2 for inorder"<<endl<<"3 for postorder"<<endl;
    int n;
    cin>> n;
    if(n==1)
        pre_order();

    else if (n==2)
        in_order();

    else if (n==3)
        post_order();
     return 0;
}

int bst_creation(int data)
{
    bst *ptr=new bst();
    ptr->info=data;
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->next=NULL;

    if(root==NULL)
        root=ptr;

    else
    {
        bst *srt;
        for(srt=root; ; )
        {
            if(ptr->info>srt->info)
            {
                if(srt->right==NULL)
                {
                    srt->right=ptr;
                    break;
                }

                else
                    srt=srt->right;

            }

            else
            {
                if(srt->left==NULL)
                {
                    srt->left=ptr;
                    break;
                }

                else
                    srt=srt->left;
            }
        }
    }

}

int push_s(bst *srt)
{
    srt->next=top;
    top=srt;
    return 0;
}

bst* pop()
{
    bst *pt;
    if(top==NULL)
        return top;

    else
    {
        pt=top;
        top=top->next;
    }

    return pt;
}

int pre_order()
{
    bst *p;
    p=root;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        if (p->right!=NULL)
            push_s(p->right);

        if (p->left!=NULL)

            p=p->left;
        else
            p=pop();
    }
    return 0;
}

int in_order()
{
    bst *p;
    p=root;
A:
    while(p!=NULL)
    {
        push_s(p);
        p=p->left;
    }

    p=pop();

    while(p!=NULL)
    {
        cout<<p->info<<" ";

        if(p->right!=NULL)
        {
            p=p->right;
            goto A;
        }
        p=pop();
    }
    return 0;
}
int post_order()
{
    bst *p;
    p=root;

    do
    {
        while(p!=NULL)
        {
            if(p->right!=NULL)
                push_s(p->right);

            push_s(p);
            p=p->left;
        }

        p=pop();

        if(p->right && top== p->right)
        {
            top=top->next;
            push_s(p);
            p=p->right;
        }

        else
        {
            cout<<p->info<<" ";
            p=NULL;
        }
    }
    while(top!= NULL);
    return 0;
}
