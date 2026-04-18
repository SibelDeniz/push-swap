#include "push_swap.h"

static void push_val_to_b(t_node **a, t_node **b, int val)
{
	int		pos;
	int		size;
	t_node	*cur;

	pos = 0;
	cur = *a;
	while (cur->nb != val)
	{
		cur = cur->next;
		pos++;
	}
	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a), write(1, "ra\n", 3);
	else
		while (pos++ < size)
			rra(a), write(1, "rra\n", 4);
	pb(a, b);
	write(1, "pb\n", 3);
}

void	sort_3(t_node **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->nb;
	mid = (*a)->next->nb;
	bot = (*a)->next->next->nb;
	if (top > mid && top > bot)
		ra(a), write(1, "ra\n", 3);
	else if (mid > top && mid > bot)
		rra(a), write(1, "rra\n", 4);
	if ((*a)->nb > (*a)->next->nb)
		sa(a), write(1, "sa\n", 3);
}

void	sort_4(t_node **a, t_node **b)
{
	push_val_to_b(a, b, 0);
	sort_3(a);
	pa(a, b);
	write(1, "pa\n", 3);
}

void	sort_5(t_node **a, t_node **b)
{
	push_val_to_b(a, b, 0);
	push_val_to_b(a, b, 1);
	sort_3(a);
	pa(a, b);
	write(1, "pa\n", 3);
	pa(a, b);
	write(1, "pa\n", 3);
}
