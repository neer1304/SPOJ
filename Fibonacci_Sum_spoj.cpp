#include<stdio.h>
#include<math.h>
# define MOD 1000000007
/*
at first try to write the first few fibo numbers:
0  1  1  2  3  5  8  13  21  34  55

now write the sum of fibo numbers from 0 to i:
0  1  2  4  7  12  20  33  54

look for a pattern in these numbers. Do you see it?!!

note that sum(x) = fib(x+2)-1

now,  x still may be up to 10^9, and it can't be calculated naively.
Lucky us, there is a faster way to calculate fibonacci numbers, using matrix powers.

you can calculate this using fast matrix exponentiation and you'll get yourself a neat O(log n) solution.

http://www.ics.uci.edu/~eppstein/161/960109.html
http://stackoverflow.com/questions/4357223/finding-the-sum-of-fibonacci-numbers
*/

/*
long long fib(long long n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    long long i;
    long long  first =0;
    long long second = 1;
    long long third = first+second;

    for(i=2;i<=n;i++)
    {
        first = second;
        second = third;
        third =first+second;
    }
    return second;
}
*/
/*
long long fib(long long n)
{
    if(n==0)
        return 0;
    if(n==1 || n==2)
        return 1;

    double t1 = (1+sqrt(5))/2;
    double t2 = (1-sqrt(5))/2;
    return (pow(t1,n)-pow(t2,n))/sqrt(5) ;
}
*/
#define LL long long

LL fib(int n);
void multiply(LL F[2][2], LL M[2][2]);
void power(LL F[2][2], int n);

LL fib(int  n)
{
  LL F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0]%MOD;
}


void power(LL F[2][2], int n)
{
  if( n == 0 || n == 1)
      return;
  LL M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

void multiply(LL F[2][2], LL M[2][2])
{
  LL x =  ((F[0][0]*M[0][0])%MOD + (F[0][1]*M[1][0])%MOD)%MOD;
  LL y =  ((F[0][0]*M[0][1])%MOD + (F[0][1]*M[1][1])%MOD)%MOD;
  LL z =  ((F[1][0]*M[0][0])%MOD + (F[1][1]*M[1][0])%MOD)%MOD;
  LL w =  ((F[1][0]*M[0][1])%MOD + (F[1][1]*M[1][1])%MOD)%MOD;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

int main()
{
    int t;
    int  n,m;
    long long sum=0;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);

     /*   for(i=n;i<=m;i++)
        {
          //  printf(" %d ",fib(i));
            sum+=fib(i);
        }
        */
        sum = (fib(m+2) - fib(n+1))%MOD;
        if(sum<0)
            sum+=MOD;
        printf("%lld\n",sum%MOD);
        sum=0;
    }
return 0;
}
