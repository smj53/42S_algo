#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INIT_BUF_MAX 2048

typedef struct s_vector {
	int	max_size;
	int	size;
	int	*buf;
}	t_vector;

t_vector	*get_vector();
void		push_back(t_vector *v, int d);
int			at(t_vector *v, int i);
void		free_vector(t_vector *v);

void	get_pi(char P[], int len, int *pi)
{
	int	i;
	int	j;

	for (i = 0; i < len; i++)
		pi[i] = 0;
	j = 0;
	for (i = 1; i < len; i++)
	{
		while (j > 0 && P[i] != P[j])
			j = pi[j - 1];
		if (P[i] == P[j])
			pi[i] = ++j;
	}
}

int	main(void)
{
	char		T[1000001];
	char		P[1000001];
	int			*pi;
	int			tlen;
	int			plen;
	int			j;
	t_vector	*ans;

	gets(T);
	gets(P);
	tlen = strlen(T);
	plen = strlen(P);
	pi = (int *)malloc(sizeof(int) * plen);
	get_pi(P, plen, pi);
	ans = get_vector();
	j = 0;
	for (int i = 0; i < tlen; i++)
	{
		while (j > 0 && T[i] != P[j])
			j = pi[j - 1];
		if (T[i] == P[j])
		{
			if (j == plen - 1)
			{
				push_back(ans, i - j + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
	printf("%d\n", ans->size);
	for (int i = 0; i < ans->size; i++)
	{
		if (i > 0)
			printf(" ");
		printf("%d", at(ans, i));
	}
	free_vector(ans);
	free(pi);
}

t_vector	*get_vector()
{
	t_vector	*ret;

	ret = (t_vector *)malloc(sizeof(t_vector));
	ret->max_size = INIT_BUF_MAX;
	ret->size = 0;
	ret->buf = (int *)malloc(sizeof(int) * ret->max_size);
	return (ret);
}

void	copy(int *dst, int *src, int n)
{
	for (int i = 0; i < n; i++)
		dst[i] = src[i];
}

int	*resize(t_vector *v, int new_size)
{
	int	*ret;

	ret = (int *)malloc(sizeof(int) * new_size);
	copy(ret, v->buf, v->size);
	v->max_size = new_size;
	free(v->buf);
	v->buf = ret;
	return (ret);
}

void	push_back(t_vector *v, int d)
{
	if (v->size == v->max_size)
		v->buf = resize(v, v->size * 2);
	v->buf[v->size++] = d;
}
int			at(t_vector *v, int i)
{
	return (v->buf[i]);
}
void		free_vector(t_vector *v)
{
	free(v->buf);
	free(v);
}
