/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:44:50 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/13 09:45:44 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

#include "../libft/ft_printf/ft_printf.h"

void	stack_print(const t_stack_elem *elem)
{
	while (elem != NULL)
	{
		ft_printf("[%12p]\ttop %12p <- %10d -> %12p bottom\n",
			elem, elem->to_top, elem->value, elem->to_bottom);
		elem = elem->to_bottom;
	}
}
