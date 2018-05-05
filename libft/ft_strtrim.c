/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 10:38:31 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/28 15:45:30 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*alloc(char const *s)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	i = 0;
	while (*(s + i) == ' ' || *(s + i) == '\t' || *(s + i) == '\n')
		i++;
	start = i;
	while (*(s + i + 1))
		i++;
	while (*(s + i) == ' ' || *(s + i) == '\t' || *(s + i) == '\n')
		i--;
	end = i;
	if (!(str = (char*)malloc(end - start + 2)))
		return (0);
	i = 0;
	while (start + i <= end)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	char	*str;

	if (s)
	{
		if (!(str = alloc(s)))
			return (0);
		return (str);
	}
	return (0);
}
