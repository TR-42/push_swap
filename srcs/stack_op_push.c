/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:28:58 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/16 00:22:01 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"
#include "../headers/stack_op_log.h"

#include "../libft/ft_mem/ft_mem.h"
#include "../libft/ft_put/ft_put.h"

#include <unistd.h>

static bool	_pop_push(V_TYPE *src, size_t *srclen, V_TYPE *dst, size_t *dstlen)
{
	if (src == NULL || dst == NULL || srclen == NULL || dstlen == NULL
		|| *srclen < 1)
		return (false);
	ft_memmove(dst + 1, dst, (*dstlen) * sizeof(V_TYPE));
	dst[0] = src[0];
	ft_memmove(src, src + 1, (*srclen - 1) * sizeof(V_TYPE));
	*srclen -= 1;
	*dstlen += 1;
	return (true);
}

void	push_a(t_stacks *stacks, t_vect *log_vect)
{
	if (0 < stacks->b_len)
		stack_op_log_append(log_vect, OP_PA);
	if (stacks == NULL)
		return ;
	_pop_push(stacks->b, &(stacks->b_len), stacks->a, &(stacks->a_len));
}

void	push_b(t_stacks *stacks, t_vect *log_vect)
{
	if (0 < stacks->a_len)
		stack_op_log_append(log_vect, OP_PB);
	if (stacks == NULL)
		return ;
	_pop_push(stacks->a, &(stacks->a_len), stacks->b, &(stacks->b_len));
}
