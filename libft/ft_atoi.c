/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:05:44 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/15 14:17:39 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	char	*s;
	int		i;
	int		flag;
	int		result;

	result = 0;
	flag = 1;
	s = (char *)str;
	i = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		s++;
		flag = -1;
	}
	while (*s >= '0' && *s <= '9')
	{
		result *= 10;
		result += *s++ - '0';
	}
	return (result * flag);
}
