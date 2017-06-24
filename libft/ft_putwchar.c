/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:39:50 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/22 13:51:51 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(int w)
{
	static unsigned char	b_static[5];
	unsigned char			*b;

	b = b_static;
	if (w < (1 << 7))
		*b++ = (unsigned char)(w);
	if (w < (1 << 11))
	{
		*b++ = (unsigned char)((w >> 6) | 0xC0);
		*b++ = (unsigned char)((w & 0x3F) | 0x80);
	}
	else if (w < (1 << 16))
	{
		*b++ = (unsigned char)(((w >> 12)) | 0xE0);
		*b++ = (unsigned char)(((w >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((w & 0x3F) | 0x80);
	}
	else if (w < (1 << 21))
	{
		*b++ = (unsigned char)(((w >> 18)) | 0xF0);
		*b++ = (unsigned char)(((w >> 12) & 0x3F) | 0x80);
		*b++ = (unsigned char)(((w >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((w & 0x3F) | 0x80);
	}
	write(1, &b_static, b - b_static);
}
