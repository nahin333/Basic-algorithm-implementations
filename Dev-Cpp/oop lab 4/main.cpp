#include<bits/stdc++.h>

using namespace std;


class object
{
private:
    double result = -1;
public:
    object(char ch1, double n1, double n2);
    object(char ch1, char ch2, double n1, double n2, double n3);
    object(double n1);
    object(object &a);
    void printans();

};

object::object(char ch, double n1 = -1, double n2 = -1)
{
    if(n2 != -1)
    {
        if(ch=='+') result = n1+n2;
        else if(ch=='-') result = n1-n2;
    }

    else
    {
        if(ch=='-') result= n1*(-1);
        else result= n1;
    }
}

object::object(char ch1, char ch2, double n1 = -1, double n2 = -1, double n3 = -1)
{
    if(ch2=='-') result=n1-n2;
    if(ch2=='+') result=n1+n2;
    if(ch2=='*') result= n1*n2;
    if(ch2=='/')
    {
        if(n2==0) cout<<"Invalid Input"<<endl;
        else result= n1/n2;
    }

    if(result != -1)
    {
        if(n3 == -1)
        {
            if(ch1=='-') result-=1;
            else if (ch1=='+') result+=1;
            else if(ch2=='*' ) result*=1;
            else if(ch1=='/') result/=result;
        }

        else
        {
            if(ch1=='-') result-=n3;
            else if (ch1=='+') result+=n3;
            else if(ch2=='*' ) result*=n3;
            else if(ch1=='/' && n3) result/=n3;
            else if(ch1=='/' && !n3) cout<<"Invalid Input"<<endl;
        }
    }


}

object::object(double n1)
{
    result=n1;
}

object::object(object &a)
{
    result= a.result;
}

void object::printans()
{
    cout<<result<<endl;

}


int main()
{
    object a('-', 3.4, 4.3);
    a.printans();
    object b('-', 5.0);
    b.printans();
    object c('+', '*', 4.2, 1, 1.0);
    c.printans();
    object d('+', '/', 3.2, 2.2);
    d.printans();
    object e(5.5);
    e.printans();
    object f(e);
    f.printans();

}
