/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 06:48:39 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/14 21:56:53 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

#include "../libft/ft_mem/ft_mem.h"
#include "../libft/ft_put/ft_put.h"

// - STDOUT_FILENO
#include <unistd.h>

static void	_rev_rotate(V_TYPE *top, size_t len)
{
	V_TYPE	tmp;

	if (top == NULL || len < 1)
		return ;
	tmp = top[len - 1];
	ft_memmove(top + 1, top, (len - 1) * sizeof(V_TYPE));
	top[0] = tmp;
}

void	reverse_rotate_flag(t_stacks *stacks, bool do_print,
			bool do_a, bool do_b)
{
	if (stacks == NULL)
		return ;
	if (do_a && do_b)
		reverse_rotate_a_b(stacks, do_print);
	else if (do_a)
		reverse_rotate_a(stacks, do_print);
	else if (do_b)
		reverse_rotate_b(stacks, do_print);
}

void	reverse_rotate_a(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_REVERSE_ROTATE_A, STDOUT_FILENO);
	if (stacks == NULL)
		return ;
	_rev_rotate(stacks->a, stacks->a_len);
}

void	reverse_rotate_b(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_REVERSE_ROTATE_B, STDOUT_FILENO);
	if (stacks == NULL)
		return ;
	_rev_rotate(stacks->b, stacks->b_len);
}

void	reverse_rotate_a_b(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_REVERSE_ROTATE_A_B, STDOUT_FILENO);
	reverse_rotate_a(stacks, false);
	reverse_rotate_b(stacks, false);
}
