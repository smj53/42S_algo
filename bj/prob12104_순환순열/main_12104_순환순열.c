#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	*get_pi(char B[], int len)
{
	int	j;
	int	*ret;

	ret = (int *)malloc(sizeof(int) * len);
	for (int i=0; i<len; i++)
		ret[i] = 0;
	j = 0;
	for (int i=1; i<len; i++)
	{
		while (j > 0 && B[i] != B[j])
			j = ret[j - 1];
		if (B[i] == B[j])
			ret[i] = ++j;
	}
	return (ret);
}

int	main(void)
{
	char	A[100001];
	char	B[100001];
	int		alen;
	int		blen;
	int		*pi;
	int		j;
	int		ans;

	scanf("%s", A);
	scanf("%s", B);
	alen = strlen(A);
	blen = strlen(A);
	pi = get_pi(B, blen);
	j = 0;
	ans = 0;
	for (int i=0; i<alen + alen - 1; i++)
	{
		int ii = i % alen;
		while (j > 0 && A[ii] != B[j])
			j = pi[j - 1];
		if (A[ii] == B[j])
		{
			if (j == blen - 1)
			{
				ans++;
				j = pi[j];
			}
			else
				++j;
		}
	}
	printf("%d", ans);
}
