#include<stdio.h>
#include<algorithm>
#include<math.h>

int dp[1000][2];

using namespace std;

int main()
{
  int n,i,s=0;

  scanf("%d",&n);

  int a[n],b[n];

  for(i=0;i<n;i++)
  {
      scanf("%d %d",&a[i],&b[i]);
  }

  for(i=0;i<n;i++)
  {
      /*
      s += max(a[i],b[i]);

      if(i+1<n)
      s += abs(max(a[i+1],b[i+1])-min(a[i],b[i])) + min(a[i+1],b[i+1]);

      if(i+2<n)
      s += abs(max(a[i+1],b[i+1])- min(a[i+2],b[i+2]));
      i=i+1;
      */
      if(i==0)
      {
          dp[i][0] = a[0];
          dp[i][1] = b[0];
      }
      else
      {
          dp[i][0] = a[i] + max(dp[i-1][0]+abs(b[i]-b[i-1]),dp[i-1][1]+abs(b[i]-a[i-1]));
          dp[i][1] = b[i] + max(dp[i-1][0]+abs(a[i]-b[i-1]),dp[i-1][1]+abs(a[i]-a[i-1]));
      }
  }
  printf("%d\n",max(dp[n-1][0],dp[n-1][1]));
return 0;
}
