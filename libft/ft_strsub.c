/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:01:58 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/26 20:45:41 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	result = (char *)ft_memalloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	while (i < start)
		i++;
	while (i < len + start)
	{
		result[i - start] = s[i];
		i++;
	}
	result[i - start] = '\0';
	return (result);
}
