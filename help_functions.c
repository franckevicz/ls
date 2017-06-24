/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:19:20 by mfrankev          #+#    #+#             */
/*   Updated: 2017/06/15 19:19:28 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		is_folder(const char *name)
{
	struct stat path_stat;

	lstat(name, &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

char	*construct_full_name(const char *folder, const char *path)
{
	char *result;
	char *tmp;

	if (path == NULL)
		return (ft_strdup(folder));
	result = (char*)malloc(ft_strlen(folder) + ft_strlen(path) + 2);
	tmp = result;
	while (*path)
		*result++ = *path++;
	*result++ = '/';
	while (*folder)
		*result++ = *folder++;
	*result = '\0';
	return (tmp);
}

void	finding_length(t_out_lengths *len, t_ls_list *crawler)
{
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	ft_bzero(len, sizeof(*len));
	while (crawler)
	{
		len->block_count += crawler->stat->st_blocks;
		if (ft_strlen(getpwuid(crawler->stat->st_uid)->pw_name) > len->own_len)
			len->own_len = ft_strlen(getpwuid(crawler->stat->st_uid)->pw_name);
		ft_strlen(getgrgid(crawler->stat->st_gid)->gr_name);
		if (GR_LEN > len->group_len)
			len->group_len = GR_LEN;
		if (len_of_st((size_t)crawler->stat->st_size) > len->file_size_len)
			len->file_size_len = len_of_st((size_t)crawler->stat->st_size);
		if (S_ISBLK(crawler->stat->st_mode) || S_ISCHR(crawler->stat->st_mode))
			len->file_size_len = 8;
		if (len_of_st((size_t)crawler->stat->st_nlink) > len->link_len)
			len->link_len = len_of_st((size_t)crawler->stat->st_nlink);
		if (ft_strlen(crawler->folder_name) > len->filename_len)
			len->filename_len = ft_strlen(crawler->folder_name);
		crawler = crawler->next;
	}
	len->columns = w.ws_col / (len->filename_len + SPACES);
}

void	specify_filetype(t_output *out, struct stat *stat)
{
	if (S_ISREG(stat->st_mode))
		out->rights[0] = '-';
	else if (S_ISDIR(stat->st_mode))
		out->rights[0] = 'd';
	else if (S_ISBLK(stat->st_mode))
		out->rights[0] = 'b';
	else if (S_ISCHR(stat->st_mode))
		out->rights[0] = 'c';
	else if (S_ISFIFO(stat->st_mode))
		out->rights[0] = 'p';
	else if (S_ISLNK(stat->st_mode))
		out->rights[0] = 'l';
	else if (S_ISSOCK(stat->st_mode))
		out->rights[0] = 's';
}

void	expanded_attr(char *path, t_struct *args)
{
	char		tmp[1];
	acl_t		acl;
	acl_entry_t	dummy;

	acl = NULL;
	if (S_ISLNK(args->stat.st_mode))
		readlink(path, args->link_val, 1024);
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	if (listxattr(path, tmp, 0, 0) > 0)
		args->exp_attr = 2;
	else if (acl != NULL)
		args->exp_attr = 1;
	else
		args->exp_attr = 0;
	return ;
}
