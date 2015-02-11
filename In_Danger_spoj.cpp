#include<stdio.h>

/* http://manyprogrammingtutorials.blogspot.in/2013/11/spoj-1786-in-danger.html */
int josephus(int n)
{
  //  printf("In josephus function");
  int power=1;

    while(power<=n)
        power=power*2;

        power=power/2;

    return(1+(n-power)*2);
}

int main(){
    char x,y;
    int d;

    while(scanf("%c%ce%d\n",&x,&y,&d)==3){
        int n = (x-'0')*10+(y-'0');
        for(int i = 0;i<d;++i) n *= 10;

        if(n==0) break;

        printf("%d\n",josephus(n));
    }

    return 0;
}
