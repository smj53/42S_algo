#include <stdio.h>

int main(void)
{
  int E, S, M;
  int e, s, m;
  int ans;

  scanf("%d %d %d", &E, &S, &M);
  e = 0;
  s = 0;
  m = 0;
  ans = 1;
  while (e + 1 != E || s + 1 != S || m + 1 != M)
  {
    ans++;
    e = (e + 1) % 15;
    s = (s + 1) % 28;
    m = (m + 1) % 19;
  }
  printf("%d", ans);
}