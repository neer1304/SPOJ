#include<stdio.h>
#include<math.h>

int CountMinCuts(int n)
{
    int i=0;

    while(pow(2,i)-1 < n)
    {
        i++;
    }
    return i-1;
}

int main()
{
    int n;
    scanf("%d",&n);

    while(n!=0)
    {
        printf("%d\n",CountMinCuts(n));
        scanf("%d",&n);
    }
    return 0;
}
