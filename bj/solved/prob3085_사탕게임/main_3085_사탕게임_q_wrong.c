#include <stdio.h>
#include <stdlib.h>

const static int	d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

typedef struct s_queue
{
	int				v;
	struct s_queue	*next;
}	t_queue;

void	*enqueue(t_queue **q, int v);
int		dequeue(t_queue **q);

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	count(char *m, int i, int N)
{
	t_queue	*q;
	int		*visited;
	int		vcnt;
	int		hcnt;
	char	c;

	vcnt = 1;
	hcnt = 1;
	q = 0;
	c = m[i];
	enqueue(&q, i);
	visited[i] = 1;
	while (!q)
	{
		i = dequeue(&q);
		for (int k=0; k<4; k++)
		{
			int nr = i / N + d[k][0];
			int nc = i % N + d[k][1];
			int j = nr * N + nc;
			if (nr<0 || nr>=N || nc<0 || nc>=N || visited[j] || m[j] != c)
				continue ;
			if (k < 2)
				hcnt++;
			else
				vcnt++;
			enqueue(&q, j);
			visited[j] = 1;
		}
	}
	return (get_max(hcnt, vcnt));
}

int	main(void)
{
	int		N;
	int		ans;
	char	*m;

	scanf("%d", &N);
	m = (char *)malloc(sizeof(char) * N * N);
	for (int i=0; i<N*N; i++)
		scanf("%c", &m[i]);
	ans = 0;
	for (int i=0; i<N*N; i++)
	{
		for (int k=0; k<4; k++)
		{
			int nr = i / N + d[k][0];
			int nc = i % N + d[k][1];
			int j = nr * N + nc;
			if (nr < 0 || nr >= N || nc < 0 || nc >= N
				|| m[j] == m[i])
				continue ;
			int t = m[i];
			m[j] = 0;
			ans = get_max(ans, count(m, i, N, 0));
			ans = get_max(ans, count(m, i, N, 2));
			m[j] = m[i];
			m[i] = t;
		}
	}
	printf("%d", ans);
}

void	*enqueue(t_queue **q, int v)
{
	t_queue	*c;
	t_queue *n;

	n = (t_queue *)malloc(sizeof(t_queue));
	n->next = 0;
	n->v = v;
	if (*q)
		*q = n;
	else
	{
		c = *q;
		while (c->next)
			c = c->next;
		c->next = n;
	}
}

int		dequeue(t_queue **q)
{
	int	t;

	t = (*q)->v;
	*q = (*q)->next;
	return (t);
}
