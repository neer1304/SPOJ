#include <stdio.h>

struct node
{
    int parent;
    char ch;
};
/* to keep track of visited node */
int flag[20005];
int n;
/* queue for bfs  */
int Q[20005];
/* node for every number */
struct node nodes[20005];

void getNumber(int end)
{
    if(end==-1) return;
    getNumber(nodes[end].parent);
    putchar(nodes[end].ch);
}

int main()
{
    int t, i, l;
    //qh - refer to current node
    //qt - total nodes
    int qh, qt, first, second, curr;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        if(n==1)
        {
            puts("1");
        }
        else
        {
            for(i=0; i<n; i++)
               flag[i] = 0;

            qh = qt = 0;

            Q[qt++] = 1;

            flag[1] = 1;

            nodes[1].parent = -1;
            nodes[1].ch = '1';

            while(1)
            {
              //  printf("qh - %d and qt - %d\n",qh,qt);
                curr = Q[qh++];
                /* generate number by adding 0 and 1*/
                first = (curr * (10 % n)) %  n;
                second = (first+1) % n;

              //  printf("first - %d and second - %d\n",first,second);

                if(!flag[first])
                {
                    nodes[first].parent = curr;
                    nodes[first].ch = '0';
                    if(!first)
                        break;
                    flag[first] = 1;
                    Q[qt++] = first;
                }

                if(!flag[second])
                {
                    nodes[second].parent = curr;
                    nodes[second].ch = '1';
                    if(!second)
                        break;
                    flag[second] = 1;
                    Q[qt++] = second;
                }
            }
       // for(int j=0;j<30;j++)
       //     printf(" %d ",Q[j]);
            getNumber(0);
        }
        putchar('\n');
    }
    return 0;
}

/*
1
17
qh - 0 and qt - 1
first - 10 and second - 11
qh - 1 and qt - 3
first - 15 and second - 16
qh - 2 and qt - 5
first - 8 and second - 9
qh - 3 and qt - 7
first - 14 and second - 15
qh - 4 and qt - 8
first - 7 and second - 8
qh - 5 and qt - 9
first - 12 and second - 13
qh - 6 and qt - 11
first - 5 and second - 6
qh - 7 and qt - 13
first - 4 and second - 5
qh - 8 and qt - 14
first - 2 and second - 3
qh - 9 and qt - 16
first - 1 and second - 2
qh - 10 and qt - 16
first - 11 and second - 12
qh - 11 and qt - 16
first - 16 and second - 0
11101

*/



# if 0
#include<stdio.h>
#include<queue>
#include<string.h>
#include<stdlib.h>

using namespace std;

bool visited[20002];

typedef struct bnode
{
    char data[1002];
    int mod;
}bnode;

std::queue<bnode> q;

int bfs(int n)
{
    bnode temp,left,right;
    int pos=0;

    memset(temp.data,0,1002);
    memset(left.data,0,1002);
    memset(right.data,0,1002);

    temp.data[pos++] = '1';
    temp.mod = 1%n;
    q.push(temp);

    while(!q.empty())
    {
        temp = q.front();
       // printf("temp.data is %s\n",temp.data);
       // printf("q.front().data is %s\n",q.front().data);
       // strcpy(temp.data,q.front().data);
        q.pop();

        if(temp.mod==0)
        {
            printf("%s\n",temp.data);
            return 0;
        }
        else
        {
            left.mod = (10*temp.mod+0)%n;
            if(!visited[left.mod])
            {
                visited[left.mod] = 1;
//                left.data = "";
                strcpy(left.data,temp.data);
              //  printf("length of temp.data is %d\n",strlen(temp.data));
                left.data[strlen(temp.data)] = '0';
              //  printf("in loop left.data is %s\n",left.data);
               // printf("length of left.data is %d\n",strlen(left.data));
                q.push(left);
            }

            right.mod = (10*temp.mod+1)%n;
            if(!visited[right.mod])
            {
                 visited[right.mod] = 1;
  //             right.data = "";
                 strcpy(right.data,temp.data);
                 right.data[strlen(temp.data)] = '1';
                 q.push(right);
            }

        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        long long num;
        scanf("%lld",&num);

        memset(visited,0,20002);
       // for(int i=0;i<20002;i++)
       //     visited[i] = 0;
        bfs(num);
    }
    return 0;
}

#endif
