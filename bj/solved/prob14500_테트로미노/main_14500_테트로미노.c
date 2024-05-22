#include <stdio.h>
#include <stdlib.h>

const static int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int max(int a, int b)
{
  if (a > b)
    return (a);
  return (b);
}

int get_sum(int N, int M, int i, int j, int **m, int cnt, int sum, int **visited)
{
  int _max;

  sum += m[i][j];
  if (cnt == 4)
    return (sum);
  visited[i][j] = 1;
  _max = 0;
  for (int k = 0; k < 4; k++)
  {
    int ni = i + d[k][0];
    int nj = j + d[k][1];
    if (ni<0 || ni>=N || nj<0 || nj>=M || visited[ni][nj])
      continue;
    _max = max(_max, get_sum(N, M, ni, nj, m, cnt + 1, sum, visited));
  }
  visited[i][j] = 0;
  return (_max);
}

int solve(int N, int M, int **m)
{
  int ret;
  int sum;
  int k;
  int cnt;
  int **visited;

  visited = (int **)malloc(sizeof(int *) * N);
  for (int i = 0; i < N; i++)
    visited[i] = (int *)calloc(M, sizeof(int));
  ret = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
    {
      ret = max(ret, get_sum(N, M, i, j, m, 1, 0, visited));
      sum = m[i][j];
      cnt = 0;
      for (k = 0; k < 4; k++)
      {
        int ni = i + d[k][0];
        int nj = j + d[k][1];
        
        if (ni<0 || ni>=N || nj<0 || nj>=M)
          continue;
        cnt++;
        sum += m[ni][nj];
      }
      if (cnt == 4)
        for (k = 0; k < 4; k++)
        {
          int ni = i + d[k][0];
          int nj = j + d[k][1];
          ret = max(ret, sum - m[ni][nj]);
        }
      else if (cnt == 3)
        ret = max(ret, sum);
    }
  return (ret);
}

int main(void)
{
  int N, M;
  int **m;

  scanf("%d %d", &N, &M);
  m = (int **)malloc(sizeof(int *) * N);
  for (int i = 0; i < N; i++)
  {
    m[i] = (int *)malloc(sizeof(int) * M);
    for (int j = 0; j < M; j++)
      scanf("%d", &m[i][j]);
  }
  printf("%d", solve(N, M, m));
}
