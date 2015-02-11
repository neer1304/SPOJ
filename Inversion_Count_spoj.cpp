#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MAXSIZE 200009


long long  merge(int a[],int lb1,int ub1,int lb2,int ub2,int temp[]);

long long  MergeSort(int a[],int low,int high,int temp[])
{
long long int mid;
long long int icnt=0;
  if(low<high)
  {
   mid=(low+high)/2;
   icnt += MergeSort(a,low,mid,temp);
   icnt += MergeSort(a,mid+1,high,temp);
   icnt += merge(a,low,mid,mid+1,high,temp);
  }
  return icnt;
}

long long merge(int a[],int lb1,int ub1,int lb2,int ub2,int c[])
{
int i=lb1,j=lb2,k=0;
long long cnt =0;
int mid = (lb1+ub2)/2;
//long long int *c = (long long int*)malloc(sizeof(long long int)*(MAXSIZE));
//memset(c,0,MAXSIZE);
    while((i<=ub1)&&(j<=ub2))  //copy elements into buffer array till one list exhaust
    {
       if(a[i]<=a[j])
       {
           c[k]=a[i];
           k++;
           i++;
       }
       else
       {
           cnt += mid+1-i;
           c[k]=a[j];
           k++;
           j++;
       }
    }

       while(i<=ub1)   //if elements left in first list
       {
         c[k]=a[i];
         k++;
         i++;
       }
       while(j<=ub2)   //if elements left in second list
       {
         // cnt++;
         c[k]=a[j];
         k++;
         j++;
       }

       k=0;i=lb1;

       while(i<=ub2)
       {
          a[i]=c[k];
          i++;
          k++;
       }
       return cnt;
}

long long CountInversion(int arr[],int m,int temp[])
{
    return MergeSort(arr,0,m-1,temp);
}

int main()
{
    int i,n;
    long long icnt=0;
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        int arr[n],temp[n];
      // long long int *arr = (long long int*)malloc(sizeof(long long int)*(MAXSIZE));
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
         icnt = CountInversion(arr,n,temp);
         printf("%lld\n",icnt);
    }
    return 0;
}
