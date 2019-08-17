/*
	[o] sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
		is only one or no elements).
	[o] sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
		is only one or no elements).
	[o] ss : sa and sb at the same time.
	[o] pa : push a - take the first element at the top of b and put it at the top of a. Do
		nothing if b is empty.
	[o] pb : push b - take the first element at the top of a and put it at the top of b. Do
		nothing if a is empty.
	[o] ra : rotate a - shift up all elements of stack a by 1. The first element becomes
		the last one.
	[o] rb : rotate b - shift up all elements of stack b by 1. The first element becomes
		the last one.
	[o] rr : ra and rb at the same time.
	[o] rra : reverse rotate a - shift down all elements of stack a by 1. The last element
		becomes the first one.
	[o] rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
		becomes the first one.
	[o] rrr : rra and rrb at the same time.
*/

#include "push_swap.h"

void			rotate_up(t_swap_stack *s)
{
	int			temp;
	int			i;

	printf("r%c\n", s->c);
	s->move_count++;
	temp = s->stack[s->index];
	i = s->index - 1;
	while (++i < s->length - 1)
	{
		s->stack[i] = s->stack[i + 1];
	}
	s->stack[s->length - 1] = temp;
}

void			rotate_up_2(t_swap_stack *a, t_swap_stack *b)
{
	printf("rr\n");
	rotate_up(a);
	rotate_up(b);
}

void			rotate_down(t_swap_stack *s)
{
	int			temp;
	int			i;

	printf("rr%c\n", s->c);
	s->move_count++;
	temp = s->stack[s->length - 1];
	i = s->length;
	while (--i >= s->index)
	{
		s->stack[i] = s->stack[i - 1];
	}
	s->stack[s->index] = temp;
}

void			rotate_down_2(t_swap_stack *a, t_swap_stack *b)
{
	printf("rrr\n");
	rotate_down(a);
	rotate_down(b);
}

void			swap_top(t_swap_stack *s)
{
	printf("s%c\n", s->c);
	s->move_count++;
	if (s->index + 1 < s->length)
	{
		s->stack[s->index] ^= s->stack[s->index + 1];
		s->stack[s->index + 1] ^= s->stack[s->index];
		s->stack[s->index] ^= s->stack[s->index + 1];
	}
}

void			swap_top_2(t_swap_stack *a, t_swap_stack *b)
{
	printf("ss\n");
	swap_top(a);
	swap_top(b);
}

// -------------------------------------------------------------------------- //

void			push_from_to(t_swap_stack *from, t_swap_stack *to)
{
	int			temp;

	printf("p%c\n", to->c);
	from->move_count++;
	if (from->index < from->length && to->index > 0)
	{
		temp = from->stack[from->index++];
		to->stack[--to->index] = temp;
	}
}
