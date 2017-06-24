/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:07:52 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/26 18:49:35 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert_to_str(unsigned int n, char *result)
{
	char	rev[12];
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (n)
	{
		rev[i++] = n % 10 + '0';
		n /= 10;
	}
	len = i - 1;
	if (result[0] == '-')
	{
		len++;
		j++;
	}
	while (j <= len)
	{
		result[j] = rev[len - j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		tmp;
	int		i;

	i = 0;
	tmp = n;
	while (tmp)
	{
		i++;
		tmp /= 10;
	}
	if (!(result = (char *)ft_memalloc(sizeof(*result) * i + 2)))
		return (NULL);
	if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	return (convert_to_str((unsigned int)n, result));
}
