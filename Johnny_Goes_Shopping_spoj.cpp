#include<stdio.h>
#include<limits.h>
#include<algorithm>

#define MAXN 10010
#define MAXC 1e16
using namespace std;

void reconstruct_partition(int d[MAXN][MAXN],int n, int k);
void print_p(int start, int end1);

unsigned long long p[MAXN];
int d[MAXN][MAXN];
unsigned long long  m[MAXN][MAXN];

void partition_dp(long long  s[], int n, int k)
{
    int i,j,x;
    unsigned long long cost=0;
    p[0] = 0;

    for(i=1;i<=n;i++)
        p[i] = p[i-1] + s[i];

    for(i=1;i<=n;i++)
        m[i][1] = p[i];

    for(j=1;j<=k;j++)
        m[1][j] = s[1];

    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k;j++)
        {
            m[i][j] = MAXC;
            for(x=1;x<i;x++)
            {
                cost = max(m[x][j-1],p[i]-p[x]);
                if(m[i][j]>cost)
                {
                    m[i][j] = cost;
                    d[i][j] = x;
                }
            }
        }
    }
    /*
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            printf("i-%d, j-%d, m[i][j] - %d,d[i][j] - %d\n",i,j,m[i][j],d[i][j]);
        }
    }
    */
    reconstruct_partition(d,n,k);
}

void reconstruct_partition(int d[MAXN][MAXN],int n, int k)
{
    if(k==1)
        print_p(1,n);
    else
    {
        reconstruct_partition(d,d[n][k],k-1);
        print_p(d[n][k]+1,n);
    }
}

void print_p(int start, int end1)
{
   /* for(int i=start;i<=end1;i++)
      printf("%d ",s[i]);
      */
      printf("%d\n",end1-start+1);
}

int main()
{
    int n;

    scanf("%d",&n);
    long long  arr[n];

    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    partition_dp(arr,n,2);
}
