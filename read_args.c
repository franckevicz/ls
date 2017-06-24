/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:05:29 by mfrankev          #+#    #+#             */
/*   Updated: 2017/06/15 19:05:36 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void			parse_flag2(char flag)
{
	if (flag == 'G')
		g_flag_big_g = TRUE;
	else if (flag == 'u')
		g_flag_u = TRUE;
	else if (flag == 'U')
		g_flag_big_u = TRUE;
	else if (flag == '1')
		g_flag_1 = TRUE;
	else if (flag == 'f')
	{
		g_flag_a = TRUE;
		g_flag_f = TRUE;
	}
	else
		wrong_flag(flag);
}

static void			parse_flag(t_args *args, char *str)
{
	str++;
	if (*str == '\0')
	{
		ft_lstadd(&args->folders, ft_lstnew("-\0", 2));
		return ;
	}
	while (*str)
	{
		if (*str == 'R')
			g_flag_big_r = TRUE;
		else if (*str == 'r')
			g_flag_r = TRUE;
		else if (*str == 't')
			g_flag_t = TRUE;
		else if (*str == 'a')
			g_flag_a = TRUE;
		else if (*str == 'l')
			g_flag_l = TRUE;
		else
			parse_flag2(*str);
		str++;
	}
	return ;
}

static inline void	add_folder(t_args *args, char *str)
{
	ft_lstpushback(&args->folders, ft_lstnew(str, ft_strlen(str) + 1));
}

static inline void	add_file(t_args *args, char *str)
{
	ft_lstpushback(&args->files, ft_lstnew(str, ft_strlen(str) + 1));
}

void				read_args_ls(t_args *args, int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc - 1)
	{
		i++;
		if (!ft_strcmp(argv[i], "--"))
			args->double_dash = TRUE;
		else if (argv[i][0] == '-' && !args->double_dash && \
				!args->folders && !args->files)
			parse_flag(args, argv[i]);
		else if (is_folder(argv[i]))
			add_folder(args, argv[i]);
		else
			add_file(args, argv[i]);
	}
	if (args->folders == NULL && args->files == NULL)
		add_folder(args, ".");
	return ;
}
