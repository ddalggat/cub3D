/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:40:30 by gjailbir          #+#    #+#             */
/*   Updated: 2022/03/10 17:40:31 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char	*new_str;
	size_t	rev_size;

	if (!str)
		return (NULL);
	while (ft_strchr(set, *str) && *str)
		str++;
	rev_size = ft_strlen(str);
	while (ft_strchr(set, str[rev_size - 1]) && *str)
		rev_size--;
	new_str = ft_substr(str, 0, rev_size);
	return (new_str);
}
