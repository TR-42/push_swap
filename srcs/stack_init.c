/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:32:52 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/12 23:38:40 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/atoi_strict.h"
#include "../headers/stack.h"

#include "../libft/ft_is/ft_is.h"
#include "../libft/ft_vect/ft_vect.h"

#include <stdio.h>

static bool	push_back_when_valid_num(t_vect *vect, int value)
{
	size_t	i;

	i = 0;
	while (i < vect->len)
		if (*(int *)vect_at(vect, i++) == value)
			return (false);
	vect_push_back(vect, &value, NULL);
	return (true);
}

bool	init_stack_from_str(const char *str, t_stacks *stacks)
{
	t_vect		vect;
	int			value;

	(void)stacks;
	if (!(ft_isspace(*str) || ft_isdigit(*str) || *str == '-' || *str == '+'))
		return (false);
	vect = vect_init(16, sizeof(int));
	if (vect.p == NULL)
		return (false);
	while (*str != '\0')
	{
		while (ft_isspace(*str))
			str++;
		if (!atoi_strict(str, &str, &value)
			|| (*str != '\0' && !ft_isspace(*str))
			|| !push_back_when_valid_num(&vect, value))
		{
			vect_dispose(&vect);
			return (false);
		}
	}
	value = 0;
	while (value < (int)(vect.len))
	{
		printf("[%2d]:%10d\n", value, *(int *)vect_at(&vect, value));
		value++;
	}
	// *stacks = init_stack((int *)(vect.p), vect.len);
	vect_dispose(&vect);
	return (true);
}

t_stacks	init_stack(int *values, size_t count)
{
	t_stacks	stack;

	(void)values;
	(void)count;
	stack.a = NULL;
	stack.a_bottom = NULL;
	stack.a_len = 0;
	stack.b = NULL;
	stack.b_bottom = NULL;
	stack.b_len = 0;
	return (stack);
}
