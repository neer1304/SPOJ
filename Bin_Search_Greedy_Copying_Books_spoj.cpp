/*
Whenever there is a problem that asks you to minimize or maximize a value where ordering is not necessary
(where the first value can be more than the second one provided a later value is greater than or equal to
the first for example), use binary search to fix the upper bound and then try finding a solution in a greedy
manner. In this problem, use binary search to get a value ‘mid’ at every iteration. This is your upper bound.
Considering that your leftmost scribe should have the least work, start filling up the sets greedily from the right.
The ok() function returns true if with a given upper bound ‘v’, you  can assign the work-set to K or less scribes.
While creating the list, simply take care that at any given moment, if the number of books to be processed equals
the remaining number of scribes, assign one to each scribe and exit.

Get the final upper bound using binary search and then proceed to fill up the sets greedily as earlier (from the
right to left).
*/

#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int N,M;
int pages[500];

bool ok(long long x)
{
    //printf("In ok func() x is %d \n",x);
	int next=0;
	int i;
	long long sum;
	for (i=0; i<M; i++)
	{
		sum=0;
		do
		{
			sum+=pages[next];
			if (sum<=x)
				next++;
		}
		while (next<N && sum<=x);
		if (next==N&&sum<=x)
        {
           // printf("In ok() x-%lld and sum is %lld returning true\n",x,sum);
            return true;
        }

	}
//	printf("In ok() x-%lld and sum is %lld returning false\n",x,sum);
	return false;
}

int main()
{
	int t,i,j;
	scanf("%d",&t);
	int books[500];
	int work[500][500];

	while (t--)
	{
		scanf("%d %d",&N,&M);
		memset(books,0,sizeof(books));
		long long total=0;
		int _m=0;

		for (i=0; i<N; i++)
		{
			scanf("%d",pages+i);
			total+=pages[i];
			_m=max(_m,pages[i]);
		}

		long long l=max((total+M-1)/M,(long long)_m);

		long long u=total;
	//	printf("u-%lld l-%lld\n",u,l);

		while (u>l)
		{
			long long m=(l+u)/2;
			//printf("m-%lld\n",m);
			if (ok(m))
            {
                u=m;
              //  printf("u is now - %d\n",u);
            }
			else
            {
                l=m+1;
               // printf("l is now - %d\n",l);
            }
		}
        // printf("After binary search u-%lld l-%lld\n",u,l);

		int next=N-1;

		for (i=M-1; i>=0; i--)
		{
			long long sum=0;
			for(;;)
			{
				sum+=pages[next];
				if (sum<=l&&next>=i)
                {
                    work[i][books[i]++]=pages[next--];
                   // printf("Work assigned i-%d next-%d sum-%d\n",i,next,sum);
                }
				else
                {
                   // printf("Breaking from work loop i-%d next-%d sum-%d\n",i,next,sum);
                    break;
                }
			}
		}

		for (i=0; i<M-1; i++)
		{
			for (j=books[i]-1; j>=0; j--)
				printf("%d ",work[i][j]);
			printf("/ ");
		}
          // for last case print without /
		for (j=books[M-1]-1; j>=0; j--)
			printf("%d ",work[M-1][j]);
	//	printf("%d\n",work[M-1][0]);

	}
}

#if 0
#include<stdio.h>
#include<limits.h>
#include<algorithm>

#define MAXN 10009
#define MAXC 1e9
using namespace std;
int r=0;
void reconstruct_partition(long long s[],int d[MAXN][MAXN],int n, int k, int ck);
void print_p(long long s[],int start, int end1, int k, int ck);

unsigned long long p[MAXN];
int d[MAXN][MAXN];
unsigned long long  m[MAXN][MAXN];

void partition_dp(long long  s[], int n, int k)
{
    int i,j,x;
    unsigned long long cost=0;
    p[0] = 0;

    for(i=1;i<=n;i++)
        p[i] = p[i-1] + s[i];

    for(i=1;i<=n;i++)
        m[i][1] = p[i];

    for(j=1;j<=k;j++)
        m[1][j] = s[1];

    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k;j++)
        {
            m[i][j] = MAXC;
            for(x=1;x<i;x++)
            {
                cost = max(m[x][j-1],p[i]-p[x]);
                if(m[i][j]>cost)
                {
                    m[i][j] = cost;
                    d[i][j] = x;
                }
            }
        }
    }
    /*
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            printf("i-%d, j-%d, m[i][j] - %d,d[i][j] - %d\n",i,j,m[i][j],d[i][j]);
        }
    }
    */
    int ck=k;
    reconstruct_partition(s,d,n,k,ck);
}

void reconstruct_partition(long long s[],int d[MAXN][MAXN],int n, int k,int ck)
{
    if(k==1)
        print_p(s,1,n,k,ck);
    else
    {
        reconstruct_partition(s,d,d[n][k],k-1,ck);
        print_p(s,d[n][k]+1,n,k,ck);
    }
}

void print_p(long long s[],int start, int end1,int k,int ck)
{
     r++;
     for(int i=start;i<=end1;i++)
        printf("%d ",s[i]);

  //  printf("ck-%d r-%d\n",ck,r);

    if(r<ck)
      printf(" / ");
}
int main()
{
    int t,n,k;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&k);
        long long arr[n];

        for(int i=1;i<=n;i++)
            scanf("%lld",&arr[i]);
            r=0;
        partition_dp(arr,n,k);

    }
    return 0;
}
#endif
