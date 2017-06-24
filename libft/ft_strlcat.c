/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:00:07 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/26 15:52:07 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	d_len;
	size_t	s_len;

	d = dst;
	s = (char *)src;
	while (*d != '\0')
		d++;
	d_len = d - dst;
	if (d_len >= size)
		return (size + ft_strlen(src));
	s_len = size - d_len;
	while (s_len != 1 && *s)
	{
		*d++ = *s++;
		s_len--;
	}
	*d = '\0';
	return (d_len + ft_strlen(src));
}
