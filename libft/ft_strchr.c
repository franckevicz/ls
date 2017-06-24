/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:58:20 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/25 19:58:21 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *result;

	result = NULL;
	if ((result = ft_memchr(s, c, ft_strlen(s) + 1)) != NULL)
		return (result);
	else
		return (NULL);
}
