#include<stdio.h>
#include<string.h>

#define MAX 26
char str[MAX];
int  memo[30][250];

int solve(int pos, int prev_sum)
{
    int len = strlen(str);

    if(pos==len)
       return 1;

    int &ret = memo[pos][prev_sum];

    if(ret == -1)
    {
        ret = 0;
        int curr_sum = 0;
        for(int i = pos; i<len; i++)
        {
            curr_sum += str[i] - '0';

            if(curr_sum >= prev_sum)
            {
                ret += solve(i+1, curr_sum);
           //     printf("ret - %d ",ret);
            }

        }
    }
    return ret;
}

int main()
{
    int k=0;
    scanf("%s",str);
    while(strcmp(str,"bye"))
    {
        k++;
        memset(memo,-1,sizeof(memo));
        printf("%d. %d\n",k,solve(0,0));
        scanf("%s",str);
    }
    return 0;
}

