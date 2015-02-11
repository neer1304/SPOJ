#include<stdio.h>
#include<string.h>

inline int min2(int a, int b) {return ((a > b)? b : a);}

const int MAX = 1 << 16;
char arr[MAX];
struct node
{
    int unmatchedOpenParens,unmatchedClosedParens;

    node merge(node& left, node& right)
    {
        int matches = min2(left.unmatchedOpenParens,right.unmatchedClosedParens);
        unmatchedOpenParens = right.unmatchedOpenParens+left.unmatchedOpenParens - matches;
        unmatchedClosedParens = right.unmatchedClosedParens+left.unmatchedClosedParens - matches;
    }

    node setValue(char paren)
    {
        if(paren == '(')
        {
            unmatchedOpenParens=1;
            unmatchedClosedParens=0;
        }
        else
        {
            unmatchedOpenParens=0;
            unmatchedClosedParens=1;
        }
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

void update(int Node, int lo, int hi, int index, char val)
{
    if(lo==hi)
    {
        if(val== '(')
            T[Node].setValue(')');
        else
            T[Node].setValue('(');

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
    int t=10;
    while(t--)
    {
        scanf("%d",&n);
        memset(arr,0,n);
      //  for(i=0;i<n;i++)
            scanf("%s",arr);

        init(1, 0, n-1);
        int m;

        scanf("%d",&m);
        int type;

        for(i=0;i<m;i++)
        {
            scanf("%d",&type);

            if(type == 0)
            {
              //  range_query(res, 1, 0, n-1);
                if(T[1].unmatchedOpenParens==0 && T[1].unmatchedClosedParens==0)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else
            {
                update(1,0,n-1,--type,arr[--type]);
            }
        }
    }
   return 0;
}
