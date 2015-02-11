#include <cstdio>
#include <queue>
#include <vector>

const int INF = 0x3f3f3f3f;

using namespace std;
int mini( int a, int b ) { return( a > b ? b : a ); }

bool from[ 10002 ], to[ 10002 ];

struct edge
{
    int v;
    int w;
};

bool operator <( edge a, edge b )
{
    return a.w > b.w;
}

int readint() {
    int n = 0;
    char c = getchar();
    while ( !( '0' <= c && c <= '9' ) ) {
        c = getchar();
    }
    while ( '0' <= c && c <= '9' ) {
        n = n * 10 + c - '0';
        c = getchar();
    }
    return n;
}

void dijkstra( vector< edge > graph[], int* dist, int S )
{
    dist[ S ] =0;
    priority_queue< edge > q;
    q.push( ( edge ) { S, 0 } );
    while ( !q.empty() )
    {
        edge p = q.top();
        q.pop();

        for ( int i = 0; i < graph[ p.v ].size(); ++i )
        {
            edge k = graph[ p.v ][ i ];
            if ( dist[ p.v ] + k.w < dist[ k.v ] )
            {
                dist[ k.v ] = dist[ p.v ] + k.w;
                q.push( k );
            }
        }
    }
}

int main()
{
    int t, S, T, k, n, m, i, u, v, w;


    scanf("%d",&t);
    while ( t-- )
    {
     //   scanf("%d %d %d %d %d",&n,&m,&k,&S,&T);
        n = readint();
        m = readint();
        k = readint();
        S = readint();
        T = readint();
        vector< edge > fo[ n+1 ], ba[ n+1 ];
        int fodist[ n+1 ], badist[ n+1 ];
        for ( i = 0; i <= n; ++i )
        {
            fodist[ i ] = badist[ i ] = INF;
			fo[ i ].clear();
			ba[ i ].clear();
        }
        for ( i = 0; i < m; ++i )
        {
           // scanf("%d %d %d",&u,&v,&w);
            u = readint();
            v = readint();
            w = readint();
            fo[ u ].push_back( ( edge ) { v, w } );
            ba[ v ].push_back( ( edge ) { u, w } );
        }
        dijkstra( fo, fodist, S );

        for(i=0;i<n;i++)
            printf(" %d ", fodist[i]);
        printf("\n");

        dijkstra( ba, badist, T );

        for(i=0;i<n;i++)
            printf(" %d ", badist[i]);
         printf("\n");

        int ans = mini( fodist[ T ], badist[ S ] );

        while ( k )
        {
          // scanf("%d %d %d",&u,&v,&w);
           u = readint();
            v = readint();
            w = readint();
            ans = mini( ans, mini( fodist[ v ] + w + badist[ u ], badist[ v ] + w + fodist[ u ] ) );
            --k;
        }

        if ( ans == INF )
        {
            printf( "-1\n" );
        }
        else
        {
            printf( "%d\n", ans );
        }
    }
    return 0;
}
