#define _CRT_SECURE_NO_WARNINGS
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
//#include <bits/stdc++.h>
using namespace std;

#define M 1010
#define N 1e9
#define Fn "i.txt"
#define mp make_pair
#define si(a) scanf("%d",&a)
#define sc(a) scanf("%c",&a)
#define sst(s) scanf("%s",s)
#define fo(a) freopen(a,"r",stdin)
#define si2(a,b) scanf("%d%d",&a,&b)
#define rep(i,a,b) for(int i=a;i<b;++i)
#define Wh(t) while(t--)
#define rep_(i,a,b) for(int i=a;i>=b;--i)
#define Set(a,b) memset(a,b,sizeof a)
#define si3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define All(s) s.begin(),s.end()
#define Sz(a) a.size()

#define lli long long int
#define llu unsigned long long
#define Mit map<int ,int>::iterator
#define Sit set<int>::iterator
#define Vi vector<int>
#define Si set<int>

typedef pair<int, int> pr;

vector<vector<pr> >list;
int t, n, e, q, a, b;


int dijk(int src, int des)
{
 priority_queue<pr>que;
 que.push(mp(0, src));
 vector<int>cost(n + 5, N);
 int nd, ed, ln;
 cost[src] = 0;
 while (1)
 {
  nd = (que.top()).second;
  ed = -(que.top()).first;
  if (nd == des)return ed;
  que.pop();
  if (cost[nd] < ed)continue;
  ln = list[nd].size();

  rep(i, 0, ln)
  {
   int x = list[nd][i].first;//cost
   int y = list[nd][i].second;//node
   if (ed + x < cost[y])que.push(mp(-(cost[y] = ed + x), y));
  }

 }
}
int main()
{
 //fo(Fn);

 char s1[20], s2[20];
 si(t);
 Wh(t)
 {
  si(n);
  map<string, int>val;
  list = vector<vector<pr> >(n + 5);
  rep(i, 1, n + 1)
  {
   scanf("%s%d", s1, &e);
   val[s1] = i;
   Wh(e)
   {
    si2(a, b);
    list[i].push_back(mp(b, a));
   }
  }
  si(q);
  Wh(q)
  {
   scanf("%s%s", s1, s2);
   printf("%d\n", dijk(val[s1], val[s2]));
  }
 }
 return 0;
}
