#include "push_swap.h"

int	rotate_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

int	find_min_pos(t_node *a)
{
	int	min;
	int	pos;
	int	min_pos;

	min = a->nb;
	pos = 0;
	min_pos = 0;
	while (a)
	{
		if (a->nb < min)
			min = a->nb, min_pos = pos;
		a = a->next;
		pos++;
	}
	return (min_pos);
}

int	find_target_pos(t_node *a, int value)
{
	int	pos;
	int	best;
	int	target;

	pos = 0;
	best = INT_MAX;
	target = find_min_pos(a);
	while (a)
	{
		if (a->nb > value && a->nb < best)
			best = a->nb, target = pos;
		a = a->next;
		pos++;
	}
	return (target);
}

static int	move_total(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	return (a + b);
}

void	find_best_move(t_node *a, t_node *b, int *best_a, int *best_b)
{
	int	sa;
	int	sb;
	int	pos;
	int	ca;
	int	cb;
	int	best;

	sa = stack_size(a);
	sb = stack_size(b);
	pos = 0;
	best = INT_MAX;
	while (b)
	{
		ca = rotate_cost(find_target_pos(a, b->nb), sa);
		cb = rotate_cost(pos, sb);
		if (move_total(ca, cb) < best)
			best = move_total(ca, cb), *best_a = ca, *best_b = cb;
		b = b->next;
		pos++;
	}
}
