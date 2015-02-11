#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <string.h>
# define MAXSIZE 109
using namespace std;
/*
if we mix mixtures i…j into a single mixture, irrespective of the steps taken to achieve this, the final
colour of the mixture is the same, equal to csum(i,j) = sum(colour(i…j)) mod 100. So we define best(i,j) as
the least amount of smoke produced while converting the mixtures from i…j into a single mixture. For achieving
this, at the previous step, we would have had to combine two mixtures which are resultants of ranges i…k and
k+1…j where i≤k<j. Thus we obtain the recurrence:

best(i,j) = min(k : i≤k<j) best(i,k) + best(k+1,j) + csum(i,k)*csum(k+1,j).

The base case is that best(i,i)=0. The recurrence allows us to calculate best(1,N) in O(N³) time
*/

int csum(int arr[],int start,int end)
{
    int i,sum=0;
    for(i=start;i<=end;i++)
    {
        sum+=arr[i];
        sum%=100;
    }
    return sum;
}

int MinSmoke(int arr[], int n)
{
    int i,L,j,k,q;
    int m[n][n];

    if(n==2)
      return arr[0]*arr[1];

    for(i=0;i<n;i++)
        m[i][i]=0;

    for(L=2;L<=n;L++)
    {
        for(i=0;i<n-L+1;i++)
        {
            j=i+L-1;
            m[i][j]=INT_MAX;

            for(k=i;k<j;k++)
            {
                q = m[i][k] + m[k+1][j] + csum(arr,i,k)*csum(arr,k+1,j);

                if(q<m[i][j])
                    m[i][j]=q;
            }
        }
    }
    /*
    printf("Array m[n][n] -\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf (" %d ",m[i][j]);
        }
        printf("\n");

    }
   */
    return m[0][n-1];
}

int main()
{
    int n;
    int i,j;
    int arr[MAXSIZE]={0};
    while(cin>>n)
    {
       for(i=0;i<n;i++)
       {
           scanf("%d",&arr[i]);
       }
       printf("%d\n",MinSmoke(arr,n));
      // arr[MAXSIZE]=0;
    }
    return 0;
}
