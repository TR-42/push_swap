/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:06:38 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/18 06:32:05 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

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

void	swap_a(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_SWAP_A, STDOUT_FILENO);
	if (stacks == NULL)
		return ;
	_swap(stacks->a, stacks->a_len);
}

void	swap_b(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_SWAP_B, STDOUT_FILENO);
	if (stacks == NULL)
		return ;
	_swap(stacks->b, stacks->b_len);
}

void	swap_a_b(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_SWAP_A_B, STDOUT_FILENO);
	swap_a(stacks, false);
	swap_b(stacks, false);
}
