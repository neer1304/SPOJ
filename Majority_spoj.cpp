#include<stdio.h>
#define MAXSIZE 1000001

int main()
{
    int t,n,i;
    int arr[MAXSIZE];
    int freq[2002];
    int flag =0,ind=0,fi=0;

    for(i=0;i<MAXSIZE;i++)
        arr[i]=0;

    scanf("%d",&t);

    while(t--)
    {
        for(i=0;i<2002;i++)
            freq[i]=0;

        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
           // printf("arr[i] is %d",arr[i]);
            fi=arr[i]+1000;
            freq[fi] += 1;
           // printf("freq[fi] is %d\n",freq[fi]);
        }

        for(i=1000;i<2002;i++)
        {
           if(freq[i]>(n/2))
           {
               flag=1;
               ind =i;
              // printf("freq[i] is %d and n/2 is %d\n",freq[i],n/2);
               break;
           }
        }
        if(flag)
           printf("YES %d\n",ind-1000);
        else
           printf("NO\n");

           flag=0;
    }
   return 0;
}
