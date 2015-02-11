#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
/* Do not break from dijkstra even if you get the target node costed me 4 WA's */
using namespace std;

typedef pair< int, int > pii;

/*
Set MAX according to the number of nodes in the graph. Remember,
nodes are numbered from 1 to N. Set INF according to what is the
maximum possible shortest path length going to be in the graph.
This value should match with the default values for d[] array.
*/
const int MAX = 1024;
const int INF = 0x3f3f3f3f;

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
    int u, v, i, c, w;

    /*
    Instead of a custom comparator struct or class, we can use
    the default comparator class greater<T> defined in quque.h
    */
    priority_queue< pii, vector< pii >, greater< pii > > Q;

    /*
    Reset the distance array and set INF as initial value. The
    source node will have weight 0. We push (0, start) in the
    priority queue as well that denotes start node has 0 weight.
    */
    memset(d, 0x3f, sizeof d);
    // 0 -weight start - node
    Q.push(pii(start, 0));
    d[start] = 0;

    /*
    As long as queue is not empty, check each adjacent node of u
    */
    while(!Q.empty())
    {
       // printf("In while loop\n");
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
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(pii(v, d[v]));
            }
        }
    }
    d[target] == INF ? printf("NO\n") : printf("%d\n", d[target]);
   // printf("NO\n");
}

int main()
{
    int n, e, i, u, v, w, start,target;
    /*
    Read a graph with n nodes and e edges.
    */
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &n, &e);
       // printf("In main\n");
        /*
        Reset the graph
        */
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
    return 0;
}



#if 0
#include<stdio.h>
#include<limits.h>
#include<vector>
#define MAX 10009

using namespace std;
int n;

//vector<int> arr[10009];

vector<vector <int> > arr;

int minDist(int dist[],bool visited[])
{
    int min1=INT_MAX;
    int min_index=0;

    for(int v=0;v<n;v++)
    {
        if(visited[v]==false && dist[v]<=min1)
        {
            min1=dist[v];
            min_index=v;
        }
    }
    return min_index;
}

void dijkstra(int a, int b)
{
  int dist[n],i;
  bool visited[n];

  for(i=0;i<n;i++)
  {
      dist[i]=INT_MAX;
      visited[i]=false;
  }
  dist[a]=0;
  int v;

  for(int i=0;i<n-1;i++)
  {
      int u = minDist(dist,visited);

      visited[u]=true;

      for(v=0;v<n;v++)
      {
          if(!visited[v] && arr[u][v] && dist[u]!= INT_MAX && (dist[u]+arr[u][v]<dist[v]))
          {
             dist[v]=dist[u]+arr[u][v];
            // printf("dist[v] - %d\n",dist[v]);
          }

     //   if(v==b)
       //     break;
      }
  }
 // for(i=0;i<n;i++)
  //  printf("dist[v] - %d ",dist[i]);
 // printf("\n");
  if(dist[b]!=INT_MAX)
    printf("%d\n",dist[b]);
  else
    printf("NO\n");
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int e;
        int s,d,w;
        int a,b;
        int i,j,k;
        scanf("%d %d",&n,&e);

        arr.resize(n+1);
        for(i=0;i<n;i++)
        {
            arr[i].resize(n+1);
            arr[i].clear();
        }

        for(i=0;i<e;i++)
        {
            scanf("%d %d %d",&s,&d,&w);
           // printf("Before crash\n");
            arr[s-1][d-1] =  w;
          //  printf("arr[s][d] - %d\n",arr[s][d]);
        }

      /*  for(i=0;i<n;i++)
            for(j=0;j<n;j++)
               printf(" %d ",arr[i][j]);

        printf("\n");
    */
        scanf("%d %d",&a,&b);
        dijkstra(a-1,b-1);
    }
    return 0;
}
#endif
