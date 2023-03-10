/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_min_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:09:11 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/10 17:18:22 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

static size_t	get_min_index(int *arr, size_t len)
{
	size_t	i;
	size_t	min_index;
	int		min_value;

	if (arr == NULL || len <= 1)
		return (0);
	min_index = 0;
	i = 0;
	min_value = *(arr++);
	while (++i < len)
	{
		if (*arr < min_value)
		{
			min_index = i;
			min_value = *arr;
		}
		arr++;
	}
	return (i);
}

size_t	stack_get_min_index_a(t_stacks *s)
{
	size_t	min_index;
	int		min_value;

	if (s == NULL)
		return (0);
	return (get_min_index(s->a, s->a_len));
}

size_t	stack_get_min_index_b(t_stacks *s)
{
	size_t	min_index;
	int		min_value;

	if (s == NULL)
		return (0);
	return (get_min_index(s->b, s->b_len));
}
