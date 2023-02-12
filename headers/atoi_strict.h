/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_strict.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:14:07 by kfujita           #+#    #+#             */
/*   Updated: 2023/02/12 23:13:38 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOI_STRICT_H
# define ATOI_STRICT_H

# include <stdbool.h>

bool	atoi_strict(const char *str, const char **endptr, int *dst);

#endif
