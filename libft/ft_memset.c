/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:10:01 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/28 12:33:45 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	item;
	size_t			i;

	i = 0;
	item = c;
	while (i < len)
	{
		*((unsigned char *)b + i++) = item;
	}
	return (b);
}
