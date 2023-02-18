/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:40:11 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/19 04:25:44 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/compress_coordinate.h"
#include "../headers/ft_sort.h"
#include "../headers/parse_arg.h"
#include "../headers/stack_sort.h"
#include "../headers/stack.h"

#include "../libft/ft_put/ft_put.h"

// - EXIT_FAILURE
// - EXIT_SUCCESS
#include <stdlib.h>

// - system
#include <unistd.h>

int	main(int argc, const char *argv[])
{
	t_stacks	stacks;

	if (!parse_arg(argc, argv, &stacks))
		return (EXIT_FAILURE);
	if (!compress_coordinate(stacks.a, stacks.a_len))
	{
		print_error();
		return (EXIT_FAILURE);
	}
	if (!stack_is_sorted(&stacks))
	{
		stack_sort_small(&stacks);
	}
	dispose_stack(&stacks);
	return (EXIT_SUCCESS);
}

#if DEBUG

__attribute__((destructor))
static void	destructor(void) {
	system("leaks -q push_swap");
}

#endif
