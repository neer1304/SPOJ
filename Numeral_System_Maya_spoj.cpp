#include<stdio.h>
#include<string.h>

    char maya[20][15] = {
	"S", ".", "..", "...", "....",
	"-", ". -", ".. -", "... -", ".... -",
	"- -", ". - -", ".. - -", "... - -", ".... - -",
	"- - -", ". - - -", ".. - - -", "... - - -", ".... - - -"
    };

    int pwr[7] = {1, 20, 360, 7200, 144000, 2880000, 57600000};


int main()
{
    int n;
    char temp[100];
    int i,j;
    int res = 0;
    scanf("%d",&n);
    memset(temp,0,100);

    while(n!=0)
    {
        getchar();
        for(i=n-1;i>=0;i--)
        {
            gets(temp);
            for(j=0;j<20;j++)
                if(!strcmp(temp,maya[j]))
                break;
            //if(j)
            res+=j*pwr[i];
        }
        printf("%d\n",res);
        scanf("%d",&n);
        res=0;
        memset(temp,0,100);
    }
return 0;
}
