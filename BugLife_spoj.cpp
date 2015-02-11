#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>

#define nb 21000

using namespace std;
/* store the assigned color/M-F(in this case) to node */
int colorArr[21000];
/* store graph in adjacency list */
vector<int> graph[21000];

bool DFS(int src)
{
    bool res = true;
   //printf("Entering DFS() loop\n");
    for(int i=0;i<graph[src].size();i++)
    {
        /* get the adjacent vertices */
        int v = graph[src][i];

        //printf("v is %d and src is %d\n",v,src);
        /* if two vertices has same color not bi-partite */
        if(colorArr[v]==colorArr[src])
            return false;

       // printf("colorArr is %d\n",colorArr[v]);
       /* if not assigned color assign second color  */
        if(colorArr[v]==-1)
        {
            colorArr[v] = 1-colorArr[src];
            /* call DFS recursively on the adjacent vertices */
            res=res and DFS(v);
        }
    }
    return res;
}

int main()
{
    int t;
    int c=0;
    scanf("%d",&t);

    while(t--)
    {
        c++;
        int nbg;
        int ni,j;
        int i;
        int flag = 1;
        bool res = true;
        scanf("%d %d",&nbg,&ni);

      //  int graph[nb][nb];
        int a,b;

        for(i=0;i<nb;i++)
        {
            graph[i].clear();
            colorArr[i]=-1;
        }

        for(j=0;j<ni;j++)
        {
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

         for(i=0;i<nb;i++)
         {
             if(colorArr[i]==-1)
             {
                 colorArr[i] = 1;
                 res=res and DFS(i);
             }
             else
             {
                 continue;
             }
         }

         if(res)
         {
             printf("Scenario #%d:\n",c);
             printf("No suspicious bugs found!\n");
         }
         else
         {
             printf("Scenario #%d:\n",c);
             printf("Suspicious bugs found!\n");
         }
    }
    return 0;
}

