/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_folders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 18:57:18 by mfrankev          #+#    #+#             */
/*   Updated: 2017/06/15 18:57:25 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		dlist_add(t_struct *args)
{
	t_ls_list		*node;
	struct stat		*new_stat;

	new_stat = (struct stat*)malloc(sizeof(struct stat));
	ft_memmove(new_stat, &args->stat, sizeof(struct stat));
	node = (t_ls_list*)malloc(sizeof(t_ls_list));
	node->folder_name = ft_strndup(args->dirent->d_name,
			args->dirent->d_namlen);
	node->stat = new_stat;
	node->link_val = NULL;
	node->exp_attr = args->exp_attr;
	if (args->link_val[0])
		node->link_val = ft_strdup(args->link_val);
	node->prev = NULL;
	node->next = NULL;
	if (args->queue == NULL)
		args->queue = node;
	else
	{
		(args->queue)->prev = node;
		node->next = args->queue;
		args->queue = node;
	}
	return ;
}

static void	open_folder(const char *folder, const char *path_to_fold,\
											t_args *ar)
{
	t_struct		args;
	char			*tmp_name;
	static int		line_feed = 0;

	ft_bzero(&args, sizeof(args));
	args.name = construct_full_name(folder, path_to_fold);
	if ((args.dir = opendir(args.name)) == NULL)
	{
		error_open_fold(&args);
		return ;
	}
	if (line_feed)
		ft_putchar('\n');
	if (path_to_fold != NULL || line_feed++ || ar->files || ar->folders->next)
		ft_printf("%s:\n", args.name);
	while ((args.dirent = readdir(args.dir)))
		if (args.dirent->d_name[0] != '.' || g_flag_a)
		{
			tmp_name = construct_full_name(args.dirent->d_name, args.name);
			lstat(tmp_name, &args.stat);
			expanded_attr(tmp_name, &args);
			free(tmp_name);
			dlist_add(&args);
		}
	print_dlist(&args.queue, ar, &args);
}

void		print_dlist(t_ls_list **head, t_args *info, t_struct *args)
{
	t_ls_list		*crawler;
	t_list			*rec_lst;
	t_out_lengths	len;

	rec_lst = NULL;
	if (!g_flag_f)
		quicksort_dlist(*head);
	finding_length(&len, *head);
	crawler = *head;
	if (crawler && g_flag_l)
		ft_printf("total %lu\n", len.block_count);
	while (crawler)
	{
		print_line(crawler, &len);
		if (g_flag_big_r && N_PR && S_ISDIR(crawler->stat->st_mode))
			ft_lstpushback(&rec_lst, ft_lstnew(crawler->folder_name, \
			ft_strchr(crawler->folder_name, '\0') - crawler->folder_name + 1));
		crawler = crawler->next;
	}
	recirsion_open_folders(&rec_lst, info, args);
	del_ls_struct(args);
	return ;
}

void		recirsion_open_folders(t_list **head, t_args *info, t_struct *args)
{
	t_list *rec_lst;

	rec_lst = *head;
	if (rec_lst)
		while (rec_lst)
		{
			open_folder((char*)rec_lst->content, args->name, info);
			rec_lst = rec_lst->next;
		}
	ft_lstdel(head, ft_free_bzero);
	return ;
}

void		proceed_folders(t_args *args)
{
	t_list *head;

	head = args->folders;
	while (args->folders)
	{
		open_folder(args->folders->content, NULL, args);
		args->folders = args->folders->next;
	}
	ft_lstdel(&head, ft_free_bzero);
	return ;
}
