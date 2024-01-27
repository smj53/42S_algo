#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
  if (a > b)
    return (a);
  return (b);
}

int solve(int N, int *T, int *P, int start, int sum)
{
  int _max;

  if (start == N)
    return (sum);
  _max = 0;
  for (int i = start; i < N; i++)
  {
    if (i + T[i] > N)
      continue;
    _max = max(_max, sum + P[i]);
    _max = max(_max, solve(N, T, P, i + T[i], sum + P[i]));
  }
  return (_max);
}

int main(void)
{
  int N;
  int *T, *P;

  scanf("%d", &N);
  T = (int *)malloc(sizeof(int) * N);
  P = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++)
    scanf("%d %d", T + i, P + i);
  printf("%d", solve(N, T, P, 0, 0));
}