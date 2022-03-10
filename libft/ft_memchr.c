/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:37:39 by gjailbir          #+#    #+#             */
/*   Updated: 2022/03/10 17:37:40 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dst, int c, size_t i)
{
	int	a;

	a = (int)i;
	while (i > 0)
	{
		if (*(const unsigned char *)dst == (unsigned char)c)
			return ((char *)dst);
		dst++;
		i--;
	}
	return (NULL);
}
