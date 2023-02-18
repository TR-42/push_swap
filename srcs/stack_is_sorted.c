/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:17:52 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/19 01:23:42 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

bool	stack_is_sorted(t_stacks *stacks)
{
	size_t	i;

	if (stacks->a == NULL || stacks->a_len <= 0 || 0 < stacks->b_len)
		return (false);
	if (stacks->a_len == 1)
		return (true);
	i = 0;
	while (++i < stacks->a_len)
	{
		if (stacks->a[i] < stacks->a[i - 1])
			return (false);
	}
	return (true);
}
