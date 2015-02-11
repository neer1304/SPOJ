#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXLEN 20

int dp[MAXLEN][MAXLEN];
char x[MAXLEN];
char y[MAXLEN];

int min2(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int findMinDist(int k)
{
    int i,j,d=0;
    int leftCell=0,topCell=0,cornerCell=0;
    int m = strlen(x);
    int n = strlen(y);

    /* Initialize first row */
    for(i=0;i<=m;++i)
        dp[i][0] = k*i;
    /* Initialize first column */
    for(j=0;j<=n;++j)
        dp[0][j] = k*j;

    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            leftCell = dp[i][j-1];
            topCell = dp[i-1][j];
            cornerCell = dp[i-1][j-1]+abs(x[i - 1] - y[j - 1]);
            dp[i][j] = min2(min2(leftCell,topCell)+k,cornerCell);
        }
    }
    /*
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
           printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    */
    return dp[m][n];
}

int main()
{
    int k;
    scanf("%s %s %d",x,y,&k);
    printf("%d\n",findMinDist(k));
    return 0;
}








