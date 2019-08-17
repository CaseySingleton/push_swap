#include "push_swap.h"

void				setup(t_swap_stack *a, t_swap_stack *b, int ac, char **av)
{
	a->c = 'a';
	a->move_count = 0;
	a->length = ac - 1;
	a->stack = (int *)malloc(sizeof(int) * a->length);
	a->index = 0;
	for (int i = 1; i < ac; i++)
	{
		a->stack[i - 1] = atoi(av[i]);
	}
	b->c = 'b';
	b->move_count = 0;
	b->length = ac - 1;
	b->index = b->length;
	b->stack = (int *)malloc(sizeof(int) * b->length);
	bzero(b->stack, sizeof(int) * b->length);
}

void				print_stacks(t_swap_stack *a, t_swap_stack *b)
{
	int				i;
	int				j;

	i = a->index;
	j = b->index;
	printf(" a	b\n----------\n");
	while (i < a->length || j < b->length)
	{
		if (i < a->length)
		{
			printf(" %d", a->stack[i]);
		}
		else
		{
			printf("  x");
		}
		if (j < b->length)
		{
			printf("\t%d", b->stack[j]);
		}
		else
		{
			printf("\tx");
		}
		printf("\n");
		i++;
		j++;
	}
	printf("----------\n");
}

static int			is_solved(t_swap_stack *s)
{
	int				i;

	i = -1;
	while (++i < s->length - 1)
	{
		if (s->stack[i] > s->stack[i + 1])
		{
			return (0);
		}
	}
	return (1);
}

static void			sort_3_gtl(t_swap_stack *s)
{
	int				a;
	int				b;
	int				c;

	a = s->index;
	b = s->index + 1;
	c = s->index + 2;
	if (s->stack[a] > s->stack[b] && s->stack[a] > s->stack[c])
	{
		if (s->stack[b] < s->stack[c])
		{
			swap_top(s);
			rotate_up(s);
		}
	}
	else if (s->stack[b] > s->stack[a] && s->stack[b] > s->stack[c])
	{
		printf("hi %c\n", s->c);
		if (s->stack[a] > s->stack[c])
		{
			swap_top(s);
		}
		else
		{
			rotate_up(s);
		}
	}
	else if (s->stack[c] > s->stack[a] && s->stack[c] > s->stack[b])
	{
		if (s->stack[a] > s->stack[b])
		{
			rotate_down(s);
		}
		else
		{
			swap_top(s);
			rotate_down(s);
		}
	}
}

static void			sort_3_ltg(t_swap_stack *s)
{
	int				a;
	int				b;
	int				c;

	a = s->index;
	b = s->index + 1;
	c = s->index + 2;
	if (s->stack[a] < s->stack[b] && s->stack[a] < s->stack[c])
	{
		if (s->stack[b] > s->stack[c])
		{
			swap_top(s);
			rotate_up(s);
		}
	}
	else if (s->stack[b] < s->stack[a] && s->stack[b] < s->stack[c])
	{
		if (s->stack[a] < s->stack[c])
		{
			swap_top(s);
		}
		else
		{
			rotate_up(s);
		}
	}
	else if (s->stack[c] < s->stack[a] && s->stack[c] < s->stack[b])
	{
		if (s->stack[a] < s->stack[b])
		{
			rotate_down(s);
		}
		else
		{
			swap_top(s);
			rotate_down(s);
		}
	}
}

static void			largest_to_top(t_swap_stack *s)
{
	int				i;

	i = s->index;
	if (s->stack[i + 1] > s->stack[i] && s->stack[i + 1] > s->stack[s->length - 1])
	{
		swap_top(s);
	}
	else if (s->stack[s->length - 1] > s->stack[i] && s->stack[s->length - 1] > s->stack[i + 1])
	{
		rotate_down(s);
	}
}

static void			smallest_to_top(t_swap_stack *s)
{
	int				i;

	i = s->index;
	if (s->stack[i + 1] < s->stack[i] && s->stack[i + 1] < s->stack[s->length - 1])
	{
		swap_top(s);
	}
	else if (s->stack[s->length - 1] < s->stack[i] && s->stack[s->length - 1] < s->stack[i + 1])
	{
		rotate_down(s);
	}
}

static void			algorithm(t_swap_stack *a, t_swap_stack *b)
{
	print_stacks(a, b);
	while (a->index < a->length - 3)
	{
		smallest_to_top(a);
		push_from_to(a, b);
		largest_to_top(b);
	}
	sort_3_ltg(a);
	print_stacks(a, b);
	while (b->index < b->length)
	{
		largest_to_top(b);
		if (a->stack[a->index] < b->stack[b->index])
		{
			push_from_to(a, b);
			swap_top(b);
			push_from_to(b, a);
		}
		push_from_to(b, a);
	}
	print_stacks(a, b);
}

int					main(int argc, char *argv[])
{
	t_swap_stack	a;
	t_swap_stack	b;
	setup(&a, &b, argc, argv);
	print_stacks(&a, &b);
	while (is_solved(&a) == 0)
	{
		algorithm(&a, &b);
	}
	printf("is sorted: %s\n", (is_solved(&a) == 1) ? "yes" : "no");
	printf("total moves: %d\n", a.move_count + b.move_count);
	return (0);
}