#include <iostream>
using namespace std;
void insertion(int);
void traverse();
void insert_sort();
void intrchange_fst_tw_elmnt();
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
    cout<<"aftr intrchnding fst tw elmnt:";
    intrchange_fst_tw_elmnt();
    traverse();
   // insert_sort();
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
    cout<<endl;
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
void intrchange_fst_tw_elmnt()
{
    node *srt,*rt;
    rt=head;
    srt=head->link;
    rt->link=srt->link;
    srt->link=rt;
    head=srt;
}
