/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_eq3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:44:27 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/19 08:57:42 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack_sort.h"

static void	swap_if_invalid_order(t_stacks *stacks)
{
	bool	a_valid;
	bool	b_valid;

	a_valid = ((stacks->a_len < 2) || (stacks->a[0] < stacks->a[1]));
	b_valid = ((stacks->b_len < 2) || (stacks->b[1] < stacks->b[0]));
	if (a_valid && b_valid)
		return ;
	if (!a_valid && !a_valid)
		swap_a_b(stacks, true);
	else if (!a_valid)
		swap_a(stacks, true);
	else
		swap_b(stacks, true);
}

static void	rev_rotate_if_invalid_order(t_stacks *s)
{
	bool	rra;
	bool	rrb;

	rra = (s->a_len <= 3 && (s->a[0] > s->a[2] || s->a[1] > s->a[2]));
	rrb = (s->b_len <= 3 && (s->b[0] < s->b[2] || s->b[1] < s->b[2]));
	if (rra && rrb)
		reverse_rotate_a_b(s, true);
	else if (rra)
		reverse_rotate_a(s, true);
	else if (rrb)
		reverse_rotate_b(s, true);
}

bool	_sort_if_3(t_stacks *s)
{
	if (s->a_len < 3)
		return (false);
	swap_if_invalid_order(s);
	rev_rotate_if_invalid_order(s);
	swap_if_invalid_order(s);
	return (true);
}
