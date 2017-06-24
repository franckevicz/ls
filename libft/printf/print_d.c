/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:05:15 by mfrankev          #+#    #+#             */
/*   Updated: 2017/02/12 19:14:26 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_d(t_ident *ident, va_list *args)
{
	t_number num;

	if (ident->modifier == 0)
	{
		num.ll = va_arg(*args, int);
		if (num.i < 0)
			ident->is_negativ = 1;
		print_n(ident, ft_ultoa(((num.ll < 0) ? -num.ll : num.ll), 10));
	}
	else if (ident->modifier == J || ident->modifier == Z || \
			ident->modifier == DL || ident->modifier == L)
	{
		num.ll = va_arg(*args, long long int);
		if (num.ll < 0)
			ident->is_negativ = 1;
		print_n(ident, ft_ultoa(((num.ll < 0) ? -num.ll : num.ll), 10));
	}
	else
		print_decider2(num, ident, args);
}

void	print_decider2(t_number num, t_ident *ident, va_list *args)
{
	if (ident->modifier == H)
	{
		num.s = (short)va_arg(*args, int);
		if (num.s < 0)
			ident->is_negativ = 1;
		print_n(ident, ft_ultoa(((num.s < 0) ? -num.s : num.s), 10));
	}
	else if (ident->modifier == DH)
	{
		num.c = (char)va_arg(*args, int);
		if (num.c < 0)
			ident->is_negativ = 1;
		print_n(ident, ft_ultoa(((num.c < 0) ? -num.c : num.c), 10));
	}
}

void	forgotten_conv(t_ident *ident, va_list *args)
{
	t_number num;

	if (ident->c == 'D')
	{
		num.ll = va_arg(*args, long long int);
		if (num.ll < 0)
			ident->is_negativ = 1;
		print_n(ident, ft_ultoa(((num.ll < 0) ? -num.ll : num.ll), 10));
	}
	if (ident->c == 'U')
	{
		num.ul = (unsigned long)va_arg(*args, unsigned long);
		print_simple_num(ident, ft_ultoa(num.ul, 10));
	}
	if (ident->c == 'O')
	{
		num.ul = (unsigned long)va_arg(*args, unsigned long);
		print_num_o(ident, ft_ultoa(num.ul, 8));
	}
}

void	print_unsigned_octal(t_ident *ident, va_list *args, char base)
{
	t_number number;

	if (ident->modifier == J || ident->modifier == Z || \
			ident->modifier == DL || ident->modifier == L)
	{
		number.ll = va_arg(*args, unsigned long long int);
		print_num_o(ident, ft_ultoa(number.ull, base));
	}
	else if (ident->modifier == H)
	{
		number.us = (unsigned short)va_arg(*args, unsigned int);
		print_num_o(ident, ft_ultoa(number.us, base));
	}
	else if (ident->modifier == DH)
	{
		number.uc = (unsigned char)va_arg(*args, unsigned int);
		print_num_o(ident, ft_ultoa(number.uc, base));
	}
	else
		print_num_o(ident, ft_ultoa(va_arg(*args, unsigned int), base));
}

void	print_unsigned_hexal(t_ident *ident, va_list *args, char base)
{
	t_number number;

	if (ident->modifier == J || ident->modifier == Z || \
			ident->modifier == DL || ident->modifier == L)
	{
		number.ll = va_arg(*args, unsigned long long int);
		print_simple_num(ident, ft_ultoa(number.ull, base));
	}
	else if (ident->modifier == H)
	{
		number.us = (unsigned short)va_arg(*args, unsigned int);
		print_simple_num(ident, ft_ultoa(number.us, base));
	}
	else if (ident->modifier == DH)
	{
		number.uc = (unsigned char)va_arg(*args, unsigned int);
		print_simple_num(ident, ft_ultoa(number.uc, base));
	}
	else
		print_simple_num(ident, ft_ultoa(va_arg(*args, unsigned int), base));
}
