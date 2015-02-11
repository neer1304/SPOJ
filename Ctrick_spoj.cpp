#include <stdio.h>

int josephus(int n, int k)
{
    int ans = 0, i;
    for(i = 2; i <= n; i++)
    {
        ans = (ans + k) % i;
        printf("%d ",ans);
        k++;
    }

    return ans;
}

// Driver Program to test above function
int main()
{
  int n = 4;
  int k = 1;
  printf("The chosen place is %d", josephus(n, k));
  return 0;
}
