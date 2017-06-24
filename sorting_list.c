/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:09:58 by mfrankev          #+#    #+#             */
/*   Updated: 2017/06/15 19:10:06 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void				swap_nodes_content(struct s_ls_list *first, \
		struct s_ls_list *second)
{
	struct stat			*tmp_st;
	char				*tmp_name;
	char				*tmp_linkval;
	int					tmp_expattr;

	tmp_expattr = first->exp_attr;
	tmp_st = first->stat;
	tmp_name = first->folder_name;
	tmp_linkval = first->link_val;
	first->link_val = second->link_val;
	first->stat = second->stat;
	first->folder_name = second->folder_name;
	first->exp_attr = second->exp_attr;
	second->stat = tmp_st;
	second->folder_name = tmp_name;
	second->link_val = tmp_linkval;
	second->exp_attr = tmp_expattr;
	return ;
}

static long				cmp_two_nodes(struct s_ls_list *first, \
										struct s_ls_list *second)
{
	long result;

	result = 0;
	if (g_flag_u && g_flag_t)
	{
		result = second->stat->st_atimespec.tv_sec -\
			first->stat->st_atimespec.tv_sec;
		result = result ? result : second->stat->st_atimespec.tv_nsec -\
		first->stat->st_atimespec.tv_nsec;
	}
	else if (g_flag_big_u && g_flag_t)
		result = cmp_creation_date(first, second);
	else if (g_flag_t)
	{
		result = second->stat->st_mtimespec.tv_sec -\
			first->stat->st_mtimespec.tv_sec;
		result = result ? result : second->stat->st_mtimespec.tv_nsec -\
		first->stat->st_mtimespec.tv_nsec;
	}
	result = result ? result : ft_strcmp(first->folder_name,\
										second->folder_name);
	return (g_flag_r ? -result : result);
}

static struct s_ls_list	*partition(struct s_ls_list *head, \
									struct s_ls_list *tail)
{
	t_ls_list *tmp;
	t_ls_list *cur;

	tmp = tail;
	cur = head;
	while (cur != tail)
	{
		if (cmp_two_nodes(tmp, cur) < 0)
		{
			swap_nodes_content(tmp, cur);
			tmp = (tmp ? tail : tmp->prev);
		}
		cur = cur->next;
	}
	tmp = (tmp ? tail : tmp->prev);
	swap_nodes_content(tmp, cur);
	return (tmp);
}

static void				quicksort(struct s_ls_list *head, \
									struct s_ls_list *tail)
{
	t_ls_list *pivot;

	if (head != NULL && head != tail && head != tail->next)
	{
		pivot = partition(head, tail);
		quicksort(head, pivot->prev);
		quicksort(pivot->next, tail);
	}
}

void					quicksort_dlist(struct s_ls_list *head)
{
	t_ls_list *crawler;

	if (head == NULL)
		return ;
	crawler = head;
	while (crawler->next)
		crawler = crawler->next;
	quicksort(head, crawler);
	return ;
}
