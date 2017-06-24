/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:02:14 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/28 12:39:34 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*elem_first;

	if (lst == NULL)
		return (NULL);
	elem = f(lst);
	elem_first = elem;
	lst = lst->next;
	while (lst)
	{
		elem->next = f(lst);
		lst = lst->next;
		elem = elem->next;
	}
	return (elem_first);
}
