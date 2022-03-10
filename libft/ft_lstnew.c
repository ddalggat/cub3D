/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:37:11 by gjailbir          #+#    #+#             */
/*   Updated: 2022/03/10 17:37:12 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list_item;

	new_list_item = malloc(sizeof(t_list));
	if (!new_list_item)
		return (NULL);
	new_list_item->content = content;
	new_list_item->next = NULL;
	return (new_list_item);
}
