
#if 0
#include<stdio.h>


class Node
{
public:
    int lCount,rCount;
    Node *lChild,*rChild;
    Node()
    {
        lCount=rCount=0;
        lChild=rChild=NULL;
    }
};

void addBit(Node *root,int n)
{
    for(int i=20;i>=0;i--)
    {
        int x= (n>>i) & 1;

        if(x)
        {
            root->rCount++;
            if(root->rChild == NULL)
                root->rChild = new Node();
            root = root->rChild;
        }
        else
        {
            root->lCount++;
            if(root->lChild == NULL)
                root->lChild = new Node();
            root = root->lChild;
        }
    }
}

int query(Node *root,int n,int k)
{
    if(root == NULL)
        return 0;
    int res = 0;
    for(int i=20;i>=0;i--)
    {
        bool ch1=(k>>i) & 1;
        bool ch2=(n>>i) & 1;
        if(ch1)
        {
            if(ch2)
            {
                res+=root->rCount;
                if(root->lChild == NULL)
                    return res;
                root = root->lChild;
            }

            else
            {
                res+=root->lCount;
                if(root->rChild == NULL)
                    return res;
                root = root->rChild;
            }
        }
        else
        {
            if(ch2)
            {
                if(root->rChild == NULL)
                    return res;
                root= root->rChild;
            }
            else
            {
                if(root->lChild == NULL)
                    return res;
                root= root->lChild;
            }
        }
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int temp,temp1,temp2=0;
        Node *root = new Node();
        addBit(root,0);
        long long total =0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            temp1= temp2^temp;
            total+=(long long)query(root,temp1,k);
            addBit(root , temp1);
            temp2 = temp1;
        }
        printf("%lld\n",total);
    }
    return 0;
}
#endif

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

class Trie
{
public:
    int lvalue,rvalue;
    Trie *left,*right;
    Trie()
    {
        lvalue=rvalue=0;
        left=right=NULL;
    }
};

void insert_trie(Trie *root,int n)
{
    printf("insert_trie n is %d\n",n);
    for(int i=20;i>=0;i--)
    {
        int x= (n>>i) & 1;
       // printf("x is %d\n",x);
        if(x)
        {
            root->rvalue++;
            if(root->right == NULL)
                root->right = new Trie();
            root = root->right;
        }
        else
        {
            root->lvalue++;
            if(root->left == NULL)
                root->left = new Trie();
            root = root->left;
        }
    }
}


int query(Trie *root, int q, int k)
{
    printf("query() :: q and k are %d and %d\n",q,k);
    int cnt=0,i;
    for(i=20;i>=0;i--)  // max k = 10^6 num of binary digit = log2(10^6) = 19.93
    {
        bool n1 = (k>>i)&1;
        bool n2 = (q>>i)&1;

        if(n1)
        {
            if(n2)
            {
                printf("n1 n2 - %d %d\n",n1,n2);
                cnt += root->rvalue;
                printf("cnt is %d\n",cnt);
                if(root->left==NULL)
                    return cnt;
                root=root->left;
            }
            else
            {
                printf("n1 n2 - %d %d\n",n1,n2);
                cnt+=root->lvalue;
                printf("cnt is %d\n",cnt);
                if(root->right==NULL)
                    return cnt;
                root=root->right;
            }
        }
        else
        {
            if(n2)
            {
                printf("n1 n2 - %d %d\n",n1,n2);
                if(root->right==NULL)
                    return cnt;
                root=root->right;
            }
            else
            {
                printf("n1 n2 - %d %d\n",n1,n2);
                if(root->left==NULL)
                    return cnt;
                root=root->left;
            }
        }
    }
return cnt;
}

int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
       int n,k;
       int i,p,q=0;
       long long ans=0;
       scanf("%d %d",&n,&k);
       //int arr[n];
       int arr_val;
       Trie *root = new Trie();
       insert_trie(root,0);
        ans=0;
        p=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&arr_val);
            q = p^arr_val;
            ans += (long long)query(root,q,k);
            insert_trie(root,q);
            p=q;
        }
        printf("%lld\n",ans);
        }
    return 0;
}

