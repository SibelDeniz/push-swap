#include "push_swap.h"

static void sa_dev_error(t_node **stack_a)
{
    free_stack(stack_a);
    printf("Error: sa requires at least two elements in stack a\n");
    exit(EXIT_FAILURE);
}

static void sb_dev_error(t_node **stack_b)
{
    free_stack(stack_b);
    printf("Error: sb requires at least two elements in stack b\n");
    exit(EXIT_FAILURE);
}

void sa(t_node **stack_a)
{
    t_node *first;
    t_node *second;
    t_node *third;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        sa_dev_error(stack_a);
    first = *stack_a;
    second = first->next;
    third = second->next;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    first->next = third;
    if (third)
        third->prev = first;
    *stack_a = second;
}

void sb(t_node **stack_b)
{
    t_node *first;
    t_node *second;
    t_node *third;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        sb_dev_error(stack_b);
    first = *stack_b;
    second = first->next;
    third = second->next;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    first->next = third;
    if (third)
        third->prev = first;
    *stack_b = second;
}
