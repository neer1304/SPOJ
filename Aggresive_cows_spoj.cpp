/*
F(x) = 1 if it is possible to arrange the cows in stalls such that the distance between any two cows is at
         least x
F(x) = 0 otherwise

F(0)=1 trivially since the distance between any two cows is at least 0. Also, since we have at least two
cows, the best we can do is push them towards the stalls at the end - so there is no way we can achieve better.
Hence F(maxbarnpos-minbarnpos+1)=0.

Now, how do we check whether F(x)=1 for a general value of x? We can do this with a greedy algorithm:
Keep placing cows at the leftmost possible stalls such that they are at least x distance away from the last
placed cow. Assuming that the array pos containing positions of stalls has been sorted,

*/


#include<stdio.h>
#include<algorithm>

using namespace std;

int n;
int c;
int arr[100001];

int F(int x)
{
    //We can always place the first cow in the leftmost stall
    int currentpos=1;
    int lastpos = arr[0];
    int i;
    for(i=1;i<n;i++)
    {
        if(arr[i]-lastpos>=x)
        {
          //  printf("arr[i]-lastpos is %d and x is %d \n",arr[i]-lastpos,x);
           if(++currentpos==c) return 1;
            lastpos = arr[i];
        }
    }
  return 0;
}

int binarySearch()
{
    int start = 0;
    int end = arr[n-1]-arr[0]+1;
    int mid;

    while(end-start>1)
    {
       // printf("Start and end are %d %d\n", start,end);
        mid = (start+end)/2;
        if(F(mid)==1)
        {
            start = mid;
        }
        else
            end = mid;
    }
    return start;
}

int main()
{
    int t,i;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n, &c);

        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
         std::sort(arr,arr+n);

        printf("%d\n",binarySearch());
    }
    return 0;
}
