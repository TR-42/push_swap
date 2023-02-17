/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:08:53 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/18 06:48:56 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

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

void	rotate_a(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_ROTATE_A, STDOUT_FILENO);
	if (stacks == NULL)
		return ;
	_rotate(stacks->a, stacks->a_len);
}

void	rotate_b(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_ROTATE_B, STDOUT_FILENO);
	if (stacks == NULL)
		return ;
	_rotate(stacks->b, stacks->b_len);
}

void	rotate_a_b(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_ROTATE_A_B, STDOUT_FILENO);
	rotate_a(stacks, false);
	rotate_b(stacks, false);
}
