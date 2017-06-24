/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:01:07 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/26 19:18:53 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		len_l;
	int		end;
	char	*b;

	len_l = ft_strlen(little);
	end = ft_strlen(big);
	b = (char *)big;
	if (len_l == 0)
		return (b);
	while (b - big <= end && b - big <= (long)(len - len_l))
	{
		if (ft_strncmp(b, little, len_l) == 0)
			return (b);
		b++;
	}
	return (NULL);
}
