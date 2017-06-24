/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:55:27 by mfrankev          #+#    #+#             */
/*   Updated: 2017/02/15 18:29:49 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_printf(const char *format, ...)
{
	va_list args;
	t_ident *ident;

	g_count = 0;
	ident = (t_ident*)malloc(sizeof(ident));
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			parse_flags(&format, ident);
			parse_width_prec(&format, ident, &args);
			parse_modifier_conv(&format, ident);
			identifier(&args, ident);
		}
		else
		{
			ft_putchar(*format);
			format++;
		}
	}
	free(ident);
	return (g_count++);
}

void	identifier(va_list *args, t_ident *ident)
{
	if (ident->c == 'd' || ident->c == 'i')
		print_d(ident, args);
	else if (ident->c == 'U' || ident->c == 'D' || ident->c == 'O')
		forgotten_conv(ident, args);
	else if (ident->c == 'u' || ident->c == 'o')
		print_unsigned_octal(ident, args, (ident->c == 'o' ? 8 : 10));
	else if (ident->c == 's' || ident->c == 'S')
		print_string(ident, va_arg(*args, char*));
	else if (ident->c == 'p')
		print_p(ident, ft_ultoa(va_arg(*args, long int), 16));
	else if (ident->c == 'x' || ident->c == 'X')
		print_unsigned_hexal(ident, args, 16);
	else if (ident->c == '%')
		print_simple_num(ident, "%");
	else if (ident->c == 'c')
		print_c(ident, (va_arg(*args, int)));
	else if (ident->c == 'C')
		print_big_c(ident, (va_arg(*args, wchar_t)));
	else if (ident->c == 'n')
		*(va_arg(*args, unsigned int*)) = g_count;
	else if (ident->c)
		print_c(ident, ident->c);
}
