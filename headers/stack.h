/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:54:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/12 23:37:00 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define V_TYPE int

// - bool
# include <stdbool.h>

// - size_t
# include <stddef.h>


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

void		push_a(t_stacks *stacks, V_TYPE value);
void		push_b(t_stacks *stacks, V_TYPE value);

void		rotate_a(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		rotate_a_b(t_stacks *stacks);

void		reverse_rotate_a(t_stacks *stacks);
void		reverse_rotate_b(t_stacks *stacks);
void		reverse_rotate_a_b(t_stacks *stacks);

#endif
