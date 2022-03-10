/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:39:54 by gjailbir          #+#    #+#             */
/*   Updated: 2022/03/10 17:39:56 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *source, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;

	i = 0;
	if (!source)
		return (NULL);
	dest = ft_calloc(ft_strlen(source) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (source[i] != '\0')
	{
		dest[i] = (*f)(i, source[i]);
		i++;
	}
	return (dest);
}
