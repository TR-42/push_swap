/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:17:52 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/19 05:39:55 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

bool	is_a_sorted(t_stacks *s)
{
	size_t	i;

	if (s == NULL || s->a == NULL || s->a_len <= 0)
		return (false);
	if (s->a_len == 1)
		return (true);
	i = 0;
	while (++i < s->a_len)
	{
		if (s->a[i] < s->a[i - 1])
			return (false);
	}
	return (true);
}

bool	is_b_sorted(t_stacks *s)
{
	size_t	i;

	if (s == NULL || s->b == NULL || s->b_len <= 0)
		return (false);
	if (s->b_len == 1)
		return (true);
	i = 0;
	while (++i < s->b_len)
	{
		if (s->b[i] > s->b[i - 1])
			return (false);
	}
	return (true);
}

bool	stack_is_sorted_a_b(t_stacks *s)
{
	size_t	i;

	if (s == NULL || s->a == NULL || s->b == NULL
		|| (s->a_len <= 0 && s->b_len <= 0))
		return (false);
	if (s->a_len <= 1 && s->b_len <= 1)
		return (true);
	i = 1;
	while (i < s->a_len && i < s->b_len)
	{
		if (i < s->a_len && s->a[i] < s->a[i - 1])
			return (false);
		if (i < s->b_len && s->b[i] > s->b[i - 1])
			return (false);
	}
	return (true);
}

bool	stack_is_sorted(t_stacks *stacks)
{
	return (stacks != NULL && stacks->b_len <= 0 && is_a_sorted(stacks));
}
