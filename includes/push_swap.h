#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_swap_stack
{
	char			c;
	int				move_count;
	int				index;
	int				length;
	int				*stack;
}					t_swap_stack;

void				rotate_up(t_swap_stack *s);
void				rotate_up_2(t_swap_stack *a, t_swap_stack *b);
void				rotate_down(t_swap_stack *s);
void				rotate_down_2(t_swap_stack *a, t_swap_stack *b);
void				swap_top(t_swap_stack *s);

void				push_from_to(t_swap_stack *a, t_swap_stack*b);

#endif