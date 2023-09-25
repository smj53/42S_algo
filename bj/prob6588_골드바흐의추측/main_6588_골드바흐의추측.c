#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LIMIT 1000001

int	get_prime(int *prime, int *is_prime)
{
	int	cnt;

	cnt = 0;
	for (int i=0; i<LIMIT; i++)
		is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (int i=2; i<LIMIT/i; i++)
		if (is_prime[i])
		{
			for (int j=i+i; j<LIMIT; j+=i)
				is_prime[j] = 0;
			prime[cnt++] = i;
		}
	return (cnt);
}

int	main(void)
{
	int	*prime;
	int	*is_prime;
	int	prime_n;
	int	N;

	prime = (int *)malloc(sizeof(int) * sqrt(LIMIT));
	is_prime = (int *)malloc(sizeof(int) * LIMIT);
	prime_n = get_prime(prime, is_prime);
	while (1)
	{
		scanf("%d", &N);
		if (!N)
			break ;
		for (int i=0; i<prime_n; i++)
		{
			if (is_prime[N - prime[i]])
			{
				printf("%d = %d + %d\n", N, prime[i], N - prime[i]);
				break ;
			}
		}
	}
}
