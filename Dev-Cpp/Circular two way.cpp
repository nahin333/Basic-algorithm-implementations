#include<iostream>
using namespace std;

void create(int);
void traverse();
void insert_first(int);
void insert_last(int);
void insert_before(int,int);
void insert_after(int,int);
void del_first();
void del_last();
void del_par(int);
void del_after(int);
void del_before(int);

class node
{
 public:
     node *fw;
     node *bw;
     int info;
}*head,*temp;

void create(int key)
{
    node *ptr,*p;
    ptr = new node();
    ptr->fw = head;
    ptr->bw = NULL;
    ptr->info = key;
    if(head == NULL )
    {
        head = ptr;
        head->bw = head;
        head->fw = head;
        temp = head;
    }
    else
    {
        p = head;
        while(p->fw != head)
            p = p->fw;
        p->fw = ptr;
        ptr->bw = p;
        head->bw = ptr;
        temp = ptr;
    }
}
void traverse()
{
    node *p;
    p = head;
    while(p->fw != head)
    {
        cout<<p->info<<" ";
        p = p->fw;
    }
    cout<<p->info<<endl;
}
void insert_first(int value)
{
    node *ptr;
    ptr = new node();
    ptr->info = value;
    temp->fw = ptr;
    ptr->bw = temp;
    ptr->fw = head;
    head->bw = ptr;
    head = ptr;
    traverse();
}
void insert_last(int value)
{
    node *ptr;
    ptr = new node();
    ptr->info = value;
    temp->fw = ptr;
    ptr->bw = temp;
    ptr->fw = head;
    head->bw = ptr;
    temp = ptr;
    traverse();
}
void insert_before(int value,int key)
{
    if(head->info == key)
        insert_first(value);
    else
    {
        node *ptr,*p;
        ptr = new node();
        ptr->info = value;
        p = head;
        while(p->fw->info != key)
            p = p->fw;
        ptr->fw = p->fw;
        ptr->bw = p;
        p->fw->bw = ptr;
        p->fw = ptr;
        traverse();
    }

}
void insert_after(int value,int key)
{
    if(temp->info == key)
        insert_last(value);
    else
    {
        node *ptr,*p;
        ptr = new node();
        ptr->info = value;
        p = head;
        while(p->info != key)
            p = p->fw;
        ptr->fw = p->fw;
        ptr->bw = p;
        p->fw->bw = ptr;
        p->fw = ptr;
        traverse();
    }
}
void del_first()
{
    head = head->fw;
    temp->fw = head;
    head->bw = temp;
    traverse();
}
void del_last()
{
    temp = temp->bw;
    head->bw = temp;
    temp->fw = head;
    traverse();
}
void del_par(int key)
{
    node *p;
    if(head->info == key)
        del_first();
    else if(temp->info == key)
        del_last();
    else
    {
        p = head;
        while(p->fw->info != key)
            p = p->fw;
        p->fw = p->fw->fw;
        p->fw->fw->bw = p;
        traverse();
    }

}
void del_after(int key)
{
    if(temp->bw->info == key)
        del_last();
    else if(temp->info == key)
        del_first();
    else
    {
        node *p;
        p = head;
        while(p->info != key)
            p = p->fw;
        p->fw = p->fw->fw;
        p->fw->fw->bw = p;
        traverse();
    }
}
void del_before(int key)
{
    if(head->fw->info == key)
        del_first();
    else if(head->info == key)
        del_last();
    else
    {
        node *p;
        p = head;
        while(p->fw->fw->info != key)
            p = p->fw;
        p->fw = p->fw->fw;
        p->fw->fw->bw = p;
        traverse();
    }
}
int main()
{
    head = NULL;
    int i,key,value;
    for(i=0;i<5;i++)
    {
        cin>>key;
        create(key);
    }
traverse();
cin>>key;
insert_first(key);
cin>>key;
insert_last(key);
cin>>value;
cin>>key;
insert_before(value,key);
cin>>value;
cin>>key;
insert_after(value,key);
del_first();
del_last();
cin>>value;
del_par(value);
cin>>value;
del_after(value);
cin>>value;
del_before(value);

    return 0;
}
