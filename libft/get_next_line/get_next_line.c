/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 15:11:48 by mfrankev          #+#    #+#             */
/*   Updated: 2017/01/26 17:05:28 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char			*out;
	char			tmp[BUFF_SIZE + 1];
	static	char	*list = NULL;
	ssize_t			i;

	i = -1;
	if (!OUT_MALLOC || line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	get_from_static(&list, &out);
	if (!out || !ft_strchr(out, '\n'))
		while ((i = read(fd, tmp, BUFF_SIZE)))
		{
			if (i == -1)
				return (-1);
			tmp[i] = '\0';
			out = ft_freejoin(out, tmp);
			if (ft_strchr(tmp, '\n'))
				break ;
		}
	if (out && !ft_strchr(out, '\n'))
		out = ft_freejoin(out, "\n");
	*line = ft_memcpy(ft_strnew(F_CHAR(out, '\n')), out, F_CHAR(out, '\n'));
	push_to_static(&list, line, &out);
	free(out);
	return ((i || ft_strlen(*line)) ? 1 : 0);
}

void	get_from_static(char **list, char **out)
{
	if (*list)
	{
		*out = *list;
		ft_memdel((void **)(list));
	}
	return ;
}

void	push_to_static(char **list, char **line, char **out)
{
	if (*(*out + ft_strlen(*line) + 1))
		*list = ft_strdup(*out + ft_strlen(*line) + 1);
	return ;
}
