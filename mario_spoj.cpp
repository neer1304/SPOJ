#include<stdio.h>
#include<algorithm>

int main()
{
    int arr[10];
    int i,sum_l=0,sum_g=0,flag=0;

    for(i=0;i<10;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<10;i++)
    {
        sum_l+=arr[i];

        if(sum_l-100>0)
        {
            if(sum_l-100<=100-(sum_l-arr[i]))
                printf("%d\n",sum_l);
             else
                 printf("%d\n",sum_l-arr[i]);

            return 0;
        }

    }
      printf("%d\n",sum_l);

    return 0;
}
