/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:14:42 by mfrankev          #+#    #+#             */
/*   Updated: 2017/02/12 19:14:31 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	g_base[] = "0123456789abcdef";

void	parse_flags(const char **format, t_ident *ident)
{
	ft_bzero(ident, sizeof(*ident));
	while (**format == '#' || **format == '0' || **format == '-' \
			|| **format == '+' || **format == ' ')
	{
		if (**format == '#')
			ident->f_hash++;
		else if (**format == '0')
			ident->f_o++;
		else if (**format == '-')
			ident->f_lj++;
		else if (**format == '+')
			ident->f_p++;
		else if (**format == ' ')
			ident->f_s++;
		(*format)++;
	}
}

void	parse_modifier_conv(const char **f, t_ident *ident)
{
	char	*flags;
	int		i;

	i = 0;
	while (ft_strchr("jlhz", (*f)[i]) && **f)
		i++;
	flags = ft_strsub(*f, 0, i);
	if (i && ft_strstr(flags, "j"))
		ident->modifier = J;
	else if (i && ft_strstr(flags, "z"))
		ident->modifier = Z;
	else if (i > 1 && ft_strstr(flags, "ll"))
		ident->modifier = DL;
	else if (i && ft_strstr(flags, "l"))
		ident->modifier = L;
	else if (i > 1 && ft_strstr(flags, "hh"))
		ident->modifier = DH;
	else if (i && ft_strstr(flags, "h"))
		ident->modifier = H;
	while (**f == 'j' || **f == 'h' || **f == 'l' || **f == 'z')
		(*f)++;
	free(flags);
	parce_conv(f, ident);
}

void	parse_width_prec(const char **format, t_ident *ident, va_list *args)
{
	if (ft_isdigit(**format) || **format == '*')
	{
		if (**format == '*' && (*format)++)
			ident->min_field = (short)va_arg(*args, int);
		ident->min_field = (ft_isdigit(**format) ? ft_atoi(*format) : \
		ident->min_field);
		while (ft_isdigit(**format))
			(*format)++;
		if (**format == '*' && (*format)++)
			ident->min_field = (short)va_arg(*args, int);
		if (ident->min_field < 0 && ++ident->f_lj)
			ident->min_field *= -1;
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (**format == '.')
		parce_prec(ident, format, args);
}

void	parce_prec(t_ident *ident, const char **format, va_list *args)
{
	(*format)++;
	ident->is_prec++;
	if (ft_isdigit(**format))
		ident->pr = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '*' && (*format)++)
		ident->pr = (unsigned short)va_arg(*args, int);
	if (ident->pr < 0)
	{
		ident->pr = 0;
		ident->is_prec = 0;
	}
}

char	*ft_ultoa(unsigned long int nb, char base)
{
	char					rev[64];
	char					*result;
	int						i;
	unsigned long int		j;

	i = 0;
	j = nb;
	while (j && ++i)
		j /= base;
	result = ft_strnew(i + 1);
	i = 0;
	j = 0;
	if (nb == 0)
		result[j++] = '0';
	while (nb)
	{
		rev[i++] = g_base[nb % base];
		nb /= base;
	}
	rev[i--] = '\0';
	while (i >= 0)
		result[j++] = rev[i--];
	return (result);
}
