#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long	solve(char S[], int K)
{
	int	*pi;
	int	len;
	int	j;

	len = strlen(S);
	pi = (int *)malloc(sizeof(int) * len);
	for (int i=0; i<len; i++)
		pi[i] = 0;
	j = 0;
	for (int i=1; i<len; i++)
	{
		while (j > 0 && S[i] != S[j])
			j = pi[j - 1];
		if (S[i] == S[j])
			pi[i] = ++j;
	}
	return ((long)K * (len - pi[len - 1]) + pi[len - 1]);
}

int	main(void)
{
	char	S[500001];
	int		K;

	scanf("%s", S);
	scanf("%d", &K);
	printf("%ld", solve(S, K));
}
