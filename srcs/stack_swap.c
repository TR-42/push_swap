/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:06:38 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/15 23:22:50 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

#include "../libft/ft_put/ft_put.h"

// - NULL
#include <stddef.h>

// - STDOUT_FILENO
#include <unistd.h>

static void	_swap(t_stack_top	*current_top_var)
{
	t_stack_elem	*top_after_exec;
	t_stack_elem	*current_top;

	if (current_top_var == NULL || (*current_top_var) == NULL
		|| (*current_top_var)->to_bottom == NULL)
		return ;
	current_top = *current_top_var;
	top_after_exec = current_top->to_bottom;
	if (current_top->to_top != NULL)
		current_top->to_top->to_bottom = top_after_exec;
	top_after_exec->to_top = current_top->to_top;
	if (top_after_exec->to_bottom != NULL)
		top_after_exec->to_bottom->to_top = current_top;
	current_top->to_bottom = top_after_exec->to_bottom;
	current_top->to_top = top_after_exec;
	top_after_exec->to_bottom = current_top;
	*current_top_var = top_after_exec;
}

void	swap_a(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_SWAP_A, STDOUT_FILENO);
	if (stacks == NULL || stacks->a_len < 2)
		return ;
	_swap(&(stacks->a));
}

void	swap_b(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_SWAP_B, STDOUT_FILENO);
	if (stacks == NULL || stacks->b_len < 2)
		return ;
	_swap(&(stacks->b));
}

void	swap_a_b(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_SWAP_A_B, STDOUT_FILENO);
	swap_a(stacks, false);
	swap_b(stacks, false);
}
