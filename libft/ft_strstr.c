/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:01:51 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/28 20:51:34 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		len_l;
	int		end;
	char	*b;

	len_l = ft_strlen(little);
	end = ft_strlen(big);
	b = (char *)big;
	if (len_l == 0)
		return (b);
	while (b - big <= end)
	{
		if (ft_strncmp(b, little, len_l) == 0)
			return (b);
		b++;
	}
	return (NULL);
}
