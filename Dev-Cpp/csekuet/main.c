#include <stdio.h>
void main()
{
    int num ;
    int *ptr;
    scanf("%d",&num);
    int i;
    for( i=0; i<num; i++)
    {
        *ptr=i;
        ptr++;
    }
    ptr--;
    for(i=num; i>0; i--)
    {
        printf("\n%d",*ptr);
        ptr--;
    }
}
