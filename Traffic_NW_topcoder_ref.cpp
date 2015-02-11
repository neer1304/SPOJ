#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

#define s(n)                                    scanf("%d",&n)
#define sl(n)                                   scanf("%lld",&n)
#define sf(n)                                   scanf("%lf",&n)
#define ss(n)                                   scanf("%s",n)
#define INF                                     0x3f3f3f3f
#define LINF                                    (long long)1e18
#define EPS                                             1e-9
#define maX(a,b)                                ((a)>(b)?(a):(b))
#define miN(a,b)                                ((a)<(b)?(a):(b))
#define abS(x)                                  ((x)<0?-(x):(x))
#define FOR(i,a,b)                              for(int i=a;i<b;i++)
#define REP(i,n)                                FOR(i,0,n)
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp                                              make_pair
#define FF                                              first
#define SS                                              second
#define tri(a,b,c)                              mp(a,mp(b,c))
#define XX                                              first
#define YY                                              second.first
#define ZZ                                              second.second
#define pb                                              push_back
#define fill(a,v)                               memset(a,v,sizeof a)
#define all(x)                                  x.begin(),x.end()
#define SZ(v)                                   ((int)(v.size()))
#define DREP(a)                                 sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)                  (lower_bound(all(arr),ind)-arr.begin())
#define debug(args...)                  {dbg,args; cerr<<endl;}
#define dline                                   cerr<<endl

#define VVII vector< vector < pair<int,int> > >
#define VVI vector< vector < int > >
#define VII vector < pair<int,int> >
#define MSI map< string , int >
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ii pair< int, int >


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


/*Main code begins now */
int n;
VVII vvi,tempVec;
// VVI dis;
vector < int > dijkstra(int source, int dest)
{
        int v, v2, w, k, i, d, cost;
        vector < int >  D(n+1, INF);
        priority_queue < ii , vector<ii>, greater<ii> > Q;
        D[source]=0;
        ii tmp, next, kp;
        Q.push(ii(0,source));
        while(!Q.empty())
        {
                tmp=Q.top();
                Q.pop();
                v=tmp.second;
              //  if(v==dest)
              //  break;
                d=tmp.first;
                if(d<=D[v]){
                        for(i=0; i<vvi[v].size(); i++){
                                next=vvi[v][i];
                                v2=next.first;
                                cost=next.second;
                                if(cost+D[v]<D[v2])
                                {
                                        D[v2]=cost+D[v];
                                        Q.push(ii(D[v2],v2));
                                }
                        }
                }
        }
     //   dis.push_back(D);
        return D;
}
void solve()
{
        vvi.clear();
        int u,v,w,m,k,s,t,ans=INF,temp;
        vector< int > d(10010,0),rd(10010,0);
      //  s(n);s(m);s(k);s(s);s(t);
        n = readint();
        m = readint();
        k = readint();
        s = readint();
        t = readint();
        int i;
        FOR(i,0,n)
        {
                VII vi;
                pair<int,int> tmp;
                vvi.push_back(vi);
        }
        FOR(i,0,m)
        {
               // s(u);s(v);s(w);
               u = readint();
               v = readint();
               w = readint();
                vvi[u-1].push_back(ii(v-1,w));
        }
        d=dijkstra(s-1,t-1);

     //   for(i=0;i<n;i++)
     //       cout<< d[i];

        FOR(i,0,n)
        {
                VII vi;
                pair<int,int> tmp;
                tempVec.push_back(vi);
        }
      /* change the direction to calculate distance in reverse direction */
        FOR(i,0,n)
        {
                FOR(j,0,vvi[i].size())
                {
                        u=vvi[i][j].first;
                        w=vvi[i][j].second;
                        tempVec[u].push_back(ii(i,w));
                }
        }
        vvi.clear();
        vvi=tempVec;

        rd=dijkstra(t-1,s-1);
      //  cout<<endl;
      //  for(i=0;i<n;i++)
      //      cout<< rd[i];

        FOR(i,0,n)
        {
                temp=d[i]+rd[i];
                cout<<temp<<endl;
                ans=min(ans,temp);
        }

        //ans = min(d[t],rd[s]);
        FOR(i,0,k)
        {
               // s(u);s(v);s(w);
               u = readint();
               v = readint();
               w = readint();
                u--;v--;
                temp=min(d[u]+rd[v]+w,d[v]+rd[u]+w);
               // cout<<temp<<endl;
                ans=min(ans,temp);
                //cout<<temp<<" "<<ans<<endl;
        }
        if(ans==INF)
                ans=-1;
        printf("%d\n",ans);
}
int main()
{
        int T; s(T);
        for(int testnum=1;testnum<=T;testnum++)
        {
                solve();
        }
}
