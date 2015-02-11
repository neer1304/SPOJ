#include<cstdio>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;
#define MAX 1<<10
#define LOG 10

typedef pair<int, int> pii;
vector<pii> G[MAX];

int P[MAX][LOG], dist[MAX], pi[MAX], lvl[MAX];

int n;
FILE *fin,*fout;

void dfs(int par, int u, int depth)
{
    fprintf(fout,"In dfs() func\n");
    int sz = G[u].size();
    int i,v,w;
    lvl[u] = depth;

    for(i=0;i<sz;i++)
    {
        v = G[u][i].first;
        w = G[u][i].second;

        if(v!=par)
        {
            dist[v] = dist[u] + w;
            pi[v] = u;
            dfs(u,v,depth+1);
        }
    }
}

void process(int n)
{
    /*
     First, let's compute a table P[1,N][1,logN] where P[i][j] is the 2^j-th ancestor of i.
     For computing this value we may use the following recursion:
     P[i][j] = pi[i] , if j=0
             = P[P[i-1][j]][j-1] , j>0
    */
    fprintf(fout,"In process() func\n");
    int i, j;
    memset(P,-1,sizeof(P));

    for(i = 1; i <= n; i++)
        P[i][0] = pi[i];

    for(j = 1; 1<<j < n; j++)
    {
        for(i = 1; i <= n; i++)
        {
            if(P[i][j-1]!=-1)
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}

int lca(int p, int q)
{
    fprintf(fout,"In lca func()\n");
    int i,log;

    //if p is situated at higher level than q then we swap them
    if(lvl[p]<lvl[q])
        swap(p,q);

    //we compute the value of [log(lvl[p)]
    for(log=1;1<<log <= lvl[p]; log++);
       log--;

    //  we find the ancestor of node p situated on the same level
    //  with q using the values in P
    fprintf(fout,"log is %d\n",log);
    for(i=log; i>=0; i--)
    {
        if(lvl[p]-(1<<i) >= lvl[q])
            p = P[p][i];
    }

    if(p==q)
        return p;

    //we compute LCA(p,q) using the values in P
    for(i=log;i>=0;i--)
    {
        if(P[p][i]!=-1 && P[p][i]!= P[q][i])
        {
            p = P[p][i];
            q = P[q][i];
        }
    }
    return pi[p];
}

int find1(int p, int t)
{
    fprintf(fout,"In find1() func\n");
    int i,log;

    //we compute the value of [log(lvl[p)]
    for(log=1;1<<log <= lvl[p]; log++);
       log--;

    for(i=log;i>=0;i--)
    {
        if(lvl[p] - (1<<i) >= t)
			p = P[p][i];
    }
    return p;
}

int main()
{
    fin  = fopen ("Qtree2.txt","r");
    fout = fopen ("Qtree2_out.txt","w");

    int t,i,a,b,cost,st,en,k;
    char query[5];

    fscanf(fin,"%d",&t);

    while(t--)
    {
        fscanf(fin,"%d",&n);

        for(i=1;i<=n;i++)
        {
            G[i].clear();
            dist[i] = 0;
            pi[i] = -1;
        }

     for(i=1;i<n;i++)
     {
         fscanf(fin,"%d %d %d",&a,&b,&cost);
         G[a].push_back(pii(b,cost));
         G[b].push_back(pii(a,cost));
     }
     dfs(-1,1,0);

     fprintf(fout,"dist[] arr after dfs is\n");
     for(i=0;i<=n;i++)
        fprintf(fout,"%d ",dist[i]);
     fprintf(fout,"\n");

     fprintf(fout,"pi[] arr after dfs is\n");
     for(i=0;i<=n;i++)
        fprintf(fout,"%d ",pi[i]);
    fprintf(fout,"\n");

    fprintf(fout,"lvl[] arr after dfs is\n");
    for(i=0;i<=n;i++)
        fprintf(fout,"%d ",lvl[i]);
    fprintf(fout,"\n");

    process(n);

    fprintf(fout,"P[] arr after process is\n");
    for(int j = 0; 1<<j < n; j++)
    {
        for(i = 1; i <= n; i++)
             fprintf(fout,"%d ",P[i][j]);
        fprintf(fout,"\n");
    }
    fprintf(fout,"\n");

     while(fscanf(fin,"%s",query)==1)
     {
         if(query[1]=='O')
            break;

         fscanf(fin,"%d %d",&st,&en);

         a=lca(st,en);
         fprintf(fout,"lca is %d\n",a);

         if(query[1]=='I')
         {
             fprintf(fout,"dist[st] - %d, dist[en] - %d, dist[a] - %d\n",dist[st],dist[en],dist[a]);
             int ans = (dist[st]+dist[en])-(2*dist[a]);
             fprintf(fout,"%d\n",ans);
         }
         else if(query[0]=='K')
         {
             fscanf(fin,"%d",&k);
             if(lvl[st]-lvl[a]+1>=k)
                b = find1(st,lvl[st]-k+1);
             else
                b = find1(en,2*lvl[a]+k-lvl[st]-1);
             fprintf(fout,"%d\n",b);
         }
     }
     fprintf(fout,"\n");
    }
    return 0;
}
