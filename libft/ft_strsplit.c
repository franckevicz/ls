/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:01:29 by mfrankev          #+#    #+#             */
/*   Updated: 2016/11/26 20:52:50 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	c_w(const char *s, char del)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == del && s[i])
			i++;
		if (s[i])
			counter++;
		while (s[i] != del && s[i])
			i++;
	}
	return (counter);
}

static int	len_word(const char *s, char del)
{
	int i;

	i = 0;
	while (s[i] != del && s[i])
		i++;
	return (i);
}

static char	*add_word(const char *str, int len)
{
	int		j;
	char	*result;

	result = (char *)malloc(sizeof(char) * len + 1);
	j = 0;
	while (j < len)
	{
		result[j] = str[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		len;
	char	**result;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(result = (char **)malloc(sizeof(char *) * (c_w(s, c) + 1))))
		return (NULL);
	while (*s == c)
		s++;
	while (*s)
	{
		while (*s == c)
			s++;
		len = len_word(s, c);
		result[i] = add_word(s, len);
		s += len;
		while (*s == c)
			s++;
		i++;
	}
	result[i] = NULL;
	return (result);
}
