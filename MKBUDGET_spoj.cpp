#include<stdio.h>
#include<limits.h>
#include<algorithm>
#include<string.h>


using namespace std;

int dp[30][30];

int min2(int a, int b)
{
    if(a>b)
        return b;
    else
        return a;
}

void compute_opt(int A[],int n,int hire,int fire,int sal,int max_a)
{
    // Fill all disallowed entries with infinity
    for (int i = 0; i < A[0]; ++i)
        dp[0][i] = 10000000;
    for(int i = A[0]; i <= max_a; i++)  //for num workers in 1st month
        dp[0][i] = i*(hire + sal);

    for(int i = 1; i < n; i++)
        for(int j = 0; j <= max_a; j++)
            {
                // No need for special case handling,
                //just check all previous numbers of employees
                dp[i][j] = 10000000;
                if (A[i] > j) continue;
                for(int k = 0; k <= max_a; k++)
                    dp[i][j] = min(dp[i][j],
                       dp[i-1][k] + j*sal + (j>k ? (j-k)*hire : (k-j)*fire));
            }
}

void compute(int arr[], int n, int hire, int sal, int fire, int maxw)
{
  int i,j,k;
  for(i=0;i<arr[0];i++)
    dp[0][i] = INT_MAX;

  for(i=arr[0];i<=maxw;i++)
  {
      dp[0][i] = i*(hire+sal);
  }

  for(i=1;i<n;i++)   //num of months
  {
    for(j=0;j<=maxw;j++)  //num of workers for ith month >=A[i] and <= max_a
    {
        dp[i][j] = INT_MAX;

    if(arr[i]>j)
        continue;

        for(k=0;k<=maxw;k++)
            dp[i][j] = min2(dp[i][j], dp[i-1][k] + j*sal + (j>k ? (j-k)*hire : (k-j)*fire));
    }
  }
}

int ans(int arr[], int n, int maxw)
{
    int i;
    int ret = dp[n-1][arr[n-1]];

    for(i=arr[n-1];i<=maxw;i++)
        ret = min2(ret,dp[n-1][i]);
    return ret;
}

int main()
{
    int n,i,cost_h,cost_m,cost_s,case1=1;
    int work[25], wmax=0;

    while(true)
    {
       scanf("%d",&n);
         if(n==0)
            break;

        memset(dp,0,sizeof(dp));
        memset(work,0,sizeof(work));

        scanf("%d %d %d",&cost_h,&cost_m,&cost_s);
        for(i=0;i<n;i++)
        {
            scanf("%d",&work[i]);
                wmax=max(wmax,work[i]);
        }
        compute_opt(work,n,cost_h,cost_m,cost_s,wmax);
        printf("Case %d, cost = $%d\n",case1,ans(work,n,wmax));
        case1++;
    }
    return 0;
}

#if 0

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector <int> > opt;

int ans(vector<int> A, int n, int max_a)
{
    int ret = opt[n-1][A[n-1]];
    for(int i = A[n-1]; i <= max_a; i++)
        ret = min (ret, opt[n-1][i]);

    return ret;
}

void compute_opt(vector<int> A,int n,int hire,int fire,int sal,int max_a)
{
    // Fill all disallowed entries with infinity
    for (int i = 0; i < A[0]; ++i)
        opt[0][i] = 1000000000;
    for(int i = A[0]; i <= max_a; i++)  //for num workers in 1st month
        opt[0][i] = i*(hire + sal);

    for(int i = 1; i < n; i++)
        for(int j = 0; j <= max_a; j++)
            {
                // No need for special case handling,
                //just check all previous numbers of employees
                opt[i][j] = 1000000000;
                if (A[i] > j) continue;
                for(int k = 0; k <= max_a; k++)
                    opt[i][j] = min(opt[i][j],
                       opt[i-1][k] + j*sal + (j>k ? (j-k)*hire : (k-j)*fire));
            }
}

int main()
{
    vector<int> A;
    int n, hire, fire, sal,max_a, c = 1;
    while(1)
    {
        cin >> n;
        if(n == 0)
            break;

        A.clear();
        opt.clear();
        max_a = 0;
        cin >> hire >> sal >> fire;
        A.resize(n);
        for(int i = 0; i < n; i++)
            {cin >> A[i];
             max_a = max(max_a,A[i]);
             }

        opt.resize(n);
        for(int i = 0; i < n; i++)
            opt[i].resize(max_a + 2);

        compute_opt(A,n,hire,fire,sal,max_a);
        cout << "Case " << c << ", cost = $" << ans(A,n,max_a) << endl;
        c++;
    }
    return 0;
}
#endif
