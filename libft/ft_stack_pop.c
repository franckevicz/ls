/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:04:09 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/15 14:09:17 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stack_pop(t_stack *s)
{
	if (s->cur_elem >= 0)
		return (s->elems[--s->cur_elem]);
	else
	{
		s->cur_elem = -1;
		return (0);
	}
}
