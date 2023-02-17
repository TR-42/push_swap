/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:28:58 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/18 06:46:21 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

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

void	push_a(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_PUSH_A, STDOUT_FILENO);
	if (stacks == NULL)
		return ;
	_pop_push(stacks->b, &(stacks->b_len), stacks->a, &(stacks->a_len));
}

void	push_b(t_stacks *stacks, bool do_print)
{
	if (do_print)
		ft_putstr_fd(STR_PUSH_B, STDOUT_FILENO);
	if (stacks == NULL)
		return ;
	_pop_push(stacks->a, &(stacks->a_len), stacks->b, &(stacks->b_len));
}
