//circular lnkd_lst.
#include <iostream>

using namespace std;
int n;
void insertion(int data);
void traverse();
class node
{
public:
    int info;
    node *link;
};
node *head=NULL,*temp;
void insertion(int data)
{
    node *ptr;
    ptr=new node();
    ptr->info=data;
    ptr->link=head;
    if(head==NULL)
    {
        head=ptr;
        ptr->link=head;
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
    for(srt=head; ; )
    {
        if(srt->link !=head)
        {
            cout<<srt->info<<endl;
        }
        else
        {
            cout<<srt->info<<endl;
            break;
        }
        srt=srt->link;
    }

}
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
}
