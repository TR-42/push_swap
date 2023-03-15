/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:06:38 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/16 00:23:54 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"
#include "../headers/stack_op_log.h"

#include "../libft/ft_put/ft_put.h"

// - NULL
#include <stddef.h>

// - STDOUT_FILENO
#include <unistd.h>

static void	_swap(V_TYPE *current_top, size_t len)
{
	V_TYPE	tmp;

	if (current_top == NULL || len < 2)
		return ;
	tmp = current_top[0];
	current_top[0] = current_top[1];
	current_top[1] = tmp;
}

void	swap_flag(t_stacks *stacks, t_vect *log_vect, bool do_a, bool do_b)
{
	if (stacks == NULL)
		return ;
	if (do_a && do_b)
		swap_a_b(stacks, log_vect);
	else if (do_a)
		swap_a(stacks, log_vect);
	else if (do_b)
		swap_b(stacks, log_vect);
}

void	swap_a(t_stacks *stacks, t_vect *log_vect)
{
	if (0 < stacks->a_len)
		stack_op_log_append(log_vect, OP_SA);
	if (stacks == NULL)
		return ;
	_swap(stacks->a, stacks->a_len);
}

void	swap_b(t_stacks *stacks, t_vect *log_vect)
{
	if (0 < stacks->b_len)
		stack_op_log_append(log_vect, OP_SB);
	if (stacks == NULL)
		return ;
	_swap(stacks->b, stacks->b_len);
}

void	swap_a_b(t_stacks *stacks, t_vect *log_vect)
{
	if (0 < stacks->a_len || 0 < stacks->b_len)
		stack_op_log_append(log_vect, OP_SS);
	swap_a(stacks, false);
	swap_b(stacks, false);
}
