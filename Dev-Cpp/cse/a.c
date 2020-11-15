#include<stdio.h>
#include<string.h>

int main()
{
    char s1[100],s2[100];
    gets(s1);
    gets(s2);
    int i,n;
    scanf("%d",&n);
    for(i=strlen(s1);i>=n;i--)
    {
        s1[i+strlen(s2)] = s1[i];
    }
    for(i=n-1;i<(n-1)+strlen(s2);i++)
    {
        s1[i] = s2[i+1-n];
    }
    puts(s1);
    //printf("%s",s1);
    return 0;
}
