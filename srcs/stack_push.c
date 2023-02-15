/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:28:58 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/16 00:04:23 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

#include "../libft/ft_put/ft_put.h"

#include <unistd.h>

static bool	_pop_push(t_stack_top *src, t_stack_top *dst)
{
	t_stack_elem	*target;
	t_stack_elem	*current_dst;

	if (src == NULL || dst == NULL || *src == NULL)
		return (false);
	target = *src;
	*src = target->to_bottom;
	if (*src != NULL)
		(*src)->to_top = target->to_top;
	current_dst = *dst;
	*dst = target;
	target->to_bottom = current_dst;
	if (current_dst != NULL)
	{
		target->to_top = current_dst->to_top;
		current_dst->to_top = target;
	}
	return (true);
}

void	push_a(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_PUSH_A, STDOUT_FILENO);
	if (stacks == NULL || stacks->b_len < 1)
		return ;
	if (_pop_push(&(stacks->b), &(stacks->a)))
	{
		stacks->b_len--;
		stacks->a_len++;
	}
}

void	push_b(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_PUSH_B, STDOUT_FILENO);
	if (stacks == NULL || stacks->a_len < 1)
		return ;
	if (_pop_push(&(stacks->a), &(stacks->b)))
	{
		stacks->a_len--;
		stacks->b_len++;
	}
}
