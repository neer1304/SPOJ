#include<stdio.h>
#include<string.h>

long long dp[56][56];

int main()
{
    int n,k,a,b;
    while(1)
    {
        scanf("%d %d",&n,&k);
        memset(dp,0,sizeof(dp));

        if(n==-1 && k==-1 )
            break;

        scanf("%d %d",&a,&b);

        --a;--b;
      //  printf("%lld\n",solve(a,0));

        dp[0][a] = 1;

        for(int i=1;i<=k;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j] = dp[i-1][(j+1)%n] + dp[i-1][(j+n-1)%n];
            }
        }
        printf("%lld\n",dp[k][b]);

      /*
        for(int i=1;i<20;i++)
        {
            for(int j=1;j<20;j++)
                printf("%d ",dp[i][j]);
        }
        */
    }
return 0;
}

#if 0
//start node and step
long long int dp[55][55];

int N,K,a,b;
//n- start node k - number of steps
long long int solve(int n, int k)
{
    static int z=0;
    printf("In solve %d\n",++z);
   if(K==k)
      return n==b;

    if(dp[n][k]!=-1)
        return dp[n][k];

    long long int ret = dp[n][k];

    ret=0;

    int u = n+1;
    int v = n-1;

    if(u==N)
        u=0;

    if(v==-1)
        v=N-1;

    ret = solve(u,k+1)+solve(v,k+1);
    return ret;
}

int main()
{
    while(1)
    {
        scanf("%d %d",&N,&K);
        memset(dp,-1,sizeof(dp));

        if(N==-1 && K==-1 )
            break;

        scanf("%d %d",&a,&b);

        --a;--b;
        printf("%lld\n",solve(a,0));

      /*
        for(int i=1;i<20;i++)
        {
            for(int j=1;j<20;j++)
                printf("%d ",dp[i][j]);
        }
        */
    }
return 0;
}
#endif
