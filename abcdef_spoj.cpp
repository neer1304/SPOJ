#include<stdio.h>
#include<algorithm>
#include<set>
#include<vector>

/*http://profutonium.blogspot.in/2009/12/spoj-problem-code-abcdef.html */

using namespace std;

int main()
{
    int n;
    int i,j,k;
    int cnt =0;
    vector<int> v1;
    vector<int> v2;

    scanf("%d",&n);
    int arr[n];

    for(i=0;i<n;i++)
       scanf("%d",&arr[i]);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                v1.push_back((arr[i]*arr[j])+arr[k]);
            }
        }
    }



    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(arr[k]==0) continue;
                v2.push_back((arr[i]+arr[j])*arr[k]);
            }
        }
    }
    std::sort(v2.begin(),v2.end());
    std::sort(v1.begin(),v1.end());

    int lo,hi;
    for(i=0;i<v1.size();i++)
    {
    /*
       if(binary_search(v2.begin(),v2.end(),v1[i]));
       cnt++;
      */
      // count the duplicate values too
       lo=lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
        hi=upper_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
        cnt+=(hi-lo);
    }
    printf("%d\n",cnt);

return 0;
}
