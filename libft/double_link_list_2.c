/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:06:01 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/15 11:27:52 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del_list(t_lst **head)
{
	while (*head)
		lst_del_elem(head);
	return ;
}

int		*lst_to_array(t_lst *head)
{
	int		*array;
	int		size;
	int		i;
	t_lst	*cur;

	i = 0;
	if (head == NULL)
		return (NULL);
	size = lst_size(head);
	array = (int*)malloc(sizeof(int) * size + 1);
	cur = head;
	array[i++] = (cur ? cur->val : 0);
	if (cur)
		cur = cur->next;
	while (cur != head)
	{
		array[i++] = cur->val;
		cur = cur->next;
	}
	return (array);
}

int		lst_search_val(t_lst *head, int value)
{
	t_lst *elem;

	if (head == NULL)
		return (0);
	elem = head;
	if (elem->val == value)
		return (1);
	elem = elem->next;
	while (elem != head)
	{
		if (elem->val == value)
			return (1);
		elem = elem->next;
	}
	return (0);
}

int		lst_size(t_lst *head)
{
	int		size;
	t_lst	*current;

	size = 0;
	if (head == NULL)
	{
		return (0);
	}
	current = head;
	size = 1;
	while (current->next != head)
	{
		current = current->next;
		size++;
	}
	return (size);
}
