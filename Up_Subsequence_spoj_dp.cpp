#include <stdio.h>
#include <string.h>

const int MAX = 111;
char str[MAX], word[MAX];
int slen, maxlen, order[MAX], curr[MAX];

void lis()
{
	int rev[MAX], i, j;
	slen = strlen(str);
	rev[slen-1] = 1;
	maxlen = 1;
	for(i=slen-2; i>=0; i--)
    {
		rev[i] = 1;
		for(j=i+1; j<slen; j++)
		{
			if(str[j]>=str[i])
			{
				if(rev[j]+1 > rev[i])
				{
					rev[i] = rev[j] + 1;
				}
			}
		}
	//	printf("%d ",rev[i]);
        if(rev[i] > maxlen)
            maxlen = rev[i];
	}

	order[0] = 1;

	for(i=1; i<slen; i++)
	{
		order[i] = 1;
		for(j=0; j<i; j++)
		{
			if(str[j] <= str[i])
			{
				if(order[j]+1 > order[i])
				{
					order[i] = order[j] + 1;
				}
			}
		}
	}
   // printf("\n");
	for(i=0; i<slen; i++)
    {
      //  printf("%d ",order[i]);
		if(order[i] + rev[i] <= maxlen)
		{
			order[i] = 0;
		}
	}
	/*
	 printf("\n");
	for(i=0;i<slen;i++)
        printf("%d ",order[i]);
    */
}

void print(int n)
{
	int i;
	if(n > maxlen)
    {
		puts(word);
		return;
	}

	for(i=slen-1; i>curr[n-1]; i--)
	{
	//    printf("i-%d n-%d\n",i,n);
		if(order[i]==n)
		{
		//    printf("i1-%d n1-%d\n",i,n);
			if(n>1 && str[i]<word[n-2])
               continue;
			curr[n] = i;
			word[n-1] = str[i];
			print(n+1);
		}
	}
}

int main() {
	int cases;
	scanf("%d", &cases);
	while(cases--)
    {
		scanf("%s", str);
		lis();
		word[maxlen] = 0;
		curr[0] = -1;
		print(1);
	}
	return 0;
}

#if 0
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<stdio.h>
#include<string.h>

using namespace std;
/*u,l,d correspond to the possible directions from which the maximum value of the LCS array came from*/
struct node
{
    int val,u,l,d;
};

int n,maxlen;
set<string> ans;
string s,s1;

//int vis[110][110];
vector<vector<node > > dp;

/*calculates LIS=LCS(s,sort(s))*/
void lis(void)
{
    s1=s;
    sort(s1.begin(),s1.end());
    //cout<<s1<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if (i == 0 || j == 0)
                dp[i][j].val = 0;
            if(s1[i-1]==s[j-1])
            {
                /*if(i==1 and j==2)
                    cout<<"Came wrong way "<<endl;*/
                int x=max(max(dp[i-1][j].val,dp[i][j-1].val),dp[i-1][j-1].val+1);
                dp[i][j].val=x;

                if(dp[i-1][j].val==x)
                {
                    dp[i][j].u=1;
                }

                if(dp[i][j-1].val==x)
                {
                    dp[i][j].l=1;
                }

                if((dp[i-1][j-1].val+1)==x)
                {
                    dp[i][j].d=1;
                }
            }
            else
            {
                int x=max(dp[i-1][j].val,dp[i][j-1].val);
                dp[i][j].val=x;

                if(dp[i-1][j].val==x)
                {
                    dp[i][j].u=1;
                }
                if(dp[i][j-1].val==x)
                {
                    dp[i][j].l=1;
                }
            }
        }
    }
    maxlen=dp[n][n].val;
    //cout<<maxlen<<endl;
}
string st;
int visited[101][101];

void dfs(int x,int y)
{
   // cout<<"In DFS\n"<<endl;
   // visited[x][y] = 1;
   // cout<<"now at "<<x<<"\t"<<y<<endl;
    if(x==0 || y==0)
    {
       // printf("In x=0,y=0");
        if(st.size()==maxlen)
        {
            set<string>::iterator it=ans.begin();
            ans.insert(it,st);
            //cout<<"print at "<<x<<"\t"<<y<<endl;
        }
        return;
    }

    if(dp[x][y].d==1 )
    {
        st=s[y-1]+st;

      //  if(!visited[x-1][y-1])
        {
           // printf("In visited x-1,y-1");
            dfs(x-1,y-1);
        }
        st.erase(st.begin(),st.begin()+1);
    }

    if(dp[x][y].u==1)
    {
      //  if(!visited[x-1][y])
        {
           // printf("In visited x-1,y");
            dfs(x-1,y);
        }
    }

    if(dp[x][y].l==1)
    {
       // if(!visited[x][y-1])
        {
           // printf("In visited x,y-1");
            dfs(x,y-1);
        }
    }
}

