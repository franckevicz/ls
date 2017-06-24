/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:12:02 by mfrankev          #+#    #+#             */
/*   Updated: 2017/06/15 19:12:26 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

unsigned char	g_flag_a = 0;
unsigned char	g_flag_l = 0;
unsigned char	g_flag_r = 0;
unsigned char	g_flag_big_r = 0;
unsigned char	g_flag_t = 0;
unsigned char	g_flag_f = 0;
unsigned char	g_flag_big_g = 0;
unsigned char	g_flag_u = 0;
unsigned char	g_flag_big_u = 0;
unsigned char	g_flag_1 = 0;

int		main(int argc, char **argv)
{
	t_args args;

	ft_bzero(&args, sizeof(args));
	read_args_ls(&args, argc, argv);
	proceed_files(&args);
	proceed_folders(&args);
	return (0);
}
