/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:13:55 by mfrankev          #+#    #+#             */
/*   Updated: 2017/06/15 19:14:06 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		parse_rights(t_output *out, t_ls_list *node)
{
	specify_filetype(out, node->stat);
	out->rights[1] = (node->stat->st_mode & S_IRUSR) ? 'r' : '-';
	out->rights[2] = (node->stat->st_mode & S_IWUSR) ? 'w' : '-';
	out->rights[3] = (node->stat->st_mode & S_IXUSR) ? 'x' : '-';
	if (out->rights[3] == 'x' && S_ISUID & node->stat->st_mode)
		out->rights[3] = 's';
	else if (S_ISUID & node->stat->st_mode)
		out->rights[3] = 'S';
	out->rights[4] = (node->stat->st_mode & S_IRGRP) ? 'r' : '-';
	out->rights[5] = (node->stat->st_mode & S_IWGRP) ? 'w' : '-';
	out->rights[6] = (node->stat->st_mode & S_IXGRP) ? 'x' : '-';
	if (out->rights[6] == 'x' && S_ISGID & node->stat->st_mode)
		out->rights[6] = 's';
	else if (S_ISGID & node->stat->st_mode)
		out->rights[6] = 'S';
	out->rights[7] = (node->stat->st_mode & S_IROTH) ? 'r' : '-';
	out->rights[8] = (node->stat->st_mode & S_IWOTH) ? 'w' : '-';
	out->rights[9] = (node->stat->st_mode & S_IXOTH) ? 'x' : '-';
	if (out->rights[9] == 'x' && S_ISVTX & node->stat->st_mode)
		out->rights[9] = 't';
	else if (S_ISVTX & node->stat->st_mode)
		out->rights[9] = 'T';
	out->rights[10] = node->exp_attr == 1 ? '+' : '\0';
	out->rights[10] = node->exp_attr == 2 ? '@' : out->rights[10];
	out->rights[11] = '\0';
}

static void		parse_user_group(t_output *out, struct stat *st)
{
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(st->st_uid);
	gr = getgrgid(st->st_gid);
	ft_memmove(out->owner, pw->pw_name, ft_strlen(pw->pw_name) + 1);
	ft_memmove(out->group, gr->gr_name, ft_strlen(gr->gr_name) + 1);
}

static void		parse_time(t_output *out, struct stat *st)
{
	char	*file_time;
	char	*cur_time;
	time_t	cur_t;

	time(&cur_t);
	if (g_flag_u)
		file_time = ctime(&st->st_atimespec.tv_sec);
	else if (g_flag_big_u)
		file_time = ctime(&st->st_birthtimespec.tv_sec);
	else
		file_time = ctime(&st->st_mtimespec.tv_sec);
	file_time = ft_strdup(file_time);
	cur_time = ctime(&cur_t);
	if (!ft_strncmp(&file_time[20], &cur_time[20], 4))
		ft_memmove(out->date, &file_time[4], 12);
	else
	{
		ft_memmove(out->date, &file_time[4], 6);
		ft_memmove(&out->date[6], "  ", 2);
		ft_memmove(&out->date[8], &file_time[20], 4);
	}
	out->date[12] = '\0';
	free(file_time);
	return ;
}

static void		print_long(t_ls_list *node, t_out_lengths *len)
{
	t_output out;

	parse_time(&out, node->stat);
	parse_filesize_devnums(&out, node->stat);
	parse_rights(&out, node);
	parse_user_group(&out, node->stat);
	out.links_count = (int)node->stat->st_nlink;
	ft_memmove(out.filename, node->folder_name, ft_strlen(node->folder_name)\
	+ 1);
	if (out.rights[0] == 'l')
	{
		ft_memmove(&out.filename[ft_strlen(out.filename)], " -> \0", 5);
		ft_memmove(&out.filename[ft_strlen(out.filename)],
				node->link_val, ft_strlen(node->link_val) + 1);
	}
	if (g_flag_big_g)
	{
		color_output(node, len, &out);
		return ;
	}
	ft_printf("%-11s %*d %-*s  %-*s  %*s %s %s\n", out.rights,\
	len->link_len, out.links_count, len->own_len, out.owner, len->group_len, \
	out.group, len->file_size_len, out.size, out.date, out.filename);
	return ;
}

void			print_line(t_ls_list *node, t_out_lengths *len)
{
	if (g_flag_l)
		print_long(node, len);
	else
	{
		if (g_flag_1 || !len->columns)
		{
			ft_putstr(node->folder_name);
			ft_putchar('\n');
		}
		else
			print_columns(node, len);
	}
}
