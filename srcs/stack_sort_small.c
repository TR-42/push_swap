/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:54:24 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/15 23:26:28 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack_sort.h"

#include <limits.h>

#define OP_SWAP (0)
#define OP_ROTATE (1)
#define OP_REV_ROTATE (2)

// swap if ... (1 to 9)
// len: 2 && { 2, 1 } -> { 1, 2}
// len: 3 && not { 1, 2, 3 } -> already sorted
// len: 3 && { 1, 3, 2 } -> { 3, 1, 2 }
// len: 3 && { 2, 1, 3 } -> { 1, 2, 3 }
// len: 3 && not { 2, 3, 1 } -> reverse rotate
// len: 3 && not { 3, 1, 2 } -> rotate
// len: 3 && { 3, 2, 1 } -> { 2, 3, 1 }
static bool	_is_swap_needed(int *arr, size_t len, bool is_1to9)
{
	int	a0;
	int	a1;
	int	a2;

	if (len < 2 || 3 < len)
		return (false);
	a0 = arr[0];
	a1 = arr[1];
	if (3 <= len)
		a2 = arr[2];
	return (
		(len == 2 && ((is_1to9 && a1 < a0) || (!is_1to9 && a0 < a1)))
		|| (
			is_1to9
			&& !(a0 < a1 && a1 < a2)
			&& !(a0 < a1 && a1 > a2 && a0 > a2)
			&& !(a0 > a1 && a1 < a2 && a0 > a2)
		)
		|| (
			!is_1to9
			&& !(a0 > a1 && a1 > a2)
			&& !(a0 > a1 && a1 < a2 && a0 < a2)
			&& !(a0 < a1 && a1 > a2 && a0 < a2)
		)
	);
}

// rotate if...
// len: 3 && 1to9: { 3, 1, 2 }
// len: 3 && 9to1: { 1, 3, 2 }
static bool	_is_rotate_needed(int *arr, size_t len, bool is_1to9)
{
	int	a0;
	int	a1;
	int	a2;

	if (len != 3)
		return (false);
	a0 = arr[0];
	a1 = arr[1];
	a2 = arr[2];
	return (
		(is_1to9 && a0 > a1 && a1 < a2 && a0 > a2)
		|| (!is_1to9 && a0 < a1 && a1 > a2 && a0 < a2)
	);
}

// reverse rotate if...
// len: 3 && 1to9: { 2, 3, 1 }
// len: 3 && 9to1: { 2, 1, 3 }
static bool	_is_rev_rotate_needed(int *a, size_t l, bool is_1to9)
{
	int	a0;
	int	a1;
	int	a2;

	if (l != 3)
		return (false);
	a0 = a[0];
	a1 = a[1];
	a2 = a[2];
	return (
		(is_1to9 && a0 < a1 && a1 > a2 && a0 > a2)
		|| (!is_1to9 && a0 > a1 && a1 < a2 && a0 < a2)
	);
}

bool	_sort_if_3(t_stacks *s, size_t a_len, size_t b_len, bool is_b_1to9)
{
	swap_flag(s, true,
		_is_swap_needed(s->a, a_len, true),
		_is_swap_needed(s->b, b_len, is_b_1to9)
		);
	rotate_flag(s, true,
		_is_rotate_needed(s->a, a_len, true),
		_is_rotate_needed(s->b, b_len, is_b_1to9)
		);
	reverse_rotate_flag(s, true,
		_is_rev_rotate_needed(s->a, a_len, true),
		_is_rev_rotate_needed(s->b, b_len, is_b_1to9)
		);
	return (true);
}

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
	_sort_if_3(stacks, stacks->a_len, stacks->b_len, false);
	while (stacks->b_len != 0)
		push_a(stacks, true);
	return (true);
}
