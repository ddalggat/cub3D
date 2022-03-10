/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:39:40 by gjailbir          #+#    #+#             */
/*   Updated: 2022/03/10 17:39:41 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	len;

	len = 0;
	if (!src && !dst)
		return (0);
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	while (--dstsize && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}
