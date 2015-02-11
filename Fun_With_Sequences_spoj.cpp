#include<stdio.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];

    for(i=0;i<n;i++)
     scanf("%d",&arr[i]);

     for(i=1;i<n;i++)
     {
         if(arr[i]==arr[i-1])
         {
           arr[i-1]  = arr[i-2];
           arr[i-2]=arr[i];
         }
     }
     for(i=0;i<n;i++)
        printf("%d ",arr[i]);
return 0;
}
