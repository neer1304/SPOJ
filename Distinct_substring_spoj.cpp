/*
http://programmerheaven9.blogspot.in/2011/10/spoj-disubstr_28.html
http://greasepalm.wordpress.com/2012/07/01/suffix-arrays-a-simple-tutorial/
http://discuss.codechef.com/questions/21385/a-tutorial-on-suffix-arrays
http://stackoverflow.com/questions/17761704/suffix-array-algorithm
http://www.quora.com/Programming-Interviews/Given-a-string-how-do-I-find-the-number-of-distinct-substrings-of-the-string
http://www.geeksforgeeks.org/suffix-array-set-2-a-nlognlogn-algorithm/
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#define LL long long
using namespace std;

string s;

int P[16][50001];

struct entry
{
 int i,nr[2];
}L[50001];

bool cmp(entry a,entry b)
{
 if(a.nr[0]==b.nr[0])
   return a.nr[1] < b.nr[1];
 else
   return a.nr[0] < b.nr[0];
}

int stp = 1;

void compute_suffix_array()
{
 int i,len;
 len = s.length();

 for(i=0;i<len;i++)
  P[0][i] = s[i];

 int cnt = 1;

   while(cnt < len)
   {
   // Store suffixes and their indexes in an array of structures.
    // The structure is needed to sort the suffixes alphabatically
    // and maintain their old indexes while sorting
     for(i=0;i<len;i++)
     {
        L[i].i = i;
        L[i].nr[0] = P[stp-1][i];
        L[i].nr[1] = i + cnt < len ? P[stp - 1][i + cnt] : -1;
     }
      // Sort the suffixes using the comparison function
     sort(L,L+len,cmp);

     int rank = 0;

     for(i = 0;i < len;i++)
     {
        if(i-1>=0)
        {
            // If first rank and next ranks are same as that of previous
            // suffix in array, assign the same new rank to this suffix
             // Otherwise increment rank and assign
            if(L[i].nr[0] != L[i-1].nr[0] || L[i].nr[1] != L[i-1].nr[1])
            rank++;
        }

        P[stp][L[i].i] = rank;
     }

     cnt = cnt<<1;
     stp++;
    }

}

int lcp(int x, int y)
{
 if(x == y)
  return s.length() - x;

 int ans  = 0;
 int i;

 for(i = stp - 1; i>=0 && x < s.length() && y < s.length();i--)
 {
    if(P[i][x] == P[i][y])
    {
      ans += 1<<i;
      x += 1<<i;
      y += 1<<i;
    }
 }
 return ans;
}

int main()
{
 int t,l,i,j;
 LL temp;
    cin>>t;

  while(t > 0)
  {
    cin>>s;
    stp = 1;
    compute_suffix_array();
    l = s.length();
    temp = 0;

    for(i=0;i<l-1;i++)
    {
       temp = temp + lcp(L[i].i,L[i+1].i);
    }

    LL l1 = s.length();

    LL ans = (l1 * (l1 + 1)) / 2 - temp;
  cout<<ans<<endl;
  t--;
 }
}
