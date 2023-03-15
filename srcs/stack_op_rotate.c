/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:08:53 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/16 00:23:47 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"
#include "../headers/stack_op_log.h"

#include "../libft/ft_mem/ft_mem.h"
#include "../libft/ft_put/ft_put.h"

// - STDOUT_FILENO
#include <unistd.h>

static void	_rotate(V_TYPE *top, size_t len)
{
	V_TYPE	tmp;

	if (top == NULL || len < 1)
		return ;
	tmp = top[0];
	ft_memmove(top, top + 1, (len - 1) * sizeof(V_TYPE));
	top[len - 1] = tmp;
}

void	rotate_flag(t_stacks *stacks, t_vect *log_vect, bool do_a, bool do_b)
{
	if (stacks == NULL)
		return ;
	if (do_a && do_b)
		rotate_a_b(stacks, log_vect);
	else if (do_a)
		rotate_a(stacks, log_vect);
	else if (do_b)
		rotate_b(stacks, log_vect);
}

void	rotate_a(t_stacks *stacks, t_vect *log_vect)
{
	if (0 < stacks->a_len)
		stack_op_log_append(log_vect, OP_RA);
	if (stacks == NULL)
		return ;
	_rotate(stacks->a, stacks->a_len);
}

void	rotate_b(t_stacks *stacks, t_vect *log_vect)
{
	if (0 < stacks->b_len)
		stack_op_log_append(log_vect, OP_RB);
	if (stacks == NULL)
		return ;
	_rotate(stacks->b, stacks->b_len);
}

void	rotate_a_b(t_stacks *stacks, t_vect *log_vect)
{
	if (0 < stacks->a_len || 0 < stacks->b_len)
		stack_op_log_append(log_vect, OP_RR);
	rotate_a(stacks, false);
	rotate_b(stacks, false);
}
