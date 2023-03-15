/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:54:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/16 00:32:07 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define V_TYPE int

// - bool
# include <stdbool.h>

// - size_t
# include <stddef.h>

# include "../libft/ft_vect/ft_vect.h"

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

typedef void	(*t_stack_op)(t_stacks *, t_vect *);

t_stacks	init_stack(V_TYPE *values, size_t count);
bool		init_stack_from_str_arr(const char **str_arr, size_t arr_len,
				t_stacks *stacks);

void		stack_print(V_TYPE *arr, size_t count);
void		stack_print_all(const t_stacks *stacks);

void		dispose_stack(t_stacks *stacks);

size_t		stack_get_max_index_a(t_stacks *s);
size_t		stack_get_max_index_b(t_stacks *s);
size_t		stack_get_min_index_a(t_stacks *s);
size_t		stack_get_min_index_b(t_stacks *s);

bool		is_a_sorted(t_stacks *s);
bool		is_b_sorted(t_stacks *s);
bool		stack_is_sorted_a_b(t_stacks *s);
bool		stack_is_sorted(t_stacks *stacks);

void		swap_flag(t_stacks *stacks, t_vect *log_vect, bool do_a, bool do_b);
void		swap_a(t_stacks *stacks, t_vect *log_vect);
void		swap_b(t_stacks *stacks, t_vect *log_vect);
void		swap_a_b(t_stacks *stacks, t_vect *log_vect);

void		push_a(t_stacks *stacks, t_vect *log_vect);
void		push_b(t_stacks *stacks, t_vect *log_vect);

void		rotate_flag(t_stacks *stacks, t_vect *log_vect,
				bool do_a, bool do_b);
void		rotate_a(t_stacks *stacks, t_vect *log_vect);
void		rotate_b(t_stacks *stacks, t_vect *log_vect);
void		rotate_a_b(t_stacks *stacks, t_vect *log_vect);

void		reverse_rotate_flag(t_stacks *stacks, t_vect *log_vect,
				bool do_a, bool do_b);
void		reverse_rotate_a(t_stacks *stacks, t_vect *log_vect);
void		reverse_rotate_b(t_stacks *stacks, t_vect *log_vect);
void		reverse_rotate_a_b(t_stacks *stacks, t_vect *log_vect);

#endif
