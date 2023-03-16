/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_coordinate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:57:27 by kfujita           #+#    #+#             */
/*   Updated: 2023/03/16 09:39:47 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/compress_coordinate.h"
#include "../headers/ft_sort.h"

#include "../libft/ft_mem/ft_mem.h"

// - malloc
// - free
#include <stdlib.h>

// - INT_MIN
#include <limits.h>

static int	compar(const void *a, const void *b)
{
	int	ia;
	int	ib;

	ia = *(int *)a;
	ib = *(int *)b;
	if (ia == ib)
		return (0);
	else if (ia < ib)
		return (-1);
	else
		return (1);
}

static size_t	_get_index(int key, const int *base, size_t len)
{
	size_t	base_i;
	size_t	needle;

	needle = len / 2;
	base_i = 0;
	while (base[needle] != key)
	{
		if (key < base[needle])
		{
			len = needle;
		}
		else
		{
			base_i += needle + 1;
			base += needle + 1;
			len -= needle + 1;
		}
		needle = len / 2;
	}
	return (base_i + needle);
}

bool	compress_coordinate(int *arr, size_t len)
{
	int		*sorted;
	size_t	i;

	sorted = malloc(sizeof(int) * len);
	if (sorted == NULL)
		return (false);
	ft_memcpy(sorted, arr, sizeof(int) * len);
	ft_qsort(sorted, len, sizeof(int), compar);
	i = 0;
	while (i < len)
	{
		*arr = INT_MIN + _get_index(*arr, sorted, len);
		arr++;
		i++;
	}
	free(sorted);
	return (true);
}
