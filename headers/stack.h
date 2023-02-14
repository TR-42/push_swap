/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:54:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/14 23:46:47 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define V_TYPE int

// - bool
# include <stdbool.h>

// - size_t
# include <stddef.h>

# define STR_SWAP_A ("sa\n")
# define STR_SWAP_B ("sb\n")
# define STR_SWAP_A_B ("ss\n")

# define STR_PUSH_A ("pa\n")
# define STR_PUSH_B ("pb\n")

# define STR_ROTATE_A ("ra\n")
# define STR_ROTATE_B ("rb\n")
# define STR_ROTATE_A_B ("rr\n")

# define STR_REVERSE_ROTATE_A ("rra\n")
# define STR_REVERSE_ROTATE_B ("rrb\n")
# define STR_REVERSE_ROTATE_A_B ("rrr\n")

typedef struct s_stack_elem
{
	struct s_stack_elem	*to_top;
	struct s_stack_elem	*to_bottom;
	V_TYPE				value;
}	t_stack_elem;

typedef t_stack_elem *	t_stack_top;
typedef t_stack_elem *	t_stack_btm;

typedef struct s_stacks
{
	t_stack_top	a;
	t_stack_btm	a_bottom;
	size_t		a_len;

	t_stack_top	b;
	t_stack_btm	b_bottom;
	size_t		b_len;
}	t_stacks;

t_stacks	init_stack(int *values, size_t count);
bool		init_stack_from_str(const char *str, t_stacks *stacks);

void		stack_print(const t_stack_elem *elem);

void		dispose_stack(t_stacks *stacks);
void		dispose_stack_elem(t_stack_elem *elem);

void		swap_a(t_stacks *stacks);
void		swap_b(t_stacks *stacks);
void		swap_a_b(t_stacks *stacks);

void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);

void		rotate_a(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		rotate_a_b(t_stacks *stacks);

void		reverse_rotate_a(t_stacks *stacks);
void		reverse_rotate_b(t_stacks *stacks);
void		reverse_rotate_a_b(t_stacks *stacks);

#endif
