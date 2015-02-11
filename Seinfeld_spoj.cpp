#include<stdio.h>
#include<stack>
#include<string.h>
#include <iostream>
#define MAXLEN 2002


/*
To find the number of mismatched brackets, you're using the stack.
We just need to know the current number of open brackets ( '{' ).
Finally, the answer is the number of closed brackets without a matched open bracket plus the remaining
mismatched open brackets / 2 because we'll change half of them to closed brackets.
*/

using namespace std;

int main()
{
    char str[MAXLEN];
    int res=0;
    int cnt=1,i=0;
    int len;
    scanf("%s",str);
    while(str[0]!= '-')
    {
        std::stack <char> s;
        res=0;
        len=strlen(str);
       for(i=0;i<len;++i)
       {
          if(str[i]=='{')
          {
                s.push(str[i]);
          }
          else
          {
              if(!s.empty())
              {
                  s.pop();
              }
              else
              {
                  res+=1;
                  s.push('{');
              }
          }
       }
       if(!s.empty())
       {
           res+=s.size()/2;
       }
       printf("%d. %d\n",cnt++,res);
       res=0;
       scanf("%s",str);
    }
    return 0;
}
