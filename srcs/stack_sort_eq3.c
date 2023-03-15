/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_eq3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:44:27 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/15 22:24:42 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack_sort.h"

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
