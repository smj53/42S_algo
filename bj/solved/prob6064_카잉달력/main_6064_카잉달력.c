#include <stdio.h>

void  swap(int *a, int *b)
{
  int t;

  t = *a;
  *a = *b;
  *b = t;
}

int get_gcd(int a, int b)
{
  if (!b)
    return (a);
  return (get_gcd(b, a % b));
}

int main(void)
{
  int T;
  int M, N, x, y;
  int k, gcd;
  int flag;

  scanf("%d", &T);
  while (T--)
  {
    scanf("%d %d %d %d", &M, &N, &x, &y);
    if (M > N)
    {
      swap(&M, &N);
      swap(&x, &y);
    }
    k = y - 1;
    gcd = get_gcd(M, N);
    flag = 0;
    while (k <= N * M / gcd)
    {
      if (k % M == x - 1)
      {
        flag = 1;
        break;
      }
      k += N;
    }
    if (flag)
      printf("%d\n", k + 1);
    else
      printf("%d\n", -1);
  }
}