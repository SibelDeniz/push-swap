#include "push_swap.h"

static int is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

static void parse_error(t_node **stack)
{
    free_stack(stack);
    printf("Error\n");
    exit(EXIT_FAILURE);
}

static long parse_number(const char **s, t_node **stack)
{
    long sign;
    long value;

    sign = 1;
    value = 0;
    if (**s == '+' || **s == '-')
    {
        if (**s == '-')
            sign = -1;
        (*s)++;
    }
    if (**s < '0' || **s > '9')
        parse_error(stack);
    while (**s >= '0' && **s <= '9')
    {
        value = value * 10 + (**s - '0');
        if ((sign == 1 && value > INT_MAX) || (sign == -1 && -value < INT_MIN))
            parse_error(stack);
        (*s)++;
    }
    return (value * sign);
}

void parse(t_node **stack, int argc, char **argv)
{
    int         i;
    const char  *s;
    long        nb;

    i = 1;
    while (i < argc)
    {
        s = argv[i];
        while (*s)
        {
            while (*s && is_space(*s))
                s++;
            if (!*s)
                break;
            nb = parse_number(&s, stack);
            if (*s && !is_space(*s))
                parse_error(stack);
            add_back(stack, (int)nb);
        }
        i++;
    }
}
