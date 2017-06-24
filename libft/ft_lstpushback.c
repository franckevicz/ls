/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:32:53 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/15 10:35:17 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list	*crawler;

	if (*alst == NULL)
	{
		ft_lstadd(alst, new);
		return ;
	}
	crawler = *alst;
	while (crawler->next)
		crawler = crawler->next;
	crawler->next = new;
	return ;
}
