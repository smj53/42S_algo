#include <stdio.h>

int main(void)
{
  int   N;
  long  ans;
  int   tp;

  scanf("%d", &N);
  tp = 1;
  ans = 0;
  while (N / tp)
  {
    ans += N - tp + 1;
    tp *= 10;
  }
  printf("%ld", ans);
}