
#include<stdio.h>
#include<iostream>
#include<limits.h>
#include<string.h>
#include<algorithm>

using namespace std;

string seq;
int dp[251];
int dp1[201][201];

int maxLenRec(int i, int j)
{
    int cost = 0;
    int k,sweet=0,sour=0;

    for(k=i;k<j;k++)
    {
        if(seq[k]=='1')
            sweet++;
        else
            sour++;
        if(sweet>sour)
        {
            cost = max(cost,maxLenRec(k+1,j)+sweet+sour);
        }
        else
            cost = max(cost,maxLenRec(k+1,j));
    }
   return cost;
}
// O(n^2) dp
int maxLenDpOptimised(int n)
{
   int i,j,cnt,add=0;
   dp[0] = seq[0]-'0';

   for(i=1;i<n;i++)
   {
       dp[i] = dp[i-1];
       cnt=0;
       for(j=i;j>=0;j--)
       {
           cnt+=((seq[j]=='1')?1:-1);

           if(cnt>0)
           {
               add=i-j+1;
               if(j>0)
                add+=dp[j-1];
               dp[i] = max(dp[i],add);
           }

       }
   }
 //  for(i=0;i<n;i++)
 //   printf(" %d ",dp[i]);
return dp[n-1];
}

int sellable(int i, int j)
{
    int sweet=0,sour=0;
    int k;
    int cnt=0;
    for(k=i;k<=j;k++)
    {
        if(seq[k]=='1')
            sweet++;
        else
            sour++;
    }
    if(sweet>sour)
        return 1;
    else
        return 0;
}

//O(n^3) dp

int maxLenDp(int n)
{
    int i,j,k,L,cost=0;

    for(i=0;i<n;i++)
        dp1[i][i] = seq[i]-'0';

    for(L=2;L<=n;L++)
    {
        for(i=0;i<n-L+1;i++)
        {
            j=i+L-1;

                if (sellable(i, j))
                {
                     cost = j - i + 1;
                }
                else
                {
                    cost=dp1[i][j];
                    for (k = i; k < j; k++)
                    cost = max(cost,dp1[i][k]+dp1[k+1][j]);
                }
                if(cost>dp1[i][j])
                    dp1[i][j] =cost;
        }
     }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%d ",dp1[i][j]);
        }
        printf("\n");
    }
    return dp1[0][n-1];
}



int main()
{
    int t,n,i,j;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        cin>>seq;
        i=0;j=n;
        memset(dp,0,sizeof(dp));
      //  printf("%d\n",maxLen(i,j));
      //  printf("%d\n",maxLenDpOptimised(n));
         printf("%d\n",maxLenDp(n));
    }

    return 0;
}




