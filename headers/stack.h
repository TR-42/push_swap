/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:54:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/18 23:33:02 by kfujita          ###   ########.fr       */
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

typedef struct s_stacks
{
	V_TYPE	*a;
	size_t	a_len;

	V_TYPE	*b;
	size_t	b_len;
}	t_stacks;

t_stacks	init_stack(V_TYPE *values, size_t count);
bool		init_stack_from_str_arr(const char **str_arr, size_t arr_len,
				t_stacks *stacks);

void		stack_print(V_TYPE *arr, size_t count);
void		stack_print_all(const t_stacks *stacks);

void		dispose_stack(t_stacks *stacks);

void		swap_a(t_stacks *stacks, bool do_print);
void		swap_b(t_stacks *stacks, bool do_print);
void		swap_a_b(t_stacks *stacks, bool do_print);

void		push_a(t_stacks *stacks, bool do_print);
void		push_b(t_stacks *stacks, bool do_print);

void		rotate_a(t_stacks *stacks, bool do_print);
void		rotate_b(t_stacks *stacks, bool do_print);
void		rotate_a_b(t_stacks *stacks, bool do_print);

void		reverse_rotate_a(t_stacks *stacks, bool do_print);
void		reverse_rotate_b(t_stacks *stacks, bool do_print);
void		reverse_rotate_a_b(t_stacks *stacks, bool do_print);

#endif
