#include <stdio.h>
#include <stdlib.h>

int	solve(int l, char *s)
{
	int	*fail;
	int	j;

	fail = (int *)malloc(sizeof(int) * l);
	j = 0;
	for (int i=0; i<l; i++)
		fail[i] = 0;
	for (int i=1; i<l; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = fail[j - 1];
		if (s[i] == s[j])
			fail[i] = ++j;
	}
	return (l - fail[l - 1]);
}

int	main(void)
{
	int		L;
	char	S[1000001];

	scanf("%d", &L);
	scanf("%s", S);
	printf("%d", solve(L, S));
}
