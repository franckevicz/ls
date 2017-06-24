/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:04:45 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/29 19:49:56 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *crawler;

	crawler = *alst;
	while (crawler)
	{
		*alst = (*alst)->next;
		ft_lstdelone(&crawler, *del);
		crawler = *alst;
	}
	*alst = NULL;
}
