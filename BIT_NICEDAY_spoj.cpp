#include<stdio.h>
#include<algorithm>
#define MAX 100009

using namespace std;

struct comp
{
    int first;
    int second;
    int third;
};

int tree[MAX+1];
int n;

bool cmp(comp a, comp b)
{
    return a.first==b.first?(a.second==b.second?a.third<b.third:a.second<b.second):a.first<b.first;
}

int min(int a, int b)
{
    return a<b?a:b;
}
// maintain min value in the index
void PutValue(int idx, int val)
{
    printf("In PutValue idx-%d\n",idx);
    while(idx<=n)
    {
       tree[idx] = min(tree[idx],val);
        idx+=(idx&-idx);
    }
}
// returns the min of the value in the tree
int read(int idx)
{
    printf("In read idxx-%d\n",idx);
    int res=1<<30;

    while(idx>0)
    {
        res=min(res,tree[idx]);
        idx-=(idx&-idx);
    }
return res;
}

int main()
{
    int t,i;

    freopen("nice_in.txt","r",stdin);
    freopen("nice_out.txt","w",stdout);
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        comp inp[n+9] ;

        for(i = 0 ; i < n ; i++)
        {
            scanf("%d %d %d", &inp[i].first, &inp[i].second, &inp[i].third);
        }

        int res=0;
        sort(inp,inp+n,cmp);

        fill(tree, tree + n+3 , 1<<30);

        for(i=0;i<n;i++)
        {
            int curr = read(inp[i].second);
            printf("curr is %d and third-%d \n ",curr,inp[i].third);
            if(curr>inp[i].third)
                res++;
            PutValue(inp[i].second,inp[i].third);
        }
        printf("inp array after sorting is-");
        for(i=0;i<n;i++)
          printf("%d %d %d ",inp[i].first,inp[i].second,inp[i].third);
        printf("\n");

        printf("tree array is \n");
        for(i=0;i<=n+3;i++)
            printf("%d ",tree[i]);
        printf("\n");
        printf("%d\n",res);
    }
    return 0;
}
