#include "push_swap.h"

void rb(t_node **stack_b)
{
    t_node *first;
    t_node *head;
    t_node *last;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    first = *stack_b;
    head = first->next;
    last = *stack_b;
    while (last->next)
        last = last->next;
    head->prev = NULL;
    first->next = NULL;
    first->prev = last;
    last->next = first;
    *stack_b = head;
}

void rra(t_node **stack_a)
{
    t_node *last;
    t_node *before;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    last = *stack_a;
    while (last->next)
        last = last->next;
    before = last->prev;
    before->next = NULL;
    last->prev = NULL;
    last->next = *stack_a;
    (*stack_a)->prev = last;
    *stack_a = last;
}

void rrb(t_node **stack_b)
{
    t_node *last;
    t_node *before;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    last = *stack_b;
    while (last->next)
        last = last->next;
    before = last->prev;
    before->next = NULL;
    last->prev = NULL;
    last->next = *stack_b;
    (*stack_b)->prev = last;
    *stack_b = last;
}

void push_non_lis(t_node **a, t_node **b, int *keep, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (keep[(*a)->nb])
            ra(a), write(1, "ra\n", 3);
        else
            pb(a, b), write(1, "pb\n", 3);
        i++;
    }
}
