/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:01:00 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/25 20:01:01 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*result;

	i = 0;
	result = (char *)malloc(size + 1);
	if (result == NULL)
		return (NULL);
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	result[i] = '\0';
	return (result);
}
