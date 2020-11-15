#include <iostream>

using namespace std;

/*class a
{
    int n;
    int m;
public:
    void getdata(void);
    int largest(void);
    void putdata(void);
};
void a::getdata(void)

{
   cin>>n>>m;
}
int a::largest()
{
    if (n>m)
    {
        cout<<"n big"<<endl;
        return n;
    }
    else
    {
        cout<<"m big"<<endl;
        return m;
    }
}
   void a::putdata()
   {
       cout<<largest();
   }
int main()
{
    a i;
    i.getdata();
    i.putdata();

}
*/
///////////////
/*
int i;
const int size=2;

class sample
{
    int m[size];
    int read(void);
public:
    void update(void);
    void write();

};
int sample::read()
{


        cin>>m[i];
        return m[i];

}
void sample::update()
{
    read();
}
void sample::write()
{

        cout<<m[i]<<endl;

}
int main()
{
    sample a[2];
    for(int i=0;i<2;i++)
    {
    a[i].update();
    a[i].write();

    }

}
*/
////////////////////////
/*
class emply
{
    char name[30];
    float age;
public:
    void getdata();
    void putdata();
};
void emply::getdata()
{
    cin>>name>>age;
}
void emply::putdata()
{
    cout<<name<<" "<<age<<endl;
}
const int size =3;
int main()
{
   emply mngr[size];
    for(int i=0;i<size;i++)
    {
        mngr[i].getdata();
    }
    cout<<"\n";
    for(int i=0;i<size;i++)
    {
        mngr[i].putdata();
    }
}
*/
////////////////////////////////////////////////
/*
class time
{
    int hr;
    int mnt;
public:
    void getdata(int h,int m)
    {
        hr=h;
        mnt=m;
    }
    void putdata()
    {
        cout<<hr<<"hr"<<" "<<mnt<<"min"<<endl;
    }
    void sum(time t1,time t2)
    {
        mnt=t1.mnt+t2.mnt;
        hr=mnt/60;
        mnt=mnt%60;
        hr=hr+t1.hr+t2.hr;
    }
};
int main()
{
    time t1,t2,t3;
    t1.getdata(2,45);
    t2.getdata(3,30);
    t3.sum(t1,t2);
    t1.putdata();
    t2.putdata();
    t3.putdata();
}
*/
////////////////////////////////////////////////////////////
/*
class smpl
{
    int a,b;
public:
    void stv()
    {
        cin>>a>>b;
    }
    friend float mn(smpl s);
};
float mn(smpl s)
{
    return float(s.a+s.b)/2;
}
int main()
{
    smpl s;
    s.stv();
    cout<<"mn vl="<<mn(s)<<endl;
}
*/
////////////////////////////////////////////////////////////
/*class A;
class X
{
    int d;
public:
    void sv(int v)
    {
        d=v;
    }
    friend void add(X,A);
};
class A
{
    int d;
public:
    void sv(int v)
    {
        d=v;
    }
    friend void add(X,A);
};
void add(X x,A a)
{
    if(x.d>=a.d)
        cout<<x.d<<"max";
    else
        cout<<a.d<<"max";
}
int main()
{
    A a;
    X x;
    x.sv(4);
    a.sv(6);
    add(x,a);

}
*/
/////////////////////////////////////////////////////////
/*class c2;
class c1
{
    int v1;
public:
   void id(int a )
   {
       v1=a;
   }
   void pd()
   {
       cout<<"v1="<<v1<<endl;
   }
   friend void swp(c1&,c2&);

};
class c2
{
    int v2;
public:
   void id(int a )
   {
       v2=a;
   }
   void pd()
   {
       cout<<"v2="<<v2<<endl;
   }
   friend void swp(c1&,c2&);

};
void swp(c1 &x,c2 &y)
{
    int t=y.v2;
    y.v2=x.v1;
    x.v1=t;
}
int main()
{
    c1 x;
    c2 y;
    x.id(2);
    y.id(4);
    cout<<"bfr"<<endl;
    x.pd();
    y.pd();
    swp(x,y);
    cout<<"aft"<<endl;
    x.pd();
    y.pd();
}
*/
/////////////////////////////////////////////////////
/*class cx
{
    float a,b;

public:
    void in(float x , float y)
    {
        a=x;
        b=y;
    }
     friend cx sm(cx c1,cx c2)
     {
         cx c3;
         c3.a=c1.a+c2.a;
         c3.b=c1.b+c2.b;
         return c3;

     }
     void show(cx c);

};
void cx::show(cx c)
     {
         cout<<c.a<<endl<<c.b<<endl;
     }
int main()
{
    cx m,n,o;
    m.in(3.1,5.65);
    n.in(2.75,1.2);
   o= sm(m,n);
   m.show(m);
   n.show(n);
   o.show(o);

}
*/
//////////////////////////////////////////////////
/*
#include <iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    cout<<"hello world"<<endl;
    const double pi =3.1416;
    cout<<pi<<endl;
}
*/
///////////
/*
#include <iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
int main()
{
char ha[6]={'h','p','\0'};
string bs="bd";
cout<<ha+bs<<endl;
string yn;
cout<<"what is ur name?";
getline(cin,yn);
cout<<yn;
return 0;}
*/
/////////////////////////////////////////
/*
#include<iostream>
using namespace std;
class time{
   int hr,mn;
   public:
  void gt(int h,int m)
   {
     hr=h;
     mn=m;
   }
  void pt()
   {
      cout<<hr<<" "<<mn<<endl;
   }
   void p(time t1,time t2 )
   {

       mn=t1.mn+t2.mn;
       hr=mn/60;
       mn=mn%60;
       hr=hr+t1.hr+t2.hr;
   }
};
int main()
{
    time t1,t2,t3;
    t1.gt(2,57);
    t2.gt(1,20);
    t3.p(t1,t2);
    t1.pt();
    t2.pt();
    t3.pt();
}
*/
/////////////////////
/*
#include <iostream>
#include<map>
#include<vector>
#include<list>
#include<string>
using namespace std;

int main()
{
    //first map
    map<string,vector<int> > m1,m2,m3,m4;
    m1["EEE1111"]= {11,22,33};
    m2["CSE2222"]= {10,20,30};
    m3["EEE3333"]= {100,200,300};
    m4["CSE4444"]= {111,222,333};

    //second list
    list<map<string,vector<int> > > Th_Lst,La_Lst;//just list
    Th_Lst.push_back(m1);
    Th_Lst.push_back(m3);
    La_Lst.push_back(m2);
    La_Lst.push_back(m4);

    class student
    {
    public:
        string name;
        map<string,list<map<string,vector<int> > > > second_map1;//map with theory and lab
        void show()
        {
            for(auto it1 = second_map1.begin(); it1 != second_map1.end(); it1++)
            {
                cout<<it1->first<<" course"<<endl;
                for(auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
                {
                    for(auto it3 = it2->begin(); it3 != it2->end(); it3++)
                    {
                        cout<<it3->first<<endl;
                        for(auto it4 = it3->second.begin(); it4 != it3->second.end(); it4++)
                        {
                            cout<<*it4<<" ";
                        }
                        cout<<endl;
                    }
                }
            }
        }
    };
    student obj1,obj2;

    obj1.second_map1["theory"] = Th_Lst;
    obj1.second_map1["lab"] = La_Lst;

    obj2.second_map1["theory"] = Th_Lst;
    obj2.second_map1["lab"] = La_Lst;

    map<int,student> R_map;
    R_map[12] = obj1;
    R_map[13] = obj2;

    map<int,map<int,student> > Y_map;
    Y_map[1] = R_map;
    Y_map[2] = R_map;

    map<string,map<int,map<int,student> > > D_map;
    D_map["EEE"] = Y_map;
    D_map["CSE"] = Y_map;

    for(auto D_it = D_map.begin(); D_it != D_map.end(); D_it++)
    {
        cout<<D_it->first<<" dept."<<endl;
        for(auto Y_it = D_it->second.begin(); Y_it != D_it->second.end(); Y_it++)
        {
            cout<<Y_it->first<<" year"<<endl;
            for(auto R_it = Y_it->second.begin(); R_it != Y_it->second.end(); R_it++)
            {
                cout<<R_it->first<<" roll"<<endl;
                R_it->second.show();
            }
        }
    }
    return 0;
}
*/
////////////////////////////////
/*
#include<iostream>
using namespace std;
class it {
    int m,n;
public:

    it()
    {
        m=n=0;
    }



    it(int e,int f)
    {
        m=e;n=f;

    }
      void disply()
      {
          cout<<m<<" "<<n<<endl;
      }
      it(it &d)
      {
          m=d.m;
          n=d.n;
      }

};
int main()
{
    it w;
    w.disply();
    it a(1,2);
    a.disply();
    it x( a);
    x.disply();
    return 0;
}
*/
//////////////////////////////
/*
#include<iostream>
using namespace std;
class cp
{
    int x,y;
    public:
    cp(){}
    cp(int a){x=y=a;}
    cp(int e,int d)
    {
        x=e;y=d;
    }
   friend cp sum(cp,cp);
  friend  void disply(cp);
};
cp sum(cp c1,cp c2)
{
    cp c3;
    c3.x=c1.x+c2.x;
    c3.y=c1.y+c2.y;
    return c3;
}
void display(cp c)
{
    cout<<c.x<<" "<<c.y<<endl;
}
int main()
{
    cp A(1,2);
    cp B(3);
    cp C;
    C=sum(A,B);
    display(A);
    display(B);
    display(C);
}
*/
/*
#include<iostream>
using namespace std;
class st{
   int m;
   public:
       st(int i=0)
       {
           m=i;
       }
      st()
       {
           m=10;
       }

void dsp()
{
    cout<<m<<endl;
}
};
int main()
{
    st x;
    x.dsp();
}
*/
//////////////////////
/*
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> v;
  v.push_back(4);
  v.push_back(2);
  v.push_back(7);
  v.push_back(6);

  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;

  // Same result as 'for' loop.
  for (vector<int>::iterator it = v.begin();it != v.end();it++)
    cout << *it << " ";
  cout << endl;
}
*/
//////////////////////
/*
#include<iostream>
using namespace std;
class cnts
{
    int m_cnts;
public:
    cnts(int ncnts)
    {
        m_cnts=ncnts;
    }
    friend cnts operator+(const cnts &c1,const cnts &c2);
    int getcnts()
    {
        return m_cnts;
    }

};

cnts operator+(const cnts &c1,const cnts &c2)
{
    return cnts(c1.m_cnts+c2.m_cnts);
}
int main()
{
  cnts ccnts1(6);
  cnts ccnts2(8);
  cnts ccntssum=ccnts1+ccnts2;
  cout<<ccntssum.getcnts()<<endl;
  return 0;
}
*/

/////////////////////////
/*
#include<iostream>
using namespace std;
class item
{
    int code;
    float  price;
public:
    void getdata( int a, float b )
    {
        code =a;
        price = b;
    }
    void show( void )
    {
        cout << "Code :" << code<<endl<< "Price :" << price << endl;
    }
};
int main()
{
    item x;
    item *ptr = &x;
    ptr->getdata(100,75.50);
    ptr->show();
}
*/
//////////////////////////////////

#include<iostream>
using namespace std;


template <typename T> // this is the template parameter declaration
const T& max(const T& x, const T& y)
{
    return (x > y) ? x : y;
}
 
class Cents
{
private:
    int m_cents;
public:
    Cents(int cents)
        : m_cents(cents)
    {
    }
 
    friend bool operator>(const Cents &c1, const Cents &c2)
    {
        return (c1.m_cents > c2.m_cents);
    }
};



int main()
{
    Cents nickle(5);
    Cents dime(10);
 
    Cents bigger = max(nickle, dime);
 
    return 0;
}
