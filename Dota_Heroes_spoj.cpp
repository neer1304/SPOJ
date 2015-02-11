#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{

    int t,i;
    int n,m,d,flg=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d",&n,&m,&d);
        int hlt[n];

        for(i=0;i<n;i++)
            scanf("%d",&hlt[i]);

        std::sort(hlt,hlt+n);
        reverse(hlt,hlt+n);
        int j=0;
        for(i=0;i<m;i++)
        {
            if(hlt[j]-d>0 )
            {
                hlt[j] -= d;
            }
            else if(j!=n)
            {
                j=j+1;
                while(hlt[j]-d<=0 && j<n)
                {
                    j++;
                    if(j==n)
                    {
                        flg=1;
                        break;
                    }
                }
                hlt[j] -=d;
            }
            else
            {
                flg=1;
                break;
            }
        }
        if(flg)
            printf("NO\n");
        else
            printf("YES\n");
            flg=0;
    }
    return 0;
}
