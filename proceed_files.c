/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 18:55:42 by mfrankev          #+#    #+#             */
/*   Updated: 2017/06/15 18:55:49 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	add_file_to_list(t_ls_list **files, char *file)
{
	t_ls_list		*node;
	char			tmp[1000];
	struct stat		*new_stat;

	new_stat = (struct stat*)malloc(sizeof(struct stat));
	lstat(file, new_stat);
	node = (t_ls_list*)malloc(sizeof(t_ls_list));
	ft_bzero(node, sizeof(*node));
	node->folder_name = ft_strdup(file);
	node->stat = new_stat;
	if (S_ISLNK(new_stat->st_mode))
	{
		readlink(file, tmp, 1000);
		node->link_val = ft_strdup(tmp);
	}
	if (*files == NULL)
		*files = node;
	else
	{
		(*files)->prev = node;
		node->next = *files;
		*files = node;
	}
	return ;
}

void		add_link_to_list(char *link, struct stat *st, t_args *args)
{
	char readlnk[1024];
	char *tmp;
	char *out;

	readlink(link, readlnk, 1024);
	if (ft_strchr(link, '/'))
	{
		tmp = ft_strndup(link, ft_strrchr(link, '/') - link + 1);
		out = ft_strjoin(tmp, readlnk);
		ft_lstadd(&args->folders, ft_lstnew(out, ft_strlen(out) + 1));
		free(tmp);
		free(out);
	}
	else
	{
		ft_lstadd(&args->folders, ft_lstnew(link, ft_strlen(link) + 1));
	}
	return ;
	if (st)
		;
}

void		proceed_files(t_args *args)
{
	struct stat	filestat;
	t_ls_list	*files;
	t_list		*head_files;
	t_struct	ar;

	files = NULL;
	head_files = args->files;
	ft_bzero(&ar, sizeof(ar));
	while (args->files)
	{
		if ((lstat((char*)args->files->content, &filestat) == -1))
			perror(args->files->content);
		else if (S_ISLNK(filestat.st_mode) && !g_flag_l)
			add_link_to_list((char*)args->files->content, &filestat, args);
		else
			add_file_to_list(&files, args->files->content);
		args->files = args->files->next;
	}
	if (files)
		print_dlist(&files, args, &ar);
	ft_lstdel(&head_files, ft_free_bzero);
	del_ls_list(&files);
	return ;
}

void		error_open_fold(t_struct *args)
{
	perror(args->name);
	free(args->name);
	return (ft_putchar('\n'));
}
