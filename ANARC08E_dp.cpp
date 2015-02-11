#include<stdio.h>

long long fact[22];

int main()
{
    int a,b;
    int s=0,t;
    fact[0] = fact[1] = 1;
    for(int i=2;i<22;i++)
        fact[i] = i*fact[i-1];

    scanf("%d %d",&a,&b);

    while(a!=-1 && b!=-1)
    {
        s=a+b;
        t = ((fact[a+b])/(fact[a]*fact[b]));

        if(s==t)
            printf("%d+%d=%d\n",a,b,s);
        else
            printf("%d+%d!=%d\n",a,b,s);
            scanf("%d %d",&a,&b);
    }
    return 0;
}
