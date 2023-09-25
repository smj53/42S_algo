#include <stdio.h>

long	get_g(int n)
{
	long	ret;

	ret = 0;
	for(int i=1; i<=n; i++)
		ret += i * (n / i);
	return (ret);
}

int	main(void)
{
	int	N;

	scanf("%d", &N);
	printf("%ld", get_g(N));
}
