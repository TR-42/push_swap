/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:01:54 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/19 02:07:59 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parse_arg.h"

// - STDERR_FILENO
#include <unistd.h>

#define ERROR_MSG ("Error\n")

bool	print_error(void)
{
	write(STDERR_FILENO, ERROR_MSG, sizeof(ERROR_MSG));
	return (true);
}

bool	parse_arg(int argc, const char *argv[], t_stacks *stacks)
{
	if (argc <= 1)
		return (false);
	if (argv == NULL)
		return (print_error() && false);
	if (!init_stack_from_str_arr(argv + 1, argc - 1, stacks))
		return (print_error() && false);
	return (true);
}
