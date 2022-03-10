/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:37:06 by gjailbir          #+#    #+#             */
/*   Updated: 2022/03/10 17:37:07 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*first;

	if (!lst || !(*f))
		return (NULL);
	first = NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			while (first)
			{
				temp = (first)->next;
				(*del)((first)->content);
				free(first);
				first = temp;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, temp);
		lst = lst->next;
	}
	return (first);
}
