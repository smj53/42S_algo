#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void	find(int *ie, int K, int cnt,
	long long int num, long long int *min, long long int *max, int v)
{
	if (cnt == K)
	{
		*min = fmin(num, *min);
		*max = fmax(num, *max);
		return ;
	}
	for (int i=0; i<10; i++)
	{
		if (v & 1 << i || (cnt > 0 && num % 10 < i == ie[cnt - 1]))
			continue;
		find(ie, K, cnt + 1, num * 10 + i, min, max, v | 1 << i);
	}
}

int main(void)
{
	char c;
	int K;
	int	*ie;
	long long int min, max;

	scanf("%d", &K);
	ie = malloc(sizeof(int) * K);
	for (int i=0; i<K; i++)
	{
		scanf(" %c", &c);
		if (c == '<')
			ie[i] = 0;
		else
			ie[i] = 1;
	}
	min = 9999999999;
	max = 0;
	find(ie, K + 1, 0, 0, &min, &max, 0);
	printf("%0*lld\n%0*lld", K+1, max, K+1, min);
}
