#include <stdio.h>
#include <stdlib.h>

long	*get_g(int n)
{
	long	*ret;

	ret = (long *)malloc(sizeof(long) * n);
	for (int i=0; i<n; i++)
		ret[i] = 0;
	for (int i=1; i<n; i++)
	{
		for (int j=1; i*j<n; j++)
			ret[i*j] += i;
		ret[i] += ret[i-1];
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
