#include<stdio.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    long long int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    long long int a=arr[0];
    long long int res;
   for(i=1;i<n;i++)
   {
       res = a^arr[i];
       a=res;
   }
   printf("%lld\n",res);
   return 0;
}







