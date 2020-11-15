/*#include <iostream>
using namespace std;
void insertion(int);
void traverse();
void insert_sort();
int n;
class node
{
public:
    int info;
    node *link;
};
node *head=NULL,*temp;
int main()
{
    int item;
    cout<<"No of node:";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>item;
        insertion(item);

    }
    traverse();
    insert_sort();
}
void insertion(int data)
{
    node *ptr;
    ptr=new node();
    ptr->info=data;
    ptr->link=NULL;
    if(head==NULL)
    {
        head=ptr;
        temp=ptr;
    }
    else
    {
        temp->link=ptr;
        temp=ptr;
    }
}
void traverse()
{
    node *srt;
    srt=head;
    while(srt!=NULL)
    {
        cout<<srt->info<<" ";
        srt=srt->link;
    }
}
void insert_sort()
{
    node *ptr,*str,*t;
    int b;
    ptr=new node();
    cout<<"The number:";
    cin>>b;
    ptr->info=b;
    str=head->link;
    for(str=head;;)
    {
        if(n>1)
        {
            if(head->info<b && str!=NULL && str->info >= b)
            {
                ptr->link=t->link;
                t->link=ptr;
                break;
            }
            else if(str->link== NULL)
            {
                str->link=ptr;
                break;

            }
            else if(head->info >= b)
            {
                ptr->link=head;
                head=ptr;
                break;
            }
            else
            {
                t=str;
                str=str->link;
            }
        }
        else
        {
            if(str->info >= b)
            {
                ptr->link=head;
                head=ptr;
                break;
            }
            else
            {
                ptr->link=NULL;
                str->link=ptr;
                break;
            }
        }
    }
    traverse();
}
*/
/////////////////////
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
  for (vector<int>::iterator it = v.begin();
       it != v.end();
       it++)
    cout << *it << " ";
  cout << endl;
}
*/
#include<iostream>
using namespace std;
class tst
{
    static int d;
public:
    void gtr()
    {
        cout<<d<<endl;
    }
    void str()
    {
        d++;
    }
};
int main()
{
    tst obj;
    obj.str();
    obj.str();
    obj.gtr();
}
