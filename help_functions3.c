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

void			wrong_flag(char c)
{
	ft_printf("The flag [%c] is not supported, there is only [afGlrRtuU1]\n", \
	c);
	exit(1);
}

void			print_columns(t_ls_list *node, t_out_lengths *len)
{
	static int count = 1;

	print_color_file(node->stat, node->folder_name, len->filename_len);
	ft_putstr("  ");
	if ((count % (len->columns)) == 0 && count)
		ft_putchar('\n');
	if (!node->next && (count % (len->columns) != 0) && count)
		ft_putchar('\n');
	count++;
	if (!node->next)
		count = 1;
}

void			color_output(t_ls_list *node, t_out_lengths *len, t_output *out)
{
	ft_printf("%-11s %*d %-*s  %-*s  %*s %s ", out->rights,\
	len->link_len, out->links_count, len->own_len, out->owner, len->group_len, \
	out->group, len->file_size_len, out->size, out->date);
	print_color_file(node->stat, out->filename, ft_strlen(out->filename));
	ft_putchar('\n');
}

long			cmp_creation_date(struct s_ls_list *first, \
								struct s_ls_list *second)
{
	long result;

	result = second->stat->st_birthtimespec.tv_sec -\
			first->stat->st_birthtimespec.tv_sec;
	result = result ? result : second->stat->st_birthtimespec.tv_nsec -\
								first->stat->st_birthtimespec.tv_nsec;
	return (result);
}

void			print_color_file(struct stat *st, char *file, int width)
{
	if (!g_flag_big_g)
		ft_printf("%-*s", width, file);
	else if (S_ISLNK(st->st_mode))
		ft_printf(CYN"%-*s"RESET, width, file);
	else if (S_ISDIR(st->st_mode))
		ft_printf(BLU"%-*s"RESET, width, file);
	else if (S_ISFIFO(st->st_mode))
		ft_printf(MAG"%-*s"RESET, width, file);
	else if (S_ISCHR(st->st_mode))
		ft_printf(GRN"%-*s"RESET, width, file);
	else if (S_ISBLK(st->st_mode))
		ft_printf(YEL"%-*s"RESET, width, file);
	else if ((st->st_mode & S_IEXEC))
		ft_printf(RED"%-*s"RESET, width, file);
	else
		ft_printf("%-*s", width, file);
}
