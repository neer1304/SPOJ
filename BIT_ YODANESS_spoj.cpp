#include<stdio.h>
#include <map>
#include<string>
#include<string.h>

using namespace std;

#define MAX 30001

map<string,int> m;
char str[MAX][21];
int tree[MAX+1];
int n;

void PutValue(int x)
{
   // printf("In PutValue x-%d\n",x);
    while(x<=n)
    {
        tree[x] += 1;
        x+=(x&-x);
    }
}

int GetCumuL(int x)
{
   // printf("In GetCummL x-%d\n",x);
    int sum=0;

    sum = tree[0];
    while(x>0)
    {
        sum+=tree[x];
        x-=(x&-x);
    }
return sum;
}

int main()
{
   // freopen("yoda_in.txt","r",stdin);
   // freopen("yoda_out.txt","w",stdout);
    int t;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        m.clear();
        for(int i=0;i<=n;i++) tree[i] = 0;
        memset(str,0,sizeof(str));
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%s",str[i]);
        }
        char temp[21];
        for(i=1;i<=n;i++)
        {
            scanf("%s",temp);
            m[temp]=i;
        }

      //  int res=(n*(n-1))/2;
        int res=0;
        for(i=n-1;i>=0;i--)
        {
            res+=GetCumuL(m[str[i]]);
            PutValue(m[str[i]]);
        }

        printf("%d\n",res);
    }
    return 0;
}
