/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:14:42 by mfrankev          #+#    #+#             */
/*   Updated: 2017/02/15 18:35:53 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_symbols_p(char symbol, int count)
{
	char	*result;
	int		i;

	i = 0;
	while (i < count)
	{
		ft_putchar(symbol);
		i++;
	}
	return ;
}

char	*ft_strtoupper(char *str, t_ident *ident)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = (char*)malloc(ft_strlen(str) + 1)))
		return (NULL);
	while (*str)
	{
		ret[i++] = ft_toupper(*str);
		str++;
	}
	ret[i] = '\0';
	return (ret);
}

void	parce_conv(const char **f, t_ident *ident)
{
	ident->c = **f;
	if (**f)
		(*f)++;
}
