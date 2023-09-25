#include <stdio.h>

int	main(void)
{
	int	n;
	int	ans;
	int	r;

	while (scanf("%d", &n) != EOF)
	{
		ans = 1;
		r = 1;
		while (r % n != 0)
		{
			r %= n;
			++ans;
			r *= 10;
			++r;
		}
		printf("%d\n", ans);
	}
}
