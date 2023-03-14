/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:54:24 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/14 23:01:02 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack_sort.h"

#include <limits.h>

bool	stack_sort_small(t_stacks *stacks)
{
	size_t	b_len;

	if (6 < stacks->a_len)
		return (false);
	b_len = 0;
	if (3 < stacks->a_len)
		b_len = stacks->a_len - 3;
	while (stacks->b_len != b_len)
	{
		if (stacks->a[0] < (INT_MIN + (int)b_len))
			push_b(stacks, true);
		else
			rotate_a(stacks, true);
	}
	_sort_if_3(stacks);
	while (stacks->b_len != 0)
		push_a(stacks, true);
	return (true);
}
