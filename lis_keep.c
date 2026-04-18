#include "push_swap.h"

static int	*stack_to_array(t_node *a, int n)
{
	int	*vals;
	int	i;

	vals = malloc(sizeof(int) * n);
	if (!vals)
		return (NULL);
	i = 0;
	while (a)
	{
		vals[i] = a->nb;
		a = a->next;
		i++;
	}
	return (vals);
}

static int	lis_end(int *v, int *len, int *prev, int n)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	while (i < n)
		len[i] = 1, prev[i++] = -1;
	end = 0;
	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (v[j] < v[i] && len[j] + 1 > len[i])
				len[i] = len[j] + 1, prev[i] = j;
			j++;
		}
		if (len[i] > len[end])
			end = i;
		i++;
	}
	return (end);
}

static void	mark_keep(int *keep, int *vals, int *prev, int end)
{
	while (end >= 0)
	{
		keep[vals[end]] = 1;
		end = prev[end];
	}
}

int	*lis_keep_array(t_node *a)
{
	int	*vals;
	int	*len;
	int	*prev;
	int	*keep;
	int	n;

	n = stack_size(a);
	keep = calloc(n, sizeof(int));
	vals = stack_to_array(a, n);
	len = malloc(sizeof(int) * n);
	prev = malloc(sizeof(int) * n);
	if (!keep || !vals || !len || !prev)
		return (free(keep), free(vals), free(len), free(prev), NULL);
	mark_keep(keep, vals, prev, lis_end(vals, len, prev, n));
	return (free(vals), free(len), free(prev), keep);
}
