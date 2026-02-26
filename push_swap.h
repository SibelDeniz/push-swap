#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>


typedef struct s_node
{
    int nb;
    struct s_node *next;
    struct s_node *prev;
} t_node;


void add_back(t_node **stack, int nb);
void afficher_stack(t_node *stack);
void parse(t_node **stack, int argc, char **argv);
void free_stack(t_node **stack);
void sa(t_node **stack_a);
void sb(t_node **stack_b);