void print_lis(void)
{
    for(int i=0;i<=n;i++)
    {
        cout<<endl;
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j].val<<"\t";
        }
    }
    cout<<endl;
}
int main(void)
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        memset(visited,0,sizeof(visited));
        cin>>s;
        n=s.size();
        dp.resize(n+1);

        for(int i=0;i<=n;i++)
        {
            dp[i].resize(n+1);
        }
        lis();
        //print_lis();
        dfs(n,n);
        //sort(ans.begin(),ans.end());
        for(set<string>::iterator it=ans.begin();it!=ans.end();it++)
            cout<<*it<<endl;
    }
    return 0;
}
#endif // 0
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<stack>

using namespace std;

#define MAX 101

char x[101];
int prev[2][MAX];
int n;
void rebuild(int bestEnd[], int mlen[]);

void FindLis()
{
   int lis[2][n], i, j, max1 = 0;
   int k;
   memset(prev,0,sizeof(prev));
   for(i=0;i<2;i++)
      prev[i][0] = -1;
   char sequence[n][n];
   /* Initialize LIS values for all indexes */
   for(j=0;j<2;j++)
   for ( i = 0; i < n; i++ )
      lis[j][i] = 1;

   /* Compute optimized LIS values in bottom up manner */
   for ( i = 1; i < n; i++ )
   {
      for ( j = 0; j < i; j++ )
      {
         if ( x[i] >= x[j] && lis[0][i] < lis[0][j] + 1)
         {
            lis[0][i] = lis[0][j] + 1;
            prev[0][i] = j;
         }
         if ( x[i] >= x[j] && lis[1][i] <= lis[1][j] + 1)
         {
            lis[1][i] = lis[1][j] + 1;
            prev[1][i] = j;
         }
      }
   }

   for(i=0;i<2;i++)
   {
      for(j=0;j<n;j++)
      {
          if(j==n-1)
         printf("lis[i][j]- %d prev[i][j]-%d ",lis[i][j],prev[i][j]);
      }
      printf("\n");
   }
   printf("\n");
   /* Pick maximum of all LIS values */
   /*
   for ( i = 0; i < n; i++ )
   {

      if ( max1 < lis[i] )
      {
         max1 = lis[i];
         bestEnd=i;
      }

   }
*/
int best[n],bestEnd[n];

   memset(best,0,n);
   memset(bestEnd,0,n);
   for(i=0;i<2;i++)
   {
       best[i]=0;
       for(j=0;j<n;j++)
       {
           if(best[i] <lis[i][j])
           {
              best[i] = lis[i][j];
              bestEnd[i] = j;
           }

       }
   }


 //  for(i=0;i<n;i++)
 //   printf("lis[i] - %d ",lis[i]);
  // printf("\n");

#if 0
   j=0;

   for(i=0;i<n;i++)
   {
       if(max1==lis[i])
       {
          best[j] = i;
          j++;
        //  printf("best[j] -%d, i-%d",best[j],i);
       }
   }
   #endif // 0


    rebuild(best,bestEnd);
  //  printf("max1-%d\n",max1);
}

void rebuild(int best[],int bestEnd[])
{
    int b=0;
    int j=0,k=0;
    while(j<2)
    {
       int current = bestEnd[j];
       b=0;
       while(current!=-1)
       {
          b++;
          printf("%c",x[current]);
          current=prev[j][current];
          if(b==best[j])
          {
            b=0;
            printf("\n");
          }

          // rebuild(prev,n,bestEnd,mlen);
       }
      // printf("\n");
       j++;
    }


    #if 0
    std::vector<char> results;
    results.reserve(mlen);

    std::stack<char> stk;

    int current = bestEnd;

    while (current!=-1)
    {
        stk.push(x[current]);
        current = prev[current];
    }

    while (!stk.empty())
    {
       results.push_back(stk.top());
      // results.insert(stk.top());
       stk.pop();
    }
    for(int i=0;i<=mlen-1;i++)
    {
        printf("%c",results[i]);
        /*
        if(i==mlen)
        {
            mlen = mlen+i;
            printf("\n");
        }
        */
    }
 #endif
}

int dp[101][101];

void FindLCS(char x[],char y[])
{
   int i,j;
   int n=strlen(x);

   for (i=0; i<=n; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         dp[i][j] = 0;

       else if (x[i-1] == y[j-1])
         dp[i][j] = dp[i-1][j-1] + 1;

       else
         dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
     }
   }
}


int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s",x);
        n=strlen(x);
        FindLCs(x,std:sort(x));
        memset(x,0,sizeof(x));
    }
return 0;
}
#endif



#if 0
void print_result(int m, int n, int len, int index)
{
    if(len==0)
    {
        for(int i = 0; i < index; i++ )
            cout << path[i];
            cout << endl;
        return;
    }

    for(char c = 'a'; c <= 'z'; c++ )
    {
        int flag = 1;

        for(int i = m; i >= 0 && flag; i-- )
        {
            if(A[i]!=c)
                continue;

            for(int j = n; j >= 0 && flag; j-- )
            {
                if(B[j]!=c)
                continue;

                if(lcs[i][j]==len)
                {
                    path[index]=c;
                    print_result(i-1,j-1,len-1,index+1);
                    flag=0;
                }
            }
        }
    }
}
#endif // 0
