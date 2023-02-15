/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:44:50 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/16 00:01:10 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

#include "../libft/ft_printf/ft_printf.h"

const t_stack_elem	*stack_print_one(const t_stack_elem *elem)
{
	if (elem != NULL)
		ft_printf("[%12p]\ttop %12p <- %10d -> %12p bottom\n",
			elem, elem->to_top, elem->value, elem->to_bottom);
	return (elem);
}

void	stack_print(const t_stack_elem *elem)
{
	while (elem != NULL)
		elem = stack_print_one(elem)->to_bottom;
}

void	stack_print_all(const t_stacks *stacks)
{
	if (stacks == NULL)
	{
		ft_printf("stack_print_all error: invalid argument");
		return ;
	}
	ft_printf("Stack a: length = %zu, top:%p, bottom: %p~~~~~~~~~\n",
		stacks->a_len, stacks->a, stacks->a_bottom);
	stack_print(stacks->a);
	ft_printf("~~~~~~~~~~~~~~~~\n");
	ft_printf("Stack b: length = %zu, top:%p, bottom: %p~~~~~~~~~\n",
		stacks->b_len, stacks->b, stacks->b_bottom);
	stack_print(stacks->b);
	ft_printf("~~~~~~~~~~~~~~~~\n");
}
