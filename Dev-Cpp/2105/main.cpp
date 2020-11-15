///1 way///////
/*
#include<iostream>

using namespace std;
int n;
void insertion(int );
void traverse();
void ins_fst();
void ins_lst();
void ins_aftr();
void ins_bfr();
void dlt_fst();
void dlt_lst();
void dlt_prt();
void dlt_aftr();
void dlt_bfr();

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
    cout<<"enter the no of node:";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>item;
        insertion(item);
    }
    traverse();
    ins_fst();
    ins_lst();
    ins_aftr();
    ins_bfr();
    cout<<"aftr fst dlt"<<endl;
    dlt_fst();
    cout<<"aftr lst dlt"<<endl;
    dlt_lst();
    dlt_prt();
    dlt_aftr();
    dlt_bfr();

}

void insertion(int data)
{
    node *ptr=new node();
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
void ins_fst()
{
    int a;
    cout<<"entr the value for fst insrt:";
    cin>>a;
    node *ptr=new node();
    ptr->info=a;
   // ptr->link=NULL;
    ptr->link=head;
    head=ptr;
    traverse();
}

void ins_lst()
{
    int a;
    cout<<"entr the value for lst insrt:";
    cin>>a;
    node *ptr=new node();
    node *srt;
    ptr->info=a;
    ptr->link=NULL;
    for(srt=head; ; )
    {
        if(srt->link==NULL)
        {
            srt->link=ptr;
            break;
        }
        else
            srt=srt->link;
    }
    traverse();
}

void ins_aftr()
{

    int a,b;
    cout<<"entr the value aftr insrt:";
    cin>>a;
    cout<<"aftr which want to ins:";
    cin>>b;
    node *ptr=new node();
    node *srt;
    ptr->info=a;
    ptr->link=NULL;
    for(srt=head; ; )
    {
        if(srt->info==b)
        {
            ptr->link=srt->link;
            srt->link=ptr;
            break;
        }
        else
            srt=srt->link;
    }
    traverse();
}

void ins_bfr()
{

    int a,b;
    cout<<"entr the value bfr insrt:";
    cin>>a;
    cout<<"bfr which want to ins:";
    cin>>b;
    node *ptr=new node();
    node *srt;
    ptr->info=a;
    ptr->link=NULL;
    for(srt=head; ; )
    {
        if(srt->info==b)
        {
            ptr->link=temp->link;
            temp->link=ptr;
            break;
        }
        else
        {

            temp=srt;
            srt=srt->link;
        }

    }
    traverse();
    cout<<endl;
}

void dlt_fst()
{
    head=head->link;
    traverse();
    cout<<endl;
}
void dlt_lst()
{
    node *srt;
    for(srt=head; ; )
    {
        if(srt->link==NULL)
        {
            temp->link=NULL;
            break;
        }
        else
            temp=srt;
        srt=srt->link;
    }
    traverse();
    cout<<endl;
}

void dlt_prt()
{
    int a;
    cout<<"which want to dlt:";
    cin>>a;
    node *srt;
    for(srt=head; ; )
    {
        if(srt->info==a)
        {
            temp->link=srt->link;
            break;
        }
        else
            temp=srt;
        srt=srt->link;
    }
    traverse();
}

void dlt_aftr()
{
    int a;
    cout<<"aftr which want to dlt:";
    cin>>a;
    node *srt;
    for(srt=head; ; )
    {
        if(srt->info==a)
        {
            temp=srt->link ;
            srt->link=temp->link;
            break;
        }
        else
            srt=srt->link;
    }
    traverse();
}

void dlt_bfr()
{

    int a;
    cout<<"bfr which want to dlt:";
    cin>>a;
    node *srt,*pre;
    for(srt=head; ; )
    {
        if(srt->info==a)
        {
            pre->link=srt;
            break;
        }
        else
        {
            pre=temp;
            temp=srt;
            srt=srt->link;
        }
    }
    traverse();
}

*/

///2way//////////

#include <iostream>

