#include<stdio.h>

/*
if boy loses on i-1/i-k/i-l position then he could win next up by sweeping
up 1/k/l coins and will win the game.
*/

bool memo[1000001];

int isWinRec(int n, int k, int l)
{
    if(n==1)
       return 1;
    else if(n==k)
       return 1;
    else if(n==l)
        return 1;
    else if(isWinRec((n-1),k,l)||isWinRec(n-k,k,l)||isWinRec(n-l,k,l))
        return 1;
    else
        return 0;
}

int main()
{
    int k,l,m;
    int i,maxN=0;

    scanf("%d %d %d",&k,&l,&m);

    int arr[m];

    for(i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>maxN)
            maxN = arr[i];
    }

    memo[0] = false;
    memo[1] = true;

    for(i=2;i<=maxN;i++)
    {
        if(i-1>=0 && !memo[i-1])
            memo[i] = true;
        else if (i-l>=0 && !memo[i-l])
            memo[i] = true;
        else if (i-k>=0 && !memo[i-k])
            memo[i] = true;
        else
            memo[i] = false;
    }

    for(i=0;i<m;i++)
    {
        if(memo[arr[i]])
            printf("A");
        else
            printf("B");
    }
return 0;
}
