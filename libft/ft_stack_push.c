/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:05:35 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/15 14:19:10 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_push(t_stack *s, int data)
{
	if (s->cur_elem >= s->stack_len)
	{
		s->elems = ft_realloc(s->elems, s->stack_len * sizeof(int), \
			s->stack_len * sizeof(int) * 2);
		s->stack_len *= 2;
	}
	s->elems[s->cur_elem] = data;
	s->cur_elem++;
}
