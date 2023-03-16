/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_qsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:57:31 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/16 10:03:13 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack_sort.h"

// - INT_MIN
#include <limits.h>

static void	_sort_and_pa(t_stacks *s, size_t len, int min, t_vect *log_vect)
{
	_sort_if_3(s, (len - s->b_len), s->b_len, log_vect);
	while (0 < len)
	{
		if (s->a[0] != min)
			push_a(s, log_vect);
		rotate_a(s, log_vect);
		min++;
		len--;
	}
}

static void	_stack_split_push_to_a(t_stacks *s,
	size_t len, int min, t_vect *log_vect)
{
	size_t	i;

	while (s->b_len != (len / 2) + (len % 2))
	{
		if (len <= 5 || (min + (int)((len / 2) + (len % 2))) <= s->b[0])
			push_a(s, log_vect);
		else
			rotate_b(s, log_vect);
	}
	if (5 < len)
	{
		_stack_split_push_to_a(s, (len / 2) + (len % 2), min, log_vect);
		i = 0;
		while (i++ < (len - ((len / 2) + (len % 2))))
			push_b(s, log_vect);
		_stack_split_push_to_a(s, len - ((len / 2) + (len % 2)),
			min + (int)((len / 2) + (len % 2)), log_vect);
	}
	else
		_sort_and_pa(s, len, min, log_vect);
}

bool	stack_sort_qsort(t_stacks *s, t_vect *log_vect)
{
	size_t	len;

	len = s->a_len;
	while (s->b_len != (len / 2))
	{
		if (len <= 5 || s->a[0] < (INT_MIN + (int)(len / 2)))
			push_b(s, log_vect);
		else
			rotate_a(s, log_vect);
	}
	if (5 < len)
	{
		_stack_split_push_to_a(s, (len / 2), INT_MIN, log_vect);
		while (s->b_len != (len - (len / 2)))
			push_b(s, log_vect);
		_stack_split_push_to_a(s,
			len - (len / 2), INT_MIN + (int)(len / 2), log_vect);
	}
	else
		_sort_and_pa(s, len, INT_MIN, log_vect);
	return (true);
}
