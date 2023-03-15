/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:40:11 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/16 00:31:17 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/compress_coordinate.h"
#include "../headers/ft_sort.h"
#include "../headers/parse_arg.h"
#include "../headers/stack_op_log.h"
#include "../headers/stack_sort.h"
#include "../headers/stack.h"

#include "../libft/ft_put/ft_put.h"

// - EXIT_FAILURE
// - EXIT_SUCCESS
#include <stdlib.h>

// (for debug)
// - getpid
// - system
#include <unistd.h>

// (for debug)
// - sprintf
#include <stdio.h>

int	main(int argc, const char *argv[])
{
	t_stacks	stacks;
	t_vect		op_log;

	if (!parse_arg(argc, argv, &stacks))
		return (EXIT_FAILURE);
	if (!compress_coordinate(stacks.a, stacks.a_len))
	{
		print_error();
		return (EXIT_FAILURE);
	}
	op_log = vect_init(100, sizeof(t_stack_op_num));
	(stack_is_sorted(&stacks)
		|| stack_sort_small(&stacks, &op_log)
		|| stack_sort_qsort(&stacks, &op_log));
	stack_op_log_print(&op_log);
	vect_dispose(&op_log);
	dispose_stack(&stacks);
	return (EXIT_SUCCESS);
}

#if DEBUG

# define DEBUG_LEAKS_CMD_LEN (32)

__attribute__((destructor))
static void	destructor(void) {
	char	cmd[DEBUG_LEAKS_CMD_LEN];

	snprintf(cmd, DEBUG_LEAKS_CMD_LEN, "leaks %d", getpid());
	system(cmd);
}

#endif
