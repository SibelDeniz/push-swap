#include "push_swap.h"

static void rotate_a_to_cost(t_node **a, int cost)
{
    while (cost > 0)
    {
        ra(a);
        write(1, "ra\n", 3);
        cost--;
    }
    while (cost < 0)
    {
        rra(a);
        write(1, "rra\n", 4);
        cost++;
    }
}

static void rotate_b_to_cost(t_node **b, int cost)
{
    while (cost > 0)
    {
        rb(b);
        write(1, "rb\n", 3);
        cost--;
    }
    while (cost < 0)
    {
        rrb(b);
        write(1, "rrb\n", 4);
        cost++;
    }
}

static void greedy_loop(t_node **a, t_node **b)
{
    int cost_a;
    int cost_b;

    while (*b)
    {
        find_best_move(*a, *b, &cost_a, &cost_b);
        rotate_a_to_cost(a, cost_a);
        rotate_b_to_cost(b, cost_b);
        pa(a, b), write(1, "pa\n", 3);
    }
}

static int small_dispatch(t_node **a, t_node **b, int size)
{
    if (size == 2)
        return (sa(a), write(1, "sa\n", 3), 1);
    if (size == 3)
        return (sort_3(a), 1);
    if (size == 4)
        return (sort_4(a, b), 1);
    if (size == 5)
        return (sort_5(a, b), 1);
    return (0);
}

int lis_greedy_sort(t_node **a, t_node **b)
{
    int *keep;
    int size;

    if (!a || !*a || is_sorted(*a))
        return (1);
    size = stack_size(*a);
    if (small_dispatch(a, b, size))
        return (1);
    keep = lis_keep_array(*a);
    if (!keep)
        return (0);
    push_non_lis(a, b, keep, size);
    greedy_loop(a, b);
    finish_stack_a(a);
    free(keep);
    return (1);
}
