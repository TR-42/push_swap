/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:44:50 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/18 06:43:09 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

#include "../libft/ft_printf/ft_printf.h"

void	stack_print(V_TYPE *arr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		ft_printf("\t[%3u]: %10d\n", (unsigned int)i++, *arr++);
}

void	stack_print_all(const t_stacks *stacks)
{
	if (stacks == NULL)
	{
		ft_printf("stack_print_all error: invalid argument");
		return ;
	}
	ft_printf("Stack a: length = %u ~~~~~~~~~\n", (unsigned int)(stacks->a_len));
	stack_print(stacks->a, stacks->a_len);
	ft_printf("~~~~~~~~~~~~~~~~\n");
	ft_printf("Stack b: length = %u ~~~~~~~~~\n", (unsigned int)(stacks->b_len));
	stack_print(stacks->b, stacks->b_len);
	ft_printf("~~~~~~~~~~~~~~~~\n\n");
}
