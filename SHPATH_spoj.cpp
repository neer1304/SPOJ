/*
http://zobayer.blogspot.in/2009/12/dijkstras-algorithm-in-c.html
http://just-yousef.blogspot.in/2014/03/spoj-shortest-path-shpath.html

*/

#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <string>



using namespace std;

typedef pair< int, int > pii;


const int MAX = 10010;
const int INF = 1e9;

vector< vector < pii > > G;
int n;
int t,i,j,nr,cost;

int dijkstra(int start, int target)
{
  //  printf("In dijkstra\n");
    int u, v, i, c, w;
    vector<int> d(n + 5, INF);

    priority_queue< pii > Q;

    Q.push(pii(0, start));
    d[start] = 0;

    while(1)
    {
        c = -(Q.top()).first; // node cost so far
        u = (Q.top()).second; // node

        if(u==target)
            return c;

        Q.pop(); // remove the top item.

        if(d[u] < c) continue;
        int s = G[u].size();
        for(i = 0; i < s; i++)
        {
            v = G[u][i].first; // node
            w = G[u][i].second; // edge weight

            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push(pii(-d[v], v));
            }
        }
    }
  //  printf("%d\n",d[target]);
}

int main()
{
   // freopen("ip.txt","r",stdin);
   // freopen("op.txt","w",stdout) ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        char src[20],dst[20];
        map<string,int>	map_city;
        G = vector< vector < pii > >(n + 5);

        for(i=1;i<=n;i++)
        {
            scanf("%s",src);
            map_city[src] = i;
            int p;

            scanf("%d",&p);

            for(j=1;j<=p;j++)
            {
                scanf("%d %d",&nr,&cost);
                G[i].push_back(pii(nr, cost));
            }
        }
        int r;
        scanf("%d",&r);

        for(j=0;j<r;j++)
        {
            scanf("%s %s",src,dst);
            printf("%d\n",dijkstra(map_city[src],map_city[dst]));
        }
    }

    return 0;
}
