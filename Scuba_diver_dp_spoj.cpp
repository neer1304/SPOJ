#if 0
#include<stdio.h>
#include<algorithm>

#define INF 800 * 1000

using namespace std;


int dp[2][22][80];

int main()
{
    int c;

    scanf("%d",&c);

    int t=0,a=0,n=0,i=0,j=0,k=0,r=0;

    while(c--)
    {
        scanf("%d %d %d",&t,&a,&n);

        int ox[n],nit[n],w[n];
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&ox[i],&nit[i],&w[i]);
        }

        for(i = 0;i <= t;++i)
            for(j = 0;j <= a;++j)
                dp[1][i][j] = INF;

        dp[1][0][0] = 0;

        for(k=0,r=0;k<n;k++,r^=1)
        {
            for(i=0;i<=t;i++)
            {
                for(j=0;j<=a;j++)
                {
                   dp[r][i][j] = min(dp[r ^ 1][i][j],w[k]+ dp[r ^ 1][max(0,i-ox[k])][max(0,j-nit[k])]);
                }
            }
        }

        printf("%d\n",dp[(n-1) & 1][t][a]);
      //  printf("%d\n",rec(0,0,0));
    }
    return 0;
}
#endif

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1024;
const int INF = 0x3f3f3f3f;

int N, O, n, test, cs;
int nitro[MAX], oxi[MAX], w[MAX];
int dp[MAX][22][80], fl[MAX][22][80];

int solve(int i, int co, int cn) {
	if(co >= O && cn >= N) return 0; if(i == n) return INF;
	//if(co >= O) co = O; if(cn >= N) cn = N;
	//if(fl[i][co][cn] == cs) return dp[i][co][cn]; fl[i][co][cn] = cs;
	return dp[i][co][cn] = min(solve(i+1, co, cn), solve(i+1, co + oxi[i], cn + nitro[i]) + w[i]);
}

int main() {
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &O, &N, &n);
		for(int i = 0; i < n; i++) scanf("%d %d %d", &oxi[i], &nitro[i], &w[i]);
		printf("%d\n", solve(0, 0, 0));
	}
	return 0;
}

