/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dispose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 06:52:13 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/18 06:59:01 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

// - free
// - NULL
#include <stdlib.h>

void	dispose_stack(t_stacks *stacks)
{
	if (stacks == NULL)
		return ;
	free(stacks->a);
	free(stacks->b);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->a_len = 0;
	stacks->b_len = 0;
}
