/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:39:33 by gjailbir          #+#    #+#             */
/*   Updated: 2022/03/10 17:39:34 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret_value;
	size_t	j;

	i = 0;
	ret_value = 0;
	j = 0;
	while (dst[i] && i < dstsize)
	{
		i++;
		ret_value++;
	}
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = ((char *)src)[j];
		i++;
		j++;
	}
	if (i < dstsize)
		dst[i] = 0;
	return (ft_strlen(src) + ret_value);
}
