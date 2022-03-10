/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:36:30 by gjailbir          #+#    #+#             */
/*   Updated: 2022/03/10 17:36:32 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp1;

	if (lst)
	{
		temp = *lst;
		while (temp)
		{
			temp1 = temp->next;
			ft_lstdelone(temp, (*del));
			temp = temp1;
		}
		*lst = NULL;
	}
}
