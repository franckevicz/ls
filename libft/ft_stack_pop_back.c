/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:05:16 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/15 14:09:01 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stack_pop_back(t_stack *s)
{
	int tmp;
	int i;

	if (s->cur_elem <= 0)
		return (0);
	i = 0;
	tmp = s->elems[0];
	while (i < s->cur_elem)
	{
		s->elems[i] = s->elems[i + 1];
		i++;
	}
	s->cur_elem--;
	return (tmp);
}
