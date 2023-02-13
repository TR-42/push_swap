/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:32:52 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/13 09:49:03 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/atoi_strict.h"
#include "../headers/stack.h"

#include "../libft/ft_is/ft_is.h"
#include "../libft/ft_vect/ft_vect.h"

// - exit
// - EXIT_FAILURE
#include <stdlib.h>

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
	*stacks = init_stack((int *)(vect.p), vect.len);
	stack_print(stacks->a);
	vect_dispose(&vect);
	return (true);
}

t_stacks	init_stack(int *values, size_t count)
{
	t_stacks		stack;
	t_stack_elem	*elem;

	stack.a_bottom = NULL;
	stack.a_len = 0;
	stack.b = NULL;
	stack.b_bottom = NULL;
	stack.b_len = 0;
	while (stack.a_len < count)
	{
		elem = malloc(sizeof(t_stack_elem));
		if (elem == NULL)
			exit(EXIT_FAILURE);
		if (stack.a_bottom == NULL)
			stack.a = elem;
		else
			stack.a_bottom->to_bottom = elem;
		elem->to_top = stack.a_bottom;
		elem->to_bottom = NULL;
		elem->value = values[(stack.a_len)++];
		stack.a_bottom = elem;
	}
	return (stack);
}