#include <stdio.h>
#include <stdlib.h>

const static int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int max(int a, int b)
{
  if (a > b)
    return (a);
  return (b);
}

int check_adj(int N, int M, int *v, int i, int j)
{
  for (int k = 0; k < 4; k++)
  {
    int ni = i + d[k][0];
    int nj = j + d[k][1];
    if (ni<0 || ni>=N || nj<0 || nj>=M)
      continue;
    if(v[ni * M + nj])
      return (1);
  }
  return (0);
}

int solve(int N, int M, int K, int *m, int *v, int cnt, int start, int sum)
{
  int _max;

  if (cnt == K)
    return (sum);
  _max = -2147483648;
  for (int i = start; i < N * M; i++)
    {
      if (check_adj(N, M, v, i / M, i % M))
        continue;
      v[i] = 1;
      _max = max(_max, solve(N, M, K, m, v, cnt + 1, i + 1, sum + m[i]));
      v[i] = 0;
    }
  return (_max);
}

int main(void)
{
  int N, M, K;
  int *m, *v;

  scanf("%d %d %d", &N, &M, &K);
  m = (int *)malloc(sizeof(int) * N * M);
  v = (int *)calloc(N * M, sizeof(int));
  for (int i = 0; i < N * M; i++)
    scanf("%d", &m[i]);
  printf("%d", solve(N, M, K, m, v, 0, 0, 0));
}