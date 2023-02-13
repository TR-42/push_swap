/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:40:11 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/13 09:11:54 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

#include "../libft/ft_put/ft_put.h"

// - EXIT_FAILURE
// - EXIT_SUCCESS
#include <stdlib.h>

// - write
// - STDERR_FILENO
#include <unistd.h>

// - bool
// - true / false
#include <stdbool.h>

#define ERROR_MSG ("Error\n")

static bool	parse_arg(int argc, char *const *argv, t_stacks *stacks)
{
	if (argc <= 1)
		return (false);
	if (argc != 2 || argv == NULL || argv[1] == NULL || argv[1][0] == '\0')
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		return (false);
	}
	if (!init_stack_from_str(argv[1], stacks))
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		return (false);
	}
	return (true);
}

int	main(int argc, char *const *argv)
{
	t_stacks	stacks;

	if (!parse_arg(argc, argv, &stacks))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}