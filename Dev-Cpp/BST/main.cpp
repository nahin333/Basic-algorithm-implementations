#include <iostream>

using namespace std;
int bst_creation(int);
int pre_ordr();
int in_ordr();
int post_ordr();
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
    cout<<"entr item:";
    while(1)
    {
        cin>>item;
        if(item==0)
            break;
        else
            bst_creation(item);
    }
    cout<<"\n1,preordr\n2,inordr\n3,postordr"<<endl;
    int a;
    cin>>a;
    if(a==1)
        pre_ordr();
    else if(a==2)
        in_ordr();
    else if(a==3)
        post_ordr();
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
            if(ptr->info<=srt->info)
            {
                if(srt->left==NULL)
                {
                    srt->left=ptr;
                    break;
                }

                else
                    srt=srt->left;

            }

            else
            {
                if(srt->right==NULL)
                {
                    srt->right=ptr;
                    break;
                }

                else
                    srt=srt->right;
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

bst *pop()
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


int pre_ordr()
{
    bst *p;
    p=root;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        if(p->right!=NULL)
            push_s(p->right);

        if(p->left!=NULL)
            p=p->left;

        else
            p=pop();
    }

    return 0;
}


int in_ordr()
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


int post_ordr()
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
        if(p->right && top==p->right)
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
   while(top!=NULL);
        return 0;
}
