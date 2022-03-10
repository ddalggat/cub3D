/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:38:17 by gjailbir          #+#    #+#             */
/*   Updated: 2022/03/10 17:38:18 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t i)
{
	char	*temp;

	temp = (char *)b;
	while (i > 0)
	{
		*temp = c;
		temp++;
		i--;
	}
	return (b);
}
