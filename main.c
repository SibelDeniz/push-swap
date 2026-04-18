#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    if (argc < 2)
        return (0);
    parse(&stack_a, argc, argv);
    if (!stack_a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    if (!assign_indexes(stack_a))
    {
        free_stack(&stack_a);
        write(2, "Error\n", 6);
        return (1);
    }
    if (!lis_greedy_sort(&stack_a, &stack_b))
        return (free_stack(&stack_a), free_stack(&stack_b), 1);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
