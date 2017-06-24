/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:39:50 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/22 13:51:51 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t len, size_t n)
{
	void *new;

	if (!(new = ft_memalloc(n)))
		return (NULL);
	ft_memmove(new, ptr, len);
	free(ptr);
	return (new);
}
