#include<stdio.h>

int Phi(int n)
{
    int i;
    int res=n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res -= res/i;
        }
        while(n%i==0)
            n = n/i;
    }
    if(n>1)
        res-=res/n;
    return res;
}

int main()
{
    int t,n;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",Phi(n));
    }
    return 0;
}
