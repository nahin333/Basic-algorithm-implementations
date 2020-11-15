#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    x=20;
    change(&x);
    printf("%d\n",x);

}
change(int *p)
{
    *p=*p+10;
}
