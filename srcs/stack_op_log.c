/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_log.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:31:43 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/15 23:51:50 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack_op_log.h"
#include "../headers/stack.h"

#include "../libft/ft_put/ft_put.h"

#include <stdbool.h>
#include <unistd.h>

static char	*_get_op_str(t_stack_op_num op)
{
	if (op == OP_RA)
		return (STR_ROTATE_A);
	else if (op == OP_RB)
		return (STR_ROTATE_B);
	else if (op == OP_RR)
		return (STR_ROTATE_A_B);
	else if (op == OP_RRA)
		return (STR_REVERSE_ROTATE_A);
	else if (op == OP_RRB)
		return (STR_REVERSE_ROTATE_B);
	else if (op == OP_RRR)
		return (STR_REVERSE_ROTATE_A_B);
	else if (op == OP_SA)
		return (STR_SWAP_A);
	else if (op == OP_SB)
		return (STR_SWAP_B);
	else if (op == OP_SS)
		return (STR_SWAP_A_B);
	else if (op == OP_PA)
		return (STR_PUSH_A);
	else if (op == OP_PB)
		return (STR_PUSH_B);
	else
		return (NULL);
}

void	stack_op_log_print(t_vect *vect)
{
	size_t			i;
	t_stack_op_num	op;

	if (vect == NULL)
		return ;
	i = 0;
	while (i < vect->len)
	{
		op = *((t_stack_op_num *)vect_at(vect, i++));
		ft_putstr_fd(_get_op_str(op), STDOUT_FILENO);
	}
}
