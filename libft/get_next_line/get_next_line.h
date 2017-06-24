/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:28:45 by mfrankev          #+#    #+#             */
/*   Updated: 2017/01/21 17:16:05 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# define READ_TO_TMP (read(fd, tmp, BUFF_SIZE))
# define OUT_MALLOC (out = ft_strnew(BUFF_SIZE + 1))
# define LINE_MALLOC (*line = ft_strnew(BUFF_SIZE))
# define F_CHAR(s, c) (s && (ft_strchr(s, c)) ? ft_strchr(s, c) - s : 0)

# include "../libft.h"

typedef	struct	s_lefts
{
	int				fd;
	char			*str;
	struct s_lefts	*next;
}				t_lefts;

int				get_next_line(const int fd, char **line);
char			*ft_freejoin(char *s1, char *s2);
void			get_from_static(char **list, char **out);
void			push_to_static(char **list, char **line, char **out);

#endif
