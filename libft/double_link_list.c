/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:06:01 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/15 11:27:39 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_add_elem(t_lst **head, int data)
{
	t_lst	*elem;
	t_lst	*prev;

	elem = (t_lst*)malloc(sizeof(t_lst));
	elem->val = data;
	if (*head)
	{
		prev = (*head)->prev;
		elem->next = *head;
		elem->prev = prev;
		prev->next = elem;
		(*head)->prev = elem;
	}
	else
	{
		elem->next = elem;
		elem->prev = elem;
	}
	*head = elem;
	return ;
}

void	lst_del_elem(t_lst **elem)
{
	t_lst *next;
	t_lst *prev;

	if (*elem == NULL)
		return ;
	next = (*elem)->next;
	prev = (*elem)->prev;
	prev->next = next;
	next->prev = prev;
	free(*elem);
	if (next == *elem)
		*elem = NULL;
	else
		*elem = next;
	return ;
}

void	lst_push_back(t_lst **head, int data)
{
	t_lst *elem;
	t_lst *prev;

	g_count++;
	if (!(*head))
		lst_add_elem(head, data);
	else
	{
		prev = (*head)->prev;
		elem = (t_lst*)malloc(sizeof(t_lst));
		elem->val = data;
		elem->next = (*head);
		elem->prev = prev;
		prev->next = elem;
		(*head)->prev = elem;
	}
	return ;
}

int		lst_is_nsorted(t_lst *head, int n)
{
	int		tmp;
	t_lst	*cur;

	if (n <= 1)
		return (1);
	cur = head;
	tmp = cur->val;
	cur = cur->next;
	if (tmp > cur->val)
		return (0);
	while (cur->next != head && --n > 1)
	{
		tmp = cur->val;
		cur = cur->next;
		if (tmp > cur->val)
			return (0);
	}
	return (1);
}

int		lst_is_nrev_sorted(t_lst *head, int n)
{
	int		tmp;
	t_lst	*cur;

	if (n <= 1)
		return (1);
	cur = head;
	tmp = cur->val;
	cur = cur->next;
	if (tmp < cur->val)
		return (0);
	while (cur->next != head && --n > 1)
	{
		tmp = cur->val;
		cur = cur->next;
		if (tmp < cur->val)
			return (0);
	}
	return (1);
}
