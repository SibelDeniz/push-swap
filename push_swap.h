#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node
{
    int nb;
    struct s_node *next;
    struct s_node *prev;
} t_node;

void    add_back(t_node **stack, int nb);
void    parse(t_node **stack, int argc, char **argv);
void    free_stack(t_node **stack);
int     stack_size(t_node *stack);
int     has_duplicate(t_node *stack, int nb);
int     is_sorted(t_node *stack);
int     assign_indexes(t_node *stack_a);
void    sort_3(t_node **a);
void    sort_4(t_node **a, t_node **b);
void    sort_5(t_node **a, t_node **b);
void    finish_stack_a(t_node **a);
int     lis_greedy_sort(t_node **a, t_node **b);
int     *lis_keep_array(t_node *a);
int     rotate_cost(int pos, int size);
int     find_min_pos(t_node *a);
int     find_target_pos(t_node *a, int value);
void    find_best_move(t_node *a, t_node *b, int *best_a, int *best_b);
void    push_non_lis(t_node **a, t_node **b, int *keep, int size);
void    sa(t_node **stack_a);
void    sb(t_node **stack_b);
void    ra(t_node **stack_a);
void    rb(t_node **stack_b);
void    rra(t_node **stack_a);
void    rrb(t_node **stack_b);
void    pa(t_node **stack_a, t_node **stack_b);
void    pb(t_node **stack_a, t_node **stack_b);
