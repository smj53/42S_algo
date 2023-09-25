#include <stdio.h>
#include <stdlib.h>

char	*get_arr(int n)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * n);
	for (int i=0; i<n; i++)
		scanf(" %c", &ret[i]);
	return (ret);
}

int	*get_pi(char *p, int n)
{
	int	*ret;
	int	j;

	ret = (int *)malloc(sizeof(int) * n);
	for (int i=0; i<n; i++)
		ret[i] = 0;
	j = 0;
	for (int i=1; i<n; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = ret[j - 1];
		if (p[i] == p[j])
			ret[i] = ++j;
	}
	return (ret);
}

int	get_gcd(int a, int b)
{
	if (a % b == 0)
		return (b);
	return (get_gcd(b, a % b));
}

int	main(void)
{
	int		N;
	char	*meat;
	char	*r;
	int		ans;
	int		*pi;
	int		j;
	int		ii;
	int		gcd;

	scanf("%d", &N);
	meat = get_arr(N);
	r = get_arr(N);
	pi = get_pi(meat, N);
	j = 0;
	ans = 0;
	for (int i=0; i<N+N-1; i++)
	{
		ii = i % N;
		while (j > 0 && r[ii] != meat[j])
			j = pi[j - 1];
		if (r[ii] == meat[j])
		{
			if (j == N - 1)
			{
				ans++;
				j = pi[j];
			}
			else
				++j;
		}
	}
	gcd = get_gcd(N, ans);
	printf("%d/%d", ans/gcd, N/gcd);
}
