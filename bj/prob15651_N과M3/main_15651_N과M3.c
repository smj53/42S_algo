#include <stdio.h>
#include <stdlib.h>

void  comb(int n, int m, int cnt, int *selected)
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
    selected[cnt] = i;
    comb(n, m, cnt + 1, selected);
  }
}

int main(void)
{
  int N, M;
  int *selected;

  scanf("%d %d", &N, &M);
  selected = (int *)malloc(sizeof(int) * M);
  comb(N, M, 0, selected);
}