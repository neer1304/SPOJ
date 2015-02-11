/*
Given you've already gotten exactly k distinct numbers so far, the probability that the next roll gives you a
new number is (n - k)/n, so the expected number of rolls to get a new number is n/(n-k).

So, the answer is n/n + n/(n-1) + n/(n-2) + ... + n/1, or n times the nth harmonic number.

*/
#include<stdio.h>

int main()
{
    int t,i;
    double n;
    double ans=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%lf",&n);
        for(i=0;i<n;i++)
        ans+= n/(n-i);
        printf("%.2lf\n",ans);
        ans=0;
    }
    return 0;

}
