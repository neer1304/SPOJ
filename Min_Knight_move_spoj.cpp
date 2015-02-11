#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

int board[8][8];

typedef struct Point
{
    struct Point *parent;
    int x;
    int y;
}Point;

struct Point chess[200];

bool isValidState(Point p)
{
    if((p.x>=1) && (p.x<=8) && (p.y>=1) && (p.y<=8))
        return true;
    else
        return false;
}

void getCount(Point p1,Point *temp)
{
   // printf("In getCount()\n");
        int cnt=0;

  while(temp->x!=-1 && temp->y!=-1)
  {
      temp=temp->parent;
      cnt++;
  }
  printf("%d\n",cnt);
}


void bfs(Point p1, Point p2)
{
  //  printf("In bfs()\n");
    std::queue<Point> q;
    Point *temp;
    int cnt=0;
    q.push(p1);
    int pos=2;
    chess[1] = p1;

    while(!q.empty())
    {
     //   printf("In while loop\n");
        temp = &(q.front());
        q.pop();
       // printf("temp->x - %d and temp->y - %d\n",temp->x,temp->y);
        if(temp->x==p2.x && temp->y==p2.y)
        {
            //printf("%d\n",cnt);
            break;
        }
        else
        {
         //   printf("In else\n");
            Point s1,s2,s3,s4,s5,s6,s7,s8;

            s1.parent= temp;
            s1.x = temp->x-2;
            s1.y = temp->y-1;

            s2.parent= temp;
            s2.x = temp->x-1;
            s2.y = temp->y-2;

            s3.parent=temp;
            s3.x = temp->x+1;
            s3.y = temp->y-2;

            s4.parent= temp;
            s4.x = temp->x-2;
            s4.y = temp->y+1;

            s5.parent= temp;
            s5.x = temp->x-1;
            s5.y = temp->y+2;

            s6.parent= temp;
            s6.x = temp->x+2;
            s6.y = temp->y-1;

            s7.parent= temp;
            s7.x = temp->x+1;
            s7.y = temp->y+2;

            s8.parent= temp;
            s8.x = temp->x+2;
            s8.y = temp->y+1;

            if(isValidState(s1) && !board[s1.x][s1.y])
            {
           //     printf("In valid state\n");
                q.push(s1);
                chess[pos++].parent= temp;
                chess[pos++].x = s1.x;
                chess[pos++].y = s1.y;
                board[s1.x][s1.y]=1;
            }

            if(isValidState(s2) && !board[s2.x][s2.y])
            {
                q.push(s2);
                chess[pos++].parent= temp;
                chess[pos++].x = s2.x;
                chess[pos++].y = s2.y;
                board[s2.x][s2.y]=1;

            }

            if(isValidState(s3) && !board[s3.x][s3.y])
            {
                q.push(s3);
                chess[pos++].parent= temp;
                chess[pos++].x = s3.x;
                chess[pos++].y = s3.y;
                board[s3.x][s3.y]=1;
            }

            if(isValidState(s4) && !board[s4.x][s4.y])
            {
                q.push(s4);
                chess[pos++].parent= temp;
                chess[pos++].x = s4.x;
                chess[pos++].y = s4.y;
                board[s4.x][s4.y]=1;
            }

           if(isValidState(s5) && !board[s5.x][s5.y])
            {
                q.push(s5);
                chess[pos++].parent= temp;
                chess[pos++].x = s5.x;
                chess[pos++].y = s5.y;
                board[s5.x][s5.y]=1;
            }

            if(isValidState(s6) && !board[s6.x][s6.y])
            {
                q.push(s6);
                chess[pos++].parent= temp;
                chess[pos++].x = s6.x;
                chess[pos++].y = s6.y;
                board[s6.x][s6.y]=1;
            }

            if(isValidState(s7) && !board[s7.x][s7.y])
            {
                q.push(s7);
                chess[pos++].parent= temp;
                chess[pos++].x = s7.x;
                chess[pos++].y = s7.y;
                board[s7.x][s7.y]=1;
            }

            if(isValidState(s8) && !board[s8.x][s8.y])
            {
                q.push(s8);
                chess[pos++].parent= temp;
                chess[pos++].x = s8.x;
                chess[pos++].y = s8.y;
                board[s8.x][s8.y]=1;
            }
        }
    }
    getCount(p1,temp);
}

int main()
{
    int t;

    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            board[i][j] = 0;
        }
    }

    scanf("%d",&t);

    while(t--)
    {
        Point p1,p2;

        p1.parent->x=-1;
        p1.parent->y=-1;

        //p2.parent->x=-1;
       // p2.parent->y=-1;

        char startp[2];
        char  endp[2];

        memset(startp,0,2);
        memset(endp,0,2);

        scanf("%s %s",startp,endp);

        p1.x = startp[0]+1;
        p1.y = startp[1]-48;

        p2.x = endp[0]-96;
        p2.y = endp[1]-48;

        //p1.x=p1.x-96;
       // p2.x=p2.x-96;

        printf("p1.x - %d, p1.y - %d, p2.x - %d, p2.y -%d\n",p1.x,p1.y,p2.x,p2.y);

        bfs(p1,p2);
    }
return 0;
}
