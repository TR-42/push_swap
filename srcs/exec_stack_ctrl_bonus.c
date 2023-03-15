/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_stack_ctrl_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:20:37 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/16 00:32:16 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/exec_stack_ctrl_bonus.h"

#include "../libft/ft_string/ft_string.h"

static bool	_exec_stack_ctrl(const char *input, t_stacks *stacks,
	const char *expected, t_stack_op ctrler)
{
	if (ft_strncmp(input, expected, 4) != 0)
		return (false);
	ctrler(stacks, false);
	return (true);
}

bool	exec_stack_ctrl(const char *input, t_stacks *stacks)
{
	return (_exec_stack_ctrl(input, stacks, STR_SWAP_A, swap_a)
		|| _exec_stack_ctrl(input, stacks, STR_SWAP_B, swap_b)
		|| _exec_stack_ctrl(input, stacks, STR_SWAP_A_B, swap_a_b)
		|| _exec_stack_ctrl(input, stacks, STR_PUSH_A, push_a)
		|| _exec_stack_ctrl(input, stacks, STR_PUSH_B, push_b)
		|| _exec_stack_ctrl(input, stacks, STR_ROTATE_A, rotate_a)
		|| _exec_stack_ctrl(input, stacks, STR_ROTATE_B, rotate_b)
		|| _exec_stack_ctrl(input, stacks, STR_ROTATE_A_B, rotate_a_b)
		|| _exec_stack_ctrl(input, stacks,
			STR_REVERSE_ROTATE_A, reverse_rotate_a)
		|| _exec_stack_ctrl(input, stacks,
			STR_REVERSE_ROTATE_B, reverse_rotate_b)
		|| _exec_stack_ctrl(input, stacks,
			STR_REVERSE_ROTATE_A_B, reverse_rotate_a_b)
	);
}
