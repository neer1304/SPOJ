#include<stdio.h>
#include<set>

using namespace std;

int main()
{
  int n,m,i,fid,j,ffid;
  scanf("%d",&n);
  set<int> s;

  for(i=0;i<n;i++)
  {
      scanf("%d",&fid);
      s.insert(fid);
      scanf("%d",&m);
      for(j=0;j<m;j++)
      {
          scanf("%d",&ffid);
          s.insert(ffid);
      }
  }
  printf("%d\n",s.size()-n);
  return 0;
}
