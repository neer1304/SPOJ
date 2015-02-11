#include<iostream>
#include<algorithm>
#include<stdio.h>

# define MAXSIZE 20009

using namespace std;

bool compare(long long i, long long j) { return (i<j); }

int main()
{
  int t,n,k,i;
  long long currmin=0,gmin=999999;
  scanf("%d",&t);

  long long h[MAXSIZE]={0};

  while(t--)
  {
      scanf("%d %d",&n,&k);

        for(i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
        }
         std::sort(h,h+n,compare);

         for(i=0;i<=n-k;i++)
         {
            currmin = h[k+i-1]-h[i];
            if(currmin<gmin)
                gmin=currmin;
         }
         printf("%lld\n",gmin);
        // h[MAXSIZE]={0};
         currmin=0,gmin=999999;
  }
  return 0;
}
