#include<cstdio>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    vector<int>vp;
    vector<int>vp2;
    vector<int>vp1;
    while(n!=0)
    {
               vp.clear();
               vp1.clear();
               vp2.clear();
               int x[n];
               /* create a hash map */
               bool flag[20001]={false};

               for(int i=0;i<n;i++)
               {
                   scanf("%d",&x[i]);
                   /* save the first array element positions */
                    if(x[i]>=0)
                        flag[x[i]]=1;
                    else
                        flag[10000+abs(x[i])]=1;
               }

               int m;
               scanf("%d",&m);
               int sum=0;

               int y[m];
               bool ycond=false;

               for(int i=0;i<m;i++)
               {
                   scanf("%d",&y[i]);
                   sum+=y[i];
                   if(y[i]>=0)
                    ycond = flag[y[i]];
                   else
                    ycond = flag[10000+abs(y[i])];
                   if(ycond)
                   {
            /* push the index element of the same element of both arrays in vector */
                        vp.push_back(i);
            /* In other vector save the sum upto that similar element*/
                        vp2.push_back(sum);
                        sum=0;
                   }
               }

               vp2.push_back(sum);

               int j=0;
               sum=0;

               for(int i=0;i<n;i++)
               {
                 sum+=x[i];
        /* Now save the sum of 1st array element where we find same array element as of 2nd array*/
                if(j<vp.size()&&y[vp[j]]==x[i])
                {
                   vp1.push_back(sum);
                   sum=0;
                   j++;
                }
               }

               vp1.push_back(sum);

               long long int sum1=0;
              /* get the max out of the two vectors */
               for(int i=0;i<vp1.size();i++)
               {
                   sum1+=max(vp1[i],vp2[i]);
               }

               printf("%lld\n",sum1);
               scanf("%d",&n);
    }
    return 0;
}



#if 0
#include<stdio.h>
#include<string.h>


int bin_search(int a[], int left, int right, int x)
{
	if (right < left) {
		return -1;
	}

     int mid = (left + right) / 2;

	if (a[mid] == x) {
        return mid;
	}

	if (a[mid] > x) {
		return bin_search(a, left, mid - 1, x);
	} else {
		return bin_search(a, mid + 1, right, x);
	}
}


int main()
{
    int n1,n2,small=0,large=0,i=0,j=0,curr,prev_i,local_sum_1=0,local_sum_2=0;
    int sum=0,max_s=0,diff,k=0;
    scanf("%d",&n1);

    while(n1!=0)
    {
        int arr1[n1];
        memset(arr1,0,n1);
        for(i=0;i<n1;i++)
            scanf("%d",&arr1[i]);

         scanf("%d",&n2);

         int arr2[n2];
         memset(arr2,0,n2);
         for(i=0;i<n2;i++)
            scanf("%d",&arr2[i]);

         if(n1>n2)
         {
            small = n2;
            large = n1;
         }
         else
         {
            small = n1;
            large = n2;
         }

          for(i=0;i<n1&&j<n2;)
          {
              printf("i is %d and j is %d \n",i,j);
              if(i==0)
              {
                  if(arr1[i]>arr2[i])
                  {
                     sum+=arr1[i];
                     curr = 1;
                  }
                  else if(arr1[i] < arr2[i])
                  {
                     sum+=arr2[i];
                     curr = 2;
                  }
                  else
                  {
                     sum+=arr1[i];
                  }
              }
              else
              {
                  if(j=bin_search(arr2,0,n2,arr1[i]))
                  {

                  }


                  if(curr==1 && arr1[i]!=arr2[i])
                  {
                      sum+=arr1[i];
                  }
                  else if(curr==2 && arr1[i] != arr2[i])
                  {
                      sum+=arr2[i];
                  }
                  else if(arr1[i] == arr2[i])
                  {
                      sum+=arr1[i];
                      j=k=++i;

                      while(arr1[j]!=arr2[j] && j<small)
                      {
                          local_sum_1 += arr1[j];
                          local_sum_2 += arr2[j];
                          printf("local_sum_1 is %d and local_sum_2 is %d\n",local_sum_1,local_sum_2);
                          j++;
                      }
                     if(local_sum_1>=local_sum_2)
                     {
                         sum+=local_sum_1+arr1[j];
                         curr=1;
                     }
                     else
                     {
                         sum+=local_sum_2+arr2[j];
                         curr=2;
                     }
                     i=j+1;
                     local_sum_1=0;
                     local_sum_2=0;
                     j=0;
                  }
                  else
                    continue;
              }

          }

      /*  while(i<large)
        {
            if(large==n1)
                sum+=arr1[i];
            else
                sum+=arr2[i];
                i++;
        }
      */
        printf("%d\n",sum);
        sum=0;
       scanf("%d",&n1);
    }
return 0;
}
#endif
