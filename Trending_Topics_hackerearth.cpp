#include<stdio.h>
#include<algorithm>

# define MAX 1000003

#define ll long long

using namespace std;

struct topic
{
    ll tid;
    ll zs;
    ll po;
    ll li;
    ll co;
    ll sh;
};

struct top
{
    ll tid;
    ll ozs;
    ll nzs;
    ll czs;
};

struct topic topics[MAX];
struct top tops[MAX];

bool compare_zs(top a, top b)
{
    if (a.czs!=b.czs)
        return (a.czs>b.czs);
     else
        return (a.tid>b.tid);
}

int main()
{
    int n,i;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%lld %lld %lld %lld %lld %lld",&topics[i].tid,&topics[i].zs,&topics[i].po,&topics[i].li,
              &topics[i].co,&topics[i].sh);

    for(i=0;i<n;i++)
    {
        tops[i].tid = topics[i].tid;
        tops[i].ozs = topics[i].zs;
        tops[i].nzs = topics[i].po*50+topics[i].li*5+topics[i].co*10+topics[i].sh*20;
        tops[i].czs = tops[i].nzs-tops[i].ozs;
    }
    std::sort(tops,tops+n,compare_zs);

    for(i=0;i<5;i++)
        printf("%lld %lld\n",tops[i].tid,tops[i].nzs);

return 0;
}
