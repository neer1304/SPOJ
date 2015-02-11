#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct Box
{
    int a[3],h;

    bool operator <(const Box &other) const
    {
        return a[0]<other.a[0];
    }
};

int main()
{
    int n;

    scanf("%d",&n);

    while(n!=0)
    {
        Box box;
        vector<Box> b;

        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&box.a[0],&box.a[1],&box.a[2]);
            sort(box.a,box.a+3);
            b.push_back(box);

            while(next_permutation(box.a,box.a+3))
                b.push_back(box);
        }
        sort(b.begin(),b.end());

        int best = 0;

        for(int i=0;i<b.size();i++)
        {
            b[i].h = b[i].a[2]; //max of 3

            for(int j=0;j<i;j++)
            {
                if(b[j].a[0]<b[i].a[0] && b[j].a[1]<b[i].a[1]) // base is small
                {
                    b[i].h = max(b[i].h, b[i].a[2]+b[j].h);
                }
            }
            best = max(best,b[i].h);
        }
        printf("%d\n",best);
        scanf("%d",&n);
    }
return 0;
}
