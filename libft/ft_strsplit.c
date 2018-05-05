/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 11:28:19 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/28 15:44:10 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**allocmemory(char const *s, char c, size_t i)
{
	char	**tab;
	size_t	j;
	size_t	len;

	len = 0;
	while (*(s + i++))
		if (*(s + i - 1) != c && (*(s + i) == c || *(s + i) == '\0'))
			len++;
	if (!(tab = (char**)malloc(sizeof(char*) * (len + 1))))
		return (0);
	*(tab + len) = 0;
	i = 0;
	j = 0;
	len = 0;
	while (*(s + i++))
		if (*(s + i - 1) != c && (*(s + i) == c || *(s + i) == '\0'))
		{
			if (!(*(tab + j++) = (char*)malloc(++len + 1)))
				return (0);
			len = 0;
		}
		else if (*(s + i) != c)
			len++;
	return (tab);
}

static	char	**copy(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!(tab = allocmemory(s, c, 0)))
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			*(*(tab + k) + j++) = *(s + i);
			if (*(s + i + 1) == c || *(s + i + 1) == '\0')
			{
				*(*(tab + k++) + j) = '\0';
				j = 0;
			}
		}
		i++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s)
	{
		if (!(tab = copy(s, c)))
			return (0);
		return (tab);
	}
	return (0);
}
