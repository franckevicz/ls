/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:11:49 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/25 17:11:50 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_u(unsigned int n)
{
	if (n / 10)
		ft_putnbr_u(n / 10);
	ft_putchar(n % 10 + '0');
}

void		ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	ft_putnbr_u((unsigned int)n);
}
