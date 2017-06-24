/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 21:22:46 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/26 19:26:04 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_s(t_list *lst)
{
	while (lst)
	{
		ft_putstr((char*)lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
	return ;
}

void	ft_lstprint_i(t_list *lst)
{
	while (lst)
	{
		ft_putnbr((int)lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
	return ;
}
