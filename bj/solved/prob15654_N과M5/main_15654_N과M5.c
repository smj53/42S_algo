#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
  int *ia = (int *)a;
  int *ib = (int *)b;
  if (*ia < *ib)
    return (-1);
  if (*ia == *ib)
    return (0);
  return (1);
}

void  comb(int n, int m, int cnt, int *visited, int *selected, int *arr)
{
  if (cnt == m)
  {
    for (int i = 0; i < m; i++)
      printf("%d ", arr[selected[i]]);
    printf("\n");
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (visited[i])
      continue;
    visited[i] = 1;
    selected[cnt] = i;
    comb(n, m, cnt + 1, visited, selected, arr);
    visited[i] = 0;
  }
}

int main(void)
{
  int N, M;
  int *arr;
  int *selected;
  int *visited;

  scanf("%d %d", &N, &M);
  selected = (int *)malloc(sizeof(int) * M);
  visited = (int *)calloc(N, sizeof(int));
  arr = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);
  qsort(arr, N, sizeof(int), comp);
  comb(N, M, 0, visited, selected, arr);
}