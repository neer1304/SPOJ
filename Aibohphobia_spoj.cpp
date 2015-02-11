#include<stdio.h>
#include<string.h>
#include<stdlib.h>

# define MAXLEN 6110

int max(int a, int b)
{
    return (a > b)? a : b;
}

int lcs(char *x, char *y, int n)
{
    int dp[2][n+1];
    int i,j,r=1;
    int result =0;
     memset(dp,0,sizeof(dp));
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            if (x[i-1] == y[j-1])
            {
                dp[r][j] = dp[!r][j-1] + 1;
            }
            else
                dp[r][j] = max(dp[r][j-1],dp[!r][j]);
        }
        r=!r;
    }
  /*  for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf(" %d ",dp[i][j]);
        }
        printf("\n");
    }
*/
    return dp[!r][n];
}

int main()
{
    int t,len,i;
    char str [MAXLEN];
    char rev[MAXLEN];

    for(i=0;i<MAXLEN;i++)
        str[i]=rev[i]=0;

    scanf("%d",&t);

    while(t--)
    {
       scanf("%s",str);
       len = strlen(str);
       for(i=0;i<len;i++)
       {
           rev[i]=str[len-i-1];
       }
      // printf(" %d %d ",len,j);
       printf("%d\n",len-lcs(str,rev,len));

     }
    return 0;
}
