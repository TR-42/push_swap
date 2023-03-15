/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_log.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:31:43 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/16 00:46:47 by kfujita          ###   ########.fr       */
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
		op = *((t_stack_op_num_type *)vect_at(vect, i++));
		ft_putstr_fd(_get_op_str(op), STDOUT_FILENO);
	}
}

static bool	_can_op_merge(t_stack_op_num op, t_stack_op_num last_op,
	t_stack_op_num op_a, t_stack_op_num op_b)
{
	return ((op == op_a && last_op == op_b) || (op == op_b && last_op == op_a));
}

void	stack_op_log_append(t_vect *vect, t_stack_op_num op)
{
	t_stack_op_num_type	*l_op;

	if (vect == NULL)
		return ;
	if (0 < vect->len)
	{
		l_op = (t_stack_op_num_type *)vect_at(vect, vect->len - 1);
		if (_can_op_merge(op, *l_op, OP_SA, OP_SB))
			op = OP_SS;
		else if (_can_op_merge(op, *l_op, OP_RA, OP_RB))
			op = OP_RR;
		else if (_can_op_merge(op, *l_op, OP_RRA, OP_RRB))
			op = OP_RRR;
		else if (_can_op_merge(op, *l_op, OP_PA, OP_PB))
		{
			*l_op = OP_NONE;
			return ;
		}
		if (*l_op == OP_NONE)
			*l_op = op;
		else
			vect_push_back(vect, &op, NULL);
	}
	else
		vect_push_back(vect, &op, NULL);
}
