/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_coordinate.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:01:42 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/19 04:14:58 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPRESS_COORDINATE_H
# define COMPRESS_COORDINATE_H

// - size_t
# include <stddef.h>

// - bool
# include <stdbool.h>

bool	compress_coordinate(int *arr, size_t len);

#endif
