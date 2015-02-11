#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include<string.h>

/* Do not break from dijkstra even if you get the target node costed me 4 WA's */
using namespace std;

typedef pair< int, int > pii;

/*
Set MAX according to the number of nodes in the graph. Remember,
nodes are numbered from 1 to N. Set INF according to what is the
maximum possible shortest path length going to be in the graph.
This value should match with the default values for d[] array.
*/
const int MAX = 10010;
const int INF = 999999;

/*
pair object for graph is assumed to be (node, weight). d[] array
holds the shortest path from the source. It contains INF if not
reachable from the source.
*/
vector< pii > G[MAX];
int d[MAX];

/*
The dijkstra routine. You can send a target node too along with
the start node.
*/
void dijkstra(int start, int target)
{
  //  printf("In dijkstra\n");
    int u, v, i, c, w;

    /*
    Instead of a custom comparator struct or class, we can use
    the default comparator class greater<T> defined in queue.h
    */
    priority_queue< pii, vector< pii >, greater< pii > > Q;

    /*
    Reset the distance array and set INF as initial value. The
    source node will have weight 0. We push (0, start) in the
    priority queue as well that denotes start node has 0 weight.
    */
    memset(d, 999999, sizeof d);
    // start - node 0 -weight
    Q.push(pii(start, 0));
    d[start] = 0;

    /*
    As long as queue is not empty, check each adjacent node of u
    */
    while(!Q.empty())
    {
    //    printf("In dijkstra while loop\n");
        u = Q.top().first; // node
        c = Q.top().second; // node cost so far
        Q.pop(); // remove the top item.

        /*
        We have discarded the visit array as we do not need it.
        If d[u] has already a better value than the currently
        popped node from queue, discard the operation on this node.
        */
        if(d[u] < c) continue;

        /*
        In case you have a target node, check if u == target node.
        If yes you can early return d[u] at this point.
        */
        /*
         if (u==target)
         {
            if(d[u] !=INF)
                printf("%d\n",d[u]);
            else
                printf("NO\n");
                return;
         }
         */
        /*
        Traverse the adjacent nodes of u. Remember, for the graph,,
        the pair is assumed to be (node, weight). Can be done as
        you like of course.
        */
        for(i = 0; i < G[u].size(); i++)
        {
            v = G[u][i].first; // node
            w = G[u][i].second; // edge weight

            /*
            Relax only if it improves the already computed shortest
            path weight.
            */
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push(pii(v, d[v]));
            }
        }
    }
 //   d[target] == INF ? printf("NO\n") : printf("%d\n", d[target]);
     printf("%d\n",d[target]);
   // printf("NO\n");
}

int main()
{
   // int n, e, i, u, v, w, start,target;
    /*
    Read a graph with n nodes and e edges.
    */
    int t,i,j,n,nr,cost;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        char name[n][11];
        memset(name[n],0,sizeof name[n]);

        for(i = 1; i <= n; i++)
           G[i].clear();

        for(i=1;i<=n;i++)
        {
            scanf("%s",name[i]);

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
            char src[11];
            char dest[11];

            memset(src,0,11);
            memset(dest,0,11);

            scanf("%s %s",src,dest);
          //  printf("src - %s dest - %s\n",src,dest);
            int is=0,id=0;

            for(i=1;i<=n;i++)
            {
             //   printf("In strcmp  name[i] is %s\n",name[i]);
                if(!strcmp(name[i],src))
                {
                    is = i;
                }
                if(!strcmp(name[i],dest))
                {
                    id = i;
                }
            }
           // printf("is - %d id - %d\n",is,id);
            dijkstra(is,id);
        }
    }
       // printf("In main\n");

       // Reset the graph

       #if 0
        for(i = 1; i <= n; i++)
           G[i].clear();

        /*
        Read all the edges. u to v with cost w
        */
        for(i = 0; i < e; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(pii(v, w));
           // G[v].push_back(pii(u, w)); // only if bi-directional
        }

        /*
        For a start node call dijkstra.
        */
        scanf("%d %d", &start, &target);

        dijkstra(start, target);

        /*
        Output the shortest paths from the start node.
        */
     /*   printf("Shortest path from node %d:\n", start);
        for(i = 1; i <= n; i++) {
            if(i == start) continue;
            if(d[i] >= INF) printf("\t to node %d: unreachable\n", i);
            else printf("\t to node %d: %d\n", i, d[i]);
        }
        */
    }
    #endif // 0
    return 0;
}
