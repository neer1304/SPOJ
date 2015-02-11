#include<stdio.h>
#include<limits.h>

#define INF INT_MAX

int main()
{
    int s1,t1,s0,t0,n,m,i,sum=0,beg = 0,res=INF,sprev,tprev,t;

    scanf("%d",&t);

    while(t--)
    {
       scanf("%d %d %d %d",&s0,&t0,&n,&m);

       sum=0;
       beg=0;
       res = INF;
       int a[n];

         sprev = s0;
         tprev = t0;

       for(i=0;i<n;i++)
      {
            s1 = (78901 + 31*sprev)% 699037;
            t1 = (23456 + 64*tprev)% 2097151;
            a[i]=(s1%100 + 1)* (t1%100 + 1);
            sprev=s1;
            tprev = t1;
       //     dp[a[i]] = 1;

           sum+=a[i];
           while(sum>m && beg <=i)
           {
               sum-=a[beg];
               beg++;
           }
           if(beg>0 && res>i-beg+1)
            res = i-beg+1;

         //   printf("%d ",a[i]);
      }

    if(res==INF)
        printf("%d\n",n);
    else
        printf("%d\n",res);

  }

    return 0;
}
