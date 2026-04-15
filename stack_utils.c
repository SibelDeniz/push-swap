#include "push_swap.h"

void add_back(t_node **stack, int nb)
{
    t_node *new_node;
    t_node *current;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->nb = nb;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (!*stack)
    {
        *stack = new_node;
        return;
    }
    current = *stack;
    while (current->next)
        current = current->next;
    current->next = new_node;
    new_node->prev = current;
}

void afficher_stack(t_node *stack)
{
    t_node *current;

    current = stack;
    while (current)
    {
        printf("%d ", current->nb);
        current = current->next;
    }
    printf("\n");
}

int stack_size(t_node *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->nb > stack->next->nb)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void free_stack(t_node **stack)
{
    t_node *current;
    t_node *next;

    if (!stack || !*stack)
        return;
    current = *stack;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}
