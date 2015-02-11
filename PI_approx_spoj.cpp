/*PI.BAS 'Prints PI to number of decimal places desired. 19830623tac.
'        Ref: American Mathematical Monthly vol#45,1938 p657-667.
'        Ref: Best of Micro vol.#1 p85-86.
'
'
'             *       ----                      ----
'        *****         \     16(-1)^k+1          \         4(-1)^k+1
'       * * *   ---     >   ------------    --    >    ----------------
'         * *   ---    /    (2k-1)5^2k-1         /      (2k-1)239^2k-1
'         * *         ----                      ----
'        *   *        k=1                       k=1
'
*/
#include "stdio.h"
#include "stdlib.h"
#include<math.h>
#include<iostream>

#define SCALE 10000
#define ARRINIT 2000

int cnt_dig(int num)
{
    int t=0;
    while(num!=0)
    {
        t++;
        num=num/10;
    }
    return t;
}

void pi_digits(int digits)
{
    int carry = 0;
    int arr[digits + 1];
    int cnt=0;
    for (int i = 0; i <= digits; ++i)
        arr[i] = ARRINIT;

    for (int i = digits; i > 0; i-= 14)
    {
        cnt++;
        int temp;
        int sum = 0;
        for (int j = i; j > 0; --j)
        {
            sum = sum * j + SCALE * arr[j];
            arr[j] = sum%(j*2-1);
            sum /= j * 2 - 1;
        }
      //  printf("sum-%d \n",sum);

        if(cnt==1)
        {
            temp = (carry + sum /SCALE);
            int num = cnt_dig(temp);
            std::cout<<temp/pow(10,num-1);
           // printf("%4f",temp/pow(10,num-1));
        }
        else
        printf("%04d", (carry + sum /SCALE));
       // std::cout<<((carry + sum /SCALE));
        carry = sum%SCALE;
    }

}

int main()
{
    pi_digits(100);
   // int n = 16*arctan(1/5)-4*arctan(1/239);
    return 0;
}
