#include<stdio.h>
#include<string.h>
/* http://tiny-code.blogspot.in/2013/07/spoj-1043can-you-answer-these-queries-i.html */
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}

const int MAX = 1 << 16;
int arr[MAX];
struct node
{
    int Sum,bestLeftSum,bestRightSum,bestSum;

    node merge(node& l, node& r)
    {
        Sum = l.Sum + r.Sum;
        bestLeftSum = max2( l.Sum + r.bestLeftSum , l.bestLeftSum );
        bestRightSum = max2( r.Sum + l.bestRightSum , r.bestRightSum );
        bestSum = max2( max2( l.bestSum , r.bestSum) , l.bestRightSum + r.bestLeftSum );
    }

    node setValue(int val)
    {
        Sum = bestLeftSum = bestRightSum = bestSum = val;
    }
};

node T[MAX << 1];

void init(int Node, int i, int j)
{
    if(i==j)
    { // Initialize Leaf Nodes
        T[Node].setValue(arr[i]);
        return;
    }
    else
    { // Summerize Descendant Nodes Nodes
        int m = (i+j)/2;
        init(2*Node, i, m);
        init(2*Node+1, m+1, j);
        T[Node].merge(T[2*Node],T[2*Node+1]);
    }
}

/*
int query(int arr[],int x, int y)
{
  int i,j;
  int bestLeftSum,bestRightSum,bestSum,sum,resultSum;

  if(x<=y)
  {
    bestLeftSum = arr[x];
    bestRightSum = arr[y];
    sum = bestLeftSum + bestRightSum;
    bestSum = max3(bestLeftSum,bestRightSum,sum);

    if(y-x+1 == 1)
       return bestLeftSum;
    else if(y-x+1 == 2)
       return bestSum;
    else
       //return(max3(query(arr,x+1,y),query(arr,x,y-1),(query(arr,x+1,y)+query(arr,x,y-1))));
       resultSum = max3 (max3(bestLeftSum,bestRightSum,sum),query(arr,x+1,y-1),bestSum);

  }
  else
    return 0;
}
*/

void range_query(node& resultNode,int Node,int i, int j, int L, int R)
{
    // Search for Node having interval info [L,R] in [i,j]; (i<=L<R<=j)

    if(i==L && j==R)
    {
        resultNode = T[Node];
        return;
    }
    else
    {
        int m = (i+j)/2;

        if(R<=m)
            range_query(resultNode, 2*Node,  i, m, L, R);  //in first half
        else if(L>m)
            range_query(resultNode, 2*Node+1, m+1, j, L, R); // in second half
        else
        {
            node left, right;
            range_query(left, 2*Node,  i, m, L, m);
            range_query(right, 2*Node+1, m+1, j, m+1, R);
            resultNode.merge(left,right);
        }
    }
}


int main()
{
    int n,i;
    node res;
    scanf("%d",&n);
    memset(arr,0,n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    init(1, 0, n-1);
    int m;

    scanf("%d",&m);
    int x,y;

    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x, &y);

        range_query(res, 1, 0, n-1, --x, --y);

        printf("%d\n",res.bestSum);
    }
   return 0;
}
