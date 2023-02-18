/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:40:11 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/19 02:05:21 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_sort.h"
#include "../headers/parse_arg.h"
#include "../headers/stack.h"

#include "../libft/ft_put/ft_put.h"

// - EXIT_FAILURE
// - EXIT_SUCCESS
#include <stdlib.h>

// - system
#include <unistd.h>

int	compar(const void *a, const void *b)
{
	return ((*(V_TYPE *)a) - (*(V_TYPE *)b));
}

int	main(int argc, const char *argv[])
{
	t_stacks	stacks;

	if (!parse_arg(argc, argv, &stacks))
		return (EXIT_FAILURE);
	stack_print_all(&stacks);
	ft_qsort(stacks.a, stacks.a_len, sizeof(V_TYPE), compar);
	stack_print_all(&stacks);
	dispose_stack(&stacks);
	return (EXIT_SUCCESS);
}

#if DEBUG

__attribute__((destructor))
static void	destructor(void) {
	system("leaks -q push_swap");
}

#endif
