#include <stdio.h>
#include <stdlib.h>

const static int	d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	count(char *m, int i, int N, const int *dir, char cur)
{
	int		cnt;
	int		r;
	int		c;

	cnt = 1;
	r = i / N - dir[0];
	c = i % N - dir[1];
	while (r >= 0 && c >= 0 && m[r * N + c] == cur)
	{
		r -= dir[0];
		c -= dir[1];
		cnt++;
	}
	r = i / N + dir[0];
	c = i % N + dir[1];
	while (r < N && c < N && m[r * N + c] == cur)
	{
		r += dir[0];
		c += dir[1];
		cnt++;
	}
	return (cnt);
}

int	main(void)
{
	int		N;
	int		ans;
	char	*m;

	scanf("%d", &N);
	m = (char *)malloc(sizeof(char) * N * N);
	for (int i=0; i<N*N; i++)
		scanf(" %c", &m[i]);
	ans = 0;
	for (int i=0; i<N*N; i++)
	{
		ans = get_max(ans, count(m, i, N, d[0], m[i]));
		ans = get_max(ans, count(m, i, N, d[2], m[i]));
		for (int k=0; k<4; k++)
		{
			int nr = i / N + d[k][0];
			int nc = i % N + d[k][1];
			int j = nr * N + nc;
			if (nr < 0 || nr >= N || nc < 0 || nc >= N || m[j] == m[i])
				continue ;
			int t = m[j];
			m[j] = 0;
			ans = get_max(ans, count(m, i, N, d[0], t));
			ans = get_max(ans, count(m, i, N, d[2], t));
			m[j] = t;
		}
	}
	printf("%d", ans);
}
