#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static long	parse_number(const char **s, t_node **stack)
{
	long	sign;
	long	nb;

	sign = 1;
	nb = 0;
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	if (!is_digit(**s))
		(free_stack(stack), write(2, "Error\n", 6), exit(EXIT_FAILURE));
	while (is_digit(**s))
	{
		nb = nb * 10 + (**s - '0');
		if ((sign == 1 && nb > INT_MAX) || (sign == -1 && -nb < INT_MIN))
			(free_stack(stack), write(2, "Error\n", 6), exit(EXIT_FAILURE));
		(*s)++;
	}
	return (nb * sign);
}

static void	parse_arg(t_node **stack, const char *s)
{
	long	nb;

	while (*s)
	{
		while (*s && is_space(*s))
			s++;
		if (!*s)
			return ;
		nb = parse_number(&s, stack);
		if (*s && !is_space(*s))
			(free_stack(stack), write(2, "Error\n", 6), exit(EXIT_FAILURE));
		if (has_duplicate(*stack, (int)nb))
			(free_stack(stack), write(2, "Error\n", 6), exit(EXIT_FAILURE));
		add_back(stack, (int)nb);
	}
}

void	parse(t_node **stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		parse_arg(stack, argv[i]);
		i++;
	}
}
