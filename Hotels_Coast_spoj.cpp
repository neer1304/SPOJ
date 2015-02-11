#include <stdio.h>
#include <string.h>

int main()
{
    int n,m,i,k,flag=0;

    scanf("%d %d",&n,&m);

    int arr[n];
    int max_so_far=0,j=0,start=0;
    int max_g=0;
    int sum_l=0;

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

     for(i=0;i<n;i++)
     {
         sum_l+=arr[i];

           if(sum_l==m)
            {
                flag=1;
                break;
            }
            if(sum_l>m)
            {
                while((sum_l>m))
                {
                    sum_l=sum_l-arr[start];
                   // printf("Value of sum_l is %d\n",sum_l);
                    start++;
                }
            }
            if(sum_l>max_so_far)
                max_so_far=sum_l;

     }
     if(flag)
     {
         printf("%d",m);
         flag=0;
     }

     else
     {
          printf("%d",max_so_far);
     }

return 0;
}

