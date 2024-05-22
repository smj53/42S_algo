#include <stdio.h>
#include <stdlib.h>

long	*get_g(int n)
{
	long	*ret;
	int		*is_prime;

	ret = (long *)malloc(sizeof(long) * n);
	is_prime = (int *)malloc(sizeof(int) * n);
	for (int i=2; i<n; i++)
		is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for(int i=2; i*i<n; i++)
		if (is_prime[i])
			for(int j=i+i; j<n; j+=i)
				is_prime[j] = 0;
	ret[0] = 0;
	ret[1] = 1;
	for(int i=2; i<n; i++)
	{
		ret[i] = ret[i - 1] + 1 + i;
		if (!is_prime[i])
			for (int j=2; j*j<=i; j++)
				if (i % j == 0)
				{
					ret[i] += j;
					if (j != i / j)
						ret[i] += i / j;
				}
	}
	return (ret);
}

int	main(void)
{
	int		N;
	int		T;
	long	*g;

	g = get_g(1000001);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		printf("%ld\n", g[N]);
	}
}
