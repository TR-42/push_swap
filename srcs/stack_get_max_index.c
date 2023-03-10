/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_max_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:09:11 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/10 17:27:19 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

static size_t	get_max_index(int *arr, size_t len)
{
	size_t	i;
	size_t	max_index;
	int		max_value;

	if (arr == NULL || len <= 1)
		return (0);
	max_index = 0;
	i = 0;
	max_value = *(arr++);
	while (++i < len)
	{
		if (max_value < *arr)
		{
			max_index = i;
			max_value = *arr;
		}
		arr++;
	}
	return (i);
}

size_t	stack_get_max_index_a(t_stacks *s)
{
	size_t	max_index;
	int		max_value;

	if (s == NULL)
		return (0);
	return (get_max_index(s->a, s->a_len));
}

size_t	stack_get_max_index_b(t_stacks *s)
{
	size_t	max_index;
	int		max_value;

	if (s == NULL)
		return (0);
	return (get_max_index(s->b, s->b_len));
}
