/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:17:52 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/14 22:14:21 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

static bool	is_sorted(int *arr, size_t len)
{
	size_t	i;
	int		last_value;

	if (arr == NULL || len == 0)
		return (false);
	i = 0;
	last_value = *(arr++);
	while (++i < len)
	{
		if (*arr < last_value)
			return (false);
		last_value = *arr;
		arr++;
	}
	return (true);
}

bool	is_a_sorted(t_stacks *s)
{
	if (s == NULL)
		return (false);
	return (is_sorted(s->a, s->a_len));
}

bool	is_b_sorted(t_stacks *s)
{
	if (s == NULL)
		return (false);
	return (is_sorted(s->b, s->b_len));
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
	return (stacks != NULL && stacks->b_len <= 0
		&& is_sorted(stacks->a, stacks->a_len));
}
