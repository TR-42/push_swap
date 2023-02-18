/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:54:24 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/19 04:47:25 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack_sort.h"

#include <limits.h>

static bool	_less_than_7(t_stacks *stacks)
{
	size_t	i;
	size_t	small_val_pos;
	size_t	b_len;

	i = 0;
	small_val_pos = 0;
	b_len = stacks->a_len - 3;
	while (i < stacks->a_len)
		if (stacks->a[i++] < (INT_MIN + (int)b_len))
			small_val_pos += i - 1;
	small_val_pos = (small_val_pos / b_len) < (stacks->a_len / 2);
	while (stacks->a_len != 3)
	{
		if (stacks->a[0] < (INT_MIN + (int)b_len))
			push_b(stacks, true);
		else if (small_val_pos)
			rotate_a(stacks, true);
		else
			reverse_rotate_a(stacks, true);
	}
	_sort_if_3(stacks);
	while (stacks->b_len != 0)
		push_a(stacks, true);
	return (true);
}

bool	stack_sort_small(t_stacks *stacks)
{
	if (stacks->a_len <= 1)
		return (true);
	else if (stacks->a_len == 2)
	{
		if (stacks->a[1] < stacks->a[0])
			swap_a(stacks, true);
		return (true);
	}
	else if (stacks->a_len == 3)
		return (_sort_if_3(stacks));
	else if (stacks->a_len <= 6)
		return (_less_than_7(stacks));
	return (false);
}
