/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:04:42 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/15 14:18:15 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_push_back(t_stack *s, int data)
{
	int i;

	i = s->cur_elem;
	if (s->cur_elem >= s->stack_len)
	{
		s->elems = ft_realloc(s->elems, s->stack_len * sizeof(int), \
			s->stack_len * sizeof(int) * 2);
		s->stack_len *= 2;
	}
	while (i > 0)
	{
		s->elems[i] = s->elems[i - 1];
		i--;
	}
	s->cur_elem++;
	s->elems[0] = data;
}
