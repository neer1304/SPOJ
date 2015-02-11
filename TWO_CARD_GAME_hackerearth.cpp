#include<stdio.h>
#include<algorithm>

using namespace std;

int fact(int n)
{
    if(n==1||n==0)
        return 1;
    else
        return n*fact(n-1);

}

int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    std::sort(arr,arr+n);

    int dis =1;

    for(i=1;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
            dis++;
    }

    n=dis;

    //printf("%d",fact(n));
    if(n==0)
        printf("0.000000 0.000000\n");
    else
    {
        double w = (double)n/fact(n);
        double l = 1-w;

     /*   double w=0,l=0;

       double den = (double)(n*(n-1));
       for(int i=0;i<n;i++)
       {
          w +=  (double)((n-i-1)/den);
       }

       l=1-w;
       */
        printf("%0.6lf %0.6lf\n",w,l);
    }
    return 0;
}
