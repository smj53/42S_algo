#include <stdio.h>
#include <stdlib.h>

int	get_max(int L, char *S)
{
	int	*pi;
	int	j;
	int	ret;

	pi = (int *)malloc(sizeof(int) * L);
	for (int i=0; i<L; i++)
		pi[i] = 0;
	j = 0;
	for (int i=1; i<L; i++)
	{
		while (j > 0 && S[i] != S[j])
			j = pi[j - 1];
		if (S[i] == S[j])
			pi[i] = ++j;
	}
	ret = L - pi[L - 1];
	free(pi);
	return (ret);
}

int	main(void)
{
	int		L;
	char	*S;

	scanf("%d", &L);
	S = (char *)malloc(sizeof(char) * (L + 1));
	scanf("%s", S);
	printf("%d", get_max(L, S));
	free(S);
}
