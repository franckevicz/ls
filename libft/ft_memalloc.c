/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:08:08 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/25 17:08:14 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*result;

	i = 0;
	result = malloc(size);
	if (result == NULL)
		return (NULL);
	while (i < size)
	{
		*((unsigned char *)result + i) = 0;
		i++;
	}
	return (result);
}
