/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:35:35 by mfrankev          #+#    #+#             */
/*   Updated: 2017/02/12 19:14:29 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_c(t_ident *ident, int letter)
{
	if (ident->min_field > 1 && ident->f_o && !ident->f_lj)
		ft_symbols_p('0', ident->min_field - 1);
	if (!ident->f_lj && ident->min_field > 1 && !ident->f_o)
		ft_symbols_p(' ', ident->min_field - 1);
	write(1, &letter, 1);
	g_count++;
	if (ident->f_lj && ident->min_field > 1)
		ft_symbols_p(' ', ident->min_field - 1);
}

void	print_big_c(t_ident *ident, wchar_t letter)
{
	if (ident->min_field > 1 && ident->f_o && !ident->f_lj)
		ft_symbols_p('0', ident->min_field - 1);
	if (!ident->f_lj && ident->min_field > 1 && !ident->f_o)
		ft_symbols_p(' ', ident->min_field - 1);
	write(1, &letter, 1);
	g_count++;
	if (ident->f_lj && ident->min_field > 1)
		ft_symbols_p(' ', ident->min_field - 1);
}
