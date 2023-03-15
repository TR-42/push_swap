/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:54:59 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/16 00:30:05 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_SORT_H
# define STACK_SORT_H

# include "../headers/stack.h"

// - bool
# include <stdbool.h>

bool	_sort_if_3(t_stacks *s, size_t a_len, bool is_b_1to9,
			t_vect *log_vect);
bool	stack_sort_small(t_stacks *stacks, t_vect *log_vect);

bool	stack_sort_qsort(t_stacks *stacks, t_vect *log_vect);

#endif
