//class 1:#
#include<stdio.h>
int e,i,a[100];
//traverse
void traverse()
{
    int sum=0;
    float avg=0;
    for(i=0; i<e; i++)
    {
        sum=sum+a[i];
    }
    avg=(float)sum/e;
    printf("average of %d numbers is %f\n",e,avg);
}
//insertion
void insertion()
{
    int pos,val;
    printf("positin to ins?: ");
    scanf("%d",&pos);
    printf("value?: ");
    scanf("%d",&val);
    printf("BEFORE:\n");
    for(i=0; i<e; i++)
    {
        printf("%d ",a[i]);
    }
    for(i=e-1; i>=pos-1; i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=val;
    e++;
    printf("\nAFTER:\n");
    for(i=0; i<e; i++)
    {
        printf("%d ",a[i]);
    }
}
//deletion
void deletion()
{
    int pos;
    printf("\nposition to del?:\n");
    scanf("%d",&pos);
    for(i=pos-1; i<e; i++)
    {
        a[i]=a[i+1];
    }
    e--;
    printf("AFTER DELETION:\n");

    for(i=0; i<e; i++)
    {
        printf("%d ",a[i]);
    }
}

void del_by_val(int *p)
{
    int *ini=&a[0],pos=p-ini+1;
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
//searching
void searching()
{
    int s,c=0,*t;
    printf("\nwhich value to delete?: ");
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
        printf("found!for %d time(s):)\n",c);
    else
        printf("not found:(\n");
        //return a[i];
        del_by_val(t);
}

int main(void)
{
    printf("no of element?: ");
    scanf("%d",&e);
    printf("enter element: \n");
    for(i=0; i<e; i++)
    {
        scanf("%d",&a[i]);
    }
    traverse();
    insertion();
    deletion();
    searching();
}


///////////////////////////////////////////////////////////////////////////////
/*#include<stdio.h>
int e,i,a[100];

void traverse()
{
    int sum=0;
    float avg=0;
    for(i=0;i<e;i++)
    {
        sum=sum+a[i];
    }
   avg=(float)sum/e;
   printf("%f",avg);
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
