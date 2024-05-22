#include <stdio.h>

int main(void)
{
  int T, N;
  int dp[11];

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i < 11; i++)
    dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &N);
    printf("%d\n", dp[N]);
  }
}