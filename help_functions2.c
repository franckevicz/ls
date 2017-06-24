/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:17:56 by mfrankev          #+#    #+#             */
/*   Updated: 2017/06/15 19:17:59 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int			len_of_st(size_t num)
{
	int i;

	i = 0;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void		del_ls_struct(t_struct *struc)
{
	del_ls_list(&(struc)->queue);
	if ((struc)->name)
		free((struc)->name);
	if (struc->dir)
		closedir(struc->dir);
	return ;
}

void		del_ls_list(t_ls_list **head)
{
	t_ls_list *prev;
	t_ls_list *crawler;

	crawler = *head;
	while (crawler)
	{
		prev = crawler;
		crawler = crawler->next;
		free(prev->folder_name);
		free(prev->stat);
		free(prev->link_val);
		free(prev);
	}
	*head = NULL;
	return ;
}

void		device_nums_parse(t_output *out, struct stat *st)
{
	size_t	i;
	size_t	minor_len;
	size_t	major_len;
	char	*major;
	char	*minor;

	i = 0;
	major = ft_itoa(major(st->st_rdev));
	minor = ft_itoa(minor(st->st_rdev));
	minor_len = ft_strlen(minor);
	major_len = ft_strlen(major);
	ft_memmove(out->size, major, major_len + 1);
	out->size[major_len] = ',';
	while (minor_len + i < 5)
		out->size[major_len + ++i] = ' ';
	ft_memmove(&out->size[major_len + i], minor, minor_len + 1);
	free(minor);
	free(major);
	return ;
}

void		parse_filesize_devnums(t_output *out, struct stat *st)
{
	char *tmp;

	if (S_ISCHR(st->st_mode) || S_ISBLK(st->st_mode))
	{
		device_nums_parse(out, st);
	}
	else
	{
		tmp = ft_itoa(st->st_size);
		ft_memmove(out->size, tmp, ft_strlen(tmp) + 1);
		free(tmp);
	}
}
