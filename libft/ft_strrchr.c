/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:40:20 by gjailbir          #+#    #+#             */
/*   Updated: 2022/03/10 17:40:21 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*p_str;

	p_str = (char *)str;
	i = 0;
	while (p_str[i])
		i++;
	while (i >= 0)
	{
		if (p_str[i] == c)
			return (&p_str[i]);
		i--;
	}
	return ((char *) NULL);
}
