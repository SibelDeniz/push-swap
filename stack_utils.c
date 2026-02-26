#include "push_swap.h"



t_node *create_node(int nb)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->nb = nb;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void add_back(t_node **stack, int nb)
{
    t_node *new_node = create_node(nb);
    if (!new_node)
        return;
    if (!*stack)
    {
        *stack = new_node;
        return;
    }

    t_node *current = *stack;
    while (current->next)
        current = current->next;
    current->next = new_node;
    new_node->prev = current;
}



void afficher_stack(t_node *stack)
{
    t_node *current = stack;
    while (current)
    {
        printf("%d ", current->nb);
        current = current->next;
    }
    printf("\n");
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
