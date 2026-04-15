#include "push_swap.h"

void sa(t_node **stack_a)
{
    t_node *first;
    t_node *second;
    t_node *third;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
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
        return;
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

void ra(t_node **stack_a)
{
    t_node *first;
    t_node *head;
    t_node *last;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    first = *stack_a;
    head = first->next;
    last = *stack_a;
    while (last->next)
        last = last->next;
    head->prev = NULL;
    first->next = NULL;
    first->prev = last;
    last->next = first;
    *stack_a = head;
}

void pa(t_node **stack_a, t_node **stack_b)
{
    t_node *moved;

    if (!stack_a || !stack_b || !*stack_b)
        return;
    moved = *stack_b;
    *stack_b = moved->next;
    if (*stack_b)
        (*stack_b)->prev = NULL;
    moved->prev = NULL;
    moved->next = *stack_a;
    if (*stack_a)
        (*stack_a)->prev = moved;
    *stack_a = moved;
}

void pb(t_node **stack_a, t_node **stack_b)
{
    t_node *moved;

    if (!stack_a || !stack_b || !*stack_a)
        return;
    moved = *stack_a;
    *stack_a = moved->next;
    if (*stack_a)
        (*stack_a)->prev = NULL;
    moved->prev = NULL;
    moved->next = *stack_b;
    if (*stack_b)
        (*stack_b)->prev = moved;
    *stack_b = moved;
}