using namespace std;
void insertion(int data);
void traverse();
void ins_fst();
void ins_lst();
void ins_aft();
void ins_bfr();
void dlt_fst();
void dlt_lst();
void dlt_pt();
void dlt_aftr();
void dlt_bfr();
int n;
class node
{
public:
    int info;
    node *backw;
    node *forw;
};
node *fst=NULL,*temp,*lst=NULL;
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
    ins_fst();
    ins_lst();
    ins_aft();
    ins_bfr();
    cout<<"aftr fst dlt"<<endl;
    dlt_fst();
    cout<<"aftr lst dlt"<<endl;
    dlt_lst();
    dlt_pt();
    dlt_aftr();
    dlt_bfr();
}
void insertion(int data)
{
    node *ptr;
    ptr=new node();
    ptr->info=data;
    ptr->backw=NULL;
    ptr->forw=NULL;


    if(fst==NULL)
    {
        fst=ptr;
        temp=ptr;
    }
    else
    {
        temp->forw=ptr;
        ptr->backw=temp;
        temp=ptr;
        lst = ptr;
    }
}
void traverse()
{

    node *srt;
    for(srt=fst; ; )
    {
        if(srt->forw!=NULL)
        {
            cout<<srt->info<<endl;
        }
        else
        {
            cout<<srt->info<<endl;
            break;
        }
        srt=srt->forw;
    }

}
void ins_fst()
{
    node *ptr;
    int item;
    cout<<"Enter item for first insert: ";
    cin>>item;
    ptr=new node();
    ptr->info = item;
    ptr->backw = NULL;
    ptr->forw=fst;
    fst->backw=ptr;
    fst=ptr;
    traverse();
}
void ins_lst()
{
    node *ptr;
    int item;
    cout<<"Enter item for lst insert: ";
    cin>>item;
    ptr=new node();
    ptr->info = item;
    lst->forw=ptr;
    ptr->backw=lst;
    ptr->forw = NULL;
    lst=ptr;
    traverse();

}
void ins_aft()
{
    node *ptr,*srt;
    ptr=new node();
    int a,v;
    cout<<"Enter the value : ";
    cin>>a;
    cout<<"Enter the value after which you will insert : ";
    cin>>v;
    ptr->info=a;
    ptr->forw = NULL;
    ptr->backw = NULL;
    for(srt = fst; ; )
    {
        if(srt->info==v)
        {
            temp=srt->forw;
            temp->backw=ptr;
            ptr->backw=srt;
            ptr->forw=temp;
            srt->forw=ptr;
            break;
        }
        else
            srt=srt->forw;
    }
    traverse();
}
void ins_bfr()
{

    node *ptr,*srt;
    ptr=new node();
    int a,v;
    cout<<"Enter the value : ";
    cin>>a;
    cout<<"Enter the value before which you will insert : ";
    cin>>v;
    ptr->info=a;
    ptr->forw = NULL;
    ptr->backw = NULL;
    for(srt = fst; ; )
    {
        if(srt->info==v)
        {
            temp=srt->backw;
            temp->forw=ptr;
            ptr->backw=temp;
            ptr->forw=srt;
            srt->backw=ptr;
            break;
        }
        else
            srt=srt->forw;
    }
    traverse();
}
void dlt_fst()
{
    fst=fst->forw;
    fst->backw=NULL;
    traverse();
}
void dlt_lst()
{
    lst=lst->backw;
    lst->forw=NULL;
    traverse();
}
void dlt_pt()
{
    node *srt,*rt;
    int v;
    cout<<"Enter the value you will delete : ";
    cin>>v;
    for(srt = fst; ; )
    {
        if(srt->info==v)
        {
            temp=srt->forw;
            temp->backw=srt->backw;
            rt=srt->backw;
            rt->forw=srt->forw;
            break;
        }
        else

            srt=srt->forw;
    }
    traverse();
}

void dlt_aftr()
{
    node *srt,*rt;
    int v;
    cout<<"Enter the value after which you will delete : ";
    cin>>v;
    for(srt = fst; ; )
    {
        if(srt->info==v)
        {
            temp=srt->forw;
            srt->forw=temp->forw;
            rt=temp->forw;
            rt->backw=temp->backw;
            break;
        }
        else
    //        temp=srt;
        srt=srt->forw;
    }
    traverse();
}
void dlt_bfr()
{
    node *srt,*rt;
    int v;
    cout<<"Enter the value before which you will delete : ";
    cin>>v;
    for(srt = fst; ; )
    {
        if(srt->info==v)
        {
            temp=srt->backw;
            srt->backw=temp->backw;
            rt=temp->backw;
            rt->forw=temp->forw;
            break;
        }
        else
            srt=srt->forw;
    }
    traverse();
}

