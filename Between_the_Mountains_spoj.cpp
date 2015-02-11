#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int t,i,j,flag=0;;
    int n1,n2;
    int min1=0;
    int diff_ind,diff_ind1;
    int temp=0;
    int i1,j1;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n1);
        int arr1[n1];

        for(i=0;i<n1;i++)
            scanf("%d",&arr1[i]);

        scanf("%d",&n2);
         int arr2[n2];

        for(j=0;j<n2;j++)
            scanf("%d",&arr2[j]);

            diff_ind = max(n1,n2);
            diff_ind1 = min(n1,n2);

          flag=0;
           min1 = 999999;
           temp =0;

        for(i1=0;i1<diff_ind;i1++)
        {
            for(j1=0;j1<diff_ind1;j1++)
            {
                if(n1-n2>=0)
                    temp = arr1[i1]-arr2[j1];
                else
                    temp = arr2[i1]-arr1[j1];

                if(temp==0)
                {
                    flag=1;
                    break;
                }
                if(temp<0)
                    temp *= -1;

                if(temp < min1)
                {
                    min1 = temp;
                }
            }
        }

        if(flag)
        {
          printf("0\n");
        }
        else
        {
           printf("%d\n",min1);
        }
    }
 return 0;
}
