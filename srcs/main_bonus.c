/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:50:27 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/19 02:55:42 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/exec_stack_ctrl_bonus.h"
#include "../headers/parse_arg.h"
#include "../headers/stack.h"

#include "../libft/gnl/get_next_line.h"
#include "../libft/ft_printf/ft_printf.h"

// - EXIT_FAILURE
// - EXIT_SUCCESS
#include <stdlib.h>

// - STDIN_FILENO
// - STDOUT_FILENO
// - write
#include <unistd.h>

#define STR_OK ("OK\n")
#define STR_KO ("KO\n")

static void	print_i_count(size_t i_count);

static void	print_result_and_dispose(bool is_err,
	t_stacks *stacks, t_gnl_state *gnl_state, size_t i_count)
{
	if (is_err)
		print_error();
	else if (stack_is_sorted(stacks))
		write(STDOUT_FILENO, STR_OK, sizeof(STR_OK));
	else
		write(STDOUT_FILENO, STR_KO, sizeof(STR_KO));
	print_i_count(i_count);
	dispose_gnl_state(gnl_state);
	dispose_stack(stacks);
}

int	main(int argc, const char *argv[])
{
	t_stacks	stacks;
	t_gnl_state	gnl_state;
	char		*instruction;
	size_t		i_count;
	bool		is_err;

	if (!parse_arg(argc, argv, &stacks))
		return (EXIT_FAILURE);
	gnl_state = gen_gnl_state(STDIN_FILENO, 16);
	i_count = 0;
	is_err = false;
	while (is_err != true)
	{
		instruction = get_next_line(&gnl_state);
		if (instruction == NULL)
			break ;
		is_err = !exec_stack_ctrl(instruction, &stacks);
		i_count++;
		free(instruction);
	}
	print_result_and_dispose(is_err, &stacks, &gnl_state, i_count);
	if (is_err)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

#if DEBUG

__attribute__((destructor))
static void	destructor(void) {
	system("leaks -q checker");
}

#endif

#if TEST

static void	print_i_count(size_t i_count)
{
	ft_dprintf(STDERR_FILENO, "i_count: %p (maybe: %u)\n",
		i_count, (unsigned int)i_count);
}

#else

static void	print_i_count(size_t i_count)
{
	(void)i_count;
}

#endif
