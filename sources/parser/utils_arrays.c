/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arrays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:06:41 by lelle             #+#    #+#             */
/*   Updated: 2022/03/09 20:17:27 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	is_digitstr(char *str)
{
	while (*str != '\0' && ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

int	sym_found(char *str, char *search)
{
	while (*str)
	{
		if (ft_strchr(search, *str) == NULL)
			return (0);
		str++;
	}
	return (1);
}
