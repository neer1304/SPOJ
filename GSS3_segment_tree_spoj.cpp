#include<stdio.h>
#include<string.h>

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

void update(int Node, int lo, int hi, int index, int val)
{
    if(lo==hi)
    {
        T[Node].setValue(val);
        return;
    }
    int mid = (lo+hi)/2;
    if(index<=mid)
        update(2*Node,lo,mid,index,val);
    else
        update(2*Node+1,mid+1,hi,index,val);
    T[Node].merge(T[2*Node],T[2*Node+1]);
}

void range_query(node& resultNode,int Node,int i, int j, int L, int R)
{ // Search for Node having interval info [L,R] in [i,j]; (i<=L<R<=j)
    if(i==L && j==R)
    {
        resultNode = T[Node];
        return;
    }
    else
    {
        int m = (i+j)/2;
        if(R<=m)
            range_query(resultNode, 2*Node, i, m, L, R);
        else if(L>m)
            range_query(resultNode, 2*Node+1, m+1, j, L, R);
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
    int x,y,type;

    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&type,&x, &y);

        if(type == 0)
        {
            update(1,0,n-1,--x,y);
        }
        else if(type==1)
        {
            range_query(res, 1, 0, n-1, --x, --y);
            printf("%d\n",res.bestSum);
        }
    }
   return 0;
}
