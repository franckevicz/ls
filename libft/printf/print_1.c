/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:48:17 by mfrankev          #+#    #+#             */
/*   Updated: 2017/02/15 18:35:24 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_n(t_ident *ident, char *str_nb)
{
	if (ident->is_prec)
		ident->f_o = 0;
	if (ident->is_prec && !(ident->pr) && *str_nb == '0')
		str_nb[0] = '\0';
	if (!ident->f_lj && ident->min_field > ft_strlen(str_nb) && !ident->f_o)
		ft_symbols_p(' ', ident->min_field - MAX(ft_strlen(str_nb), ident->pr)\
	- IS_SIGN);
	if (ident->is_negativ)
		ft_putchar('-');
	else if (!ident->is_negativ && ident->f_p)
		ft_putchar('+');
	else if (!ident->is_negativ && ident->f_s)
		ft_putchar(' ');
	if (!ident->f_lj && ident->min_field > ft_strlen(str_nb) && ident->f_o)
		ft_symbols_p('0', ident->min_field - MAX(ft_strlen(str_nb), ident->pr)\
	- IS_SIGN);
	if ((ident->is_prec || ident->pr < 0) && ft_strlen(str_nb) < ident->pr)
		ft_symbols_p('0', ident->pr - ft_strlen(str_nb));
	ft_putstr(str_nb);
	free(str_nb);
	if (ident->f_lj && ident->min_field > MAX(ft_strlen(str_nb), ident->pr)\
	+ IS_SIGN)
		ft_symbols_p(' ', ident->min_field - MAX(ft_strlen(str_nb), ident->pr)\
	- IS_SIGN);
}

void	print_string(t_ident *ident, char *str)
{
	if (str == NULL)
		str = "(null)";
	str = ft_strdup(str);
	if (ident->is_prec)
		str[ident->pr] = '\0';
	if (ident->min_field > ft_strlen(str) && ident->f_o && !ident->f_lj)
		ft_symbols_p('0', ident->min_field - ft_strlen(str) - IS_SIGN);
	if (!ident->f_lj && !ident->f_o && ident->min_field > ft_strlen(str))
		ft_symbols_p(' ', ident->min_field - ft_strlen(str));
	ft_putstr(str);
	free(str);
	if (ident->f_lj && ident->min_field > ft_strlen(str))
		ft_symbols_p(' ', ident->min_field - ft_strlen(str));
}

void	print_p(t_ident *ident, char *str)
{
	if (ident->is_prec && ident->pr == 0)
		str[ident->pr] = '\0';
	if (!ident->f_lj && ident->min_field > ft_strlen(str))
		ft_symbols_p(' ', ident->min_field - ft_strlen(str) - 2);
	ft_putstr("0x");
	if (ident->is_prec && ft_strlen(str) < ident->pr)
		ft_symbols_p('0', ident->pr - ft_strlen(str));
	if (ident->min_field > ft_strlen(str) && ident->f_o && \
		!ident->is_prec && !ident->f_lj)
		ft_symbols_p('0', ident->min_field - ft_strlen(str) - 2);
	ft_putstr(str);
	if (ident->f_lj && ident->min_field > ft_strlen(str))
		ft_symbols_p(' ', ident->min_field - ft_strlen(str) - 2);
	free(str);
}

void	print_simple_num(t_ident *ident, char *str)
{
	if (ident->is_prec && !(ident->pr) && *str == '0')
	{
		str[0] = '\0';
		ident->f_hash = ((ident->c == 'X' || ident->c == 'x') ? 0 : \
			ident->f_hash);
	}
	ident->is_prec = (*str == '%' ? 0 : ident->is_prec);
	if (!ident->f_lj && ident->min_field > ft_strlen(str) && !ident->f_o)
		ft_symbols_p(' ', ident->min_field - MAX(ft_strlen(str), ident->pr) \
	- IS_SIGN - (ident->f_hash ? 2 : 0));
	if (ident->f_hash && (ident->c == 'x' || ident->c == 'X') && *str != '0')
		ft_putstr((ident->c == 'x' ? "0x" : "0X"));
	if (!ident->f_lj && ident->min_field > ft_strlen(str) && ident->f_o)
		ft_symbols_p('0', ident->min_field - MAX(ft_strlen(str), ident->pr) \
	- IS_SIGN - (ident->f_hash ? 2 : 0));
	if (ident->is_prec && ft_strlen(str) < ident->pr)
		ft_symbols_p('0', ident->pr - ft_strlen(str));
	if (ident->c == 'X')
		str = ft_strtoupper(str, ident);
	ft_putstr(str);
	if (ident->f_lj && ident->min_field > ft_strlen(str))
		ft_symbols_p(S_OR_O, ident->min_field - MAX(ft_strlen(str), ident->pr)\
	- (((ident->c == 'x' || ident->c == 'X') && ident->f_hash) ? 2 : 0));
	if (ft_strchr("sSpdDioOuUxXcC", ident->c))
		free(str);
}

void	print_num_o(t_ident *ident, char *str)
{
	if (ident->is_prec && !(ident->pr) && *str == '0')
		str[0] = '\0';
	ident->is_prec = (*str == '%' ? 0 : ident->is_prec);
	if (!ident->f_lj && ident->min_field > ft_strlen(str) && !ident->f_o)
		ft_symbols_p(' ', ident->min_field - MAX(ft_strlen(str), ident->pr) \
	- IS_SIGN - (ident->f_hash ? 1 : 0));
	if (ident->f_hash && (ident->c == 'o' || ident->c == 'O') && *str != '0')
	{
		ft_putchar('0');
		ident->min_field = (ident->min_field ? ident->min_field - 1 : 0);
	}
	if (!ident->f_lj && ident->min_field > ft_strlen(str) && ident->f_o)
		ft_symbols_p('0', ident->min_field - MAX(ft_strlen(str), ident->pr) \
	- IS_SIGN - (ident->f_hash ? 1 : 0));
	if (ident->is_prec && ft_strlen(str) < ident->pr)
		ft_symbols_p('0', ident->pr - ft_strlen(str) - \
			(ident->f_hash ? 1 : 0));
	ft_putstr(str);
	if (ident->f_lj && ident->min_field > ft_strlen(str))
		ft_symbols_p(' ', ident->min_field - MAX(ft_strlen(str), ident->pr));
	free(str);
}
