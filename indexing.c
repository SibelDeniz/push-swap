#include "push_swap.h"

static int *stack_to_array(t_node *stack, int size)
{
    int *arr;
    int i;

    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);
    i = 0;
    while (stack)
    {
        arr[i] = stack->nb;
        stack = stack->next;
        i++;
    }
    return (arr);
}

static void sort_array(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

static int set_indexes(t_node *a, int *arr, int size)
{
    int i;
    int found;

    while (a)
    {
        i = 0;
        found = 0;
        while (i < size)
        {
            if (arr[i] == a->nb)
            {
                a->nb = i;
                found = 1;
                break;
            }
            i++;
        }
        if (!found)
            return (0);
        a = a->next;
    }
    return (1);
}

int assign_indexes(t_node *stack_a)
{
    int *arr;
    int size;
    int i;
    int ok;

    size = stack_size(stack_a);
    if (size <= 1)
        return (1);
    arr = stack_to_array(stack_a, size);
    if (!arr)
        return (0);
    sort_array(arr, size);
    i = 1;
    while (i < size)
        if (arr[i] == arr[i - 1])
            return (free(arr), 0);
        else
            i++;
    ok = set_indexes(stack_a, arr, size);
    free(arr);
    return (ok);
}
