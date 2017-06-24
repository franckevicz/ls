/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:39:16 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/15 14:10:37 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_new(t_stack *s)
{
	s->stack_len = START_STACK_SIZE;
	s->cur_elem = 0;
	s->elems = malloc(s->stack_len * sizeof(int));
}
