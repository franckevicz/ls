/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:00:13 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/26 20:47:47 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	size_t	len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = f(s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
