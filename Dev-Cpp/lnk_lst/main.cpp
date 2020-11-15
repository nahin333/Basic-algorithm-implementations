

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
    ptr->forw=NULL

              ;
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


/*

//class 1:##############################################################################################################################
#include<stdio.h>
int e,i,a[100];

void traverse()
{
    int maxm,mini,tempmax=a[0],tempmini=a[0];
    for(i=0;i<e;i++)
    {
        if(a[i]>tempmax)
            tempmax=a[i];
        if(a[i]<tempmini)
            tempmini=a[i];
    }
    printf("max: %d\n",tempmax);
    printf("min: %d\n",tempmini);
}

void insertion()
{
    int pos,val;
    printf("pos to ins?: ");
    scanf("%d",&pos);
    printf("val?: ");
    scanf("%d",&val);
    printf("BEFORE:\n");
    for(i=0;i<e;i++)
    {
        printf("%d ",a[i]);
    }
    for(i=e-1;i>=pos-1;i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=val;
    e++;
    printf("\nAFTER:\n");
    for(i=0;i<e;i++)
    {
        printf("%d ",a[i]);
    }
}

void deletion()
{
    int pos;
    printf("\npos to del?:\n");
    scanf("%d",&pos);
    for(i=pos-1;i<e;i++)
    {
        a[i]=a[i+1];
    }
    e--;
    printf("AFTER DELETION:\n");
    for(i=0;i<e;i++)
    {
        printf("%d ",a[i]);
    }
}

int main(void)
{
    printf("no of ele?: ");
    scanf("%d",&e);
    printf("enter ele: \n");
    for(i=0;i<e;i++)
    {
        scanf("%d",&a[i]);
    }
    traverse();
    insertion();
    deletion();
}
///////////////////////////////////////////////////////////////////////////////
#include<cstdio>
int e,i,a[100];

void traverse()
{
    int maxm,mini,tempmax=a[0],tempmini=a[0];
    for(i=0;i<e;i++)
    {
        if(a[i]>tempmax)
            tempmax=a[i];
        if(a[i]<tempmini)
            tempmini=a[i];
    }
    printf("max: %d\n",tempmax);
    printf("min: %d\n",tempmini);
}

void insertion()
{
    int pos,val;
    printf("pos to ins?: ");
    scanf("%d",&pos);
    printf("val?: ");
    scanf("%d",&val);
    printf("BEFORE:\n");
    for(i=0;i<e;i++)
    {
        printf("%d ",a[i]);
    }
    for(i=e-1;i>=pos-1;i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=val;
    e++;
    printf("\nAFTER:\n");
    for(i=0;i<e;i++)
    {
        printf("%d ",a[i]);
    }
}

void del_by_val(int *p)
{
    int *ini=&a[0],pos=p-ini+1;
    //printf("\nval to del?:\n");
    //scanf("%d",&pos);
    for(i=pos-1;i<e;i++)
    {
        a[i]=a[i+1];
    }
    e--;
    printf("AFTER DELETION:\n");
    for(i=0;i<e;i++)
    {
        printf("%d ",a[i]);
    }
}

void searching()
{
    int s,c=0,*t;
    printf("which one?: ");
    scanf("%d",&s);
    for(i=0;i<e;i++)
    {
        if(a[i]==s)
        {
            c++;
            t=&a[i];
        }
    }
    if(c)
        printf("found!!! for %d time(s):)\n",c);
    else
        printf("not found:(\n");
        //return a[i];
        del_by_val(t);
}

int main(void)
{
    printf("no of ele?: ");
    scanf("%d",&e);
    printf("enter ele: \n");
    for(i=0;i<e;i++)
    {
        scanf("%d",&a[i]);
    }
    traverse();
    insertion();
    //deletion();
    searching();
}
*/
