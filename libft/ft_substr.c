/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:40:38 by gjailbir          #+#    #+#             */
/*   Updated: 2022/03/10 17:40:39 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	dest = NULL;
	if (!s)
		return (NULL);
	dest = ft_calloc(len + 1, sizeof(char));
	if (dest == 0)
		return (NULL);
	if (ft_strlen(s) >= start)
		ft_strlcpy(dest, &s[start], len + 1);
	return (dest);
}
