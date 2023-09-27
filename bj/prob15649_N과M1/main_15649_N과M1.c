#include <stdio.h>
#include <stdlib.h>

void  comb(int n, int m, int cnt, int *visited, int *selected)
{
  if (cnt == m)
  {
    for (int i = 0; i < m; i++)
      printf("%d ", selected[i]);
    printf("\n");
    return;
  }
  for (int i = 1; i <= n; i++)
  {
    if (visited[i])
      continue;
    visited[i] = 1;
    selected[cnt] = i;
    comb(n, m, cnt + 1, visited, selected);
    visited[i] = 0;
  }
}

int main(void)
{
  int N, M;
  int *selected;
  int *visited;

  scanf("%d %d", &N, &M);
  selected = (int *)malloc(sizeof(int) * M);
  visited = (int *)calloc(N + 1, sizeof(int));
  comb(N, M, 0, visited, selected);
}