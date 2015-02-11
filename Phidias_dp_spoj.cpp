#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

int dp[601][601];

int main()
{
    int t,w,h,n,i,j,k;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&w,&h);
        scanf("%d",&n);
        int wi,hi;

        memset(dp,360000,sizeof(dp));

        for(i=0;i<n;i++)
        {
            scanf("%d %d",&wi,&hi);
            dp[wi][hi] = 0; //waste to be zero
        }

        for(i=0;i<=w;i++)
        {
            for(j=0;j<=h;j++)
            {
               dp[i][j] = min(dp[i][j],i*j); //whole slab is wasted

               for(k=1;k<i;k++) //cut the slab horizontally
                dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]);

               for(k=1;k<j;k++) //cut the slab vertically
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]);
            }
        }
        printf("%d\n",dp[w][h]);
    }
    return 0;
}
