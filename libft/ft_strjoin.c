/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:32:24 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/28 14:04:54 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		*ptr;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		if (!(ptr = (char*)malloc(size + 1)))
			return (NULL);
		i = 0;
		j = 0;
		size = ft_strlen(s1);
		while (i < size)
			*(ptr + i++) = *(s1 + j++);
		j = 0;
		size = ft_strlen(s2);
		while (j < size)
			*(ptr + i++) = *(s2 + j++);
		*(ptr + i) = '\0';
		return (ptr);
	}
	return (0);
}
