#include<stdio.h>
#include<string.h>

/*
 there is always a solution which contain some consecutive elements
if we get the mod of c for each element on the array, either you will find mod zero
( so here is the solution from the start to this element) or one of the mods at least will appear
more than one time "pigeonhole principle" so between these any two appearances of this mod is the
solution :)

*/

int main()
{
    int c,n,i,j,s;
    int visited[100000];
    int arr[100000];

    scanf("%d %d",&c,&n);

    while(c!=0 && n!=0)
    {
       s=0;
       memset(visited,-1,sizeof(visited));
       visited[0]=0;

       for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

       for(i=0;i<n;i++)
       {
         s = (s+arr[i])%c;
         if(visited[s]==-1)
            visited[s]=i+1;
         else
         {
             for(j=visited[s]+1;j<=i+1;j++)
                printf("%d ",j);
                printf("\n");
             break;
         }
       }
       scanf("%d %d",&c,&n);
    }
    return 0;
}
