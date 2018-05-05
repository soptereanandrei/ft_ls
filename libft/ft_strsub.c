/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:13 by asoptere          #+#    #+#             */
/*   Updated: 2018/02/09 22:57:06 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (!(ptr = (char*)malloc(len + 1)))
		return (NULL);
	i = 0;
	if (s)
	{
		while (i < len)
		{
			*(ptr + i) = *(s + start + i);
			i++;
		}
		*(ptr + i) = '\0';
	}
	return (ptr);
}
