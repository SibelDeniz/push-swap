#include "push_swap.h"

int main(int argc, char **argv) {
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;

    if (argc < 2)
        return (0);
    parse(&stack_a, argc, argv);

    add_back(&stack_b, 7);
    add_back(&stack_b, 5);
    add_back(&stack_b, 6);

    afficher_stack(stack_a);
    afficher_stack(stack_b);
    sb(&stack_b);
    afficher_stack(stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);

    return (0);
}
