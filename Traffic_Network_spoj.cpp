#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

typedef pair< int, int > pii;

typedef vector< vector < pii > > vvpi;


int n;

vector<int> dijkstra(vector< vector< pii > >G, int start, int target)
{
    int u, v, i, c, w;
    vector < int >  d(n+1, INF);
    priority_queue< pii, vector< pii >, greater< pii > > Q;
    // 0 -weight start - node
    Q.push(pii(start, 0));
    d[start] = 0;

    while(!Q.empty())
    {
       // printf("In while loop\n");
        u = Q.top().first; // node
        c = Q.top().second; // node cost so far
        Q.pop(); // remove the top item.

        if(d[u] < c) continue;
        if(u==target)
            return d;
        for(i = 0; i < G[u].size(); i++)
        {
            v = G[u][i].first; // node
            w = G[u][i].second; // edge weight

            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push(pii(v, d[v]));
            }
        }
    }
    return d;
}

int main()
{
  int ds;
  scanf("%d",&ds);

  while(ds--)
  {
      int i,j;

      int m,k,s,t;
      scanf("%d %d %d %d %d",&n,&m,&k,&s,&t);
       vector< int > fd(n+1,0),rd(n+1,0);

     //  vector < pii > G[n+1];
      // vector < pii >  temp[n+1];

      vector < vector < pii > > G(n+1) , temp(n+1);


       for(i=0;i<n;i++)
       {
          G[i].clear();
          temp[i].clear();
          fd[i] = INF;
          rd[i] = INF;
       }

      int di,ci,li;

      for(i=0;i<m;i++)
      {
          scanf("%d %d %d",&di,&ci,&li);
          G[di].push_back(pii(ci, li));
          temp[ci].push_back(pii(di, li));
      }

      int uj,vj,qj;

      fd = dijkstra(G,s,t);

     // for(i=1;i<=n;i++)
     //   printf(" %d ",fd[i]);


      int u;
      int w;

      rd = dijkstra(temp,t,s);
     // printf("\n");

     // for(i=1;i<=n;i++)
     //   printf(" %d ",rd[i]);

      int ans=INF;
      int min_t;

  /*    for(i=1;i<=n;i++)
      {
       //   printf("fd[i] - %d, rd[i] - %d \n",fd[i],rd[i]);
           min_t = fd[i]+rd[i];
           ans = min(ans,min_t);
      }
      */
      ans = min(fd[t],rd[s]);

     // ans = min(fd[t],rd[s]);
    //  printf("ans-%d\n",ans);
     /*
      int min_loc,min_s=min1;

        for(i=0;i<k;i++)
        {
          scanf("%d %d %d",&uj,&vj,&qj);

           G[uj].push_back(pii(vj,qj));
           G[vj].push_back(pii(uj,qj));

           min_loc = dijkstra(n,s,t);

           G[uj].pop_back();
           G[vj].pop_back();

            if(min_s>min_loc)
                min_s=min_loc;
        //    printf("dis[i] is %d\n",dis[i]);
        }
       */
        for(i=0;i<k;i++)
        {
          scanf("%d %d %d",&uj,&vj,&qj);
          ans = min(ans,min((fd[uj]+qj+rd[vj]),(fd[vj]+qj+rd[uj])));
      //    printf("ans-%d\n",ans);
        }
          if(ans!=INF)
            printf("%d\n",ans);
          else
            printf("-1\n");
  }
return 0;
}
