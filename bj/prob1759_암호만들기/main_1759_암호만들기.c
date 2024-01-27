#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
  char *ca = (char *)a;
  char *cb = (char *)b;
  if (*ca > *cb)
    return (1);
  if (*ca < *cb)
    return (-1);
  return (0);
}

int is_vowel(char c)
{
  return (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u');
}

void  solve(char *c, int C, int L, int cnt, int start, char *s, int vowel)
{
  if (cnt == L)
  {
    if (vowel >= 1 && L - vowel >= 2)
      printf("%s", s);
    return;
  }
  for (int i = start; i < C; i++)
  {
    s[cnt] = c[i];
    solve(c, C, L, cnt + 1, i + 1, s, vowel + is_vowel(c[i]));
  }
}

int main(void)
{
  int L, C;
  char *c, *s;

  scanf("%d %d", &L, &C);
  c = (char *)malloc(sizeof(char) * C);
  for (int i = 0; i < C; i++)
    scanf(" %c", c + i);
  s = (char *)malloc(sizeof(char) * (L + 2));
  s[L + 1] = 0;
  s[L] = '\n';
  qsort(c, C, sizeof(char), cmp);
  solve(c, C, L, 0, 0, s, 0);
}