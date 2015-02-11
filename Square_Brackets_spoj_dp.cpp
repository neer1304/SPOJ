/*
Let count(i,j) be the number of valid ways of filling the first i positions such that there are j more brackets of
type '[' than of type ']'. Valid ways would mean that it is the prefix of a matched  bracket expression and that
the locations at which we have enforced '[' brackets have been satisfied. It is easy to see that count(2N,0) is the
final answer we need.

The base case of the DP is that count(1,1)=1. You have to fill the first position with a '[' bracket, and there is
only way to do this. count(1,i)=0 for i>1.

The recurrence for i>1 is:
count(i,0) = count(i-1,1)
count(i,j) = count(i-1,j-1) + count(i-1,j+1) for j>0

If i is a location where we have enforced a '[' bracket, the recurrence changes to:
count(i,0) = 0
count(i,j) = count(i-1,j-1) for j>0

Using these relations, count(2N,0) can be found in O(N²) time.
*/

#include<stdio.h>
#include<string.h>
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))

#if 0
int pos[20];

int dp[40][40];

int isExist(int a,int k)
{
    for(int i=0;i<k;i++)
    {
        if(pos[i]==a)
            return 1;
    }
    return 0;
}

int calc(int n, int k)
{
  int i,j;

  for(i=1;i<=2*n;i++)
  {
      for(j=0;j<=i;j++)
      {
          if(i==1)
          {
              if(j==1)
                dp[i][j] =  1;
              else
                dp[i][j] = 0;
          }
          else
          {
              if(isExist(i,k))
                dp[i][j] = ((j==0)?0:dp[i-1][j-1]);
              else
                dp[i][j] = dp[i-1][j+1] + ((j==0)?0:dp[i-1][j-1]);
          }
      }
   }
return dp[2*n][0];
}

int main()
{
    int t;
    scanf("%d",&t);

    int n,k,i;

    while(t--)
    {
       scanf("%d %d",&n,&k);
       memset(pos,0,sizeof(pos));
       memset(dp,0,sizeof(dp));

       for(i=0;i<k;i++)
         scanf("%d",&pos[i]);

       printf("%d\n",calc(n,k));
    }
    return 0;
}
#endif


const int MAX = 40;

bool f[MAX];
int dp[MAX][MAX], n;

int solve(int pos, int open)
{
	if(open < 0)
	    return 0; // invalid

	if(pos == n)
        return open == 0; // must for being valid

	int &ret = dp[pos][open];

	if(ret != -1)
	    return ret;

	if(f[pos])
        return ret = solve(pos+1, open+1); // must put a [ here

	return ret = solve(pos+1, open+1) + solve(pos+1, open-1); // try [ and ] both
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t, k, m, i;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		n <<= 1;
		CLR(f); SET(dp);
		for(i = 0; i < k; i++) {
			scanf("%d", &m);
			f[m-1] = 1;
		}
		printf("%d\n", solve(0, 0));
	}
	//system("pause");
	return 0;
}
