/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:02:02 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/19 02:06:17 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARG_H
# define PARSE_ARG_H

# include "../headers/stack.h"

// - bool
# include <stdbool.h>

bool	print_error(void);

bool	parse_arg(int argc, const char *argv[], t_stacks *stacks);

#endif
