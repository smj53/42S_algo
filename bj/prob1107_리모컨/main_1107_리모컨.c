#include <stdio.h>

int abs(int n)
{
  if (n < 0)
    return (-n);
  return (n);
}

int min(int a, int b)
{
  if (a < b)
    return (a);
  return (b);
}

int can_make(int n, int broken)
{
  do
  {
    if (broken & 1<<(n%10))
      return (0);
    n /= 10;
  } while (n);
  return (1);
}

int get_digit(int N)
{
  int ret;

  ret = 1;
  while (N / 10)
  {
    N /= 10;
    ret++;
  }
  return (ret);
}

int get_ans(int N, int broken, int diff)
{
  int t;

  for (int i = 0; i < diff; i++)
  {
    if (N-i >= 0 && can_make(N - i, broken))
      return min(diff, i + get_digit(N - i)); 
    if (can_make(N + i, broken))
      return min(diff, i + get_digit(N + i));
  }
  return (diff);
}

int main(void)
{
  int N, M;
  int broken;
  int t;

  scanf("%d %d", &N, &M);
  broken = 0;
  while (M--)
  {
    scanf("%d", &t);
    broken |= 1 << t;
  }
  printf("%d", get_ans(N, broken, abs(N - 100)));
}