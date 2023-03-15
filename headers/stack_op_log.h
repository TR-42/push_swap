/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_log.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:31:53 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/15 23:45:52 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OP_LOG_H
# define STACK_OP_LOG_H

# include "../libft/ft_vect/ft_vect.h"

typedef enum e_stack_op_num
{
	OP_NONE,
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
}	t_stack_op_num;

void	stack_op_log_append(t_vect *vect, t_stack_op_num op);

void	stack_op_log_print(t_vect *vect);

#endif
