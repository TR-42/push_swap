/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:54:59 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/19 04:45:54 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_SORT_H
# define STACK_SORT_H

# include "../headers/stack.h"

// - bool
# include <stdbool.h>

bool	_sort_if_3(t_stacks *stacks);
bool	stack_sort_small(t_stacks *stacks);

bool	stack_sort_qsort(t_stacks *stacks);

#endif