/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_qsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:57:31 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/16 00:30:41 by kfujita          ###   ########.fr       */
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
	size_t	len_half;
	size_t	i;

	len_half = (len / 2) + (len % 2);
	while (s->b_len != len_half)
	{
		if (len <= 5 || (min + (int)len_half) <= s->b[0])
			push_a(s, log_vect);
		else
			rotate_b(s, log_vect);
	}
	if (5 < len)
	{
		_stack_split_push_to_a(s, len_half, min, log_vect);
		i = 0;
		while (i++ < (len - len_half))
			push_b(s, log_vect);
		_stack_split_push_to_a(s,
			len - len_half, min + (int)len_half, log_vect);
	}
	else
		_sort_and_pa(s, len, min, log_vect);
}

static void	_stack_split(t_stacks *s, size_t len, int min, t_vect *log_vect)
{
	size_t	len_half;

	len_half = len / 2;
	while (s->b_len != len_half)
	{
		if (len <= 5 || s->a[0] < (min + (int)len_half))
			push_b(s, log_vect);
		else
			rotate_a(s, log_vect);
	}
	if (5 < len)
	{
		_stack_split_push_to_a(s, len_half, min, log_vect);
		while (s->b_len != (len - len_half))
			push_b(s, log_vect);
		_stack_split_push_to_a(s,
			len - len_half, min + (int)len_half, log_vect);
	}
	else
		_sort_and_pa(s, len, min, log_vect);
}

bool	stack_sort_qsort(t_stacks *s, t_vect *log_vect)
{
	_stack_split(s, s->a_len, INT_MIN, log_vect);
	return (true);
}
